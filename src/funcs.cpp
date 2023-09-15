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
    while(true) {
        std::cout << "===== JOGO DA FORCA =====" << "\n";
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

    std::cout << "Ola " << playerName << " e um prazer ter voce jogando meu jogo! (^-^)" 
    << std::endl;
    std::cout << "Pressione Enter Para Continuar...";
    std::cin.get();
    clearScreen();
}

void HangmanGame::chooseTheTheme() {
    while(true) {
        std::cout << "===== JOGO DA FORCA =====" << "\n";
        std::cout << "Agora Vamos Escolher um Tema Para Podermos Comecar" << std::endl;
        std::cout << "1 - Paises, 2 - Comidas, 3 - Animais, 4 - Nomes de Pessoas" << std::endl;
        std::cout << "Digite o Numero do Tema Escolhido: "; 
        std::cin >> indice;
        std::cin.ignore();

        if(indice != 1 && indice != 2 && indice != 3 && indice != 4) {
            std::cout << "Desculpe Mais Numero Invalido Digite um Numero Valido!" << std::endl;
            std::cout << "Aperte Enter para Continuar...";
            std::cin.get();
            clearScreen();
            continue;
        }

        else {
            switch(indice) {
                case 1:
                std::cout << "Voce Escolheu Paises Voce confirma? sim(s)/nao(n): ";
                std::cin >> opc;

                if(opc == 's' || opc == 'S') {
                    std::cout << "Ok " << playerName << " Vamos de Tema Paises!";
                    break;
                }
                else {
                    clearScreen();
                    continue;
                }
                break;

                case 2:
                std::cout << "Voce Escolheu Comida Voce confirma? sim(s)/nao(n): ";
                std::cin >> opc;

                if(opc == 's' || opc == 'S') {
                    std::cout << "Ok " << playerName << " Vamos de Tema Comida!";
                    break;
                }
                else {
                    clearScreen();
                    continue;
                }
                break;

                case 3:
                std::cout << "Voce Escolheu Animais Voce confirma? sim(s)/nao(n): ";
                std::cin >> opc;

                if(opc == 's' || opc == 'S') {
                    std::cout << "Ok " << playerName << " Vamos de Tema Animais!";
                    break;
                }
                else {
                    clearScreen();
                    continue;
                }
                break;

                case 4:
                std::cout << "Voce Escolheu Nomes Voce confirma? sim(s)/nao(n): ";
                std::cin >> opc;

                if(opc == 's' || opc == 'S') {
                    std::cout << "Ok " << playerName << " Vamos de Tema Nomes!";
                    break;
                }
                else {
                    clearScreen();
                    continue;
                }
            }

            break;
        }
    }
    clearScreen();
}

void HangmanGame::playGame() {
    std::cout << "===== JOGO DA FORCA =====" << "\n";
    if(indice == 1) {
        for(auto & i : countries) {
            std::cout << i << "\n";
        }
    }
}