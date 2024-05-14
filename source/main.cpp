#include <iostream>
#include <thread>
#include "../header/hangman.hpp"
#include "../header/menu.hpp"
#include "../header/music.hpp"
#include "../header/screen_clear.hpp"

int main(int argc, char* argv[])
{
    Screen::clear();

    Menu menu;
    Hangman hangman;
    
    // Thread que faz tocar musica
    std::atomic<bool> isMusicPlaying {true};
    std::thread musicThread([&isMusicPlaying]()
    {
        soundtrack(isMusicPlaying);
    });

    // Loop Principal onde o jogo roda
    bool mainLoopIsTrue {true};
    while(mainLoopIsTrue)
    {
        bool itsTheFirstTime {true};
        bool settingsLoopIsTrue {true};

        menu.mainMenu();

        switch(menu.getOption())
        {
            case 1:
                while(true)
                {   
                    // Verificação que permite o jogador escolher o nome se não for a primeia vez a função 
                    // não executa
                    if(itsTheFirstTime)
                    {
                        // Função para escolher o nome
                        hangman.askPlayerName();
                    }
                    
                    // Função para escolher o tema da partida
                    hangman.chooseTheme();

                    // Função onde ocorre o jogo
                    hangman.game();

                    // Verificação caso o player queira jogar outra partida 
                    std::string yesNot {hangman.getYesOrNot()};
                    hangman.yesOrNotVerify("Do you want to play again? (Y/N): ", yesNot);

                    if(yesNot == "Y")
                    {
                        itsTheFirstTime = false;
                        yesNot.clear();
                        Screen::clear();
                        continue;
                    }

                    Screen::clear();

                    break;
                }
                break;

            case 2:
                while(settingsLoopIsTrue)
                {
                    // Função do menu de configurações
                    menu.settingsMenu();

                    switch(menu.getSettingsOption())
                    {   
                        // inicia a musica
                        case 1:
                            if(!isMusicPlaying)
                            {
                                isMusicPlaying = true;

                                if(musicThread.joinable())
                                {
                                    musicThread.join();
                                }

                                musicThread = std::thread([&isMusicPlaying]()
                                {
                                    soundtrack(isMusicPlaying);
                                });

                                continue;
                            }

                            std::cout << "The Music already is on!" << '\n';
                            std::cout << "Press Enter to continue...";
                            std::cin.get();
                            Screen::clear();
                            break;

                        // Para a musica
                        case 2:
                            if(isMusicPlaying)
                            {
                                isMusicPlaying = false;

                                if(musicThread.joinable())
                                {
                                    musicThread.join();
                                }

                                continue;
                            }

                            std::cout << "The Music already is off!" << '\n';
                            std::cout << "Press Enter to continue...";
                            std::cin.get();
                            Screen::clear();
                            break;
                        
                        // Sai do loop de configurações
                        case 3:
                            settingsLoopIsTrue = false;
                            break;
                    }

                    if(!settingsLoopIsTrue)
                    {
                        break;
                    }
                }
                break;
            
            case 3:
                // Para a musica e termina o Game
                isMusicPlaying = false;
                mainLoopIsTrue = false;

                if(musicThread.joinable())
                {
                    musicThread.join();
                }
                break;
        }
    }

    return 0;
}