#ifndef PADDLE_H
#define PADDLE_H

#include "pongObject.h"
#include "wall.h"

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
    void HandleInput(PaddleDirection direction, bool pressed);
    void Update(Wall &topWall, Wall &bottomWall);
    float GetVelocity();
  
  private:
    int length_;
    int x_;
    float y_;
    PaddleVelocity velocity_{0.0, up};
    float maxSpeed_;
    int blockHeight_;
};

#endif