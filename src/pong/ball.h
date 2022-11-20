#ifndef BALL_H
#define BALL_H

#include <SDL.h>
#include "pongObject.h"

typedef struct BallVelocity {
  float speed, direction_deg;
} BallVelocity;

class Ball: public PongObject {
  public:
    Ball(int gridWidth, int gridHeight, int blockWidth, int blockHeight, float speed);

  private:
    float x_;
    float y_;
    BallVelocity velocity_{0.0, 90.0};
};

#endif