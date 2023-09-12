#include <iostream>
#include <vector>
#include "..\header\funcs.h"

int main() { 
    HangmanGame game;

    game.clearScreen();
    
    // Funções que adicionam palavras para os Vectors
    game.addWordsCountries();
    game.addWordsFood();
    game.addWordsAnimals();
    game.addWordsNames();

    // Pergunta o nome do Jogador
    game.askPlayerName();

    return 0;
}