#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "ball.h"
#include "paddle.h"
#include "wall.h"

class Renderer;

class Score {
  public:
    int leftScore{0};
    int rightScore{0};
};

class Game {
  public:
    Game(std::size_t gridWidth, std::size_t gridHeight, std::size_t screenWidth, std::size_t screenHeight);
    void Run(Controller const &controller, Renderer &renderer,
            std::size_t targetFrameDuration);
    Score GetScore() const {return score_; };

  private:
    Ball ball_;
    Paddle leftPaddle_;
    Paddle rightPaddle_;
    Wall topWall_;
    Wall bottomWall_;

    int blockWidth_;
    int blockHeight_;

    std::random_device dev_;
    std::mt19937 engine_;
    std::uniform_int_distribution<int> randomServe_;

    Score score_;

    void Update();
};

#endif