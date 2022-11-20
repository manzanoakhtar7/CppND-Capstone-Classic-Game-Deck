#ifndef PADDLE_H
#define PADDLE_H

#include "pongObject.h"

enum PaddlePosition {
  left,
  right
};

enum PaddleDirection {
  up,
  down,
};

typedef struct PaddleVelocity {
  float speed;
  PaddleDirection direction;
} PaddleVelocity;

class Paddle : public PongObject {
  public:
    Paddle(int gridWidth, int gridHeight, int blockWidth, int blockHeight, int length, float maxSpeed, PaddlePosition pos);
  
  private:
    int length_;
    int x_;
    float y_;
    PaddleVelocity velocity{0.0, up};
    float maxSpeed_;
};

#endif