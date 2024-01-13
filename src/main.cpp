#include "..\header\hangman.hpp"
#include "..\header\menu.hpp"

int main()
{
    Menu objMenu;
    Hangman objHangman;
    bool itsTheFirstTime {true};

    while(true)
    {
        objMenu.optionsMenu();

        if(objMenu.getOption() == 1)
        {
            // if(itsTheFirstTime)
            // {
            //     objHangman.askPlayerName();
            // }

            objHangman.chooseTheme();
            objHangman.game();
        }

        else if(objMenu.getOption() == 2)
        {

        }

        else if(objMenu.getOption() == 3)
        {
            break;
        }
    }

    return 0;
}