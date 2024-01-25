#pragma once

class Menu
{
private:
    unsigned int option_;
    unsigned int settingsOption_;

public:
    Menu();
    ~Menu() = default;

    void mainMenu();
    void settingsMenu();
    const unsigned int getOption() const;
    const unsigned int getSettingsOption() const;
};