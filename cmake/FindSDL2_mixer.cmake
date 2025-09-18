# Locate SDL2_mixer library
# This module defines
# SDL2_MIXER_LIBRARY, the name of the library to link against
# SDL2_MIXER_FOUND, if false, do not try to link to SDL2_mixer
# SDL2_MIXER_INCLUDE_DIR, where to find SDL_mixer.h
#
# Additional Note: If you see an empty SDL2_MIXER_LIBRARY_TEMP in your configuration
# and no SDL2_MIXER_LIBRARY, it means CMake did not find your SDL2_mixer library
# (SDL2_mixer.dll, libsdl2_mixer.so, SDL2_mixer.framework, etc).

# On macOS, we will use Homebrew installation paths
if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    execute_process(COMMAND brew --prefix OUTPUT_VARIABLE BREW_PREFIX OUTPUT_STRIP_TRAILING_WHITESPACE)
    set(SDL2_MIXER_SEARCH_PATHS
        ${BREW_PREFIX}/lib
        /usr/local/lib
        /opt/local/lib
    )
    set(SDL2_MIXER_INCLUDE_SEARCH_PATHS
        ${BREW_PREFIX}/include/SDL2
        ${BREW_PREFIX}/include
        /usr/local/include/SDL2
        /usr/local/include
        /opt/local/include/SDL2
        /opt/local/include
    )
endif()

find_path(SDL2_MIXER_INCLUDE_DIR SDL_mixer.h
    HINTS
    $ENV{SDL2MIXERDIR}
    PATH_SUFFIXES include/SDL2 include
    PATHS ${SDL2_MIXER_INCLUDE_SEARCH_PATHS}
)

find_library(SDL2_MIXER_LIBRARY_TEMP
    NAMES SDL2_mixer
    HINTS
    $ENV{SDL2MIXERDIR}
    PATH_SUFFIXES lib64 lib lib/x64 lib/x86
    PATHS ${SDL2_MIXER_SEARCH_PATHS}
)

if(NOT SDL2_MIXER_BUILDING_LIBRARY)
    if(NOT SDL2_MIXER_INCLUDE_DIR AND SDL2_MIXER_LIBRARY_TEMP)
        set(SDL2_MIXER_INCLUDE_DIR "")
    endif()
endif()

set(SDL2_MIXER_FOUND "NO")
if(SDL2_MIXER_LIBRARY_TEMP)
    if(NOT SDL2_MIXER_BUILDING_LIBRARY)
        if(SDL2_MIXER_INCLUDE_DIR)
            set(SDL2_MIXER_FOUND "YES")
        endif()
    else()
        set(SDL2_MIXER_FOUND "YES")
    endif()
endif()

set(SDL2_MIXER_LIBRARY "${SDL2_MIXER_LIBRARY_TEMP}" CACHE STRING "Where the SDL2_mixer Library can be found")
set(SDL2_MIXER_LIBRARY_TEMP "${SDL2_MIXER_LIBRARY_TEMP}" CACHE INTERNAL "")

if(SDL2_MIXER_FOUND)
    set(SDL2_MIXER_LIBRARIES ${SDL2_MIXER_LIBRARY})
endif()