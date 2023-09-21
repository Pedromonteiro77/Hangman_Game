#ifndef FUNCS_H
#define FUNCS_H

#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <cctype>
#include <set>

class HangmanGame
{
private:
    std::string playerName;
    std::string randomWord;
    std::vector<std::string> countries;
    std::vector<std::string> food;
    std::vector<std::string> animals;
    std::vector<std::string> names;
    int indice;
    char opc;
    char letter;

public:
    void start()
    {
        clearScreen();

        askPlayerName();

        while (true)
        {
            chooseTheTheme();

            playGame();

            std::cout << "Desejar jogar outra partida? sim(s)/nao(n): ";
            std::cin >> opc;
            std::cin.ignore();

            if (opc == 's' || opc == 'S')
            {
                clearScreen();
                continue;
            }
            else
            {
                clearScreen();
                std::cout << "Obrigado por ter Jogado" << std::endl;
                break;
            }
        }
    }

    void showTitleName();
    void clearScreen();
    void addWordsCountries();
    void addWordsFood();
    void addWordsAnimals();
    void addWordsNames();
    void askPlayerName();
    void chooseTheTheme();
    void generatesRandomWord(std::vector<std::string> &vec, std::string &wordRand);
    void prepareTheGame();
    void showTheme();
    void showLetterList(std::set<char> & keepTheLetter);
    void verifyAlreadyLetter(std::set<char> & keepTheLetter, char & letter);
    void playGame();
};

#endif