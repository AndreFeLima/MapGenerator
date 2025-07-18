#include "Paleta.h"
#include "ImagePPM.h"     // cabeçalho da classe
#include "MapHeight.h"
#include <iostream>

int main () {
    std::string file;

    // "Palet.txt"
    std::cout << "Digite o nome do arquivo da paleta: ";
    std::cin >> file;

    int side;
    std::cout << "\nDigite o tamanho do mapa (O mapa tera dimensoes 2^n + 1): ";
    std::cin >> side;
    
    Map map (side);

    int roughness;
    std::cout << "\nDigite a rugosidade (Recomendado: >500): ";
    std::cin >> roughness;

    map.diamond_square (roughness);

    //Map.txt
    map.paint (file);

    std::cout << "\nSeu mapa esta pronto! Abra o arquivo .PPM para vizualiza-lo";

    return 0;
}