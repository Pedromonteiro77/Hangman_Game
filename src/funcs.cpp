#include <iostream>
#include "..\header\funcs.h"

void HangmanGame::showTitleName()
{
    std::cout << "===== JOGO DA FORCA ====="
              << "\n";
}

void HangmanGame::clearScreen()
{
    std::system("cls");
}

void HangmanGame::addWordsCountries()
{
    countries = {
        "BRASIL", "ARGENTINA", "RUSSIA", "PERU", "MEXICO",
        "EGITO", "UCRANIA", "UGANDA", "ESPANHA", "CHINA"};
}

void HangmanGame::addWordsFood()
{
    food = {
        "PIZZA", "HAMBURGUER", "TACOS", "FEIJOADA", "LASANHA",
        "CHURRASCO", "ESTROGONOFE", "SUSHI", "CURRY", "ACARAJE"};
}

void HangmanGame::addWordsAnimals()
{
    animals = {
        "GATO", "CACHORRO", "TIGRE", "CROCODILO", "GAIVOTA",
        "JAVALI", "LEBRE", "URSO", "MORCEGO", "PANDA"};
}

void HangmanGame::addWordsNames()
{
    names = {
        "JULIA", "MARIA", "CARLOS", "GABRIEL", "SOPHIA",
        "BRUNO", "MIGUEL", "ARTHUR", "HELENA", "LAURA"};
}

void HangmanGame::askPlayerName()
{
    while (true)
    {
        showTitleName();
        std::cout << "Digite o seu nome: ";
        std::getline(std::cin, playerName);

        if (playerName.empty())
        {
            std::cout << "Desculpe mais nao pode deixar vazio, por favor digite seu nome ou nickname que deseja usar!"
                      << std::endl;
            std::cout << "Pressione Enter para continuar...";
            std::cin.get();
            clearScreen();
            continue;
        }

        else
        {
            std::cout << "Seu nome e " << playerName << " esta correto? sim(s)/nao(n): ";
            std::cin >> opc;
            std::cin.ignore();

            if (opc == 's' || opc == 'S')
            {
                break;
            }

            else
            {
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

void HangmanGame::chooseTheTheme()
{
    while (true)
    {
        showTitleName();
        std::cout << "Agora Vamos Escolher um Tema Para Podermos Comecar" << std::endl;
        std::cout << "1 - Paises, 2 - Comidas, 3 - Animais, 4 - Nomes de Pessoas" << std::endl;
        std::cout << "Digite o Numero do Tema Escolhido: ";
        std::cin >> indice;
        std::cin.ignore();

        if (indice != 1 && indice != 2 && indice != 3 && indice != 4)
        {
            std::cout << "Desculpe Mais Numero Invalido Digite um Numero Valido!" << std::endl;
            std::cout << "Aperte Enter para Continuar...";
            std::cin.get();
            clearScreen();
            continue;
        }

        else
        {
            switch (indice)
            {
            case 1:
                std::cout << "Voce Escolheu Paises Voce confirma? sim(s)/nao(n): ";
                std::cin >> opc;

                if (opc == 's' || opc == 'S')
                {
                    std::cout << "Ok " << playerName << " Vamos de Tema Paises!";
                    break;
                }
                else
                {
                    clearScreen();
                    continue;
                }
                break;

            case 2:
                std::cout << "Voce Escolheu Comida Voce confirma? sim(s)/nao(n): ";
                std::cin >> opc;

                if (opc == 's' || opc == 'S')
                {
                    std::cout << "Ok " << playerName << " Vamos de Tema Comida!";
                    break;
                }
                else
                {
                    clearScreen();
                    continue;
                }
                break;

            case 3:
                std::cout << "Voce Escolheu Animais Voce confirma? sim(s)/nao(n): ";
                std::cin >> opc;

                if (opc == 's' || opc == 'S')
                {
                    std::cout << "Ok " << playerName << " Vamos de Tema Animais!";
                    break;
                }
                else
                {
                    clearScreen();
                    continue;
                }
                break;

            case 4:
                std::cout << "Voce Escolheu Nomes Voce confirma? sim(s)/nao(n): ";
                std::cin >> opc;

                if (opc == 's' || opc == 'S')
                {
                    std::cout << "Ok " << playerName << " Vamos de Tema Nomes!";
                    break;
                }
                else
                {
                    clearScreen();
                    continue;
                }
                break;

            default:
                break;
            }

            break;
        }
    }
    clearScreen();
}

void HangmanGame::generatesRandomWord(std::vector<std::string> &vec, std::string &wordRand)
{
    std::random_device aleatorio;

    std::mt19937 rng(aleatorio());

    std::shuffle(vec.begin(), vec.end(), rng);

    wordRand = vec[0];
}

void HangmanGame::prepareTheGame()
{
    showTitleName();

    if (indice == 1)
    {
        addWordsCountries();
        generatesRandomWord(countries, randomWord);
    }
    else if (indice == 2)
    {
        addWordsFood();
        generatesRandomWord(food, randomWord);
    }
    else if (indice == 3)
    {
        addWordsAnimals();
        generatesRandomWord(animals, randomWord);
    }
    else if (indice == 4)
    {
        addWordsNames();
        generatesRandomWord(names, randomWord);
    }
    clearScreen();
}

void HangmanGame::showTheme()
{
    if (indice == 1)
    {
        std::cout << "Tema: Paises" << std::endl;
    }
    else if (indice == 2)
    {
        std::cout << "Tema: Comidas" << std::endl;
    }
    else if (indice == 3)
    {
        std::cout << "Tema: Animais" << std::endl;
    }
    else if (indice == 4)
    {
        std::cout << "Tema: Nome de Pessoas" << std::endl;
    }
}

void HangmanGame::playGame()
{
    prepareTheGame();
    std::string keepTheRandomWord(randomWord.size(), '_');
    int attempts = 5;
    char letter;

    while (true)
    {
        showTitleName();
        showTheme();
        std::cout << "Voce Tem " << attempts << " Tentativas" << std::endl;
        bool found = false;

        for (size_t i = 0; i < keepTheRandomWord.size(); i++)
        {
            std::cout << keepTheRandomWord[i] << " ";
        }

        std::cout << std::endl;

        std::cout << "Digite a Letra que deseja tentar: ";
        std::cin >> letter;
        std::cin.ignore();

        letter = std::toupper(letter);

        for (size_t c = 0; c < randomWord.size(); c++)
        {
            if (randomWord[c] == letter)
            {
                found = true;
                keepTheRandomWord[c] = letter;
            }
        }

        if (found)
        {
            std::cout << "Acertou" << std::endl;
            std::cout << "Aperte Enter Para Continuar...";
            std::cin.get();
            clearScreen();
        }
        else
        {
            std::cout << "Errou" << std::endl;
            --attempts;
            std::cout << "Aperte Enter Para Continuar...";
            std::cin.get();
            clearScreen();
        }

        if (keepTheRandomWord == randomWord)
        {
            std::cout << "A Palavra era: " << randomWord << std::endl;
            std::cout << "Parabens Voce Descobriu a Palavra !(^_^)!" << std::endl;
            break;
        }
        else if (attempts == 0)
        {
            std::cout << "A Palavra era: " << randomWord << std::endl;
            std::cout << "Lamento suas tentativas acabaram |(-_-)|" << std::endl;
            break;
        }
    }
    std::cout << std::endl;
}