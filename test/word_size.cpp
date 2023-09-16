#include <iostream>
#include <string>

int main() {
    int attempts = 5;
    int erros = 0;

    while(erros < attempts) {
        
    }

    while(attempts < ) {
        std::cout << "Voce Tem " << attempts << " Para Adivinhar a Palavra";
        attempts--;
    }

    // std::string word = "CASA";
    // char opc;
    // std::string palavraAdivinhada(word.size(), '_');

    // while(true) {
    //     bool encontrou = false;

    //     for(size_t i = 0; i < palavraAdivinhada.size(); i++) {
    //         std::cout << palavraAdivinhada[i] << " ";
    //     }
        
    //     std::cout << std::endl;

    //     std::cout << "Digite uma letra: ";
    //     std::cin >> opc;
    //     std::cin.ignore();

    //     opc = std::toupper(opc);

    //     std::cout << std::endl;

    //     for(size_t c = 0; c < word.size(); c++) {
    //         if(word[c] == opc) {
    //             encontrou = true;
    //             palavraAdivinhada[c] = opc;
    //         }
    //     }

    //     if(encontrou) {
    //         std::cout << "Letra encontrada!" << std::endl;
    //         std::cout << "Aperte Enter Para Continuar...";
    //         std::cin.get();
    //         std::system("cls");
    //     }
    //     else {
    //         std::cout << "Letra não encontrada" << std::endl;
    //         std::cout << "Aperte Enter Para Continuar...";
    //         std::cin.get();
    //         std::system("cls");
    //     }

    //     if(palavraAdivinhada == word) {
    //         std::cout << "Parabens Voce encontrou a palavra " << word << " (^-^)";
    //         break;
    //     }
    // }

    return 0;
}