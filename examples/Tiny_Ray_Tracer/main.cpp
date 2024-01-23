#include <LilyGo_AMOLED.h>
#include <TFT_eSPI.h>

#include <memory>
#include <iostream>

#include "FileParser.h"
#include "RandomSampleGenerator.h"
#include "RayGenerator.h"
#include "SceneDescription.h"

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite spr = TFT_eSprite(&tft);
TFT_eSprite progressBarSprite = TFT_eSprite(&tft);
LilyGo_Class amoled;

#define WIDTH  amoled.height()
#define HEIGHT amoled.width()

std::string sceneDescription = R"(
size 536 240
output sword.png

# --- --- --- --- -- CAMERA -- --- --- --- ---

# Sideways
camera 0 6.5 -2.44 0 0 -2.44 -1 0 0 45

# Hilt
#camera  0 2 0.18 0 0 0.18 0 0 -1 45

# Bottom to top
#camera 0 3 8 0 0 0 0 1 0 45

# --- --- --- --- -- LIGHTS -- --- --- --- ---

attenuation 0 1 0
point 1.5 1 -4.333 1 1 1
point -1.5 1 -1.667 1 1 1
attenuation 0 1 10
point -1.5 1 2 0.25 0.25 0.25

# --- --- --- --- - GEOMETRY - --- --- --- ---

maxverts 50

# Blade
# --- --- --- --- --- --- --- --- ---

ambient  0.26 0.36  0.36
diffuse  0.3 0.5 0.5
specular 0.1 0.2 0.2
shininess 9999999999
maxdepth 5

# Outter face
vertex  0.355  0.175  0
vertex  0.355  0.175 -6
vertex  0      0.175 -7
vertex -0.355  0.175 -6
vertex -0.355  0.175  0
vertex  0      0.175 -2.842

# Inner face
vertex  0.667  0  0
vertex  0.667  0 -6.545
vertex  0      0 -8
vertex -0.667  0 -6.545
vertex -0.667  0  0

# Outter face (front)
tri 0 1 5
tri 1 2 5
tri 2 3 5
tri 3 4 5
tri 4 0 5
# Inner face (front)
tri 0 6 1
tri 6 7 1
tri 1 8 2
tri 1 7 8
tri 2 8 3
tri 3 8 9
tri 4 3 10
tri 10 3 9

pushTransform
rotate 0 0 1 180
# Outter face (back)
tri 0 1 5
tri 1 2 5
tri 2 3 5
tri 3 4 5
tri 4 0 5
# Inner face (back)
tri 0 6 1
tri 6 7 1
tri 1 8 2
tri 1 7 8
tri 2 8 3
tri 3 8 9
tri 4 3 10
tri 10 3 9
popTransform

# Cross-guard
# --- --- --- --- --- --- --- --- ---

# Yellow
ambient  1 0.5  0
diffuse  0 0.75 0
specular 0 0.25 0

# Top
vertex -1.334  0.375 0
vertex  1.334  0.375 0
vertex  1.334 -0.375 0
vertex -1.334 -0.375 0

# Bottom
vertex -0.667  0.375 0.36
vertex  0.667  0.375 0.36
vertex  0.667 -0.375 0.36
vertex -0.667 -0.375 0.36

# Top
tri 11 12 13
tri 11 13 14

# Bottom
tri 15 16 17
tri 15 17 18

# Front
tri 15 16 12
tri 15 12 11

# Back
tri 17 18 13
tri 13 18 14

# Right
tri 16 17 13
tri 16 13 12

# Left
tri 18 15 11
tri 18 11 14

# Hilt
# --- --- --- --- --- --- --- --- ---

ambient  0 0.3  0.3
diffuse  0.3 0.5 0.5
specular 0.1 0.2 0.2

# Top
vertex  0.32475  0.1875 0.36
vertex  0.32475 -0.1875 0.36
vertex  0        0      0.36
vertex  0       -0.375  0.36
vertex -0.32475 -0.1875 0.36
vertex -0.32475  0.1875 0.36
vertex  0        0.375  0.36

# Bottom
vertex  0.2598  0.15 2.76
vertex  0.2598 -0.15 2.76
vertex  0       0    2.76
vertex  0      -0.3  2.76
vertex -0.2598 -0.15 2.76
vertex -0.2598  0.15 2.76
vertex  0       0.3  2.76

pushTransform

rotate 0 0 1 30

# Top
tri 19 20 21
tri 20 22 21
tri 22 23 21
tri 23 24 21
tri 24 25 21
tri 25 19 21

## Bottom
tri 28 27 26
tri 28 29 27
tri 28 30 29
tri 28 31 30
tri 28 32 31
tri 28 26 32

