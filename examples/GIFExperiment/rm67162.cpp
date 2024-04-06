#include "rm67162.h"
#include "SPI.h"
#include "Arduino.h"
#include "driver/spi_master.h"

volatile bool TE_flag=false;
volatile uint8_t frame_count=0;

void IRAM_ATTR ISR() 
{
    //TE_flag=digitalRead(9);
    TE_flag=true;
    frame_count++;
}

//psram buffer for matrix rotation (536 * 240 * 2)
uint16_t* qBuffer = (uint16_t*) heap_caps_malloc(257280, MALLOC_CAP_SPIRAM); 

const static lcd_cmd_t rm67162_qspi_init[] = {
    {0x11, {0x00}, 0x80},        // Sleep Out
    {0x44, {0x00, 0}, 0x02},     // Set_Tear_Scanline to line 0
    {0x35, {0x02},0x01},         // TE ON
    // {0x34, {0x00}, 0x00},     // TE OFF
    // {0x36, {0x00}, 0x01},     // Scan Direction Control
    {0x3A, {0x55}, 0x01},        // Interface Pixel Format	16bit/pixel
    // {0x3A, {0x66},0x01},      // Interface Pixel Format	18bit/pixel
    // {0x3A, {0x77},0x01},      // Interface Pixel Format	24bit/pixel
    {0x51, {0x00}, 0x01},        // Write Display Brightness MAX_VAL=0XFF
    {0x29, {0x00}, 0x80},        // Display on
    {0x51, {0xD0}, 0x01},        // Write Display Brightness	MAX_VAL=0XFF
};

static spi_device_handle_t spi;

static void lcd_send_cmd(uint32_t cmd, uint8_t *dat, uint32_t len)
{
    TFT_CS_L;
    spi_transaction_t t;
    memset(&t, 0, sizeof(t));
    t.flags = (SPI_TRANS_MULTILINE_CMD | SPI_TRANS_MULTILINE_ADDR);
    t.cmd = 0x02;
    t.addr = cmd << 8;
    if (len != 0)
    {
        t.tx_buffer = dat;
        t.length = 8 * len;
    }
    else
    {
        t.tx_buffer = NULL;
        t.length = 0;
    }
    spi_device_polling_transmit(spi, &t);
    TFT_CS_H;
}

void rm67162_init(void)
{
    pinMode(TFT_CS, OUTPUT);
    pinMode(TFT_RES, OUTPUT);

    TFT_RES_L;
    delay(300);
    TFT_RES_H;
    delay(200);

    esp_err_t ret;

    spi_bus_config_t buscfg = {
        .data0_io_num = TFT_QSPI_D0,
        .data1_io_num = TFT_QSPI_D1,
        .sclk_io_num = TFT_QSPI_SCK,
        .data2_io_num = TFT_QSPI_D2,
        .data3_io_num = TFT_QSPI_D3,
        .max_transfer_sz = (SEND_BUF_SIZE * 16) + 8,
        .flags = SPICOMMON_BUSFLAG_MASTER | SPICOMMON_BUSFLAG_GPIO_PINS
        ,
    };
    spi_device_interface_config_t devcfg = {
        .command_bits = 8,
        .address_bits = 24,
        .mode = TFT_SPI_MODE,
        .clock_speed_hz = SPI_FREQUENCY,
        .spics_io_num = -1,
        .flags = SPI_DEVICE_HALFDUPLEX,
        .queue_size = 1,
    };
    ret = spi_bus_initialize(TFT_SPI_HOST, &buscfg, SPI_DMA_CH_AUTO);
    ESP_ERROR_CHECK(ret);
    ret = spi_bus_add_device(TFT_SPI_HOST, &devcfg, &spi);
    ESP_ERROR_CHECK(ret);

    // Initialize the screen multiple times to prevent initialization failure
    int i = 3;
    while (i--) {
        const lcd_cmd_t *lcd_init = rm67162_qspi_init;
        for (int i = 0; i < sizeof(rm67162_qspi_init) / sizeof(lcd_cmd_t); i++)
        {
            lcd_send_cmd(lcd_init[i].cmd,
                         (uint8_t *)lcd_init[i].data,
                         lcd_init[i].len & 0x7f);

            if (lcd_init[i].len & 0x80)
                delay(120);
        }
    }
}

void lcd_setRotation(uint8_t r)
{
    uint8_t gbr = TFT_MAD_RGB;

    switch (r)
    {
    case 0: // Portrait
        // WriteData(gbr);
        break;
    case 1: // Landscape (Portrait + 90)
        gbr = TFT_MAD_MX | TFT_MAD_MV | gbr;
        break;
    case 2: // Inverter portrait
        gbr = TFT_MAD_MX | TFT_MAD_MY | gbr;
        break;
    case 3: // Inverted landscape
        gbr = TFT_MAD_MV | TFT_MAD_MY | gbr;
        break;
    }
    lcd_send_cmd(TFT_MADCTL, &gbr, 1);
}

