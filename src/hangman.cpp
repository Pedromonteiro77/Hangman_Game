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
:   themes_({}),
    peopleName_({}),
    fruits_({}),
    countries_({}),
    foods_({}),
    playerName_(""),
    yesOrNot_(""),
    word_(""),
    themeIndex_(0),
    letter_('Y'),
    attempts_(0)
{}

// Função que atribui strings para o array
void Hangman::writeThemes()
{
    themes_ = {
       "PEOPLE_NAME", "FRUITS", "COUNTRIES", "FOODS" 
    };
}

// Função que atribui strings para o array
void Hangman::writePeopleName()
{
    peopleName_ = {
        "LUCY", "JILL", "STACY", "LEON", "SASHA",
        "JHON", "BELLA", "JAMES", "MAYA", "SAGE"
    };
}

// Função que atribui strings para o array
void Hangman::writeFruits()
{
    fruits_ = {
        "STRAWBERRY", "JACKFRUIT", "ORANGE", "GRAPE", "WATERMELON",
        "BANANA", "MANGO", "PEAR", "RASPBERRY", "AVOCADO" 
    };
}

// Função que atribui strings para o array
void Hangman::writeCountries()
{
    countries_ = {
        "FRANCE", "GERMANY", "BRAZIL", "NETHERLANDS", "JAPAN",
        "SPAIN", "CHINA", "RUSSIA", "INDIA", "SWITZERLAND"
    };
}

// Função que atribui strings para o array
void Hangman::writeFoods()
{
    foods_ = {
        "PIZZA", "LASAGNA", "BARBECUE", "CURRY", "SUSHI",
        "TACOS", "BURGER", "HOTDOG", "RAMEN", "SOUP"
    };
}

// Função para não ter que ficar repetindo a verificação
void Hangman::yesOrNotVerify(const std::string & textParam, std::string & yesNotParam)
{
    while(true)
    {
        std::cout << textParam;
        std::getline(std::cin, yesNotParam);

        if(!(yesNotParam == "y" || yesNotParam == "Y" || yesNotParam == "n" || yesNotParam == "N"))
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
            std::getline(std::cin, playerName_);

            if(playerName_.empty())
            {
                throw std::invalid_argument("INVALID! Don't leave the field empty.");
            }

            yesOrNotVerify("Your name is " + playerName_ + " do you confirm? (Y/N): ", yesOrNot_);

            if(yesOrNot_ == "y" || yesOrNot_ == "Y")
            {
                Screen::clear();
                yesOrNot_.clear();
                break;
            }

            Screen::clear();
        }

        catch(const std::invalid_argument & e)
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
void Hangman::randomWord(std::string & wordParam, std::array<std::string, 10> & arrayParam)
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
            for(auto i = 0; i < themes_.size(); i++)
            {
                std::cout << i+1 << " - " << themes_[i] << '\n';
            }

            std::cout << "Choose the number of a theme to play: ";
            std::getline(std::cin, strThemeIndex);

            if(!std::all_of(strThemeIndex.begin(), strThemeIndex.end(), ::isdigit))
            {
                throw std::invalid_argument("INVALID! Type a number.");
            }

            themeIndex_ = std::stoi(strThemeIndex);

            if(themeIndex_ < 1 || themeIndex_ > 4)
            {
                throw std::invalid_argument("INVALID! Choose one of the themes.");
            }

            yesOrNotVerify("The Theme is " + themes_[themeIndex_-1] + " are you sure? (Y/N): ", yesOrNot_);

            if(yesOrNot_ == "y" || yesOrNot_ == "Y")
            {
                Screen::clear();
                yesOrNot_.clear();
                break;
            }

            Screen::clear();
        }

        catch(const std::invalid_argument & e)
        {
            std::cerr << e.what() << '\n';
            std::cout << "Press Enter to continue...";
            std::cin.get();
            Screen::clear();
            strThemeIndex.clear();
            continue;
        }
    }

    if(themeIndex_ == 1)
    {
        writePeopleName();
        randomWord(word_, peopleName_);
    }

    else if(themeIndex_ == 2)
    {
        writeFruits();
        randomWord(word_, fruits_);
    }
    else if(themeIndex_ == 3)
    {
        writeCountries();
        randomWord(word_, countries_);
    }

    else if(themeIndex_ == 4)
    {
        writeFoods();
        randomWord(word_, foods_);
    }
}

// Função onde ocorre o game
void Hangman::game()
{
    std::string underlineString(word_.size(), '_');
    std::string strLetter;
    attempts_ = 5;
    std::vector<char> wrongLetters;

    while(true)
    {
        std::cout << "=== HANGMAN GAME ===" << '\n';
        std::cout << "The Theme is " << themes_[themeIndex_-1] << '\n';
        std::cout << "You have " << attempts_ << " attempts left" << '\n';

        if(!wrongLetters.empty())
        {   
            std::cout << "Wrong Letters: ";
            for(auto & i : wrongLetters)
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

        letter_ = strLetter[0];

        letter_ = std::toupper(letter_);

        bool rightLetter {false};
        for(auto i = 0; i < word_.size(); i++)
        {
            if(word_[i] == letter_)
            {
                rightLetter = true;
                underlineString[i] = letter_;              
            }
        }

        for(auto & i : wrongLetters)
        {
            if(letter_ == i)
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
            wrongLetters.push_back(letter_);
            std::cout << "Wrong letter!" << '\n';
            --attempts_;
            std::cout << "Press Enter to continue...";
            std::cin.get();
        }

        strLetter.clear();

        Screen::clear();

        if(underlineString == word_)
        {
            std::cout << "Congratulations " << playerName_ << " you won!" << '\n';
            break;
        }

        if(attempts_ == 0)
        {
            std::cout << "Sorry " << playerName_ << " you lost" << '\n';
            std::cout << "The word was " << word_ << '\n';
            break;
        }
    }
}

// Pega a variavel yesOrNot
std::string Hangman::getYesOrNot()
{
    return yesOrNot_;
}