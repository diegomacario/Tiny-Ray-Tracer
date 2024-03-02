#include "rm67162.h"
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite img = TFT_eSprite(&tft);

unsigned int colorIndex = 0;
unsigned long frameCounter = 0;

void setup() {
  img.createSprite(536, 240);
  rm67162_init();
  lcd_setRotation(1);
}

void loop() {
  if (colorIndex == 0) {
    img.fillRect(0, 0, 536, 240, TFT_RED);
  } else if (colorIndex == 1) {
    img.fillRect(0, 0, 536, 240, TFT_GREEN);
  } else if (colorIndex == 2) {
    img.fillRect(0, 0, 536, 240, TFT_BLUE);
  }

  lcd_PushColors(0, 0, 536, 240, (uint16_t*)(img.getPointer()));

  frameCounter += 1;
  if (frameCounter % 180 == 0) {
    colorIndex += 1;
    colorIndex %= 3;
  }
}
