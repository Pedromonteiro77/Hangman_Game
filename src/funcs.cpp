#include <iostream>
#include "..\header\funcs.h"

void HangmanGame::clearScreen() {
    std::system("cls");
}

void HangmanGame::addWordsCountries() {
    countries = {
        "BRASIL", "ARGENTINA", "RUSSIA", "PERU", "MEXICO", 
        "EGITO", "UCRANIA", "UGANDA", "ESPANHA", "CHINA"
    };   
}

void HangmanGame::addWordsFood() {
    food = {
        "PIZZA", "HAMBURGUER", "TACOS", "FEIJOADA", "LASANHA",
        "CHURRASCO", "ESTROGONOFE", "SUSHI", "CURRY", "ACARAJE"
    };
}

void HangmanGame::addWordsAnimals() {
    animals = {
        "GATO", "CACHORRO", "TIGRE", "CROCODILO", "GAIVOTA",
        "JAVALI", "LEBRE", "URSO", "MORCEGO", "PANDA"
    };
}

void HangmanGame::addWordsNames() {
    names = {
        "JULIA", "MARIA", "CARLOS", "GABRIEL", "SOPHIA",
        "BRUNO", "MIGUEL", "ARTHUR", "HELENA", "LAURA"
    };
}

void HangmanGame::askPlayerName() {
    char opc;

    while(true) {
        std::cout << "Digite o seu nome: ";
        std::getline(std::cin, playerName);

        if(playerName.empty()) {
            std::cout << "Desculpe mais nao pode deixar vazio, por favor digite seu nome ou nickname que deseja usar!" 
            << std::endl;
            std::cout << "Pressione Enter para continuar...";
            std::cin.get();
            clearScreen();
            continue;
        }

        else {
            std::cout << "Seu nome e " << playerName << " esta correto? sim(s)/nao(n): ";
            std::cin >> opc;
            std::cin.ignore();

            if(opc == 's' || opc == 'S') {
                break;
            }

            else {
                clearScreen();
                continue;
            }
        }
    }

    std::cout << "Ola " << playerName << " e um prazer ter voce jogando meu jogo! (^-^)" << std::endl;
}
