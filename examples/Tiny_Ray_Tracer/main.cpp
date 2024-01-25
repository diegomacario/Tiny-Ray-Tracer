#include <LilyGo_AMOLED.h>
#include <TFT_eSPI.h>

#include <memory>
#include <iostream>
#include <sstream>
#include <iomanip>

#include "FileParser.h"
#include "RandomSampleGenerator.h"
#include "RayGenerator.h"
#include "SceneDescription.h"
#include "Data.h"

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite imageRenderingSprite = TFT_eSprite(&tft);
TFT_eSprite percentageProgressLabelSprite = TFT_eSprite(&tft);
TFT_eSprite rayTracingLabelSprite = TFT_eSprite(&tft);
TFT_eSprite progressBarSprite = TFT_eSprite(&tft);
LilyGo_Class amoled;

#define WIDTH  amoled.height()
#define HEIGHT amoled.width()

FileParser fileParser(swordSceneDescription);
std::unique_ptr<SceneDescription> sceneDesc = nullptr;
std::unique_ptr<Scene> scene = nullptr;
RandomSampleGenerator sampleGenerator;
RayGenerator rayGenerator;
Sample sample;
Ray ray;
Intersection intersection;

struct TextSpriteSettings {
    TextSpriteSettings(int32_t textSize, int32_t fontHeight, int32_t fontWidth, std::string longestPossibleString)
        : textSize(textSize)
        , fontHeight(fontHeight)
        , fontWidth(fontWidth)
        , numCharacters(longestPossibleString.length())
        , spriteWidth(fontWidth * textSize * numCharacters)
        , spriteHeight(fontHeight * textSize)
    { }

    int32_t textSize;
    int32_t fontHeight;
    int32_t fontWidth;
    int32_t numCharacters;
    int32_t spriteWidth;
    int32_t spriteHeight;
};

TextSpriteSettings rayTracingSpriteSettings(3, 8, 6, "Ray-tracing...");
uint32_t numDots = 0;
unsigned long lastTimeRayTracingSpriteWasUpdated = 0;

TextSpriteSettings percentageProgressSpriteSettings(3, 8, 6, "100.0%");

const int32_t progressBarWidth = 536;
const int32_t progressBarHeight = 10;
const int32_t progressBarXPosition = 0;
const int32_t progressBarYPosition = 240 - progressBarHeight;
const int32_t progressBarFillableWidth = progressBarWidth;
const int32_t progressBarFillableHeight = progressBarHeight;
int32_t prevProgressWidth = 0;

bool doOnce = true;

uint32_t rgb888ToRgb565(uint8_t r, uint8_t g, uint8_t b) {
    return ((r >> 3) << 11) | ((g >> 2) << 5) | (b >> 3);
}

void updateRayTracingSprite() {
    if (millis() > lastTimeRayTracingSpriteWasUpdated + 1000) {
        numDots += 1;
        numDots %= 4;
        rayTracingLabelSprite.fillSprite(TFT_BLACK);
        std::string rayTracingString = "Ray-tracing";
        switch(numDots) {
            case 0:
                break;
            case 1:
                rayTracingString += ".";
                break;
            case 2:
                rayTracingString += "..";
                break;
            case 3:
                rayTracingString += "...";
                break;
            default:
                break;
        }
        rayTracingLabelSprite.drawString(rayTracingString.c_str(), 0, 0);
        amoled.pushColors(0, 0, rayTracingSpriteSettings.spriteWidth, rayTracingSpriteSettings.spriteHeight, (uint16_t *)rayTracingLabelSprite.getPointer());
        lastTimeRayTracingSpriteWasUpdated = millis();
    }
}

void updatePercentageProgressSprite(float progress) {
    percentageProgressLabelSprite.fillSprite(TFT_BLACK);
    std::stringstream stream;
    stream << std::fixed << std::setprecision(1) << (progress * 100.0f);
    std::string numberAsString = stream.str();
    numberAsString += "%";
    percentageProgressLabelSprite.drawString(numberAsString.c_str(), percentageProgressSpriteSettings.spriteWidth, 0);

    amoled.pushColors(WIDTH - percentageProgressSpriteSettings.spriteWidth, 0, percentageProgressSpriteSettings.spriteWidth, percentageProgressSpriteSettings.spriteHeight, (uint16_t *)percentageProgressLabelSprite.getPointer());
}

void updateProgressBar(float progress) {
    int32_t progressWidth = static_cast<int32_t>(progress * static_cast<float>(progressBarFillableWidth));
    if (progressWidth > prevProgressWidth) {
        progressBarSprite.fillRect(1, 1, progressWidth, progressBarFillableHeight, TFT_GREEN);
        prevProgressWidth = progressWidth;
    }
    amoled.pushColors(progressBarXPosition, progressBarYPosition, progressBarWidth, progressBarHeight, (uint16_t *)progressBarSprite.getPointer());
}

