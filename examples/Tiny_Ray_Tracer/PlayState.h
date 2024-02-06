#ifndef PLAY_STATE_H
#define PLAY_STATE_H

#include <LilyGo_AMOLED.h>
#include <TFT_eSPI.h>

#include "State.h"
#include "FSM.h"
#include "FileParser.h"
#include "RandomSampleGenerator.h"
#include "RayGenerator.h"
#include "SceneDescription.h"

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

class PlayState : public State
{
public:

   PlayState(const std::shared_ptr<FiniteStateMachine>& finiteStateMachine,
            TFT_eSPI& tft,
            LilyGo_Class* amoled,
            uint16_t screenWidth,
            uint16_t screenHeight);
   ~PlayState() = default;

   PlayState(const PlayState&) = delete;
   PlayState& operator=(const PlayState&) = delete;

   PlayState(PlayState&&) = delete;
   PlayState& operator=(PlayState&&) = delete;

   void enter() override;
   void update() override;
   void exit() override;

private:

   void updateRayTracingSprite();
   void updatePercentageProgressSprite(float progress);
   void updateProgressBar(float progress);

   std::shared_ptr<FiniteStateMachine> mFSM;

   LilyGo_Class* amoled;

   const uint16_t mScreenWidth;
   const uint16_t mScreenHeight;

   TFT_eSprite imageRenderingSprite;
   TFT_eSprite rayTracingLabelSprite;
   TFT_eSprite percentageProgressLabelSprite;
   TFT_eSprite progressBarSprite;

   FileParser fileParser;
   std::unique_ptr<SceneDescription> sceneDesc;
   std::unique_ptr<Scene> scene;
   RandomSampleGenerator sampleGenerator;
   RayGenerator rayGenerator;
   Sample sample;
   Ray ray;
   Intersection intersection;

   TextSpriteSettings rayTracingSpriteSettings;
   uint32_t numDots;
   unsigned long lastTimeRayTracingSpriteWasUpdated;

   TextSpriteSettings percentageProgressSpriteSettings;

   const int32_t progressBarWidth;
   const int32_t progressBarHeight;
   const int32_t progressBarXPosition;
   const int32_t progressBarYPosition;
   const int32_t progressBarFillableWidth;
   const int32_t progressBarFillableHeight;
   int32_t prevProgressWidth;

   bool doOnce;
};

#endif
