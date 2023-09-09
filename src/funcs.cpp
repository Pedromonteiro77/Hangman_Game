#include <iostream>
#include "..\header\funcs.h"

void addWordsCountries(std::vector<std::string> & countries) {
    countries = {
        "BRASIL", "ARGENTINA", "RUSSIA", "PERU", "MEXICO", 
        "EGITO", "UCRANIA", "UGANDA", "ESPANHA", "CHINA"
    };   
}

void addWordsFood(std::vector<std::string> & food) {
    food = {
        "PIZZA", "HAMBURGUER", "TACOS", "FEIJOADA", "LASANHA",
        "CHURRASCO", "ESTROGONOFE", "SUSHI", "CURRY", "ACARAJE"
    };
}

void addWordsAnimals(std::vector<std::string> & animals) {
    animals = {
        "GATO", "CACHORRO", "TIGRE", "CROCODILO", "GAIVOTA",
        "JAVALI", "LEBRE", "URSO", "MORCEGO", "PANDA"
    };
}

void addWordsNames(std::vector<std::string> & names) {
    names = {
        "JULIA", "MARIA", "CARLOS", "GABRIEL", "SOPHIA",
        "BRUNO", "MIGUEL", "ARTHUR", "HELENA", "LAURA"
    };
}

void askPlayerName(std::string & name) {
    char opc;

    while(true) {
        std::cout << "Digite o seu nome: ";
        std::getline(std::cin, name);

        if(name.empty()) {
            std::cout << "Desculpe mais nao pode deixar vazio, por favor digite seu nome ou nickname que deseja usar!" 
            << std::endl;
            std::cout << "Pressione Enter para continuar...";
            std::cin.get();
            std::system("cls");
            continue;
        }

        else {
            std::cout << "Seu nome e " << name << " esta correto? sim(s)/nao(n): ";
            std::cin >> opc;
            std::cin.ignore();

            if(opc == 's' || opc == 'S') {
                break;
            }

            else {
                std::system("cls");
                continue;
            }
        }
    }

    std::cout << "Ola " << name << " e um prazer ter voce jogando meu jogo! (^-^)" << std::endl;
}