# Hexagonal sides
ambient 0.24 0.071875 0.071875
tri 32 26 19
tri 32 19 25
ambient 0.138 0.0367 0.040625
tri 26 27 20
tri 26 20 19
ambient 0.24 0.071875 0.071875
tri 27 29 22
tri 27 22 20
ambient 0.138 0.0367 0.040625
tri 29 30 23
tri 29 23 22
ambient 0.24 0.071875 0.071875
tri 30 31 24
tri 30 24 23
ambient 0.138 0.0367 0.040625
tri 31 32 25
tri 31 25 24

popTransform

# Sphere
# --- --- --- --- --- --- --- --- ---

# Yellow
ambient 1 0.5 0
diffuse  0 0.75 0
specular 0 0.25 0

sphere 0 0 2.76 0.36

# Ruby
# --- --- --- --- --- --- --- --- ---

# Red
ambient 0.5 0.1 0.1
diffuse 0.5 0 0
specular 0.25 0 0

# Outter face
vertex  0     0.45  0
vertex  0     0.45  1.5
vertex  1.299 0.45  0.75
vertex  1.299 0.45 -0.75
vertex  0     0.45 -1.5
vertex -1.299 0.45 -0.75
vertex -1.299 0.45  0.75

# Inner face
vertex  0          0.375  2.25
vertex  1.94855716 0.375  1.125
vertex  1.94855716 0.375 -1.125
vertex  0          0.375 -2.25
vertex -1.94855716 0.375 -1.125
vertex -1.94855716 0.375  1.125

pushTransform

translate 0 0 0.18
scale 0.05 1 0.07

# Outter face
tri 33 34 35
tri 33 35 36
tri 33 36 37
tri 33 37 38
tri 33 38 39
tri 33 39 34

# Inner face
tri 40 35 34
tri 40 41 35
tri 41 36 35
tri 41 42 36
tri 42 37 36
tri 42 43 37
tri 43 38 37
tri 43 44 38
tri 44 39 38
tri 44 45 39
tri 45 34 39
tri 45 40 34

popTransform

pushTransform

# Emerald
# --- --- --- --- --- --- --- --- ---

# Green
ambient 0 0.3 0.3
diffuse 0 0.75 0
specular 0 0.25 0 

rotate 0 0 1 180
translate 0 0 0.18
scale 0.05 1 0.07

# Outter face
tri 33 34 35
tri 33 35 36
tri 33 36 37
tri 33 37 38
tri 33 38 39
tri 33 39 34

# Inner face
tri 40 35 34
tri 40 41 35
tri 41 36 35
tri 41 42 36
tri 42 37 36
tri 42 43 37
tri 43 38 37
tri 43 44 38
tri 44 39 38
tri 44 45 39
tri 45 34 39
tri 45 40 34

popTransform
)";

FileParser fileParser(sceneDescription);
std::unique_ptr<SceneDescription> sceneDesc = nullptr;
std::unique_ptr<Scene> scene = nullptr;
RandomSampleGenerator sampleGenerator;
RayGenerator rayGenerator;
Sample sample;
Ray ray;
Intersection intersection;

const int32_t progressBarWidth = 500;
const int32_t progressBarHeight = 10;
const int32_t progressBarXPosition = 18;
const int32_t progressBarYPosition = 222;

void setup()
{
    Serial.begin(115200);

    if (!amoled.begin()) {
        while (1) {
            Serial.println("There is a problem with the device!"); delay(1000);
        }
    }

    spr.createSprite(WIDTH, HEIGHT);
    progressBarSprite.createSprite(progressBarWidth, progressBarHeight);

    spr.setSwapBytes(1);
    progressBarSprite.setSwapBytes(1);

    spr.fillSprite(TFT_BLACK);
    progressBarSprite.fillSprite(TFT_BLACK);

    progressBarSprite.drawRect(0, 0, progressBarWidth, progressBarHeight, TFT_WHITE);
    progressBarSprite.fillRect(1, 1, progressBarWidth - 2, progressBarHeight - 2, TFT_GREEN);

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
}

uint32_t rgb888ToRgb565(uint8_t r, uint8_t g, uint8_t b) {
    return ((r >> 3) << 11) | ((g >> 2) << 5) | (b >> 3);
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

            spr.drawPixel(sample.x, sample.y, colour);
            uint16_t* spritePtr = (uint16_t*)spr.getPointer();
            uint16_t* pixelPtr = spritePtr + (sample.y * WIDTH + sample.x);
            amoled.setAddrWindow(sample.x, sample.y, sample.x, sample.y);
            amoled.pushColors(pixelPtr, 1);
        }

        float progress = sampleGenerator.getProgress();
        amoled.pushColors(progressBarXPosition, progressBarYPosition, progressBarWidth, progressBarHeight, (uint16_t *)progressBarSprite.getPointer());
    }
}
