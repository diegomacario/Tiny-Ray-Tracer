#include <iomanip>

#include "PlayState.h"
#include "Data.h"

// TODO: Figure out where to put this
uint32_t rgb888ToRgb565(uint8_t r, uint8_t g, uint8_t b) {
    return ((r >> 3) << 11) | ((g >> 2) << 5) | (b >> 3);
}

PlayState::PlayState(const std::shared_ptr<FiniteStateMachine>& finiteStateMachine,
                     LilyGo_Class* amoled,
                     TFT_eSPI& tft,
                     uint16_t screenWidth,
                     uint16_t screenHeight)
   : mFSM(finiteStateMachine)
   , amoled(amoled)
   , mScreenWidth(screenWidth)
   , mScreenHeight(screenHeight)
   , mImageRenderingSprite(&tft)
   , mRayTracingLabelSprite(&tft)
   , mPercentageProgressLabelSprite(&tft)
   , mProgressBarSprite(&tft)
   , mFileParser(planetSceneDescription)
   , mSceneDesc(nullptr)
   , mScene(nullptr)
   , mRayTracingSpriteSettings(3, 8, 6, "Ray-tracing...")
   , mNumDots(0)
   , mLastTimeRayTracingSpriteWasUpdated(0)
   , mPercentageProgressSpriteSettings(3, 8, 6, "100.0%")
   , mProgressBarWidth(536)
   , mProgressBarHeight(10)
   , mProgressBarXPosition(0)
   , mProgressBarYPosition(240 - mProgressBarHeight)
   , mProgressBarFillableWidth(mProgressBarWidth)
   , mProgressBarFillableHeight(mProgressBarHeight)
   , mPrevProgressWidth(0)
   , mDoOnce(true)
{

}

void PlayState::enter()
{
   mImageRenderingSprite.createSprite(mScreenWidth, mScreenHeight);
   mImageRenderingSprite.setSwapBytes(1);
   mImageRenderingSprite.fillSprite(TFT_BLACK);

   mRayTracingLabelSprite.createSprite(mRayTracingSpriteSettings.spriteWidth, mRayTracingSpriteSettings.spriteHeight);
   mRayTracingLabelSprite.setSwapBytes(1);
   mRayTracingLabelSprite.fillSprite(TFT_BLACK);
   mRayTracingLabelSprite.setTextColor(TFT_WHITE);
   mRayTracingLabelSprite.setTextSize(mRayTracingSpriteSettings.textSize);
   mRayTracingLabelSprite.setTextFont(1);
   mRayTracingLabelSprite.drawString("Ray-tracing", 0, 0);
   mRayTracingLabelSprite.setTextDatum(TL_DATUM);
   amoled->pushColors(0, 0, mRayTracingSpriteSettings.spriteWidth, mRayTracingSpriteSettings.spriteHeight, (uint16_t *)mRayTracingLabelSprite.getPointer());

   mPercentageProgressLabelSprite.createSprite(mPercentageProgressSpriteSettings.spriteWidth, mPercentageProgressSpriteSettings.spriteHeight);
   mPercentageProgressLabelSprite.setSwapBytes(1);
   mPercentageProgressLabelSprite.fillSprite(TFT_BLACK);
   mPercentageProgressLabelSprite.setTextColor(TFT_WHITE);
   mPercentageProgressLabelSprite.setTextSize(mPercentageProgressSpriteSettings.textSize);
   mPercentageProgressLabelSprite.setTextFont(1);
   mPercentageProgressLabelSprite.drawString("0.0%", mPercentageProgressSpriteSettings.spriteWidth, 0);
   mPercentageProgressLabelSprite.setTextDatum(TR_DATUM);
   amoled->pushColors(mScreenWidth - mPercentageProgressSpriteSettings.spriteWidth, 0, mPercentageProgressSpriteSettings.spriteWidth, mPercentageProgressSpriteSettings.spriteHeight, (uint16_t *)mPercentageProgressLabelSprite.getPointer());

   mProgressBarSprite.createSprite(mProgressBarWidth, mProgressBarHeight);
   mProgressBarSprite.setSwapBytes(1);
   mProgressBarSprite.fillSprite(TFT_BLACK);

   mFileParser.readFile(mSceneDesc, mScene);

   mSampleGenerator = RandomSampleGenerator(mSceneDesc->getWidth(), mSceneDesc->getHeight());

   mRayGenerator = RayGenerator(mSceneDesc->getWidth(),
                                mSceneDesc->getHeight(),
                                mSceneDesc->getEye(),
                                mSceneDesc->getCenter(),
                                mSceneDesc->getUpVec(),
                                mSceneDesc->getFovy());

   mRay.origin = mSceneDesc->getEye();
   mRay.direction = Vector(0, 0, 0);

   mLastTimeRayTracingSpriteWasUpdated = millis();
}

