#include <iostream>
#include <stdexcept>
#include "..\header\menu.hpp"
#include "..\header\screen_clear.hpp"

// Construtor da Classe Menu
Menu::Menu() : m_Option(), m_SettingsOption() {}

// Menu Principal
void Menu::mainMenu()
{   
    std::string strOption;

    while(true)
    {
        try
        {
            std::cout << "=== Options Menu ===" << '\n';
            std::cout << "1 - Play Game" << '\n';
            std::cout << "2 - Options" << '\n';
            std::cout << "3 - Exit Game" << '\n';
            std::cout << "Choose an option: ";
            std::getline(std::cin, strOption);

            if(strOption.empty() || strOption.length() > 1)
            {
                throw std::invalid_argument("INVALID! Don't leave the field empty and Enter one of the options");
            }

            bool isInt {true};
            for(auto& i : strOption)
            {
                if(!std::isdigit(i))
                {
                    isInt = false;
                    break;
                }
            }

            if(!isInt)
            {
                throw std::invalid_argument("INVALID! Enter one of the options");
            }

            m_Option = std::stoi(strOption);

            if(m_Option < 1 || m_Option > 3)
            {
                throw std::invalid_argument("INVALID! Enter a number between 1 and 3");
            }

            break;
        }

        catch(const std::invalid_argument& e)
        {
            std::cerr << e.what() << '\n';
            std::cout << "Press Enter to continue...";
            std::cin.get();
            strOption.clear();
            Screen::clear();
            continue;
        }
    }

    Screen::clear();
}

// Menu de configurações
void Menu::settingsMenu()
{
    std::string strSettingOpt;
    bool isInt {true};

    while(true)
    {
        try
        {
            std::cout << "=== SETTINGS ===" << '\n';
            std::cout << "1 - Turn on the music" << '\n';
            std::cout << "2 - Turn off the music" << '\n';
            std::cout << "3 - Go Back to Menu" << '\n';
            std::cout << "Choose one of the options: ";
            std::getline(std::cin, strSettingOpt);

            if(strSettingOpt.empty() || strSettingOpt.length() > 1)
            {
                throw std::invalid_argument("INVALID! Don't leave the field empty and Enter one of the options");
            }

            for(auto& i : strSettingOpt)
            {
                if(!std::isdigit(i))
                {
                    isInt = false;
                    break;
                }
            }

            if(!isInt)
            {
                throw std::invalid_argument("INVALID! Enter one of the options");
            }

            m_SettingsOption= std::stoi(strSettingOpt);

            if(m_SettingsOption < 1 || m_SettingsOption > 3)
            {
                throw std::invalid_argument("INVALID! Enter a number between 1 and 3");
            }

            break;
        }

        catch(const std::invalid_argument& e)
        {
            std::cerr << e.what() << '\n';
            std::cout << "Press Enter to continue...";
            std::cin.get();
            strSettingOpt.clear();
            Screen::clear();
            continue;
        }
    }

    Screen::clear();
}

// Retorna a variavel m_Option
const uint16_t Menu::getOption() const
{
    return m_Option;
}

// Retorna a variavel settingsOption
const uint16_t Menu::getSettingsOption() const
{
    return m_SettingsOption;
}