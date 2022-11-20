#include "controller.h"
#include <iostream>
#include "SDL.h"

// void Controller::ChangeDirection(Snake &snake, Snake::Direction input,
//                                  Snake::Direction opposite) const {
//   if (snake.direction != opposite || snake.size == 1) snake.direction = input;
//   return;
// }

void Controller::HandleInput(bool &running) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          std::cout << "Up!\n";
          break;

        case SDLK_DOWN:
          std::cout << "Down!\n";
          break;

        case SDLK_LEFT:
          std::cout << "Left!\n";
          break;

        case SDLK_RIGHT:
          std::cout << "Right!\n";
          break;
      }
    }
  }
}