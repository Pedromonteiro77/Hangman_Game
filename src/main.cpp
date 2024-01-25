#include <iostream>
#include <thread>
#include "..\header\hangman.hpp"
#include "..\header\menu.hpp"
#include "..\header\screen_clear.hpp"
#include "..\header\music.hpp"

int main()
{
    Menu objMenu;
    Hangman objHangman;
    MusicPlayer objMusicPlayer;
    
    // Thread que faz tocar musica
    std::atomic<bool> atomStop(false);
    std::thread musicThread([&objMusicPlayer, &atomStop]()
    {
        objMusicPlayer.soundtrack("modolistik.wav", atomStop);
    });

    // loop Principal do programa onde o jogo roda
    while(true)
    {
        bool itsTheFirstTime {true};

        // função que mostra o menu de opções
        objMenu.mainMenu();

        if(objMenu.getOption() == 1)
        {
            while(true)
            {   
                // Verificação que permite o jogador escolher o nome se não for a primeia vez a função 
                // não executa
                if(itsTheFirstTime)
                {
                    // Função para escolher o nome
                    objHangman.askPlayerName();
                }
                
                // Função para escolher o tema da partida
                objHangman.chooseTheme();

                // Função onde ocorre o jogo
                objHangman.game();

                std::string yesNot {objHangman.getYesOrNot()};
                objHangman.yesOrNotVerify("Do you want to play again? (Y/N): ", yesNot);

                // Verificação caso o player queira jogar outra partida 
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
            while(true)
            {
                // Função do menu de configurações
                objMenu.settingsMenu();

                // inicia a musica
                if(objMenu.getSettingsOption() == 1)
                {
                    if(atomStop)
                    {
                        atomStop.store(false);

                        if(musicThread.joinable())
                        {
                            musicThread.join();
                        }

                        musicThread = std::thread([&objMusicPlayer, &atomStop]()
                        {
                            objMusicPlayer.soundtrack("modolistik.wav", atomStop);
                        });

                        continue;
                    }

                    std::cout << "The Music already is on!" << '\n';
                    std::cout << "Press Enter to continue...";
                    std::cin.get();
                    Screen::clear();
                    continue;
                }

                // Para a musica
                else if(objMenu.getSettingsOption() == 2)
                {
                    atomStop.store(true);

                    if(musicThread.joinable())
                    {
                        musicThread.join();
                    }
                }

                // Sai do loop de configurações
                else if(objMenu.getSettingsOption() == 3)
                {
                    break;
                }
            }
        }

        else if(objMenu.getOption() == 3)
        {
            // Para a musica assim que o player sai do loop principal
            atomStop = true;

            if(musicThread.joinable())
            {
                musicThread.join();
            }

            break;
        }
    }

    return 0;
}