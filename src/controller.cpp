/*
 * ============================================================================
 * SnakeGame-C - Input Controller Implementation
 * ============================================================================
 * 
 * File: controller.cpp
 * Author: Your Name
 * Created: 2025
 * Version: 1.0.0
 * 
 * Description:
 * Implementation of the professional input handling system with
 * anti-spam protection and smooth control response.
 * 
 * Copyright (c) 2025 Your Name. All rights reserved.
 * ============================================================================
 */

#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"

void Controller::ChangeDirection(Snake &snake, Snake::Direction input,
                                 Snake::Direction opposite) {
  Uint32 current_time = SDL_GetTicks();
  if ((current_time - last_direction_change_time) > 100) { // Prevent too rapid direction changes
    if (snake.direction != opposite || snake.size == 1) {
      snake.direction = input;
      last_direction_change_time = current_time;
    }
  }
}

void Controller::HandleInput(bool &running, Snake &snake) {
  const Uint8* state = SDL_GetKeyboardState(NULL);
  
  if (state[SDL_SCANCODE_UP]) {
    ChangeDirection(snake, Snake::Direction::kUp,
                    Snake::Direction::kDown);
  }
  else if (state[SDL_SCANCODE_DOWN]) {
    ChangeDirection(snake, Snake::Direction::kDown,
                    Snake::Direction::kUp);
  }
  else if (state[SDL_SCANCODE_LEFT]) {
    ChangeDirection(snake, Snake::Direction::kLeft,
                    Snake::Direction::kRight);
  }
  else if (state[SDL_SCANCODE_RIGHT]) {
    ChangeDirection(snake, Snake::Direction::kRight,
                    Snake::Direction::kLeft);
  }
}
