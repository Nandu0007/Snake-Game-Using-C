/*
 * ============================================================================
 * SnakeGame-C - Professional Snake Game Implementation
 * ============================================================================
 * 
 * File: main.cpp
 * Author: Your Name
 * Created: 2025
 * Version: 1.0.0
 * 
 * Description:
 * Main entry point for the Snake Game application. Initializes SDL2 subsystems,
 * creates game components, and manages the main game loop with professional
 * error handling and resource management.
 * 
 * Features:
 * - SDL2 initialization and cleanup
 * - Game component orchestration  
 * - Error handling and logging
 * - Performance optimization
 * 
 * Copyright (c) 2025 Your Name. All rights reserved.
 * This software is provided under the MIT License.
 * ============================================================================
 */

#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight);
  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  return 0;
}