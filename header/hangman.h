#ifndef FUNCS_H
#define FUNCS_H

#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <cctype>
#include <set>

class HangmanGame {
private:
    std::string playerName;
    std::vector<std::string> themes;
    std::vector<std::string> countries;
    std::vector<std::string> food;
    std::vector<std::string> animals;
    std::vector<std::string> names;
    std::vector<std::string> fruits;
    std::string chosenTheme;
    std::string randomWord;
    int indice;
    int attempts;
    char opc;
    char letter;

    void showTitleName();
    void clearScreen();
    void addWordThemes();
    void addWordsCountries();
    void addWordsFood();
    void addWordsAnimals();
    void addWordsNames();
    void addWordsFruits();
    void askPlayerName();
    void generatesRandomWord(std::vector<std::string> & vec, std::string & wordRand);
    void prepareTheGame();
    void showTheme();
    void showLetterList(std::set<char> & keepTheLetter);
    void verifyAlreadyLetter(std::set<char> & keepTheLetter, char & letter);
    void chooseTheTheme();
    void gameWorking();
    
public:
    HangmanGame();

    void play(); 
};

#endif