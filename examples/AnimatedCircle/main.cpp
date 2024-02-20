#include "rm67162.h"
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite img = TFT_eSprite(&tft);

void setup() {
  img.createSprite(536, 240);
  img.setSwapBytes(1);
  rm67162_init();
  lcd_setRotation(1);
}

int x = 0;

void loop() {  
  //img.fillCircle(x, 120, 90, TFT_BLACK);
  img.drawCircle(x, 120, 90, TFT_BLACK);
  x = x + 1;
  if (x > 536) x = 0;

  if (x >= 200 && x < 400) {
    //img.fillCircle(x, 120, 90, TFT_GREEN);
    img.drawCircle(x, 120, 90, TFT_GREEN);
  } else if (x >= 400 && x < 536) {
    //img.fillCircle(x, 120, 90, TFT_BLUE);
    img.drawCircle(x, 120, 90, TFT_BLUE);
  } else {
    //img.fillCircle(x, 120, 90, TFT_RED);
    img.drawCircle(x, 120, 90, TFT_RED);
  }

  //img.fillRect(18, 70, 100, 100, TFT_BLACK);
  //img.drawString(String(x), 20, 74, 7);

  lcd_PushColors(0, 0, 536, 240, (uint16_t*)(img.getPointer()));
}
