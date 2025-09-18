/*
 * ============================================================================
 * SnakeGame-C - Professional Audio Engine
 * ============================================================================
 * 
 * File: audio.h
 * Author: Your Name
 * Created: 2025
 * Version: 1.0.0
 * 
 * Description:
 * Advanced audio system with programmatic sound synthesis and professional
 * audio management. Features real-time audio generation, mixing, and
 * dynamic sound effects without external audio file dependencies.
 * 
 * Technical Features:
 * - Real-time sound synthesis and generation
 * - Professional audio mixing and processing
 * - SDL2_mixer integration with optimal performance
 * - Dynamic audio effects with envelope shaping
 * 
 * Copyright (c) 2025 Your Name. All rights reserved.
 * ============================================================================
 */

#ifndef AUDIO_H
#define AUDIO_H

#include "SDL_mixer.h"
#include <string>
#include <map>

class AudioManager {
public:
    AudioManager();
    ~AudioManager();
    
    bool Initialize();
    void Cleanup();
    
    // Load sounds
    bool LoadSound(const std::string& name, const std::string& filename);
    
    // Play sounds
    void PlaySound(const std::string& name);
    void PlayEatSound();
    void PlayGameOverSound();
    
    // Generate simple sound effects programmatically
    void GenerateSounds();
    
private:
    bool initialized;
    std::map<std::string, Mix_Chunk*> sounds;
    
    // Helper methods for sound generation
    Mix_Chunk* GenerateBeepSound(int frequency, int duration_ms, int volume = 128);
    Mix_Chunk* GenerateClickSound(int volume = 64);
};

#endif