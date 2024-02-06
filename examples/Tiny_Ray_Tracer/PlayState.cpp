#include <iomanip>

#include "PlayState.h"
#include "Data.h"

// TODO: Figure out where to put this
uint32_t rgb888ToRgb565(uint8_t r, uint8_t g, uint8_t b) {
    return ((r >> 3) << 11) | ((g >> 2) << 5) | (b >> 3);
}

PlayState::PlayState(const std::shared_ptr<FiniteStateMachine>& finiteStateMachine,
                     TFT_eSPI& tft,
                     LilyGo_Class* amoled,
                     uint16_t screenWidth,
                     uint16_t screenHeight)
   : mFSM(finiteStateMachine)
   , amoled(amoled)
   , mScreenWidth(screenWidth)
   , mScreenHeight(screenHeight)
   , imageRenderingSprite(&tft)
   , rayTracingLabelSprite(&tft)
   , percentageProgressLabelSprite(&tft)
   , progressBarSprite(&tft)
   , fileParser(planetSceneDescription)
   , sceneDesc(nullptr)
   , scene(nullptr)
   , rayTracingSpriteSettings(3, 8, 6, "Ray-tracing...")
   , numDots(0)
   , lastTimeRayTracingSpriteWasUpdated(0)
   , percentageProgressSpriteSettings(3, 8, 6, "100.0%")
   , progressBarWidth(536)
   , progressBarHeight(10)
   , progressBarXPosition(0)
   , progressBarYPosition(240 - progressBarHeight)
   , progressBarFillableWidth(progressBarWidth)
   , progressBarFillableHeight(progressBarHeight)
   , prevProgressWidth(0)
   , doOnce(true)
{

}

void PlayState::enter()
{
   imageRenderingSprite.createSprite(mScreenWidth, mScreenHeight);
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
   amoled->pushColors(0, 0, rayTracingSpriteSettings.spriteWidth, rayTracingSpriteSettings.spriteHeight, (uint16_t *)rayTracingLabelSprite.getPointer());

   percentageProgressLabelSprite.createSprite(percentageProgressSpriteSettings.spriteWidth, percentageProgressSpriteSettings.spriteHeight);
   percentageProgressLabelSprite.setSwapBytes(1);
   percentageProgressLabelSprite.fillSprite(TFT_BLACK);
   percentageProgressLabelSprite.setTextColor(TFT_WHITE);
   percentageProgressLabelSprite.setTextSize(percentageProgressSpriteSettings.textSize);
   percentageProgressLabelSprite.setTextFont(1);
   percentageProgressLabelSprite.drawString("0.0%", percentageProgressSpriteSettings.spriteWidth, 0);
   percentageProgressLabelSprite.setTextDatum(TR_DATUM);
   amoled->pushColors(mScreenWidth - percentageProgressSpriteSettings.spriteWidth, 0, percentageProgressSpriteSettings.spriteWidth, percentageProgressSpriteSettings.spriteHeight, (uint16_t *)percentageProgressLabelSprite.getPointer());

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

void PlayState::update()
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
         uint16_t* pixelPtr = spritePtr + (sample.y * mScreenWidth + sample.x);
         amoled->setAddrWindow(sample.x, sample.y, sample.x, sample.y);
         amoled->pushColors(pixelPtr, 1);
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
      amoled->pushColors(0, 0, rayTracingSpriteSettings.spriteWidth, rayTracingSpriteSettings.spriteHeight, (uint16_t *)rayTracingLabelSprite.getPointer());

      sleep(2);

      amoled->pushColors(0, 0, mScreenWidth, mScreenHeight, (uint16_t *)imageRenderingSprite.getPointer());
      doOnce = false;
   }
}

void PlayState::exit()
{

}

void PlayState::updateRayTracingSprite() {
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
        amoled->pushColors(0, 0, rayTracingSpriteSettings.spriteWidth, rayTracingSpriteSettings.spriteHeight, (uint16_t *)rayTracingLabelSprite.getPointer());
        lastTimeRayTracingSpriteWasUpdated = millis();
    }
}

void PlayState::updatePercentageProgressSprite(float progress) {
    percentageProgressLabelSprite.fillSprite(TFT_BLACK);
    std::stringstream stream;
    stream << std::fixed << std::setprecision(1) << (progress * 100.0f);
    std::string numberAsString = stream.str();
    numberAsString += "%";
    percentageProgressLabelSprite.drawString(numberAsString.c_str(), percentageProgressSpriteSettings.spriteWidth, 0);

    amoled->pushColors(mScreenWidth - percentageProgressSpriteSettings.spriteWidth, 0, percentageProgressSpriteSettings.spriteWidth, percentageProgressSpriteSettings.spriteHeight, (uint16_t *)percentageProgressLabelSprite.getPointer());
}

void PlayState::updateProgressBar(float progress) {
    int32_t progressWidth = static_cast<int32_t>(progress * static_cast<float>(progressBarFillableWidth));
    if (progressWidth > prevProgressWidth) {
        progressBarSprite.fillRect(1, 1, progressWidth, progressBarFillableHeight, TFT_GREEN);
        prevProgressWidth = progressWidth;
    }
    amoled->pushColors(progressBarXPosition, progressBarYPosition, progressBarWidth, progressBarHeight, (uint16_t *)progressBarSprite.getPointer());
}
