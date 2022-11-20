#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "snake.h"
#include "game.h"
#include "ball.h"
#include "paddle.h"
#include "wall.h"

class Game;
class Score;

class Renderer {
  public:
    Renderer(const std::size_t screen_width, const std::size_t screen_height,
            const std::size_t grid_width, const std::size_t grid_height);
    ~Renderer();

    void Render(const Paddle &leftPaddle, const Paddle &rightPaddle, const Ball &ball, const Wall &topWall, const Wall &bottomWall);
    void UpdateWindowTitle(Score score, int fps);

  private:
    SDL_Window *sdl_window;
    SDL_Renderer *sdl_renderer;

    const std::size_t screen_width;
    const std::size_t screen_height;
    const std::size_t grid_width;
    const std::size_t grid_height;
};

#endif