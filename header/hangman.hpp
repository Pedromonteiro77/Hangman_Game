#pragma once

#include <array>
#include <string>
#include <cstdint>

const uint16_t THEME_ARRAY_SIZE {4};
const uint16_t ARRAYS_SIZE {10};

class Hangman
{
private:
    std::array<const char*, THEME_ARRAY_SIZE> m_Themes;
    std::array<const char*, ARRAYS_SIZE> m_PeopleName;
    std::array<const char*, ARRAYS_SIZE> m_Fruits;
    std::array<const char*, ARRAYS_SIZE> m_Countries;
    std::array<const char*, ARRAYS_SIZE> m_Foods;
    std::string m_PlayerName; 
    std::string m_YesOrNot;
    std::string m_Word;
    uint16_t m_ThemeIndex;
    char m_Letter;
    uint16_t m_Attempts;

    void writeThemes();
    void writePeopleName();
    void writeFruits();
    void writeCountries();
    void writeFoods();
    void randomWord(std::string& wordParam, std::array<const char*, ARRAYS_SIZE>& arrayParam);
    
public:
    Hangman();
    
    void yesOrNotVerify(const std::string& textParam, std::string& yesNotParam);
    void askPlayerName();
    void chooseTheme();
    void game();
    const std::string& getYesOrNot();

    ~Hangman() = default;
};