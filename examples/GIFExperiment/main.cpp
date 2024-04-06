#include "rm67162.h"
#include <TFT_eSPI.h>

#define TE_pin 9
#define display_enable_pin 38

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite img = TFT_eSprite(&tft);
TFT_eSprite img2 = TFT_eSprite(&tft);

void IRAM_ATTR ISR();

void setup() {
  pinMode(display_enable_pin, OUTPUT);
  digitalWrite(display_enable_pin, HIGH);
  pinMode(TE_pin, INPUT);
  Serial.begin(115000);
  img.createSprite(536, 240);
  img2.createSprite(200, 100);
  rm67162_init();

  attachInterrupt(TE_pin, ISR, RISING);
}

void loop() {
    // 90 degree rotate - Fullscreen - Tear free

    lcd_setRotation(0);

    img.fillRect(0, 0, 536, 240, TFT_RED);
    lcd_PushColors_Rotated_90(0, 0, 536, 240, (uint16_t*)img.getPointer());
    delay(1000);
        
    img.fillRect(0, 0, 536, 240, TFT_GREEN);
    lcd_PushColors_Rotated_90(0, 0, 536, 240, (uint16_t*)img.getPointer());
    delay(1000);
     
    img.fillRect(0, 0, 536, 240, TFT_BLUE);
    lcd_PushColors_Rotated_90(0, 0, 536, 240, (uint16_t*)img.getPointer());
    delay(1000);

    // 90 degree rotate - Fullscreen - Fast but not tear free

    lcd_setRotation(1);

    img.fillRect(0, 0, 536, 240, TFT_DARKCYAN);
    lcd_PushColors(0, 0, 536, 240, (uint16_t*)img.getPointer());
    delay(1000);
        
    img.fillRect(0, 0, 536, 240, TFT_GREENYELLOW);
    lcd_PushColors(0, 0, 536, 240, (uint16_t*)img.getPointer());
    delay(1000);
     
    img.fillRect(0, 0, 536, 240, TFT_PURPLE);
    lcd_PushColors(0, 0, 536, 240, (uint16_t*)img.getPointer());
    delay(1000);

    // 90 degree rotate - Not Fullscreen - Buggy

    int32_t width = 200;
    int32_t height = 100;

    img2.fillRect(0, 0, width, height, TFT_DARKCYAN);
    lcd_PushColors(0, 0, width, height, (uint16_t*)img2.getPointer());
    delay(1000);
        
    img2.fillRect(0, 0, width, height, TFT_GREENYELLOW);
    lcd_PushColors(0, 0, width, height, (uint16_t*)img2.getPointer());
    delay(1000);
     
    img2.fillRect(0, 0, width, height, TFT_PURPLE);
    lcd_PushColors(0, 0, width, height, (uint16_t*)img2.getPointer());
    delay(1000);
}