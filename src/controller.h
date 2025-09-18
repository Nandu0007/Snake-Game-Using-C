/*
 * ============================================================================
 * SnakeGame-C - Input Controller System
 * ============================================================================
 * 
 * File: controller.h
 * Author: Your Name
 * Created: 2025
 * Version: 1.0.0
 * 
 * Description:
 * Professional input handling system with responsive controls and
 * anti-spam protection. Features smooth directional input processing
 * with optimized timing mechanisms.
 * 
 * Copyright (c) 2025 Your Name. All rights reserved.
 * ============================================================================
 */

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"

class Controller {
 public:
  Controller() : last_direction_change_time(0) {}
  void HandleInput(bool &running, Snake &snake);

 private:
  void ChangeDirection(Snake &snake, Snake::Direction input,
                       Snake::Direction opposite);
  Uint32 last_direction_change_time;
};

#endif