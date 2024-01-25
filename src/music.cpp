#include <chrono>
#include <thread>
#include "..\header\music.hpp"

// Construtor da Classe MusicPlayer
MusicPlayer::MusicPlayer() : music({}) {}

// Função que toca a musica em loop
const int MusicPlayer::soundtrack(const std::string & musicParam, std::atomic<bool> & stopMusicParam)
{
    if(!music.openFromFile("music/" + musicParam))
    {
        return 1;
    }

    music.play();

    music.setLoop(true);

    while(!stopMusicParam)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    music.stop();

    return EXIT_SUCCESS;
};