void lcd_address_set(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
{
    lcd_cmd_t t[3] = {
        {0x2a, {(uint8_t)(x1 >> 8), (uint8_t)x1, uint8_t(x2 >> 8), (uint8_t)(x2)}, 0x04},
        {0x2b, {(uint8_t)(y1 >> 8), (uint8_t)(y1), (uint8_t)(y2 >> 8), (uint8_t)(y2)}, 0x04},
    };

    for (uint32_t i = 0; i < 3; i++)
    {
        lcd_send_cmd(t[i].cmd, t[i].data, t[i].len);
    }
}

void lcd_fill(uint16_t xsta, uint16_t ysta, uint16_t xend, uint16_t yend, uint16_t color)
{
    uint16_t w = xend - xsta;
    uint16_t h = yend - ysta;
    uint16_t *color_p = (uint16_t *)heap_caps_malloc(w * h * 2, MALLOC_CAP_INTERNAL);
    memset(color_p, color, w * h * 2);
    lcd_PushColors(xsta, ysta, w, h, color_p);
    free(color_p);
}

void lcd_DrawPoint(uint16_t x, uint16_t y, uint16_t color)
{
    lcd_address_set(x, y, x + 1, y + 1);
    lcd_PushColors(&color, 1);
}

void lcd_PushColors(uint16_t x, uint16_t y, uint16_t width, uint16_t high, uint16_t *data)
{
    bool first_send = 1;
    size_t len = width * high;
    uint16_t *p = (uint16_t *)data;
    lcd_address_set(x, y, x + width - 1, y + high - 1);      
    TFT_CS_L;
    do
    {
        size_t chunk_size = len;
        spi_transaction_ext_t t = {0};
        memset(&t, 0, sizeof(t));
        if (first_send)
        {
            t.base.flags = SPI_TRANS_MODE_QIO;
            t.base.cmd = 0x32;
            t.base.addr = 0x002C00;
            first_send = 0;
        }
        else
        {
            t.base.flags = SPI_TRANS_MODE_QIO | SPI_TRANS_VARIABLE_CMD | SPI_TRANS_VARIABLE_ADDR | SPI_TRANS_VARIABLE_DUMMY;
            t.command_bits = 0;
            t.address_bits = 0;
            t.dummy_bits = 0;
        }
        if (chunk_size > SEND_BUF_SIZE)
        {
            chunk_size = SEND_BUF_SIZE;
        }
        t.base.tx_buffer = p;
        t.base.length = chunk_size * 16;

        spi_device_polling_transmit(spi, (spi_transaction_t *)&t);
        len -= chunk_size;
        p += chunk_size;

    } while (len > 0);

    //Serial.println(frame_count);
    frame_count=0;
    TFT_CS_H;
}



void lcd_PushColors_Rotated_90(uint16_t x, uint16_t y, uint16_t width, uint16_t high, uint16_t *data)
{
    uint16_t  _x = 240 - (y + high);
    uint16_t  _y = x;
    uint16_t  _h = width;
    uint16_t  _w = high;
    lcd_address_set(_x, _y, _x + _w - 1, _y + _h - 1);

    bool first_send = 1;
    bool frame_top = 1;  
    size_t len = width * high;
    uint16_t *p = (uint16_t *)data;
    uint16_t *q = (uint16_t *)qBuffer;
    uint32_t index = 0; 
    
    for (uint16_t j = 0; j < width; j++)
    {
        for (uint16_t i = 0; i < high; i++)
        {
            qBuffer[index++] = ((uint16_t)p[width * (high - i - 1) + j]);             
        }
    }

    TFT_CS_L;
    do
    {
        size_t chunk_size = len;
        spi_transaction_ext_t t = {0};
        memset(&t, 0, sizeof(t));
        if (first_send)
        {
            frame_top = 1;  
            t.base.flags = SPI_TRANS_MODE_QIO;
            t.base.cmd = 0x32;
            t.base.addr = 0x002C00;
            first_send = 0;
        }
        else
        {
            t.base.flags = SPI_TRANS_MODE_QIO | SPI_TRANS_VARIABLE_CMD | SPI_TRANS_VARIABLE_ADDR | SPI_TRANS_VARIABLE_DUMMY;
            t.command_bits = 0;
            t.address_bits = 0;
            t.dummy_bits = 0;
        }
        if (chunk_size > SEND_BUF_SIZE)
        {
            chunk_size = SEND_BUF_SIZE;
        }
        t.base.tx_buffer = q;
        t.base.length = chunk_size * 16;

        if(frame_top==1)
        {   
        //if TE_flag is high then cancel and wait for the next one as we might be half way thru the blanking period.
        if(TE_flag==true) TE_flag=false;  
        //infinite loop until TE_flag goes high again. We need to start transmission on the rising edge of TE.      
        while (TE_flag==false) ;
        frame_top=0;
        }  

        spi_device_polling_transmit(spi, (spi_transaction_t *)&t);
        len -= chunk_size;
        q += chunk_size;
    } while (len > 0);

    //Serial.println(frame_count);
    frame_count=0;
    TFT_CS_H;
}


void lcd_PushColors_Rotated_270(uint16_t x, uint16_t y, uint16_t width, uint16_t high, uint16_t *data)
{
    uint16_t  _x = 240 - (y + high);
    uint16_t  _y = x;
    uint16_t  _h = width;
    uint16_t  _w = high;
    lcd_address_set(_x, _y, _x + _w - 1, _y + _h - 1);

    bool first_send = 1;
    bool frame_top = 1;  
    size_t len = width * high;
    uint16_t *p = (uint16_t *)data;
    uint16_t *q = (uint16_t *)qBuffer;
    uint32_t index = 0; 
    
    for (uint16_t j = 0; j < width; j++)
    {
        for (uint16_t i = 0; i < high; i++)
        {
            qBuffer[index++] = ((uint16_t)p[width * (i + 1) - j]);       
        }
    }

    TFT_CS_L;
    do
    {
        size_t chunk_size = len;
        spi_transaction_ext_t t = {0};
        memset(&t, 0, sizeof(t));
        if (first_send)
        {
            frame_top = 1;  
            t.base.flags = SPI_TRANS_MODE_QIO;
            t.base.cmd = 0x32;
            t.base.addr = 0x002C00;
            first_send = 0;
        }
        else
        {
            t.base.flags = SPI_TRANS_MODE_QIO | SPI_TRANS_VARIABLE_CMD | SPI_TRANS_VARIABLE_ADDR | SPI_TRANS_VARIABLE_DUMMY;
            t.command_bits = 0;
            t.address_bits = 0;
            t.dummy_bits = 0;
        }
        if (chunk_size > SEND_BUF_SIZE)
        {
            chunk_size = SEND_BUF_SIZE;
        }
        t.base.tx_buffer = q;
        t.base.length = chunk_size * 16;

        if(frame_top==1)
        {   
        //if TE_flag is high then cancel and wait for the next one as we might be half way thru the blanking period.
        if(TE_flag==true) TE_flag=false; 
        //infinite loop until TE_flag goes high again. We need to start transmission on the rising edge of TE.      
        while (TE_flag==false) ;
        frame_top=0;
        }  

        spi_device_polling_transmit(spi, (spi_transaction_t *)&t);
        len -= chunk_size;
        q += chunk_size;
    } while (len > 0);

    //Serial.println(frame_count);
    frame_count=0;
    TFT_CS_H;
}


void lcd_PushColors(uint16_t *data, uint32_t len)
{
    bool first_send = 1;
    uint16_t *p = (uint16_t *)data;
    TFT_CS_L;
    do
    {
        size_t chunk_size = len;
        spi_transaction_ext_t t = {0};
        memset(&t, 0, sizeof(t));
        if (first_send)
        {
            t.base.flags = SPI_TRANS_MODE_QIO;
            t.base.cmd = 0x32;
            t.base.addr = 0x002C00;
            first_send = 0;
        }
        else
        {
            t.base.flags = SPI_TRANS_MODE_QIO | SPI_TRANS_VARIABLE_CMD |
                           SPI_TRANS_VARIABLE_ADDR | SPI_TRANS_VARIABLE_DUMMY;
            t.command_bits = 0;
            t.address_bits = 0;
            t.dummy_bits = 0;
        }
        if (chunk_size > SEND_BUF_SIZE)
        {
            chunk_size = SEND_BUF_SIZE;
        }
        t.base.tx_buffer = p;
        t.base.length = chunk_size * 16;

        //if TE_flag is high then cancel and wait for the next one as we might be half way thru the blanking period.
        if(TE_flag==true )  TE_flag=false;    

        //infinite loop until TE_flag goes high again. We need to start transmission on the rising edge of TE.
        while (TE_flag==false) 
        ;        
        
        spi_device_polling_transmit(spi, (spi_transaction_t *)&t);
        TE_flag=false;
        len -= chunk_size;
        p += chunk_size;
    } while (len > 0);
    TFT_CS_H;
}

void lcd_sleep() {lcd_send_cmd(0x10, NULL, 0);}
void lcd_brightness(uint8_t bright) {lcd_send_cmd(0x51, &bright, 0x01);}	
void lcd_display_off() {lcd_send_cmd(0x28, NULL, 0x01);}
void lcd_display_on() {lcd_send_cmd(0x29, NULL, 0x01);}
void lcd_display_invert_on() {lcd_send_cmd(0x21, NULL, 0x01);}
void lcd_display_invert_off() {lcd_send_cmd(0x20, NULL, 0x01);}


//experimental
void lcd_display_set_colour_enhance_low_byte(uint8_t ce_low_byte) {lcd_send_cmd(0x5A, &ce_low_byte, 0x01);}
void lcd_display_set_colour_enhance_high_byte(uint8_t ce_high_byte) {lcd_send_cmd(0x5B, &ce_high_byte, 0x01);}
void lcd_display_high_brightness_mode_on(uint8_t hbm_en) {lcd_send_cmd(0xB0, &hbm_en, 0x01);}
void lcd_display_high_brightness_mode_off(uint8_t hbm_en) {lcd_send_cmd(0xB0, &hbm_en, 0x01);}
void lcd_set_colour_enhance(uint8_t enh) {lcd_send_cmd(0x58, &enh, 0x01);}	