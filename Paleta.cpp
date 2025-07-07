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


struct Color {
    int R;
    int G;
    int B;
};


class Paleta {
    int size;
    Color colors[100];
    int hights[100]; //Cada altura estará relacionada com uma cor

    public:
    Paleta (int size, const Color color[100], const int hight [100] = {0}){
        this -> size = size;
        for (int i = 0; i<size; i++) {
            this -> colors[i] = color[i];
            this -> hights[i] = hight[i];
        }
    }
    
    Paleta () {
        size = 1;
        colors [0] = {0,0,0};
        hights [0] = 0; 
    }

    int get_size () {return size;}

    Color get_color (int i) {return colors[i];}

    Color get_color_by_hight (int hight) {
        for (int i = 0; i<size; i++) {
            if (this -> hights[i] == hight) {return colors[i];}
        }}

    int get_hight (int i) {return hights[i];}

    void set_size (int size) {this -> size = size;}

    void set_color (Color color, int i) { this -> colors[i] = color;}

    void set_hight (int i, int hight) { this -> hights[i] = hight;}

    // PARA ARQUIVOS

    void get_from_arq () {
        std::ifstream arquivo ("Data.txt");
        if (arquivo.is_open()) {
            arquivo >> this -> size;
            
            for (int i = 0; i<size; i++) {
                arquivo >> this -> hights[i]
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

};  

int main () { 

Color colors[] = {
    {255, 0, 0},
    {0,255, 0}
};
int hight[] = { 0, 10 };


Paleta cores {
 2, // quantidade de cores
 colors, // cores
 hight // valores associados às cores de mesmo índice
};

Paleta coresArq;

int i = 0;
coresArq.get_from_arq();

std::cout << coresArq.get_size () << std::endl;


for (int i = 0; i<coresArq.get_size(); i++){
    std::cout << coresArq.get_hight(i) << ' ';

    Color cor = coresArq.get_color(i);
    std::cout << cor.R << ' '
              << cor.G << ' '
              << cor.B;

    

}

return 0;
}