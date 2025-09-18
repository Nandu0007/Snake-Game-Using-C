# SnakeGame-C 🐍

**Professional Snake Game Implementation with Advanced Graphics and Audio**

[![Version](https://img.shields.io/badge/version-1.0.0-blue.svg)](https://github.com/yourusername/SnakeGame-C)
[![License](https://img.shields.io/badge/license-MIT-green.svg)](LICENSE)
[![Platform](https://img.shields.io/badge/platform-macOS%20%7C%20Linux%20%7C%20Windows-lightgrey.svg)]()
[![C++17](https://img.shields.io/badge/C++-17-blue.svg)](https://en.cppreference.com/w/cpp/17)

A feature-rich, professionally crafted Snake game implementation showcasing advanced C++ programming techniques, modern graphics rendering, and sophisticated game architecture.

## 🎮 Features

### Core Gameplay
- **Smooth Snake Movement** - Fluid directional controls with anti-spam protection
- **Dynamic Food System** - Randomly generated food with visual feedback
- **Progressive Difficulty** - Increasing speed as the snake grows
- **Collision Detection** - Professional boundary and self-collision handling

### Advanced Graphics
- **Gradient Backgrounds** - Nature-inspired dynamic color transitions
- **Particle System** - Real-time physics simulation with gravity effects
- **Rounded UI Elements** - Smooth, modern interface components
- **Alpha Blending** - Professional transparency and visual effects
- **Custom Bitmap Fonts** - Crisp, readable text rendering system

### Professional Audio
- **Programmatic Sound Generation** - No external audio file dependencies
- **Real-time Audio Synthesis** - Dynamic sound effects with envelope shaping
- **Eating Sound Effects** - Pleasant chime feedback (800Hz)
- **Game Over Audio** - Dramatic descending tone sequence

### Game States & UI
- **Welcome Screen** - Professional start interface with controls guide
- **Pause Functionality** - Seamless pause/resume with spacebar
- **Game Over Screen** - Elegant overlay with retry options
- **Live Score Display** - Transparent score card with real-time updates
- **Professional Menus** - Polished UI with glowing borders and effects

## 🛠️ Technical Architecture

### Modern C++ Features
- **C++17 Standard** - Modern language features and optimizations
- **RAII Principles** - Proper resource management and exception safety
- **Smart Pointers** - Memory-safe resource handling
- **STL Containers** - Efficient data structures and algorithms

### Graphics Pipeline
- **SDL2 Hardware Acceleration** - Optimized rendering for 60+ FPS
- **Custom Rendering Engine** - Professional 2D graphics system
- **Particle Physics** - Real-time simulation with velocity and gravity
- **Color Space Management** - Advanced blending and transparency

### Audio Engine
- **SDL2_mixer Integration** - Professional audio processing
- **Waveform Synthesis** - Mathematical sound generation
- **Audio Mixing** - Multi-channel sound processing
- **Performance Optimization** - Low-latency audio feedback

## 🚀 Installation

### Prerequisites
- **C++17 Compatible Compiler** (GCC 7+, Clang 5+, MSVC 2017+)
- **CMake 3.10+**
- **SDL2 Development Libraries**
- **SDL2_mixer Development Libraries**

### macOS Installation
```bash
# Install dependencies using Homebrew
brew install cmake sdl2 sdl2_mixer

# Clone and build
git clone https://github.com/yourusername/SnakeGame-C.git
cd SnakeGame-C
mkdir build && cd build
cmake ..
make

# Run the game
./SnakeGame
```

### Linux Installation (Ubuntu/Debian)
```bash
# Install dependencies
sudo apt update
sudo apt install cmake libsdl2-dev libsdl2-mixer-dev g++

# Build and run
git clone https://github.com/yourusername/SnakeGame-C.git
cd SnakeGame-C
mkdir build && cd build
cmake ..
make -j4
./SnakeGame
```

### Windows Installation
```powershell
# Using vcpkg (recommended)
vcpkg install sdl2 sdl2-mixer

# Build with Visual Studio
git clone https://github.com/yourusername/SnakeGame-C.git
cd SnakeGame-C
mkdir build && cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=[vcpkg_path]/scripts/buildsystems/vcpkg.cmake
cmake --build . --config Release
```

## 🎯 How to Play

### Controls
| Key | Action |
|-----|--------|
| **Arrow Keys** | Move snake (Up, Down, Left, Right) |
| **Spacebar** | Pause/Resume game |
| **R** | Restart game (when game over) |
| **ESC** | Quit game (from pause or game over) |
| **Any Key** | Start game (from welcome screen) |

### Game Flow
1. **Welcome Screen** - Read controls and press any key to start
2. **Playing** - Use arrow keys to guide snake to food
3. **Pause** - Press spacebar to pause, press again to resume
4. **Game Over** - When snake hits wall or itself, choose to retry or quit

### Scoring
- **+1 Point** per food item consumed
- **Speed Increase** with each food item (progressive difficulty)
- **High Score Tracking** displayed in real-time

## 🏗️ Project Structure

```
SnakeGame-C/
├── src/
│   ├── main.cpp           # Application entry point
│   ├── game.h/.cpp        # Core game logic and state management
│   ├── renderer.h/.cpp    # Advanced graphics rendering system
│   ├── snake.h/.cpp       # Snake entity and physics
│   ├── controller.h/.cpp  # Input handling and controls
│   ├── particle.h/.cpp    # Particle physics system
│   └── audio.h/.cpp       # Professional audio engine
├── cmake/
│   └── FindSDL2_mixer.cmake  # CMake module for SDL2_mixer
├── build/                 # Build directory (generated)
├── CMakeLists.txt        # Build configuration
├── README.md             # This file
└── LICENSE               # MIT License
```

## 🎨 Visual Showcase

### Advanced Graphics Features
- **Nature-Inspired Gradients** - Dynamic background color transitions
- **Particle Effects** - Golden burst effects when eating food
- **Smooth Animations** - 60+ FPS gameplay with fluid motion
- **Professional UI** - Modern design with rounded corners and glows
- **Typography** - Custom bitmap font system for crisp text

### Audio Features
- **Synthesized Sound Effects** - No external file dependencies
- **Real-time Generation** - Mathematical waveform synthesis
- **Professional Quality** - Envelope shaping and smooth audio curves

## 🔧 Development

### Building from Source
```bash
# Debug build
mkdir build-debug && cd build-debug
cmake -DCMAKE_BUILD_TYPE=Debug ..
make

# Release build (optimized)
mkdir build-release && cd build-release  
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```

### Code Style
- **C++17 Modern Standards** - Latest language features
- **Professional Architecture** - Clean separation of concerns
- **Comprehensive Documentation** - Detailed inline comments
- **Performance Optimized** - Efficient algorithms and data structures

## 📊 Performance

- **Target FPS**: 60+ frames per second
- **Memory Usage**: < 50MB typical
- **CPU Usage**: < 5% on modern systems
- **Startup Time**: < 1 second

## 🤝 Contributing

Contributions are welcome! Please follow these guidelines:

1. **Fork** the repository
2. **Create** a feature branch (`git checkout -b feature/amazing-feature`)
3. **Commit** your changes (`git commit -m 'Add amazing feature'`)
4. **Push** to the branch (`git push origin feature/amazing-feature`)
5. **Open** a Pull Request

### Code Standards
- Follow C++17 best practices
- Maintain consistent formatting
- Add comprehensive comments
- Include unit tests for new features

## 📝 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🙏 Acknowledgments

- **SDL2 Community** - For excellent cross-platform multimedia library
- **Modern C++ Community** - For advancing language standards
- **Game Development Community** - For inspiration and best practices

## 📧 Contact

**Nandish P** - nandishreddy00700@gmail.com
Project Link: https://github.com/Nandu0007/Snake-Game-Using-C.git
---

⭐ **Star this repository if you found it helpful!** ⭐
