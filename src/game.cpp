#include <iostream>
#include <vector>
#include <chrono>
#include "..\header\funcs.h"

int main() { 
    HangmanGame game;

    game.clearScreen();
    
    game.addWordsCountries();
    game.addWordsFood();
    game.addWordsAnimals();
    game.addWordsNames();

    game.askPlayerName();

    return 0;
}