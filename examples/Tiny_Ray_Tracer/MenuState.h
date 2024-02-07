#ifndef MENU_STATE_H
#define MENU_STATE_H

#include <LilyGo_AMOLED.h>
#include <TFT_eSPI.h>

#include "State.h"
#include "FSM.h"

// TODO: Figure out where to put this
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

class MenuState : public State
{
public:

   MenuState(const std::shared_ptr<FiniteStateMachine>& finiteStateMachine,
             LilyGo_Class* amoled,
             TFT_eSPI& tft,
             uint16_t screenWidth,
             uint16_t screenHeight);
   ~MenuState() = default;

   MenuState(const MenuState&) = delete;
   MenuState& operator=(const MenuState&) = delete;

   MenuState(MenuState&&) = delete;
   MenuState& operator=(MenuState&&) = delete;

   void enter() override;
   void update() override;
   void exit() override;

private:

   void updateRayTracingSprite();
   void updatePercentageProgressSprite(float progress);
   void updateProgressBar(float progress);

   std::shared_ptr<FiniteStateMachine> mFSM;

   LilyGo_Class*                       amoled;

   const uint16_t                      mScreenWidth;
   const uint16_t                      mScreenHeight;

   TFT_eSprite                         mSprite;
};

#endif
