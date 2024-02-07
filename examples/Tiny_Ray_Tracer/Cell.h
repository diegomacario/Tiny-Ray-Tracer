#ifndef CELL_H
#define CELL_H

#include <stdint.h>

class Cell
{
public:

   Cell(int32_t xPos, int32_t yPos);
   ~Cell() = default;

   int32_t mXPos;
   int32_t mYPos;
};

#endif
