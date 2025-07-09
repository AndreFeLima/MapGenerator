/*
    FAZER TERRENO COM 2^n +1;

    GERAR NUMERO ALEATORIO:
    #include <cstdlib>
    #include <ctime>

    strand () -> define a sementre inicial
    rand () -> gera um numero aleatorio entre 0 e o maior inteiro possível;
    srand(time{0}); COMECAR UTILIZANDO UM VALOR QUE SEI!!

    int n1 = rand();
    int n2 = rand();

    int max, min;
    int rnd = (rand()%(max-min + 1)) + min;
    */

#ifndef __Map
#define __Map

#include <string>

class Map {
int side;
int seed;
int *heights;

public:

//CONSTRUTORES
Map ();             
Map (int side, int seed);

//DESTRUTOR
~Map();

//FUNCOES PARA MUDANCA
void set_width_length(int width, int lenght);
void set_heights ( int heights[]);

//FUNCOES PARA PRINTAR
int get_side ();
int get_height (int line, int column);

//FUNCAO DIAMOND-SQUARE 
void diamond_square (int side, int roughness, int *heights);


//SALVAR  MAPA EM ARQUIVO
void save_map (std::string archive);

};

#endif