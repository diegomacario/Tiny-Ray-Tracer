#include <LilyGo_AMOLED.h>
#include <TFT_eSPI.h>

#include <memory>
#include <iostream>
#include <sstream>
#include <iomanip>

#include "Game.h"

TFT_eSPI tft = TFT_eSPI();
LilyGo_Class amoled;

#define WIDTH  amoled.height()
#define HEIGHT amoled.width()

Game game;

void setup()
{
    Serial.begin(115200);

    if (!amoled.begin()) {
        while (1) {
            Serial.println("There is a problem with the device!"); delay(1000);
        }
    }

    game.initialize(tft, &amoled, WIDTH, HEIGHT);
}

void loop()
{
    game.update();
}
