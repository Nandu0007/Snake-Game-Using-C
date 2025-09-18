/*
 * ============================================================================
 * SnakeGame-C - Professional Audio Engine Implementation
 * ============================================================================
 * 
 * File: audio.cpp
 * Author: Your Name
 * Created: 2025
 * Version: 1.0.0
 * 
 * Description:
 * Implementation of the advanced audio system with programmatic sound
 * synthesis. Features professional-grade audio processing and real-time
 * sound generation for immersive gaming experience.
 * 
 * Copyright (c) 2025 Your Name. All rights reserved.
 * ============================================================================
 */

#include "audio.h"
#include <iostream>
#include <cmath>
#include <vector>

AudioManager::AudioManager() : initialized(false) {
}

AudioManager::~AudioManager() {
    Cleanup();
}

bool AudioManager::Initialize() {
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
        return false;
    }
    
    initialized = true;
    GenerateSounds(); // Create sound effects programmatically
    return true;
}

void AudioManager::Cleanup() {
    if (!initialized) return;
    
    // Free all loaded sounds
    for (auto& pair : sounds) {
        if (pair.second) {
            Mix_FreeChunk(pair.second);
        }
    }
    sounds.clear();
    
    Mix_CloseAudio();
    initialized = false;
}

bool AudioManager::LoadSound(const std::string& name, const std::string& filename) {
    if (!initialized) return false;
    
    Mix_Chunk* chunk = Mix_LoadWAV(filename.c_str());
    if (!chunk) {
        std::cerr << "Failed to load sound " << filename << "! SDL_mixer Error: " << Mix_GetError() << std::endl;
        return false;
    }
    
    sounds[name] = chunk;
    return true;
}

void AudioManager::PlaySound(const std::string& name) {
    if (!initialized) return;
    
    auto it = sounds.find(name);
    if (it != sounds.end() && it->second) {
        Mix_PlayChannel(-1, it->second, 0);
    }
}

void AudioManager::PlayEatSound() {
    PlaySound("eat");
}

void AudioManager::PlayGameOverSound() {
    PlaySound("gameover");
}

void AudioManager::GenerateSounds() {
    // Generate eating sound - pleasant chime
    Mix_Chunk* eatSound = GenerateBeepSound(800, 200, 100);
    if (eatSound) {
        sounds["eat"] = eatSound;
    }
    
    // Generate game over sound - descending tone
    std::vector<Sint16> gameOverSamples;
    int sampleRate = 44100;
    int duration = 800; // 0.8 seconds
    int totalSamples = (sampleRate * duration) / 1000;
    
    for (int i = 0; i < totalSamples; ++i) {
        float t = static_cast<float>(i) / sampleRate;
        float frequency = 400.0f - (200.0f * t); // Descending from 400Hz to 200Hz
        float amplitude = 8000.0f * (1.0f - t); // Fading out
        
        Sint16 sample = static_cast<Sint16>(amplitude * sin(2.0f * M_PI * frequency * t));
        gameOverSamples.push_back(sample);
        gameOverSamples.push_back(sample); // Stereo (duplicate for both channels)
    }
    
    // Create SDL chunk from samples
    Mix_Chunk* gameOverChunk = static_cast<Mix_Chunk*>(malloc(sizeof(Mix_Chunk)));
    gameOverChunk->allocated = 1;
    gameOverChunk->alen = gameOverSamples.size() * sizeof(Sint16);
    gameOverChunk->abuf = static_cast<Uint8*>(malloc(gameOverChunk->alen));
    gameOverChunk->volume = MIX_MAX_VOLUME;
    
    memcpy(gameOverChunk->abuf, gameOverSamples.data(), gameOverChunk->alen);
    sounds["gameover"] = gameOverChunk;
}

Mix_Chunk* AudioManager::GenerateBeepSound(int frequency, int duration_ms, int volume) {
    int sampleRate = 44100;
    int totalSamples = (sampleRate * duration_ms) / 1000;
    
    std::vector<Sint16> samples;
    samples.reserve(totalSamples * 2); // Stereo
    
    for (int i = 0; i < totalSamples; ++i) {
        float t = static_cast<float>(i) / sampleRate;
        float amplitude = volume * 60.0f; // Scale volume
        
        // Add envelope for smooth start/end
        float envelope = 1.0f;
        if (i < totalSamples * 0.1) {
            envelope = static_cast<float>(i) / (totalSamples * 0.1f); // Fade in
        } else if (i > totalSamples * 0.9) {
            envelope = 1.0f - static_cast<float>(i - totalSamples * 0.9f) / (totalSamples * 0.1f); // Fade out
        }
        
        Sint16 sample = static_cast<Sint16>(amplitude * envelope * sin(2.0f * M_PI * frequency * t));
        samples.push_back(sample);
        samples.push_back(sample); // Stereo
    }
    
    // Create SDL chunk
    Mix_Chunk* chunk = static_cast<Mix_Chunk*>(malloc(sizeof(Mix_Chunk)));
    chunk->allocated = 1;
    chunk->alen = samples.size() * sizeof(Sint16);
    chunk->abuf = static_cast<Uint8*>(malloc(chunk->alen));
    chunk->volume = MIX_MAX_VOLUME;
    
    memcpy(chunk->abuf, samples.data(), chunk->alen);
    return chunk;
}

Mix_Chunk* AudioManager::GenerateClickSound(int volume) {
    return GenerateBeepSound(1200, 50, volume);
}