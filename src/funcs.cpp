#include <iostream>
#include "..\header\funcs.h"

void addWordsPaises(std::vector<std::string> & paises) {
    paises = {
        "BRASIL", "ARGENTINA", "RUSSIA", "PERU", "MEXICO", 
        "EGITO", "UCRANIA", "UGANDA", "ESPANHA", "CHINA"
    };   
}

void addWordsComidas(std::vector<std::string> & comidas) {
    comidas = {
        "PIZZA", "HAMBURGUER", "TACOS", "FEIJOADA", "LASANHA",
        "CHURRASCO", "ESTROGONOFE", "SUSHI", "CURRY", "ACARAJE"
    };
}

void addWordsAnimais(std::vector<std::string> & animais) {
    animais = {
        "GATO", "CACHORRO", "TIGRE", "CROCODILO", "GAIVOTA",
        "JAVALI", "LEBRE", "URSO", "MORCEGO", "PANDA"
    };
}

void addWordsNomes(std::vector<std::string> & nomes) {
    nomes = {
        "JULIA", "MARIA", "CARLOS", "GABRIEL", "SOPHIA",
        "BRUNO", "MIGUEL", "ARTHUR", "HELENA", "LAURA"
    };
}
