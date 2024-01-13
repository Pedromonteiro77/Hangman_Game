#pragma once

class Menu
{
protected:
    unsigned int option_;

public:
    Menu();
    ~Menu() = default;

    void optionsMenu();
    const unsigned int getOption() const;
};