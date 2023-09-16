#include <iostream>
#include <string>

int main() {
    std::string word = "KING";
    char opc;

    while(true) {
        bool encontrou = false;

        for(auto i = 0; i < word.size(); i++) {
            std::cout << '_' << " ";
        }

        std::cout << std::endl;

        std::cout << "Digite uma letra: ";
        std::cin >> opc;

        opc = std::toupper(opc);

        for(auto c = 0; c < word.size(); c++) {
            if(word[c] == opc) {
                word[c] = opc;
            }
        }

        if(encontrou) {
            std::cout << "Letra encontrada!" << std::endl;
            std::cout << "Aperte Enter Para Continuar...";
            std::cin.get();
            std::system("cls");
        }
        else {
            std::cout << "Letra não encontrada" << std::endl;
            std::cout << "Aperte Enter Para Continuar...";
            std::cin.get();
            std::system("cls");
        }

        if( == word) {
            std::cout << "Parabens Voce encontrou a palavra " << word << " (^-^)";
            break;
        }

        break;
    }


    return 0;
}