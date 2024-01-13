#include <iostream>
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

void Hangman::writeThemes()
{
    themes_ = {
       "PEOPLE_NAME", "FRUITS", "COUNTRIES", "FOODS" 
    };
}

void Hangman::writePeopleName()
{
    peopleName_ = {
        "LUCY", "JILL", "STACY", "LEON", "SASHA",
        "JHON", "BELLA", "JAMES", "MAYA", "SAGE"
    };
}

void Hangman::writeFruits()
{
    fruits_ = {
        "STRAWBERRY", "JACKFRUIT", "ORANGE", "GRAPE", "WATERMELON",
        "BANANA", "MANGO", "PEAR", "RASPBERRY", "AVOCADO" 
    };
}

void Hangman::writeCountries()
{
    countries_ = {
        "FRANCE", "GERMANY", "BRAZIL", "NETHERLANDS", "JAPAN",
        "SPAIN", "CHINA", "RUSSIA", "INDIA", "SWITZERLAND"
    };
}

void Hangman::writeFoods()
{
    foods_ = {
        "PIZZA", "LASAGNA", "BARBECUE", "CURRY", "SUSHI",
        "TACOS", "BURGER", "HOTDOG", "RAMEN", "SOUP"
    };
}

void Hangman::yesOrNotVerify(const std::string & textParam, std::string & yesNotParam)
{
    while(true)
    {
        std::cout << textParam;
        std::cin >> yesNotParam;
        std::cin.ignore();

        if(!(yesNotParam == "y" || yesNotParam == "Y" || yesNotParam == "n" || yesNotParam == "N"))
        {
            std::cerr << "INVALID! Please type Y or N.";
            std::cin.get();
            Screen::clear();
            continue;
        }
        
        break;
    }
}

void Hangman::askPlayerName()
{
    while(true)
    {
        try
        {
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

void Hangman::randomWord(std::string & wordParam, std::array<std::string, 10> & arrayParam)
{
    std::random_device rand;

    std::mt19937 mt(rand());

    std::shuffle(arrayParam.begin(), arrayParam.end(), mt);

    wordParam = arrayParam[0];
}

void Hangman::chooseTheme()
{
    writeThemes();

    while(true)
    {
        try
        {
            for(auto i = 0; i < themes_.size(); i++)
            {
                std::cout << i+1 << " - " << themes_[i] << '\n';
            }

            std::cout << "Choose the number of a theme to play: ";
            std::cin >> themeIndex_;

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
            continue;
        }
    }

    switch(themeIndex_)
    {
        case 1:
            writePeopleName();
            randomWord(word_, peopleName_);
            break;
        
        case 2:
            writeFruits();
            randomWord(word_, fruits_);
            break;
        
        case 3:
            writeCountries();
            randomWord(word_, countries_);
            break;

        case 4:
            writeFoods();
            randomWord(word_, foods_);
            break;

        default:
            std::cerr << "INVALID!";
            break;
    }
}

void Hangman::game()
{
    std::string underlineString(word_.size(), '_');
    attempts_ = 5;
    std::vector<char> wrongLetters;

    std::cout << word_ << '\n';

    while(true)
    {
        std::cout << "HANGMAN GAME" << '\n';
        std::cout << "You have " << attempts_ << " attempts left" << '\n';

        if(!wrongLetters.empty())
        {   
            std::cout << "Wrong Letters: ";
            for(auto & i : wrongLetters)
            {
                std::cout << i << " ";
            }

            std::cout << '\n' << '\n';
        }

        for(auto i = 0; i < underlineString.size(); i++)
        {
            std::cout << underlineString[i] << " ";
        }

        std::cout << '\n';

        std::cout << "Type a letter: ";
        std::cin >> letter_;
        std::cin.ignore();

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

        Screen::clear();

        if(underlineString == word_)
        {
            std::cout << "Congratulations you won";
            std::cin.get();
            break;
        }

        if(attempts_ == 0)
        {
            std::cout << "You lose";
            std::cin.get();
            break;
        }
    }

    Screen::clear();
}