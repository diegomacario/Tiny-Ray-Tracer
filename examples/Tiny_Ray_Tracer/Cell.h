#ifndef CELL_H
#define CELL_H

#include <string>

class Cell
{
public:

   Cell(int32_t xPos, int32_t yPos, std::string text);
   ~Cell() = default;

   int32_t mXPos;
   int32_t mYPos;
   std::string mText;
};

#endif
