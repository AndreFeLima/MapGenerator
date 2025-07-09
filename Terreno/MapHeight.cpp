/*
    FAZER TERRENO COM 2^n +1;

    GERAR NUMERO ALEATORIO:
    #include <cstdlib>
    #include <ctime>

    strand () -> define a sementee inicial
    rand () -> gera um numero aleatorio entre 0 e o maior inteiro possível;
    srand(time{0}); COMECAR UTILIZANDO UM VALOR QUE SEI!!

    int n1 = rand();
    int n2 = rand();

    int max, min;
    int rnd = (rand()%(max-min + 1)) + min;
    */

#include "MapHeight.h"

int map_side (int n) {return (2*n + 1);}

//CONSTRUTORES
Map::Map () {
    this -> side = 3;
    heights = new int [ ( this -> side ) * ( this -> side )];
};             

Map::Map (int N, int seed) {
    this -> side = map_side (N);

    heights = new int [ ( this -> side ) * ( this -> side )];
};

//DESTRUTOR
Map::~Map() {};

//FUNCOES PARA PRINTAR
int Map::get_side () {return this -> side;};
int Map::get_height (int line, int column) {return heights[line + column*( this -> side)];};


//DIAMOND-SQUARE 
void Map::diamond_square (int side, int roughness, int *heights) {

}

void Map::save_map (std::string archive) {

}
