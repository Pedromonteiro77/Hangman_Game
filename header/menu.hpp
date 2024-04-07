#pragma once

#include <cstdint>

class Menu
{
private:
    uint16_t option_;
    uint16_t settingsOption_;

public:
    Menu();
    ~Menu() = default;

    void mainMenu();
    void settingsMenu();
    const uint16_t getOption() const;
    const uint16_t getSettingsOption() const;
};