#include <cstdlib>
#include "..\header\screen_clear.hpp"

// Limpa a tela dependendo do sistema
void Screen::clear()
{
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
}