#include <algorithm>
#include <iostream>

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
   , mCellHorizontalMargin(10)
   , mCellVerticalMargin(10)
   , mCellHorizontalPadding(10)
   , mCellVerticalPadding(2)
   , mCellWidth((mScreenWidth - (mCellHorizontalMargin * (mNumColumns + 1))) * (1.0f / mNumColumns))
   , mCellHeight((mScreenHeight - (mCellVerticalMargin * (mNumRows + 1))) * (1.0f / mNumRows))
   , mCellRadius(20)
   , mButtonPin(1)
   , mButtonState(LOW)
   , mLastButtonState(LOW)
   , mLastDebounceTime(0)
   , mDebounceDelay(50)
{
   std::vector<std::string> cellLabels = {"Sword", "Rupee", "Castle", "Planet", "Ice Cream", "Pyramid", "Spheres", "Cake"};

   std::vector<std::string>::iterator longestLabel = std::max_element(cellLabels.begin(), cellLabels.end(), [](const std::string& a, const std::string& b) {
    return a.size() < b.size();
   });

   int32_t longestLabelLength = (*longestLabel).length();

   int32_t fontWidth = 6;
   // The font has a height of 8 pixels, but the last pixel corresponds to an empty line to separate letters vertically
   // We ignore that last empty line to center the text correctly
   int32_t fontHeight = 8 - 1;
   mFontSize = 1;
   int32_t longestLabelWidth = fontWidth * mFontSize * longestLabelLength;
   int32_t longestLabelHeight = fontHeight * mFontSize;

   int32_t maxTextWidth = mCellWidth - (mCellHorizontalPadding * 2);
   int32_t maxTextHeight = mCellHeight - (mCellVerticalPadding * 2);

   while (longestLabelWidth < maxTextWidth && longestLabelHeight < maxTextHeight && mFontSize < 7) {
      mFontSize++;
      longestLabelWidth = fontWidth * mFontSize * longestLabelLength;
      longestLabelHeight = fontHeight * mFontSize;

      // If the new dimensions exceed the cell size, revert mFontSize and calculate the dimensions again
      if (longestLabelWidth > maxTextWidth || longestLabelHeight > maxTextHeight) {
         mFontSize--;
         longestLabelWidth = fontWidth * mFontSize * longestLabelLength;
         longestLabelHeight = fontHeight * mFontSize;
         break;
      }
   }

   int32_t cellIndex = 0;
   for (int32_t columnIndex = 0; columnIndex < mNumColumns; ++columnIndex) {
      for (int32_t rowIndex = 0; rowIndex < mNumRows; ++rowIndex) {
         int32_t xPos = mCellHorizontalMargin + ((mCellWidth + mCellHorizontalMargin) * columnIndex);
         int32_t yPos = mCellVerticalMargin + ((mCellHeight + mCellVerticalMargin) * rowIndex);

         int32_t textXPos = xPos + mCellHorizontalPadding;
         int32_t textYPos = yPos + mCellVerticalPadding;
         int32_t gap = (maxTextHeight - longestLabelHeight) * 0.5f;
         textYPos += gap;

         mCells.push_back(Cell(xPos, yPos, cellLabels[cellIndex], textXPos, textYPos));
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
      mSprite.drawString(cell.mText.c_str(), cell.mTextXPos, cell.mTextYPos);
   }

   amoled->pushColors(0, 0, mScreenWidth, mScreenHeight, (uint16_t *)mSprite.getPointer());

   pinMode(mButtonPin, INPUT_PULLDOWN);
}

void MenuState::update()
{
  // read the state of the switch into a local variable:
  int reading = digitalRead(mButtonPin);

   if (reading != mLastButtonState) {
      // reset the debouncing timer
      mLastDebounceTime = millis();
   }

   if ((millis() - mLastDebounceTime) > mDebounceDelay) {
      // whatever the reading is at, it's been there for longer than the debounce
      // delay, so take it as the actual current state:

      // if the button state has changed:
      if (reading != mButtonState) {
         mButtonState = reading;

         if (mButtonState == HIGH) {
            // Do magical things here
            std::cout << "Pressed!" << '\n' ;
         }
      }
   }

   // save the reading. Next time through the loop, it'll be the lastButtonState:
   mLastButtonState = reading;
}

void MenuState::exit()
{
   mSprite.deleteSprite();
}
