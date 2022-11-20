#include "wall.h"

Wall::Wall(int gridWidth, int gridHeight, int blockWidth, int blockHeight, WallPosition pos)
  : PongObject(0, pos == top ? 0 : (gridHeight-1)*blockHeight, gridWidth*blockWidth, blockHeight) {}