#include "paddle.h"

Paddle::Paddle(int gridWidth, int gridHeight, int blockWidth, int blockHeight, int length, float maxSpeed, PaddlePosition pos) 
  : PongObject(pos == left ? blockWidth : (gridWidth-2)*blockWidth, (((gridHeight+1)/2) - ((length+1)/2))*blockHeight, blockWidth, length*blockHeight),
  length_(length),
  x_(pos == left ? blockWidth : (gridWidth-2)*blockWidth),
  y_((gridHeight/2.0) - (length/2.0)*blockHeight),
  maxSpeed_(maxSpeed)
  {}