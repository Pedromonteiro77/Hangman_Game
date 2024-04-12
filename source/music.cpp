#include <iostream>
#include <chrono>
#include <thread>
#include <stdexcept>
#include "../header/music.hpp"

// Construtor da Classe MusicPlayer
MusicPlayer::MusicPlayer() : music_({}) {}

// Função que toca a musica em loop
const int MusicPlayer::soundtrack(std::atomic<bool>& stopMusicParam)
{
    const std::string musicPathFolder {"music/modolistik.wav"};

    if(!music_.openFromFile(musicPathFolder))
    {
        std::cerr << "It's not possible to open the music!";
        return EXIT_FAILURE;
    }

    music_.play();

    music_.setLoop(true);

    while(!stopMusicParam)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    music_.stop();

    return EXIT_SUCCESS;
};