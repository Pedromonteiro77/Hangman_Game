#pragma once

#include <SFML/Audio.hpp>
#include <atomic>

class MusicPlayer
{
private:
    sf::Music music_;

public:
    MusicPlayer();
    ~MusicPlayer() = default;
    const int soundtrack(std::atomic<bool>& stopMusicParam);
};