// nikthefix 18.03.23 - lilygo s3 amoled - screen tearing experiment

#include "rm67162.h"
#include <TFT_eSPI.h>
#include "hugeFatFont.h"

#define TE_pin 9
#define display_enable_pin 38

uint8_t frame_rate;

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite img = TFT_eSprite(&tft);

void IRAM_ATTR ISR(); //declare prototype for TE interrupt

void setup() {
  pinMode(display_enable_pin, OUTPUT);                        //for s3 amoled touch
  digitalWrite(display_enable_pin, HIGH);                     //display enable
  pinMode(TE_pin, INPUT);                                     //TE line detect
  Serial.begin(115000);
  img.createSprite(536, 240);
  rm67162_init();

  //lcd_setRotation(3);//.....

  //Todo:
  //lcd_rotate function to select from the following rotation options.....

  //portrait
  //landscape 90 degrees
  //portrait 180 degrees
  //lanscape 270 degrees
  //portrait tear safe
  //landscape 90 degrees tear safe
  //portrait 180 degrees tear safe
  //lanscape 270 degrees tear safe

  //Todo:
  //Differential update to display gram using smaller pushed regions.


  attachInterrupt(TE_pin, ISR, RISING);
  img.loadFont(hugeFatFont);
  
}

void loop() {

    uint32_t f1; uint32_t f2;

//270 degree rotate

    f1=millis();
    img.fillRect(0, 0, 536, 240, TFT_RED);
    img.setTextColor(TFT_WHITE, TFT_RED);
    img.drawString("TEARING TEST",175,100);
    lcd_PushColors_Rotated_270(0, 0, 536, 240, (uint16_t*)img.getPointer());
    f2=millis();
    frame_rate = (1000/(f2-f1));
    Serial.println(frame_rate);
    delay(1000);
        
    f1=millis();    
    img.fillRect(0, 0, 536, 240, TFT_GREEN);
    img.setTextColor(TFT_WHITE, TFT_GREEN);
    img.drawString("TEARING TEST",175,100);
    lcd_PushColors_Rotated_270(0, 0, 536, 240, (uint16_t*)img.getPointer());
    f2=millis();
    frame_rate = (1000/(f2-f1));
    Serial.println(frame_rate);
    delay(1000);
     
    f1=millis();
    img.fillRect(0, 0, 536, 240, TFT_BLUE);
    img.setTextColor(TFT_WHITE, TFT_BLUE);
    img.drawString("TEARING TEST",175,100);
    lcd_PushColors_Rotated_270(0, 0, 536, 240, (uint16_t*)img.getPointer());
    f2=millis();
    frame_rate = (1000/(f2-f1));
    Serial.println(frame_rate);
    delay(1000);
  


//90 degree rotate

    f1=millis();
    img.fillRect(0, 0, 536, 240, TFT_RED);
    img.setTextColor(TFT_WHITE, TFT_RED);
    img.drawString("TEARING TEST",175,100);
    lcd_PushColors_Rotated_90(0, 0, 536, 240, (uint16_t*)img.getPointer());
    f2=millis();
    frame_rate = (1000/(f2-f1));
    Serial.println(frame_rate);
    delay(1000);
        
    f1=millis();    
    img.fillRect(0, 0, 536, 240, TFT_GREEN);
    img.setTextColor(TFT_WHITE, TFT_GREEN);
    img.drawString("TEARING TEST",175,100);
    lcd_PushColors_Rotated_90(0, 0, 536, 240, (uint16_t*)img.getPointer());
    f2=millis();
    frame_rate = (1000/(f2-f1));
    Serial.println(frame_rate);
    delay(1000);
     
    f1=millis();
    img.fillRect(0, 0, 536, 240, TFT_BLUE);
    img.setTextColor(TFT_WHITE, TFT_BLUE);
    img.drawString("TEARING TEST",175,100);
    lcd_PushColors_Rotated_90(0, 0, 536, 240, (uint16_t*)img.getPointer());
    f2=millis();
    frame_rate = (1000/(f2-f1));
    Serial.println(frame_rate);
    delay(1000);

    // f1=millis();
    // img.fillRect(0, 0, 536, 240, TFT_RED);
    // img.setTextColor(TFT_WHITE, TFT_RED);
    // img.drawString("TEARING TEST",175,100);
    // lcd_PushColors(0, 0, 536, 240, (uint16_t*)img.getPointer());
    // f2=millis();
    // frame_rate = (1000/(f2-f1));
    // Serial.println(frame_rate);
    // delay(1000);
        
    // f1=millis();    
    // img.fillRect(0, 0, 536, 240, TFT_GREEN);
    // img.setTextColor(TFT_WHITE, TFT_GREEN);
    // img.drawString("TEARING TEST",175,100);
    // lcd_PushColors(0, 0, 536, 240, (uint16_t*)img.getPointer());
    // f2=millis();
    // frame_rate = (1000/(f2-f1));
    // Serial.println(frame_rate);
    // delay(1000);
     
    // f1=millis();
    // img.fillRect(0, 0, 536, 240, TFT_BLUE);
    // img.setTextColor(TFT_WHITE, TFT_BLUE);
    // img.drawString("TEARING TEST",175,100);
    // lcd_PushColors(0, 0, 536, 240, (uint16_t*)img.getPointer());
    // f2=millis();
    // frame_rate = (1000/(f2-f1));
    // Serial.println(frame_rate);
    // delay(1000);

}