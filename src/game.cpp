/*
 * ============================================================================
 * SnakeGame-C - Core Game Logic Implementation
 * ============================================================================
 * 
 * File: game.cpp
 * Author: Your Name
 * Created: 2025
 * Version: 1.0.0
 * 
 * Description:
 * Implementation of the core game logic with professional architecture.
 * Features state-of-the-art game mechanics, audio feedback, and smooth
 * state transitions for an engaging user experience.
 * 
 * Copyright (c) 2025 Your Name. All rights reserved.
 * ============================================================================
 */

#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      game_state(GameState::StartScreen),
      grid_width(grid_width),
      grid_height(grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)) {
  audio_manager.Initialize();
  PlaceFood();
}

void Game::Run(Controller &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    // Handle input based on game state using events
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        running = false;
      } else if (event.type == SDL_KEYDOWN) {
        switch (game_state) {
          case GameState::StartScreen:
            // Any key starts the game
            game_state = GameState::Playing;
            break;
          case GameState::Playing:
            if (event.key.keysym.sym == SDLK_SPACE) {
              game_state = GameState::Paused;
            }
            break;
          case GameState::Paused:
            if (event.key.keysym.sym == SDLK_SPACE) {
              game_state = GameState::Playing;
            } else if (event.key.keysym.sym == SDLK_ESCAPE) {
              running = false;
            }
            break;
          case GameState::GameOver:
            if (event.key.keysym.sym == SDLK_r) {
              RestartGame();
            } else if (event.key.keysym.sym == SDLK_ESCAPE) {
              running = false;
            }
            break;
        }
      }
    }
    
    // Handle game-specific input only when playing
    if (game_state == GameState::Playing) {
      controller.HandleInput(running, snake);
      Update(renderer);
    }
    
    renderer.Render(snake, food, score, game_state);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y)) {
      food.x = x;
      food.y = y;
      return;
    }
  }
}

void Game::Update(Renderer &renderer) {
  if (!snake.alive) {
    HandleGameOver(renderer);
    return;
  }

  snake.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  // Check if there's food over here
  if (food.x == new_x && food.y == new_y) {
    score++;
    // Play eating sound and emit particles
    audio_manager.PlayEatSound();
    renderer.EmitFoodParticles(static_cast<float>(food.x), static_cast<float>(food.y));
    PlaceFood();
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += 0.02;
  }
}

void Game::HandleGameOver(Renderer &renderer) {
  if (game_state == GameState::Playing) {
    // First time entering game over state
    game_state = GameState::GameOver;
    audio_manager.PlayGameOverSound();
  }
}

void Game::RestartGame() {
  // Reset game state
  game_state = GameState::Playing;
  score = 0;
  
  // Reset snake
  snake = Snake(grid_width, grid_height);
  
  // Place new food
  PlaceFood();
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }