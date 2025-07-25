/*
ESTUDO DAS CORES: 
> Neve (2501 - +INFINITO): 255,255,255 (Ideia)
> Montanha (1000 - 2500) : 100,100,100
> Grama (10 - 999): 12,138,49
> Areia (1-9): 245, 207, 138;
> Agua (-INFINITO - 0): 80, 140, 255
*/

#include <iostream>
#include <fstream> 
#include "Paleta.h"



Paleta::Paleta (int size, Color *color, int *height){
        this -> size = size;
        this -> colors = new Color [ this -> size];  
        this -> heights = new int [ this -> size];

        for (int i = 0; i<size; i++) {
            this -> colors[i] = color[i];
            this -> heights[i] = height[i];
        }
    }
    
Paleta::Paleta () {
        size = 100;
        colors = new Color [ this -> size];
        heights = new int [ this -> size];

    }

Paleta::~Paleta () {
    delete[] this->colors;
    delete[] this->heights;

    this->colors = nullptr;
    this->heights = nullptr;
}

Color Paleta::get_color_by_height (int height) {
        for (int i = 0; i< (size-1) ; i++) {
            if ( this -> heights[i] <= height && this -> heights[i + 1] > height) {return this -> colors[i];}

        }

        if (size > 0 && height >= this->heights[size - 1]) {
        return this->colors[size - 1];
    }
    
        return colors[0];
    }


    // PARA ARQUIVOS

void Paleta::set_by_file (std::string archive) {
    std::ifstream arquivo (archive);
     if (arquivo.is_open()) {
        arquivo >> this -> size;
            
        for (int i = 0; i<size; i++) {
            arquivo >> this -> heights[i]
                    >> this -> colors[i].R 
                    >> this -> colors[i].G 
                    >> this -> colors[i].B;            
            }
        }
    else {
        std::cout << "Erro ao abrir arquivo.";
    }

        arquivo.close();
    }