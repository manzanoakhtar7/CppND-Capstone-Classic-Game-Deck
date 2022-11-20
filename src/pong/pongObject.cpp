#include "pongObject.h"

PongObject::PongObject(int x, int y, int w, int h) {
  object_ = {x, y, w, h};
}

bool PongObject::IsCollidingWith(PongObject *aOther) {
  return SDL_HasIntersection(&object_, aOther->GetObject());
}

void PongObject::Render(SDL_Renderer *sdl_renderer) const {
    SDL_RenderFillRect(sdl_renderer, &object_);
}