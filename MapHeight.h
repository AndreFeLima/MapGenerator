#ifndef __Map
#define __Map

#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Paleta.h"
#include "ImagePPM.h"

class Map {
int side;
int seed;
int *heights;

public:

//CONSTRUTORES
Map ();             
Map (int side);

//DESTRUTOR
~Map();

//FUNCOES PARA MUDANCA
void set_side(int side);
void set_map_from_archive (std::string archive);

//FUNCOES PARA PRINTAR
int get_side ();
int get_height (int line, int column);

//FUNCAO DIAMOND-SQUARE 
void diamond (int *heights, int roughness, int d, int map_side);
void square (int *heights, int roughness, int d, int map_side);
void diamond_square ();


//SALVAR  MAPA EM ARQUIVO
void save_map (std::string archive);

void map_image (std::string paleta);

void paint (std::string paleta);

void darken(ImagePPM image, int heights[]);

};

#endif