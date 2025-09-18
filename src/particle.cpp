/*
 * ============================================================================
 * SnakeGame-C - Advanced Particle Physics Implementation
 * ============================================================================
 * 
 * File: particle.cpp
 * Author: Your Name
 * Created: 2025
 * Version: 1.0.0
 * 
 * Description:
 * Implementation of the professional particle physics system with
 * realistic motion simulation and dynamic visual effects.
 * 
 * Copyright (c) 2025 Your Name. All rights reserved.
 * ============================================================================
 */

#include "particle.h"
#include <cmath>
#include <algorithm>

ParticleSystem::ParticleSystem() 
    : rng(std::random_device{}()),
      angle_dist(0.0f, 2.0f * M_PI),
      speed_dist(50.0f, 200.0f),
      life_dist(0.5f, 2.0f) {
}

void ParticleSystem::EmitFoodParticles(float x, float y, int count) {
    for (int i = 0; i < count; ++i) {
        float angle = angle_dist(rng);
        float speed = speed_dist(rng);
        float life = life_dist(rng);
        
        float vx = std::cos(angle) * speed;
        float vy = std::sin(angle) * speed;
        
        // Golden/orange particles for food consumption
        Uint8 r = 255;
        Uint8 g = static_cast<Uint8>(150 + (rng() % 105)); // 150-255
        Uint8 b = 0;
        
        float size = 2.0f + static_cast<float>(rng() % 3);
        
        particles.emplace_back(x, y, vx, vy, life, r, g, b, size);
    }
}

void ParticleSystem::EmitTrailParticles(float x, float y, int count) {
    for (int i = 0; i < count; ++i) {
        float angle = angle_dist(rng);
        float speed = speed_dist(rng) * 0.3f; // Slower particles
        float life = life_dist(rng) * 0.5f;   // Shorter life
        
        float vx = std::cos(angle) * speed;
        float vy = std::sin(angle) * speed;
        
        // Blue/cyan trail particles
        Uint8 r = 0;
        Uint8 g = static_cast<Uint8>(100 + (rng() % 155));
        Uint8 b = 255;
        
        float size = 1.0f + static_cast<float>(rng() % 2);
        
        particles.emplace_back(x, y, vx, vy, life, r, g, b, size);
    }
}

void ParticleSystem::Update(float dt) {
    // Update all particles
    for (auto& particle : particles) {
        particle.Update(dt);
    }
    
    // Remove dead particles
    particles.erase(
        std::remove_if(particles.begin(), particles.end(), 
                      [](const Particle& p) { return !p.IsAlive(); }),
        particles.end()
    );
}

void ParticleSystem::Render(SDL_Renderer* renderer, int block_width, int block_height) {
    for (const auto& particle : particles) {
        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
        SDL_SetRenderDrawColor(renderer, particle.r, particle.g, particle.b, particle.a);
        
        // Convert grid coordinates to screen coordinates
        int screen_x = static_cast<int>(particle.x * block_width + block_width / 2);
        int screen_y = static_cast<int>(particle.y * block_height + block_height / 2);
        
        // Draw particle as a small filled rectangle
        SDL_Rect rect;
        rect.x = screen_x - static_cast<int>(particle.size / 2);
        rect.y = screen_y - static_cast<int>(particle.size / 2);
        rect.w = static_cast<int>(particle.size);
        rect.h = static_cast<int>(particle.size);
        
        SDL_RenderFillRect(renderer, &rect);
    }
    
    // Reset blend mode
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_NONE);
}

void ParticleSystem::Clear() {
    particles.clear();
}