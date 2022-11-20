#ifndef WALL_H
#define WALL_H

#include "pongObject.h"

enum WallPosition {
  top,
  bottom
};

class Wall : public PongObject {
  public:
    Wall(int gridWidth, int gridHeight, int blockWidth, int blockHeight, WallPosition pos);
};

#endif