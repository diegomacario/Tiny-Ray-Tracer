

#include "rm67162.h"
#include <TFT_eSPI.h>

#define TE_pin 9
#define display_enable_pin 38

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite img = TFT_eSprite(&tft);

void IRAM_ATTR ISR(); //declare prototype for TE interrupt


void setup() {
  pinMode(display_enable_pin, OUTPUT);                        //for s3 amoled touch
  digitalWrite(display_enable_pin, HIGH);                     //display enable
  pinMode(TE_pin, INPUT);                                     //TE line detect
  //Serial.begin(115000);
  img.createSprite(536, 240);
  rm67162_init();
  lcd_setRotation(1);
  attachInterrupt(TE_pin, ISR, RISING);

}

void loop() {
        
    img.fillRect(0, 0, 536, 240, TFT_RED);
    lcd_PushColors(0, 0, 536, 240, (uint16_t*)img.getPointer());
    delay(1000);
        
    img.fillRect(0, 0, 536, 240, TFT_GREEN);
    lcd_PushColors(0, 0, 536, 240, (uint16_t*)img.getPointer());
    delay(1000);
     
    img.fillRect(0, 0, 536, 240, TFT_BLUE);
    lcd_PushColors(0, 0, 536, 240, (uint16_t*)img.getPointer());
    delay(1000);
    
}