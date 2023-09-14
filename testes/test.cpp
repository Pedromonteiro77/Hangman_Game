#include <iostream>
#include <string>

int main() {    
    std::string algo;

    std::cout << "Digite algo: ";
    std::cin >> algo;

    for(auto & i : algo) {
        i = std::toupper(i);
    }

    std::cout << algo;

}