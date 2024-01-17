#pragma once

#include <SFML\Audio.hpp>
#include <atomic>

class MusicPlayer
{
private:
    sf::Music music;

public:
    MusicPlayer();
    ~MusicPlayer() = default;
    const int soundtrack(const std::string & musicParam, std::atomic<bool> & stopMusicParam);
};