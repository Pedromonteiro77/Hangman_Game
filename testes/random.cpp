#include <iostream>
#include <string>
#include <algorithm>
#include <random>

int main() {
    std::vector<std::string> countries {
        "BRASIL", "ARGENTINA", "RUSSIA", "PERU", "MEXICO", 
        "EGITO", "UCRANIA", "UGANDA", "ESPANHA", "CHINA"
    };

    std::random_device aleatorio;

    std::mt19937 chosealeatorio(aleatorio());

    std::shuffle(countries.begin(), countries.end(), chosealeatorio);

    std::string palavraAleatoria = countries[0];

    std::cout << palavraAleatoria;


    return 0;
}   