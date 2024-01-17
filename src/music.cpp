#include "..\header\music.hpp"
#include <chrono>
#include <thread>

MusicPlayer::MusicPlayer() : music({}) {}

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