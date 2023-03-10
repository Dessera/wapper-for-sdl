#include "Draggable.hpp"

#include <SDL2/SDL_log.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_stdinc.h>

bool Draggable::on_mouse_down(const SDL_Event &event) {
  SDL_Point point = {event.button.x, event.button.y};
  if (event.button.button == SDL_BUTTON_LEFT &&
      (SDL_PointInRect(&point, &this->get_rect()) != 0U)) {
    mouse_offset.x = event.button.x - this->get_rect().x;
    mouse_offset.y = event.button.y - this->get_rect().y;
    is_dragging = true;
    return false;
  }
  return true;
}

bool Draggable::on_mouse_up(const SDL_Event &event) {
  if (event.button.button == SDL_BUTTON_LEFT) {
    is_dragging = false;
  }
  return true;
}

bool Draggable::on_mouse_motion(const SDL_Event &event) {
  if (is_dragging) {
    this->get_rect().x = event.motion.x - mouse_offset.x;
    this->get_rect().y = event.motion.y - mouse_offset.y;
    return false;
  }
  return true;
}
