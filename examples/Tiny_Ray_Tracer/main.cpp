#include "rm67162.h"
#include <TFT_eSPI.h>

#include "Game.h"

#define TE_pin 9
#define display_enable_pin 38

TFT_eSPI tft = TFT_eSPI();

Game game;

void IRAM_ATTR ISR();

void setup()
{
    pinMode(display_enable_pin, OUTPUT);
    digitalWrite(display_enable_pin, HIGH);
    pinMode(TE_pin, INPUT);
    Serial.begin(115000); // 115200?
    rm67162_init();

    attachInterrupt(TE_pin, ISR, RISING);

    uint16_t height = 240;
    uint16_t width = 536;
    game.initialize(tft, width, height);
}

void loop()
{
    game.update();
}
