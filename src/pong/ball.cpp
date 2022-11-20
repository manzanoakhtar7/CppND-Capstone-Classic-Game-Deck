#include "ball.h"

Ball::Ball(int gridWidth, int gridHeight, int blockWidth, int blockHeight, float speed)
  : PongObject(((gridWidth+1)/2)*blockWidth,(gridHeight+1)/2*blockHeight,1,1),
  x_(gridWidth*blockWidth/2.0),
  y_(gridHeight*blockHeight/2.0) {
    velocity_.speed = speed;
  }