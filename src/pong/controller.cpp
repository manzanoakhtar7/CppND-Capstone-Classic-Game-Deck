#include "controller.h"
#include <iostream>
#include "SDL.h"

void Controller::HandleInput(bool &running, Paddle &leftPaddle, Paddle &rightPaddle) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          rightPaddle.HandleInput(up, true);
          break;
        case SDLK_DOWN:
          rightPaddle.HandleInput(down, true);
          break;
        case SDLK_w:
          leftPaddle.HandleInput(up, true);
          break;
        case SDLK_s:
          leftPaddle.HandleInput(down, true);
          break;
      }
    } else if (e.type == SDL_KEYUP) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          rightPaddle.HandleInput(up, false);
          break;
        case SDLK_DOWN:
          rightPaddle.HandleInput(down, false);
          break;
        case SDLK_w:
          leftPaddle.HandleInput(up, false);
          break;
        case SDLK_s:
          leftPaddle.HandleInput(down, false);
          break;
      }
    }
  }
}