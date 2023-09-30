#include <iostream>
#include "..\header\hangman.h"

HangmanGame::HangmanGame() 
    : playerName(""),
    themes({}), 
    countries({}), 
    food({}), 
    animals({}), 
    names({}),
    randomWord(""),
    indice(0),
    attempts(0),
    opc('N')
    {}

void HangmanGame::showTitleName() {
    std::cout << "===== JOGO DA FORCA =====" << "\n";
}

void HangmanGame::clearScreen() {
    std::system("cls");
}

void HangmanGame::addWordThemes() {
    themes = {
        "Paises", "Comidas", "Animais", "Nomes de pessoas", "Frutas"
    };
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

void HangmanGame::addWordsFruits() {
    fruits = {
        "ABACATE", "FRAMBOESA", "DAMASCO", "UVA", "FIGO",
        "LIMAO", "MANGA", "BANANA", "AMORA", "ABACAXI"
    };
}

void HangmanGame::askPlayerName() {
    while(true) {
        showTitleName();
        std::cout << "Digite o seu nome: ";
        std::getline(std::cin, playerName);

        if(playerName.empty()) {
            std::cout << "Desculpe mais nao pode deixar vazio, por favor digite seu nome ou nickname que deseja usar!" 
            << '\n';
            std::cout << "Pressione Enter para continuar...";
            std::cin.get();
            clearScreen();
            continue;
        }

        else {
            std::cout << "Seu nome e " << playerName << " esta correto? sim(s)/nao(n): ";
            std::cin >> opc;
            std::cin.ignore();

            if (opc == 's' || opc == 'S') {
                break;
            }

            else {
                clearScreen();
                continue;
            }
        }
    }

    std::cout << "Ola " << playerName << " e um prazer ter voce jogando meu jogo!" << '\n';
    std::cout << "Pressione Enter Para Continuar...";
    std::cin.get();
    clearScreen();
}

void HangmanGame::chooseTheTheme() {
    addWordThemes();
    while(true) {
        showTitleName();
        std::cout << "Agora Vamos Escolher um Tema Para Podermos Comecar" << '\n';
        
        for(auto i = 0; i < themes.size(); i++) {
            std::cout << i + 1 << " - " << themes[i] << '\n';
        }
        
        std::cout << "Digite o numero do Tema escolhido: ";

        if(std::cin >> indice && indice >= 1 && indice <= themes.size()) {
            std::cin.ignore();
            chosenTheme = themes[indice - 1];
            std::cout << "Voce Escolheu " << chosenTheme << '\n';
            std::cout << "Voce Confirma sim(s)/nao(n): ";
            std::cin >> opc;

            if(opc == 's' || opc == 'S') {
                std::cout << "Ok " << playerName << " Vamos de " << chosenTheme << '\n';
                break;
            }
            else {
                clearScreen();
                continue;
            }
        }

        else {
            std::cout << "Entrada invalida digite um numero entre 1 e " << themes.size() << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Aperte Enter para continuar...";
            std::cin.get();
            clearScreen();
            continue;
        }   
    }
    clearScreen();
}

void HangmanGame::generatesRandomWord(std::vector<std::string> &vec, std::string &wordRand) {
    std::random_device aleatorio;

    std::mt19937 rng(aleatorio());

    std::shuffle(vec.begin(), vec.end(), rng);

    wordRand = vec[0];
}

void HangmanGame::prepareTheGame() {
    showTitleName();

    if(indice == 1) {
        addWordsCountries();
        generatesRandomWord(countries, randomWord);
    }

    else if(indice == 2) {
        addWordsFood();
        generatesRandomWord(food, randomWord);
    }

    else if(indice == 3) {
        addWordsAnimals();
        generatesRandomWord(animals, randomWord);
    }

    else if(indice == 4) {
        addWordsNames();
        generatesRandomWord(names, randomWord);
    }

    else if(indice == 5) {
        addWordsFruits();
        generatesRandomWord(fruits, randomWord);
    }

    clearScreen();
}

void HangmanGame::showTheme() {
    if(indice == 1) {
        std::cout << "Tema: Paises" << '\n';
    }

    else if(indice == 2) {
        std::cout << "Tema: Comidas" << '\n';
    }

    else if(indice == 3) {
        std::cout << "Tema: Animais" << '\n';
    }

    else if(indice == 4) {
        std::cout << "Tema: Nome de Pessoas" << '\n';
    }

    else if(indice == 5) {
        std::cout << "Tema: Frutas" << '\n';
    }
}

void HangmanGame::showLetterList(std::set<char> & keepTheLetter) {
    std::cout << "Letras ja digitadas: ";

    for(auto i : keepTheLetter) {
        std::cout << i << " - ";
    }

    std::cout << std::endl;
}

void HangmanGame::verifyAlreadyLetter(std::set<char> & keepTheLetter, char & letter) {
    if(keepTheLetter.count(letter) > 0) {
        std::cout << "Voce Ja tentou essa letra tente outra." << '\n';
        std::cout << "Aperte Enter Para Continuar...";
        std::cin.get();
        clearScreen();
    }

    else {
        keepTheLetter.insert(letter);
    }
}

void HangmanGame::playGame() {
    prepareTheGame();
    std::string keepTheRandomWord(randomWord.size(), '_');
    std::set<char> keepTheLetter;
    attempts = 5;

    while(true) {
        showTitleName();
        showTheme();
        std::cout << "Voce Tem " << attempts << " Tentativas" << '\n';
        bool found {false};

        for (size_t i = 0; i < keepTheRandomWord.size(); i++) {
            std::cout << keepTheRandomWord[i] << " ";
        }

        std::cout << '\n';

        std::cout << "Digite a Letra que deseja tentar: ";
        std::cin >> letter;
        std::cin.ignore();

        letter = std::toupper(letter);

        for (size_t c = 0; c < randomWord.size(); c++) {
            if (randomWord[c] == letter) {
                found = true;
                keepTheRandomWord[c] = letter;
            }
        }

        verifyAlreadyLetter(keepTheLetter, letter);

        if(found) {
            clearScreen();
        }

        else {
            std::cout << "Errou" << '\n';
            --attempts;
            std::cout << "Aperte Enter Para Continuar...";
            std::cin.get();
            clearScreen();
        }

        showLetterList(keepTheLetter);

        if(keepTheRandomWord == randomWord) {
            clearScreen();
            std::cout << "A Palavra era: " << randomWord << '\n';
            std::cout << "Parabens Voce Descobriu a Palavra !(^_^)!" << '\n';
            break;
        }
        
        else if(attempts == 0) {
            clearScreen();
            std::cout << "A Palavra era: " << randomWord << '\n';
            std::cout << "Lamento suas tentativas acabaram |(-_-)|" << '\n';
            break;
        }
    }
}