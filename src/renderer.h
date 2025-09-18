/*
 * ============================================================================
 * SnakeGame-C - Advanced Graphics Rendering Engine
 * ============================================================================
 * 
 * File: renderer.h
 * Author: Your Name
 * Created: 2025
 * Version: 1.0.0
 * 
 * Description:
 * State-of-the-art graphics rendering system with modern visual effects.
 * Features advanced 2D graphics including gradient backgrounds, particle
 * systems, smooth animations, and professional UI components.
 * 
 * Advanced Features:
 * - Gradient background rendering with nature-inspired themes
 * - Real-time particle system with physics simulation
 * - Rounded rectangle rendering with smooth edges
 * - Custom bitmap font system for crisp text rendering
 * - Multi-state UI rendering (Start, Game, Pause, GameOver)
 * - Alpha blending and transparency effects
 * 
 * Copyright (c) 2025 Your Name. All rights reserved.
 * ============================================================================
 */

#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <cmath>
#include <string>
#include "SDL.h"
#include "snake.h"
#include "particle.h"

enum class GameState {
  StartScreen,
  Playing,
  Paused,
  GameOver
};

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void Render(Snake const snake, SDL_Point const &food, int score, GameState game_state);
  void UpdateWindowTitle(int score, int fps);
  void EmitFoodParticles(float x, float y);
  void UpdateParticles(float dt);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
  
  // Enhanced graphics features
  ParticleSystem particle_system;
  float animation_time;
  
  // Helper methods for advanced graphics
  void RenderGradientBackground();
  void RenderRoundedRect(SDL_Rect rect, int radius, Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255);
  void RenderGlowingFood(SDL_Point const &food);
  void RenderEnhancedSnake(Snake const snake);
  void DrawCircle(int center_x, int center_y, int radius, Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255);
  void SetPixel(int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255);
  
  // UI rendering methods
  void RenderScoreCard(int score);
  void RenderStartScreen();
  void RenderPauseOverlay();
  void RenderGameOverScreen(int score);
  void RenderText(const std::string& text, int x, int y, int size, Uint8 r, Uint8 g, Uint8 b);
  void RenderBitmapText(const std::string& text, int x, int y, int scale = 2);
};

#endif