void setup()
{
    Serial.begin(115200);

    if (!amoled.begin()) {
        while (1) {
            Serial.println("There is a problem with the device!"); delay(1000);
        }
    }

    imageRenderingSprite.createSprite(WIDTH, HEIGHT);
    imageRenderingSprite.setSwapBytes(1);
    imageRenderingSprite.fillSprite(TFT_BLACK);

    rayTracingLabelSprite.createSprite(rayTracingSpriteSettings.spriteWidth, rayTracingSpriteSettings.spriteHeight);
    rayTracingLabelSprite.setSwapBytes(1);
    rayTracingLabelSprite.fillSprite(TFT_BLACK);
    rayTracingLabelSprite.setTextColor(TFT_WHITE);
    rayTracingLabelSprite.setTextSize(rayTracingSpriteSettings.textSize);
    rayTracingLabelSprite.setTextFont(1);
    rayTracingLabelSprite.drawString("Ray-tracing", 0, 0);
    rayTracingLabelSprite.setTextDatum(TL_DATUM);
    amoled.pushColors(0, 0, rayTracingSpriteSettings.spriteWidth, rayTracingSpriteSettings.spriteHeight, (uint16_t *)rayTracingLabelSprite.getPointer());

    percentageProgressLabelSprite.createSprite(percentageProgressSpriteSettings.spriteWidth, percentageProgressSpriteSettings.spriteHeight);
    percentageProgressLabelSprite.setSwapBytes(1);
    percentageProgressLabelSprite.fillSprite(TFT_BLACK);
    percentageProgressLabelSprite.setTextColor(TFT_WHITE);
    percentageProgressLabelSprite.setTextSize(percentageProgressSpriteSettings.textSize);
    percentageProgressLabelSprite.setTextFont(1);
    percentageProgressLabelSprite.drawString("0.0%", percentageProgressSpriteSettings.spriteWidth, 0);
    percentageProgressLabelSprite.setTextDatum(TR_DATUM);
    amoled.pushColors(WIDTH - percentageProgressSpriteSettings.spriteWidth, 0, percentageProgressSpriteSettings.spriteWidth, percentageProgressSpriteSettings.spriteHeight, (uint16_t *)percentageProgressLabelSprite.getPointer());

    progressBarSprite.createSprite(progressBarWidth, progressBarHeight);
    progressBarSprite.setSwapBytes(1);
    progressBarSprite.fillSprite(TFT_BLACK);

    fileParser.readFile(sceneDesc, scene);

    sampleGenerator = RandomSampleGenerator(sceneDesc->getWidth(), sceneDesc->getHeight());

    rayGenerator = RayGenerator(sceneDesc->getWidth(),
                                sceneDesc->getHeight(),
                                sceneDesc->getEye(),
                                sceneDesc->getCenter(),
                                sceneDesc->getUpVec(),
                                sceneDesc->getFovy());

    ray.origin = sceneDesc->getEye();
    ray.direction = Vector(0, 0, 0);

    lastTimeRayTracingSpriteWasUpdated = millis();
}

void loop()
{
    if (sampleGenerator.sampleIsAvailable())
    {
        sampleGenerator.generateSample(sample);
        rayGenerator.generateRay(sample, ray);

        // If the current ray intersects an object, we calculate the lighting at the intersection point and store the colour
        // If not, the current pixel remains black
        if (scene->findNearestIntersection(ray, &intersection))
        {
            Colour pixelColour = scene->calculateLightingAtIntersection(sceneDesc->getEye(), &intersection);

            uint8_t r = static_cast<uint8_t>(std::min(255 * pixelColour.r, 255.0f));
            uint8_t g = static_cast<uint8_t>(std::min(255 * pixelColour.g, 255.0f));
            uint8_t b = static_cast<uint8_t>(std::min(255 * pixelColour.b, 255.0f));
            uint32_t colour = rgb888ToRgb565(r, g, b);

            imageRenderingSprite.drawPixel(sample.x, sample.y, colour);
            uint16_t* spritePtr = (uint16_t*)imageRenderingSprite.getPointer();
            uint16_t* pixelPtr = spritePtr + (sample.y * WIDTH + sample.x);
            amoled.setAddrWindow(sample.x, sample.y, sample.x, sample.y);
            amoled.pushColors(pixelPtr, 1);
        }

        float progress = sampleGenerator.getProgress();

        updateRayTracingSprite();
        updatePercentageProgressSprite(progress);
        updateProgressBar(progress);
    }
    else if (doOnce) {
        rayTracingLabelSprite.fillSprite(TFT_BLACK);
        std::string doneString = "Done!";
        rayTracingLabelSprite.drawString(doneString.c_str(), 0, 0);
        amoled.pushColors(0, 0, rayTracingSpriteSettings.spriteWidth, rayTracingSpriteSettings.spriteHeight, (uint16_t *)rayTracingLabelSprite.getPointer());

        sleep(2);

        amoled.pushColors(0, 0, WIDTH, HEIGHT, (uint16_t *)imageRenderingSprite.getPointer());
        doOnce = false;
    }
}
