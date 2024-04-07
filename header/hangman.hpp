#pragma once

#include <array>
#include <string>
#include <cstdint>
#include <cstddef>

const size_t THEME_ARRAY_SIZE {4};
const size_t ARRAYS_SIZE {10};

class Hangman
{
private:
    std::array<std::string, THEME_ARRAY_SIZE> themes_;
    std::array<std::string, ARRAYS_SIZE> peopleName_;
    std::array<std::string, ARRAYS_SIZE> fruits_;
    std::array<std::string, ARRAYS_SIZE> countries_;
    std::array<std::string, ARRAYS_SIZE> foods_;
    std::string playerName_; 
    std::string yesOrNot_;
    std::string word_;
    uint32_t themeIndex_;
    char letter_;
    uint32_t attempts_;

    void writeThemes();
    void writePeopleName();
    void writeFruits();
    void writeCountries();
    void writeFoods();
    void randomWord(std::string& wordParam, std::array<std::string, ARRAYS_SIZE>& arrayParam);
    
public:
    Hangman();
    ~Hangman() = default;
    
    void yesOrNotVerify(const std::string& textParam, std::string& yesNotParam);
    void askPlayerName();
    void chooseTheme();
    void game();

    const std::string& getYesOrNot();
};