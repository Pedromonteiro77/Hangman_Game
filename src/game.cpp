#include <iostream>
#include <vector>
#include <chrono>
#include "..\header\funcs.h"

int main() {
    auto begin = std::chrono::steady_clock::now();

    std::string name;
    std::vector<std::string> countries;
    std::vector<std::string> food;
    std::vector<std::string> animals;
    std::vector<std::string> names;
    char letra;

    std::system("cls");

    addWordsCountries(countries);
    addWordsFood(food);
    addWordsAnimals(animals);
    addWordsNames(names);

    askPlayerName(name);

    auto end = std::chrono::steady_clock::now();

    std::chrono::duration<double> time = end - begin;

    std::cout << std::endl;

    std::cout << "Tempo de execução: " << time.count();

    return 0;
}