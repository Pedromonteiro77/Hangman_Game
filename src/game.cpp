#include <iostream>
#include <vector>
#include "..\header\funcs.h"

int main() {
    std::vector<std::string> paises;
    std::vector<std::string> comidas;
    std::vector<std::string> animais;
    std::vector<std::string> nomes;
    char letra;

    addWordsPaises(paises);
    addWordsComidas(comidas);
    addWordsAnimais(animais);
    addWordsNomes(nomes);

    for(auto & i : nomes) {
        std::cout << i << "\n";
    }

    std::cout << "Tamanho do vector: " << nomes.size() << std::endl;

    return 0;
}