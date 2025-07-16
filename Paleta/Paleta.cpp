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



Paleta::Paleta (int size, Color color[100],int height [100] = {0}){
        this -> size = size;
        this -> colors = new Color [ this -> size];  
        this -> heights = new int [ this -> size];

        for (int i = 0; i<size; i++) {
            this -> colors[i] = color[i];
            this -> heights[i] = height[i];
        }
    }
    
Paleta::Paleta () {
        size = 1;
        colors = new Color [ this -> size];
        colors [0] = {0,0,0};
        heights = new int [ this -> size];
        heights [0] = 0; 
    }



Color Paleta::get_color_by_height (int height) {
        for (int i = 0; i<size; i++) {
            if ( this -> heights[i] <= height && this -> heights[i + 1] > height) {return this -> colors[i];}
            else {return this -> colors[i+1];}
        }}


    // PARA ARQUIVOS

void Paleta::set_by_archive (std::string archive) {
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