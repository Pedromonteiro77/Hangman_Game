#pragma once

#include "../resources/SDL2/include/SDL.h"
#include "../resources/SDL2/include/SDL_mixer.h"
#include <atomic>
    
int soundtrack(std::atomic<bool>& isMusicPlaying);