#ifndef MENU_STATE_H
#define MENU_STATE_H

#include <LilyGo_AMOLED.h>
#include <TFT_eSPI.h>

#include "State.h"
#include "FSM.h"

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

   float                               mHorizontalPadding;
   float                               mVerticalPadding;

   float                               mCellWidth;
   float                               mCellHeight;
   int32_t                             mCellRadius;
};

#endif
