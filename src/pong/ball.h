#ifndef BALL_H
#define BALL_H

#include <random>
#include <SDL.h>
#include "pongObject.h"
#include "paddle.h"
#include "wall.h"

typedef struct BallVelocity {
  float speed, direction_deg;
} BallVelocity;

class Ball: public PongObject {
  public:
    Ball(int gridWidth, int gridHeight, int blockWidth, int blockHeight, float speed);
    void Update(Paddle &leftPaddle, Paddle &rightPaddle, Wall &topWall, Wall &bottomWall);
    void Reset();

  private:
    float x_;
    float y_;
    float startX_;
    float startY_;
    int blockWidth_;
    int blockHeight_;
    BallVelocity velocity_{0.0, 0.0};

    std::random_device dev_;
    std::mt19937 engine_;
    std::uniform_int_distribution<int> randomServeDirection_;
    std::uniform_int_distribution<int> randomServeAngle_;
};

#endif