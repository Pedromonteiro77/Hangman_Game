#include <iostream>
#include <cctype>
#include <stdexcept>
#include <algorithm>
#include <random>
#include <vector>
#include "..\header\hangman.hpp"
#include "..\header\screen_clear.hpp"

// Construtor da classe inicializando as variaveis
Hangman::Hangman() 
:   m_Themes(),
    m_PeopleName(),
    m_Fruits(),
    m_Countries(),
    m_Foods(),
    m_PlayerName(),
    m_YesOrNot(),
    m_Word(),
    m_ThemeIndex(),
    m_Letter(),
    m_Attempts()
{}

// Função que atribui strings para o array
void Hangman::writeThemes()
{
    m_Themes = {
       "PEOPLE NAME", "FRUITS", "COUNTRIES", "FOODS" 
    };
}

// Função que atribui strings para o array
void Hangman::writePeopleName()
{
    m_PeopleName = {
        "LUCY", "JILL", "STACY", "LEON", "SASHA",
        "JHON", "BELLA", "JAMES", "MAYA", "SAGE"
    };
}

// Função que atribui strings para o array
void Hangman::writeFruits()
{
    m_Fruits = {
        "STRAWBERRY", "JACKFRUIT", "ORANGE", "GRAPE", "WATERMELON",
        "BANANA", "MANGO", "PEAR", "RASPBERRY", "AVOCADO" 
    };
}

// Função que atribui strings para o array
void Hangman::writeCountries()
{
    m_Countries = {
        "FRANCE", "GERMANY", "BRAZIL", "NETHERLANDS", "JAPAN",
        "SPAIN", "CHINA", "RUSSIA", "INDIA", "SWITZERLAND"
    };
}

// Função que atribui strings para o array
void Hangman::writeFoods()
{
    m_Foods = {
        "PIZZA", "LASAGNA", "BARBECUE", "CURRY", "SUSHI",
        "TACOS", "BURGER", "HOTDOG", "RAMEN", "SOUP"
    };
}

// Função para não ter que ficar repetindo a verificação
void Hangman::yesOrNotVerify(const std::string& textParam, std::string& yesNotParam)
{
    while(true)
    {
        std::cout << textParam;
        std::getline(std::cin, yesNotParam);

        yesNotParam = std::toupper(yesNotParam[0]);

        if(!(yesNotParam == "Y" || yesNotParam == "N"))
        {
            std::cerr << "INVALID! Please type Y or N" << '\n';
            std::cout << "Press Enter to continue...";
            std::cin.get();
            Screen::clear();
            continue;
        }
        
        break;
    }
}

// Função para o player digitar o nome
void Hangman::askPlayerName()
{
    while(true)
    {
        try
        {
            std::cout << "=== HANGMAN GAME ===" << '\n';
            std::cout << "Type your Name: ";
            std::getline(std::cin, m_PlayerName);

            if(m_PlayerName.empty())
            {
                throw std::invalid_argument("INVALID! Don't leave the field empty.");
            }

            yesOrNotVerify("Your name is " + m_PlayerName + " do you confirm? (Y/N): ", m_YesOrNot);

            if(m_YesOrNot == "Y")
            {
                Screen::clear();
                m_YesOrNot.clear();
                break;
            }

            Screen::clear();
        }

        catch(const std::invalid_argument& e)
        {
            std::cerr << e.what() << '\n';
            std::cout << "Press Enter to continue...";
            std::cin.get();
            Screen::clear();
            continue;
        }
    }
}

// Função que pega um palavra aleatoria do array escolhido
void Hangman::randomWord(std::string& wordParam, std::array<const char*, ARRAYS_SIZE>& arrayParam)
{
    std::random_device rand;

    std::mt19937 mt(rand());

    std::shuffle(arrayParam.begin(), arrayParam.end(), mt);

    wordParam = arrayParam[0];
}

