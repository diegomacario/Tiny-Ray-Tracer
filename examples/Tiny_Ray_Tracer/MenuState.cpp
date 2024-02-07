#include <iomanip>

#include "MenuState.h"
#include "Data.h"

MenuState::MenuState(const std::shared_ptr<FiniteStateMachine>& finiteStateMachine,
                     LilyGo_Class* amoled,
                     TFT_eSPI& tft,
                     uint16_t screenWidth,
                     uint16_t screenHeight)
   : mFSM(finiteStateMachine)
   , amoled(amoled)
   , mScreenWidth(screenWidth)
   , mScreenHeight(screenHeight)
   , mSprite(&tft)
   , mHorizontalPadding(10.0f)
   , mVerticalPadding(10.0f)
   , mCellWidth((mScreenWidth - (mHorizontalPadding * 3.0f)) * 0.5f)
   , mCellHeight((mScreenHeight - (mVerticalPadding * 4.0f)) * (1.0f / 3.0f))
   , mCellRadius(20)
{

}

void MenuState::enter()
{
   mSprite.createSprite(mScreenWidth, mScreenHeight);
   mSprite.setSwapBytes(1);
   mSprite.fillSprite(TFT_BLACK);

   int32_t xPos = 0;
   int32_t yPos = 0;

   // Starting with the top left cell and moving down

   // First column
   xPos = mHorizontalPadding;
   yPos = mVerticalPadding;
   mSprite.drawRoundRect(xPos, yPos, static_cast<int32_t>(mCellWidth), static_cast<int32_t>(mCellHeight), mCellRadius, TFT_WHITE);

   yPos = mVerticalPadding + mCellHeight + mVerticalPadding;
   mSprite.drawRoundRect(xPos, yPos, static_cast<int32_t>(mCellWidth), static_cast<int32_t>(mCellHeight), mCellRadius, TFT_WHITE);

   yPos = mVerticalPadding + (mCellHeight + mVerticalPadding) * 2.0f;
   mSprite.drawRoundRect(xPos, yPos, static_cast<int32_t>(mCellWidth), static_cast<int32_t>(mCellHeight), mCellRadius, TFT_WHITE);

   // Second column
   xPos = mHorizontalPadding + mCellWidth + mHorizontalPadding;
   yPos = mVerticalPadding;
   mSprite.drawRoundRect(xPos, yPos, static_cast<int32_t>(mCellWidth), static_cast<int32_t>(mCellHeight), mCellRadius, TFT_WHITE);

   yPos = mVerticalPadding + mCellHeight + mVerticalPadding;
   mSprite.drawRoundRect(xPos, yPos, static_cast<int32_t>(mCellWidth), static_cast<int32_t>(mCellHeight), mCellRadius, TFT_WHITE);

   yPos = mVerticalPadding + (mCellHeight + mVerticalPadding) * 2.0f;
   mSprite.drawRoundRect(xPos, yPos, static_cast<int32_t>(mCellWidth), static_cast<int32_t>(mCellHeight), mCellRadius, TFT_WHITE);

   amoled->pushColors(0, 0, mScreenWidth, mScreenHeight, (uint16_t *)mSprite.getPointer());
}

void MenuState::update()
{

}

void MenuState::exit()
{
   mSprite.deleteSprite();
}
