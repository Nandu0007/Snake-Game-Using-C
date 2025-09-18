/*
 * ============================================================================
 * SnakeGame-C - Advanced Particle Physics System
 * ============================================================================
 * 
 * File: particle.h
 * Author: Your Name
 * Created: 2025
 * Version: 1.0.0
 * 
 * Description:
 * Professional particle system implementation featuring realistic physics
 * simulation, dynamic effects, and optimized rendering. Provides immersive
 * visual feedback with customizable particle behaviors.
 * 
 * Key Features:
 * - Real-time physics simulation with gravity and velocity
 * - Dynamic particle emission and lifecycle management
 * - Alpha blending and transparency effects
 * - Optimized rendering for smooth 60+ FPS performance
 * 
 * Copyright (c) 2025 Your Name. All rights reserved.
 * ============================================================================
 */

#ifndef PARTICLE_H
#define PARTICLE_H

#include "SDL.h"
#include <vector>
#include <random>

struct Particle {
    float x, y;
    float velocity_x, velocity_y;
    float life;
    float max_life;
    Uint8 r, g, b, a;
    float size;
    
    Particle(float x, float y, float vx, float vy, float life, Uint8 r, Uint8 g, Uint8 b, float size)
        : x(x), y(y), velocity_x(vx), velocity_y(vy), life(life), max_life(life), 
          r(r), g(g), b(b), a(255), size(size) {}
    
    void Update(float dt) {
        x += velocity_x * dt;
        y += velocity_y * dt;
        life -= dt;
        
        // Fade out as particle dies
        a = static_cast<Uint8>((life / max_life) * 255);
        
        // Gravity effect
        velocity_y += 50.0f * dt;
    }
    
    bool IsAlive() const {
        return life > 0;
    }
};

class ParticleSystem {
public:
    ParticleSystem();
    ~ParticleSystem() = default;
    
    void EmitFoodParticles(float x, float y, int count = 15);
    void EmitTrailParticles(float x, float y, int count = 3);
    void Update(float dt);
    void Render(SDL_Renderer* renderer, int block_width, int block_height);
    void Clear();
    
private:
    std::vector<Particle> particles;
    std::mt19937 rng;
    std::uniform_real_distribution<float> angle_dist;
    std::uniform_real_distribution<float> speed_dist;
    std::uniform_real_distribution<float> life_dist;
};

#endif