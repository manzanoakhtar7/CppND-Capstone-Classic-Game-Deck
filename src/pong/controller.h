#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "paddle.h"

class Controller {
  public:
    void HandleInput(bool &running, Paddle &leftPaddle, Paddle &rightPaddle) const;
};

#endif