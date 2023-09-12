#ifndef FUNCS_H
#define FUNCS_H

#include <string>
#include <vector>

class HangmanGame {
private:
    std::string playerName;
    std::vector<std::string> countries;
    std::vector<std::string> food;
    std::vector<std::string> animals;
    std::vector<std::string> names;
    char letra;

public:
    std::vector<std::string> getCountries() {
        return countries;
    }

    std::vector<std::string> getFood() {
        return food;
    }

    std::vector<std::string> getAnimals() {
        return animals;
    }

    std::vector<std::string> getNames() {
        return names;
    }

    std::string getPlayerName() const {
        return playerName;
    }

    void clearScreen();

    void addWordsCountries();

    void addWordsFood();

    void addWordsAnimals();

    void addWordsNames();
  
    void askPlayerName();
};

#endif