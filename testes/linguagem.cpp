#include <iostream>
#include <string>
#include <locale>

int main() {
    std::globa (LC_ALL, "Portuguese_Brazil");

    std::string oi;

    std::cout << "ol�, come�ar, n�o, �s, ca�ar " << std::endl;    
    
    std::cout << "digite algo: " ;
    std::getline(std::cin, oi); 

    std::cout << oi << std::endl;

    return 0;
}