#ifndef PONGOBJECT_H
#define PONGOBJECT_H

#include <vector>
#include <SDL.h>

class PongObject {
  public:
    PongObject(int x, int y, int w, int h);
    SDL_Rect* GetObject() { return &object_; };
    bool IsCollidingWith(PongObject *aOther);
    void Render(SDL_Renderer *sdl_renderer) const;
  private:
    SDL_Rect object_;
};

#endif