void PlayState::update()
{
   if (mSampleGenerator.sampleIsAvailable())
   {
      mSampleGenerator.generateSample(mSample);
      mRayGenerator.generateRay(mSample, mRay);

      // If the current ray intersects an object, we calculate the lighting at the intersection point and store the colour
      // If not, the current pixel remains black
      if (mScene->findNearestIntersection(mRay, &mIntersection))
      {
         Colour pixelColour = mScene->calculateLightingAtIntersection(mSceneDesc->getEye(), &mIntersection);

         uint8_t r = static_cast<uint8_t>(std::min(255 * pixelColour.r, 255.0f));
         uint8_t g = static_cast<uint8_t>(std::min(255 * pixelColour.g, 255.0f));
         uint8_t b = static_cast<uint8_t>(std::min(255 * pixelColour.b, 255.0f));
         uint32_t colour = rgb888ToRgb565(r, g, b);

         mImageRenderingSprite.drawPixel(mSample.x, mSample.y, colour);
         uint16_t* spritePtr = (uint16_t*)mImageRenderingSprite.getPointer();
         uint16_t* pixelPtr = spritePtr + (mSample.y * mScreenWidth + mSample.x);
         amoled->setAddrWindow(mSample.x, mSample.y, mSample.x, mSample.y);
         amoled->pushColors(pixelPtr, 1);
      }

      float progress = mSampleGenerator.getProgress();

      updateRayTracingSprite();
      updatePercentageProgressSprite(progress);
      updateProgressBar(progress);
   }
   else if (mDoOnce) {
      mRayTracingLabelSprite.fillSprite(TFT_BLACK);
      std::string doneString = "Done!";
      mRayTracingLabelSprite.drawString(doneString.c_str(), 0, 0);
      amoled->pushColors(0, 0, mRayTracingSpriteSettings.spriteWidth, mRayTracingSpriteSettings.spriteHeight, (uint16_t *)mRayTracingLabelSprite.getPointer());

      sleep(2);

      amoled->pushColors(0, 0, mScreenWidth, mScreenHeight, (uint16_t *)mImageRenderingSprite.getPointer());
      mDoOnce = false;
   }
}

void PlayState::exit()
{
   mImageRenderingSprite.deleteSprite();
   mRayTracingLabelSprite.deleteSprite();
   mPercentageProgressLabelSprite.deleteSprite();
   mProgressBarSprite.deleteSprite();
}

void PlayState::updateRayTracingSprite() {
    if (millis() > mLastTimeRayTracingSpriteWasUpdated + 1000) {
        mNumDots += 1;
        mNumDots %= 4;
        mRayTracingLabelSprite.fillSprite(TFT_BLACK);
        std::string rayTracingString = "Ray-tracing";
        switch(mNumDots) {
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
        mRayTracingLabelSprite.drawString(rayTracingString.c_str(), 0, 0);
        amoled->pushColors(0, 0, mRayTracingSpriteSettings.spriteWidth, mRayTracingSpriteSettings.spriteHeight, (uint16_t *)mRayTracingLabelSprite.getPointer());
        mLastTimeRayTracingSpriteWasUpdated = millis();
    }
}

void PlayState::updatePercentageProgressSprite(float progress) {
    mPercentageProgressLabelSprite.fillSprite(TFT_BLACK);
    std::stringstream stream;
    stream << std::fixed << std::setprecision(1) << (progress * 100.0f);
    std::string numberAsString = stream.str();
    numberAsString += "%";
    mPercentageProgressLabelSprite.drawString(numberAsString.c_str(), mPercentageProgressSpriteSettings.spriteWidth, 0);

    amoled->pushColors(mScreenWidth - mPercentageProgressSpriteSettings.spriteWidth, 0, mPercentageProgressSpriteSettings.spriteWidth, mPercentageProgressSpriteSettings.spriteHeight, (uint16_t *)mPercentageProgressLabelSprite.getPointer());
}

void PlayState::updateProgressBar(float progress) {
    int32_t progressWidth = static_cast<int32_t>(progress * static_cast<float>(mProgressBarFillableWidth));
    if (progressWidth > mPrevProgressWidth) {
        mProgressBarSprite.fillRect(1, 1, progressWidth, mProgressBarFillableHeight, TFT_GREEN);
        mPrevProgressWidth = progressWidth;
    }
    amoled->pushColors(mProgressBarXPosition, mProgressBarYPosition, mProgressBarWidth, mProgressBarHeight, (uint16_t *)mProgressBarSprite.getPointer());
}
