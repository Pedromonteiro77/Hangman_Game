#include <cstdlib>
#include "..\header\screen_clear.hpp"

// Limpa a tela dependendo do sistema
void Screen::clear()
{
    #if _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
}