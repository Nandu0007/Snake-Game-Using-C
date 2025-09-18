/*
 * ============================================================================
 * SnakeGame-C - Core Game Logic Module
 * ============================================================================
 * 
 * File: game.h
 * Author: Your Name
 * Created: 2025
 * Version: 1.0.0
 * 
 * Description:
 * Core game logic implementation featuring advanced state management,
 * audio integration, and professional game flow control. Handles all
 * game mechanics including scoring, collision detection, and state transitions.
 * 
 * Key Features:
 * - Multi-state game management (Start, Playing, Paused, GameOver)
 * - Integrated audio system with programmatic sound generation
 * - Advanced collision detection and game physics
 * - Professional error handling and resource management
 * 
 * Copyright (c) 2025 Your Name. All rights reserved.
 * ============================================================================
 */

#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include "audio.h"

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;
  void RestartGame();

 private:
  Snake snake;
  SDL_Point food;
  GameState game_state;
  AudioManager audio_manager;
  
  std::size_t grid_width;
  std::size_t grid_height;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};

  void PlaceFood();
  void Update(Renderer &renderer);
  void HandleGameOver(Renderer &renderer);
};

#endif