// Função para escolher o tema 
void Hangman::chooseTheme()
{
    std::string strThemeIndex;

    writeThemes();

    while(true)
    {
        try
        {
            std::cout << "=== THEMES ===" << '\n';
            for(auto i = 0; i < m_Themes.size(); i++)
            {
                std::cout << i+1 << " - " << m_Themes[i] << '\n';
            }

            std::cout << "Choose the number of a theme to play: ";
            std::getline(std::cin, strThemeIndex);

            if(strThemeIndex.empty())
            {
                throw std::invalid_argument("INVALID! Don't leave the field empty");
            }

            for(auto &i : strThemeIndex)
            {
                if(!std::isdigit(i))
                {
                    throw std::invalid_argument("INVALID! Type a number.");
                }
            }

            m_ThemeIndex = std::stoi(strThemeIndex);

            if(m_ThemeIndex < 1 || m_ThemeIndex > 4)
            {
                throw std::invalid_argument("INVALID! Choose one of the themes.");
            }

            yesOrNotVerify("You have choose " + std::string(m_Themes[m_ThemeIndex-1]) + " are you sure? (Y/N): ", m_YesOrNot);

            if(m_YesOrNot == "Y")
            {
                Screen::clear();
                m_YesOrNot.clear();
                break;
            }

            Screen::clear();
        }

        catch(const std::invalid_argument& e)
        {
            std::cerr << e.what() << '\n';
            std::cout << "Press Enter to continue...";
            std::cin.get();
            Screen::clear();
            strThemeIndex.clear();
            continue;
        }
    }

    switch(m_ThemeIndex)
    {
        case 1:
            writePeopleName();
            randomWord(m_Word, m_PeopleName);
            break;

        case 2:
            writeFruits();
            randomWord(m_Word, m_Fruits);
            break;

        case 3:
            writeCountries();
            randomWord(m_Word, m_Countries);
            break;

        case 4:
            writeFoods();
            randomWord(m_Word, m_Foods);
            break;
    }
}

// Função onde ocorre o game
void Hangman::game()
{
    std::string underlineString(m_Word.size(), '_');
    std::string strLetter;
    m_Attempts = 5;
    std::vector<char> wrongLetters;
    wrongLetters.reserve(5);

    while(true)
    {
        std::cout << "=== HANGMAN GAME ===" << '\n';
        std::cout << "The Theme is " << m_Themes[m_ThemeIndex-1] << '\n';
        std::cout << "You have " << m_Attempts << " attempts left" << '\n';

        if(!wrongLetters.empty())
        {   
            std::cout << "Wrong Letters: ";
            for(auto& i : wrongLetters)
            {
                std::cout << i << " ";
            }

            std::cout << '\n';
        }

        std::cout << '\n';

        for(auto i = 0; i < underlineString.size(); i++)
        {
            std::cout << underlineString[i] << " ";
        }

        std::cout << '\n';

        std::cout << "Type a letter: ";
        std::cin >> strLetter;
        std::cin.ignore();

        if(std::all_of(strLetter.begin(), strLetter.end(), ::isdigit))
        {
            std::cout << "INVALID! Type a letter" << '\n';
            std::cout << "Press Enter to continue...";
            std::cin.get();
            strLetter.clear();
            Screen::clear();
            continue;
        }

        if(strLetter.length() > 1)
        {
            std::cout << "INVALID! type only a letter!" << '\n';
            std::cout << "Press Enter to continue...";
            std::cin.get();
            strLetter.clear();
            Screen::clear();
            continue;
        }

        m_Letter = strLetter[0];

        m_Letter = std::toupper(m_Letter);

        bool rightLetter {false};
        for(auto i = 0; i < m_Word.size(); i++)
        {
            if(m_Word[i] == m_Letter)
            {
                rightLetter = true;
                underlineString[i] = m_Letter;              
            }
        }

        for(auto& i : wrongLetters)
        {
            if(m_Letter == i)
            {
                std::cout << "You have already tried this letter!" << '\n';
                std::cout << "Press Enter to continue...";
                std::cin.get();
                rightLetter = true;
                strLetter.clear();
                continue;
            }
        }

        if(!rightLetter)
        {
            wrongLetters.push_back(m_Letter);
            std::cout << "Wrong letter!" << '\n';
            --m_Attempts;
            std::cout << "Press Enter to continue...";
            std::cin.get();
        }

        strLetter.clear();

        Screen::clear();

        if(underlineString == m_Word)
        {
            std::cout << "Congratulations " << m_PlayerName << " you won!" << '\n';
            break;
        }

        if(m_Attempts == 0)
        {
            std::cout << "Sorry " << m_PlayerName << " you lost" << '\n';
            std::cout << "The word was " << m_Word << '\n';
            break;
        }
    }
}

// Retorna o endereço da variavel yesOrNot
const std::string& Hangman::getYesOrNot()
{
    return m_YesOrNot;
}