#include "rm67162.h"
#include <TFT_eSPI.h>
#include "hugeFatFont.h"

#define TE_pin 9
#define display_enable_pin 38

uint8_t frame_rate;

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite img = TFT_eSprite(&tft);

void IRAM_ATTR ISR();

void setup() {
  pinMode(display_enable_pin, OUTPUT);
  digitalWrite(display_enable_pin, HIGH);
  pinMode(TE_pin, INPUT);
  Serial.begin(115000);
  img.createSprite(536, 240);
  rm67162_init();

  attachInterrupt(TE_pin, ISR, RISING);
  img.loadFont(hugeFatFont);
}

void loop() {

    uint32_t f1; uint32_t f2;

    // 90 degree rotate - Tear free

    lcd_setRotation(0);

    img.fillRect(0, 0, 536, 240, TFT_RED);
    img.setTextColor(TFT_WHITE, TFT_RED);
    img.drawString("TEARING TEST",175,100);
    lcd_PushColors_Rotated_90(0, 0, 536, 240, (uint16_t*)img.getPointer());
    delay(1000);
        
    img.fillRect(0, 0, 536, 240, TFT_GREEN);
    img.setTextColor(TFT_WHITE, TFT_GREEN);
    img.drawString("TEARING TEST",175,100);
    lcd_PushColors_Rotated_90(0, 0, 536, 240, (uint16_t*)img.getPointer());
    delay(1000);
     
    img.fillRect(0, 0, 536, 240, TFT_BLUE);
    img.setTextColor(TFT_WHITE, TFT_BLUE);
    img.drawString("TEARING TEST",175,100);
    lcd_PushColors_Rotated_90(0, 0, 536, 240, (uint16_t*)img.getPointer());
    delay(1000);

    // 90 degree rotate - Fast but not tear free

    lcd_setRotation(1);

    img.fillRect(0, 0, 536, 240, TFT_DARKCYAN);
    img.setTextColor(TFT_WHITE, TFT_RED);
    img.drawString("TEARING TEST",175,100);
    lcd_PushColors(0, 0, 536, 240, (uint16_t*)img.getPointer());
    delay(1000);
        
    img.fillRect(0, 0, 536, 240, TFT_GREENYELLOW);
    img.setTextColor(TFT_WHITE, TFT_GREEN);
    img.drawString("TEARING TEST",175,100);
    lcd_PushColors(0, 0, 536, 240, (uint16_t*)img.getPointer());
    delay(1000);
     
    img.fillRect(0, 0, 536, 240, TFT_PURPLE);
    img.setTextColor(TFT_WHITE, TFT_BLUE);
    img.drawString("TEARING TEST",175,100);
    lcd_PushColors(0, 0, 536, 240, (uint16_t*)img.getPointer());
    delay(1000);
}