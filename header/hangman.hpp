#pragma once

#include <array>
#include <string>

class Hangman
{
private:
    std::array<std::string, 4> themes_;
    std::array<std::string, 10> peopleName_;
    std::array<std::string, 10> fruits_;
    std::array<std::string, 10> countries_;
    std::array<std::string, 10> foods_;
    std::string playerName_; 
    std::string yesOrNot_;
    std::string word_;
    unsigned int themeIndex_;
    char letter_;
    unsigned int attempts_;

    void writeThemes();
    void writePeopleName();
    void writeFruits();
    void writeCountries();
    void writeFoods();
    void randomWord(std::string & wordParam, std::array<std::string, 10> & arrayParam);
    
public:
    Hangman();
    ~Hangman() = default;
    
    void yesOrNotVerify(const std::string & textParam, std::string & yesNotParam);
    void askPlayerName();
    void chooseTheme();
    void game();

    std::string getYesOrNot();
};