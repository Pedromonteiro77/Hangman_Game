#pragma once

#include <cstdint>

class Menu
{
private:
    uint16_t m_Option;
    uint16_t m_SettingsOption;

public:
    Menu();

    void mainMenu();
    void settingsMenu();
    const uint16_t getOption() const;
    const uint16_t getSettingsOption() const;
    
    ~Menu() = default;
};