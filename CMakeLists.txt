# ============================================================================
# SnakeGame-C - Professional Snake Game Implementation
# Author: Your Name
# Version: 1.0.0
# Description: Advanced Snake Game with Modern Graphics and Audio
# ============================================================================

cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Compiler flags for optimal performance and debugging
set(CMAKE_CXX_FLAGS "-Wall -Wextra -O2")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")

# Project configuration
project(SnakeGame-C
    VERSION 1.0.0
    DESCRIPTION "Professional Snake Game with Advanced Graphics and Audio"
    LANGUAGES CXX
)

# Module path for finding custom CMake modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

# Find required libraries
find_package(SDL2 REQUIRED)
find_package(SDL2_mixer REQUIRED)

# Include directories
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_MIXER_INCLUDE_DIR} src)

# Source files
set(SOURCES
    src/main.cpp
    src/game.cpp
    src/controller.cpp
    src/renderer.cpp
    src/snake.cpp
    src/particle.cpp
    src/audio.cpp
)

# Create executable
add_executable(SnakeGame ${SOURCES})

# Link libraries
string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
target_link_libraries(SnakeGame ${SDL2_LIBRARIES} ${SDL2_MIXER_LIBRARIES})

# Set target properties
set_target_properties(SnakeGame PROPERTIES
    OUTPUT_NAME "SnakeGame"
    VERSION ${PROJECT_VERSION}
)
