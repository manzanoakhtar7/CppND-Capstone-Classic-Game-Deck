#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(std::size_t gridWidth, std::size_t gridHeight, std::size_t screenWidth, std::size_t screenHeight)
  : ball_(gridWidth, gridHeight, screenWidth/gridWidth, screenHeight/gridHeight, 0.5),
  leftPaddle_(gridWidth, gridHeight, screenWidth/gridWidth, screenHeight/gridHeight, gridHeight/4, 2.0, left),
  rightPaddle_(gridWidth, gridHeight, screenWidth/gridWidth, screenHeight/gridHeight, gridHeight/4, 2.0, right),
  topWall_(gridWidth, gridHeight, screenWidth/gridWidth, screenHeight/gridHeight, top),
  bottomWall_(gridWidth, gridHeight, screenWidth/gridWidth, screenHeight/gridHeight, bottom),
  blockWidth_(screenWidth/gridWidth),
  blockHeight_(screenHeight/gridHeight),
  engine_(dev_()),
  randomServe_(0, static_cast<int>(gridWidth - 1)) {}

void Game::Run(Controller const &controller, Renderer &renderer,
                std::size_t targetFrameDuration) {
  Uint32 titleTimestamp = SDL_GetTicks();
  Uint32 frameStart;
  Uint32 frameEnd;
  Uint32 frameDuration;
  int frameCount = 0;
  bool running = true;
  std::cout << "Game Starting!\n";
  while (running) {
    frameStart = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running);
    Update();
    renderer.Render(leftPaddle_, rightPaddle_, ball_, topWall_, bottomWall_);

    frameEnd = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frameCount++;
    frameDuration = frameEnd - frameStart;

    // After every second, update the window title.
    if (frameEnd - titleTimestamp >= 1000) {
      renderer.UpdateWindowTitle(score_, frameCount);
      frameCount = 0;
      titleTimestamp = frameEnd;
    }

    // If the time for this frame is too small (i.e. frameDuration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frameDuration < targetFrameDuration) {
      SDL_Delay(targetFrameDuration - frameDuration);
    }
  }
}

void Game::Update() {
  std::cout << "Update!\n";
}