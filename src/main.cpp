#include <thread>
#include "..\header\hangman.hpp"
#include "..\header\menu.hpp"
#include "..\header\screen_clear.hpp"
#include "..\header\music.hpp"

int main()
{
    Menu objMenu;
    MusicPlayer objMusicPlayer;

    std::atomic<bool> atomStop(false);
    std::thread musicThread([&objMusicPlayer, &atomStop]()
    {
        objMusicPlayer.soundtrack("modolistik.wav", atomStop);
    });

    while(true)
    {

        objMenu.optionsMenu();

        if(objMenu.getOption() == 1)
        {
            Hangman objHangman;

            bool itsTheFirstTime {true};

            while(true)
            {   
                if(itsTheFirstTime)
                {
                    objHangman.askPlayerName();
                }

                objHangman.chooseTheme();
                objHangman.game();

                std::string yesNot {objHangman.getYesOrNot()};
                objHangman.yesOrNotVerify("Do you want to play again? (Y/N): ", yesNot);

                if(yesNot == "y" || yesNot == "Y")
                {
                    itsTheFirstTime = false;
                    yesNot.clear();
                    Screen::clear();
                    continue;
                }

                Screen::clear();

                break;
            }
        }
        else if(objMenu.getOption() == 2)
        {

        }

        else if(objMenu.getOption() == 3)
        {
            break;
        }

    }

    atomStop = true;

    if(musicThread.joinable())
    {
        musicThread.join();
    }

    return 0;
}