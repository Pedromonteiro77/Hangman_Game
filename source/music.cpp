#include <iostream>
#include <chrono>
#include <thread>
#include <stdexcept>
#include "../header/music.hpp"

// Função que toca a musica em loop
int soundtrack(std::atomic<bool>& isMusicPlaying)
{
    if(SDL_Init(SDL_INIT_AUDIO) != 0)
    {
        std::cerr << "Failed to Init AUDIO: " << SDL_GetError();
        return EXIT_FAILURE;
    }

    if(Mix_OpenAudio(48000, MIX_DEFAULT_FORMAT, 2, 2048) != 0)
    {
        std::cerr << "Failed to Open AUDIO: " << Mix_GetError();
        return EXIT_FAILURE;
    }

    Mix_Music* music = Mix_LoadMUS("music/moonolistik.wav");

    if(!music)
    {
        std::cerr << "Failed to Load the music: " << Mix_GetError();
        return EXIT_FAILURE;
    }

    if(Mix_PlayMusic(music, -1) == -1)
    {
        std::cerr << "Failed to Play the music: " << Mix_GetError();
        return EXIT_FAILURE;
    }

    while(isMusicPlaying)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    Mix_HaltMusic();
    Mix_FreeMusic(music);
    Mix_CloseAudio();
    SDL_Quit();

    return 0;
};