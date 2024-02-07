#include <algorithm>

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
   , mNumRows(4)
   , mNumColumns(2)
   , mHorizontalPadding(10)
   , mVerticalPadding(10)
   , mCellWidth((mScreenWidth - (mHorizontalPadding * (mNumColumns + 1))) * (1.0f / mNumColumns))
   , mCellHeight((mScreenHeight - (mVerticalPadding * (mNumRows + 1))) * (1.0f / mNumRows))
   , mCellRadius(25)
{
   std::vector<std::string> cellLabels = {"Sword", "Rupee", "Castle", "Planet", "Ice Cream", "Pyramid", "Spheres", "Cake"};

   std::vector<std::string>::iterator longestLabel = std::max_element(cellLabels.begin(), cellLabels.end(), [](const std::string& a, const std::string& b) {
    return a.size() < b.size();
   });

   int32_t longestLabelLength = (*longestLabel).length();

   int32_t fontWidth = 6;
   int32_t fontHeight = 8;
   mFontSize = 1;
   int32_t longestLabelWidth = fontWidth * mFontSize * longestLabelLength;
   int32_t longestLabelHeight = fontHeight * mFontSize;

   while (longestLabelWidth < mCellWidth && longestLabelHeight < mCellHeight && mFontSize <= 7) {
      mFontSize++;
      longestLabelWidth = fontWidth * mFontSize * longestLabelLength;
      longestLabelHeight = fontHeight * mFontSize;

      // If the new dimensions exceed the cell size, revert mFontSize and calculate the dimensions again
      if (longestLabelWidth > mCellWidth || longestLabelHeight > mCellHeight) {
         mFontSize--;
         longestLabelWidth = fontWidth * mFontSize * longestLabelLength;
         longestLabelHeight = fontHeight * mFontSize;
         break;
      }
   }

   int32_t cellIndex = 0;
   for (int32_t columnIndex = 0; columnIndex < mNumColumns; ++columnIndex) {
      for (int32_t rowIndex = 0; rowIndex < mNumRows; ++rowIndex) {
         int32_t xPos = mHorizontalPadding + ((mCellWidth + mHorizontalPadding) * columnIndex);
         int32_t yPos = mVerticalPadding + ((mCellHeight + mVerticalPadding) * rowIndex);
         mCells.push_back(Cell(xPos, yPos, cellLabels[cellIndex]));
         cellIndex += 1;
      }
   }
}

void MenuState::enter()
{
   mSprite.createSprite(mScreenWidth, mScreenHeight);
   mSprite.setSwapBytes(1);
   mSprite.fillSprite(TFT_BLACK);
   mSprite.setTextColor(TFT_WHITE);
   mSprite.setTextSize(mFontSize);
   mSprite.setTextFont(1);

   for (const Cell& cell: mCells) {
      //mSprite.drawRoundRect(cell.mXPos, cell.mYPos, static_cast<int32_t>(mCellWidth), static_cast<int32_t>(mCellHeight), mCellRadius, TFT_WHITE);
      mSprite.drawRect(cell.mXPos, cell.mYPos, static_cast<int32_t>(mCellWidth), static_cast<int32_t>(mCellHeight), TFT_WHITE);
      mSprite.drawString(cell.mText.c_str(), cell.mXPos, cell.mYPos);
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
