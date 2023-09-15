#ifndef FUNCS_H
#define FUNCS_H

#include <string>
#include <vector>
#include <algorithm>
#include <random>

class HangmanGame {
private:
    std::string playerName;
    std::vector<std::string> countries;
    std::vector<std::string> food;
    std::vector<std::string> animals;
    std::vector<std::string> names;
    int indice;
    char opc;

public:
    void start() {
        clearScreen();
        
        addWordsCountries();
        addWordsFood();
        addWordsAnimals();
        addWordsNames();

        askPlayerName();

        chooseTheTheme();

        playGame();
    }
    
    std::vector<std::string> getCountries() const {
        return countries;
    }

    std::vector<std::string> getFood() const {
        return food;
    }

    std::vector<std::string> getAnimals() const {
        return animals;
    }

    std::vector<std::string> getNames() const {
        return names;
    }

    std::string getPlayerName() const {
        return playerName;
    }

    int getIndice() const {
        return indice;
    }

    char getOpc() const {
        return opc;
    }

    void clearScreen();
    void addWordsCountries();
    void addWordsFood();
    void addWordsAnimals();
    void addWordsNames();
    void askPlayerName();
    void chooseTheTheme();
    void playGame();
};

#endif