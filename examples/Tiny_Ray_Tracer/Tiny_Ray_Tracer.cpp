#include <LilyGo_AMOLED.h>
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite spr = TFT_eSprite(&tft);
LilyGo_Class amoled;

#define WIDTH  amoled.height()
#define HEIGHT amoled.width()

void setup()
{
    Serial.begin(115200);

    if (!amoled.begin()) {
        while (1) {
            Serial.println("There is a problem with the device!"); delay(1000);
        }
    }

    spr.createSprite(WIDTH, HEIGHT);

    spr.setSwapBytes(1);
}

void loop()
{
    spr.fillSprite(TFT_BLACK);
    spr.drawString("Hello World",20,20,4);
    spr.fillRect(10,100,60,60,TFT_RED);
    spr.fillRect(80,100,60,60,TFT_GREEN);
    spr.fillRect(150,100,60,60,TFT_BLUE);
 
    amoled.pushColors(0, 0, WIDTH, HEIGHT, (uint16_t *)spr.getPointer());
}
