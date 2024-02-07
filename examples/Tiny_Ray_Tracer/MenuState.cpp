#include <iomanip>

#include "MenuState.h"

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
   , mNumRows(3)
   , mNumColumns(2)
   , mHorizontalPadding(10)
   , mVerticalPadding(10)
   , mCellWidth((mScreenWidth - (mHorizontalPadding * (mNumColumns + 1))) * (1.0f / mNumColumns))
   , mCellHeight((mScreenHeight - (mVerticalPadding * (mNumRows + 1))) * (1.0f / mNumRows))
   , mCellRadius(25)
{
   for (int32_t columnIndex = 0; columnIndex < mNumColumns; ++columnIndex) {
      for (int32_t rowIndex = 0; rowIndex < mNumRows; ++rowIndex) {
         int32_t xPos = mHorizontalPadding + ((mCellWidth + mHorizontalPadding) * columnIndex);
         int32_t yPos = mVerticalPadding + ((mCellHeight + mVerticalPadding) * rowIndex);
         mCells.push_back(Cell(xPos, yPos));
      }
   }
}

void MenuState::enter()
{
   mSprite.createSprite(mScreenWidth, mScreenHeight);
   mSprite.setSwapBytes(1);
   mSprite.fillSprite(TFT_BLACK);

   for (const Cell& cell: mCells) {
      mSprite.drawRoundRect(cell.mXPos, cell.mYPos, static_cast<int32_t>(mCellWidth), static_cast<int32_t>(mCellHeight), mCellRadius, TFT_WHITE);
   }

   amoled->pushColors(0, 0, mScreenWidth, mScreenHeight, (uint16_t *)mSprite.getPointer());
}

void MenuState::update()
{

}

void MenuState::exit()
{
   mSprite.deleteSprite();
}
