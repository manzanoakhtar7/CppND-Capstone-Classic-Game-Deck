#include "ball.h"
#include <iostream>
#include <math.h>

#define PI 3.14159265

Ball::Ball(int gridWidth, int gridHeight, int blockWidth, int blockHeight, float speed)
  : PongObject((((gridWidth+1)/2)*blockWidth) - (blockWidth/2),(((gridHeight+1)/2)*blockHeight) - (blockHeight/2),blockWidth,blockHeight),
  startX_(gridWidth*blockWidth/2.0),
  startY_(gridHeight*blockHeight/2.0),
  blockWidth_(blockWidth),
  blockHeight_(blockHeight),
  engine_(dev_()),
  randomServeDirection_(0, 1),
  randomServeAngle_(-15,15){
    velocity_.speed = speed;
  }

void Ball::Update(Paddle &leftPaddle, Paddle &rightPaddle, Wall &topWall, Wall &bottomWall) {
  x_ += velocity_.speed * cos(velocity_.direction_deg*PI/180);
  y_ -= velocity_.speed * sin(velocity_.direction_deg*PI/180);
  object_.x = static_cast<int>(x_);
  object_.y = static_cast<int>(y_);
  if (IsCollidingWith(&topWall)) {
    std::cout << "Colliding with top wall." << std::endl;
    y_ = topWall.GetObject()->y + topWall.GetObject()->h;
    object_.y = static_cast<int>(y_);
    velocity_.direction_deg = fmod(-1*velocity_.direction_deg, 360);
    if (velocity_.direction_deg < 0) {
        velocity_.direction_deg += 360;
    }
  } else if (IsCollidingWith(&bottomWall)) {
    std::cout << "Colliding with bottom wall." << std::endl;
    y_ = bottomWall.GetObject()->y - (blockHeight_);
    object_.y = static_cast<int>(y_);
    velocity_.direction_deg = fmod(-1*velocity_.direction_deg, 360);
    if (velocity_.direction_deg < 0) {
        velocity_.direction_deg += 360;
    }
  }
  if (IsCollidingWith(&leftPaddle)) {
    std::cout << "Colliding with left paddle." << std::endl;
    x_ = leftPaddle.GetObject()->x + leftPaddle.GetObject()->w;
    object_.x = static_cast<int>(x_);
    float vel = leftPaddle.GetVelocity();
    velocity_.direction_deg = fmod(540-(velocity_.direction_deg+(2*vel)), 360);
    if (velocity_.direction_deg < 0) {
        velocity_.direction_deg += 360;
    }
  } else if (IsCollidingWith(&rightPaddle)) {
    std::cout << "Colliding with right paddle." << std::endl;
    x_ = rightPaddle.GetObject()->x - (blockWidth_);
    object_.x = static_cast<int>(x_);
    float vel = rightPaddle.GetVelocity();
    velocity_.direction_deg = fmod(540-(velocity_.direction_deg+(2*vel)), 360);
    if (velocity_.direction_deg < 0) {
        velocity_.direction_deg += 360;
    }
  }
}

void Ball::Reset() {
  x_ = startX_;
  y_ = startY_;
  PaddlePosition serveDirection = static_cast<PaddlePosition>(randomServeDirection_(engine_));
  int serveAngle = randomServeAngle_(engine_);
  if (serveDirection == right) {
    velocity_.direction_deg = serveAngle;
  } else {
    velocity_.direction_deg = 180 + serveAngle;
  }
  object_.x = static_cast<int>(x_);
  object_.x = static_cast<int>(y_);
}