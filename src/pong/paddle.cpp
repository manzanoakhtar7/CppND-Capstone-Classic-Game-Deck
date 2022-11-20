#include "paddle.h"
#include <iostream>

Paddle::Paddle(int gridWidth, int gridHeight, int blockWidth, int blockHeight, int length, float maxSpeed, PaddlePosition pos) 
  : PongObject(pos == left ? blockWidth : (gridWidth-2)*blockWidth, (((gridHeight+1)/2) - ((length+1)/2))*blockHeight, blockWidth, length*blockHeight),
  length_(length),
  x_(pos == left ? blockWidth : (gridWidth-2)*blockWidth),
  y_(((gridHeight/2.0) - (length/2.0))*blockHeight),
  maxSpeed_(maxSpeed),
  blockHeight_(blockHeight) {}

void Paddle::HandleInput(PaddleDirection direction, bool pressed) {
  if (pressed) {
    if (direction == velocity_.direction) {
      if (0.0 == velocity_.speed) {
        velocity_.speed = maxSpeed_/2.0;
      } else {
        velocity_.speed *= 2;
        if (velocity_.speed > maxSpeed_) {
          velocity_.speed = maxSpeed_;
        }
      }
    } else {
      velocity_.direction = direction;
      velocity_.speed = maxSpeed_/2.0;
    }
  } else {
    velocity_.speed = 0.0;
  }
}

void Paddle::Update(Wall &topWall, Wall &bottomWall) {
  y_ +=  GetVelocity();
  object_.y = static_cast<int>(y_);
  if (IsCollidingWith(&topWall)) {
    y_ = topWall.GetObject()->y + topWall.GetObject()->h;
    object_.y = static_cast<int>(y_);
  } else if (IsCollidingWith(&bottomWall)) {
    y_ = bottomWall.GetObject()->y - (length_*blockHeight_);
    object_.y = static_cast<int>(y_);
  }
}

float Paddle::GetVelocity() {
  float vel;
    if (velocity_.direction == up) {
      vel = -1.0 * velocity_.speed;
    } else {
      vel = 1.0 * velocity_.speed;
    }
  return vel;
}