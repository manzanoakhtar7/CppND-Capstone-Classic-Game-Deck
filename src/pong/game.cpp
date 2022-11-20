#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(std::size_t gridWidth, std::size_t gridHeight, std::size_t screenWidth, std::size_t screenHeight)
  : ball_(gridWidth, gridHeight, screenWidth/gridWidth, screenHeight/gridHeight, 12.0),
  leftPaddle_(gridWidth, gridHeight, screenWidth/gridWidth, screenHeight/gridHeight, gridHeight/4, 16.0, left),
  rightPaddle_(gridWidth, gridHeight, screenWidth/gridWidth, screenHeight/gridHeight, gridHeight/4, 16.0, right),
  topWall_(gridWidth, gridHeight, screenWidth/gridWidth, screenHeight/gridHeight, top),
  bottomWall_(gridWidth, gridHeight, screenWidth/gridWidth, screenHeight/gridHeight, bottom),
  blockWidth_(screenWidth/gridWidth),
  blockHeight_(screenHeight/gridHeight),
  screenWidth_(screenWidth) {}

void Game::Run(Controller const &controller, Renderer &renderer,
                std::size_t targetFrameDuration) {
  Uint32 titleTimestamp = SDL_GetTicks();
  Uint32 frameStart;
  Uint32 frameEnd;
  Uint32 frameDuration;
  int frameCount = 0;
  bool running = true;
  std::cout << "Game Starting!\n";
  ball_.Reset();
  while (running) {
    frameStart = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, leftPaddle_, rightPaddle_);
    Update();
    renderer.Render(leftPaddle_, rightPaddle_, ball_, topWall_, bottomWall_);

    if ((score_.rightScore >= 10) || (score_.leftScore >= 10)) {
      running = false;
    }

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
  leftPaddle_.Update(topWall_, bottomWall_);
  rightPaddle_.Update(topWall_, bottomWall_);
  ball_.Update(leftPaddle_, rightPaddle_, topWall_, bottomWall_);
  int ballX = ball_.GetObject()->x;
  if (ballX < 0) {
    score_.rightScore += 1;
    ball_.Reset();
  } else if (ballX > screenWidth_) {
    score_.leftScore += 1;
    ball_.Reset();
  }
}