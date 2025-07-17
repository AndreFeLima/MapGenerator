#ifndef __Map
#define __Map

#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Paleta.h"
#include "ImagePPM.h"

/// @brief Classe que armazena o lado do mapa e as alturas de cada ponto

class Map {
int side;
int *heights;

public:

//CONSTRUTORES

/// @brief Construtor padrão
Map ();

///@brief Construtor com parâmetros
Map (int side);

//DESTRUTOR
/// @brief Destrutor padrão
~Map();

//FUNCOES PARA MUDANCA

/// @brief Função para definir o lado do mapa
/// @param side Valor inteiro que será o lado
void set_side(int side);



void set_map_from_archive (std::string archive);

//FUNCOES PARA PRINTAR

/// @brief Função que retorna o valor do lado do mapa
int get_side ();

/// @brief Função que retorna uma altura de uma determinada linha e coluna da matriz;
/// @param line Linha que está a altura;
/// @param column Coluna que está a altura
/// @return 
int get_height (int line, int column);

//FUNCAO DIAMOND-SQUARE 

/// @brief Função que aplica o algoritmo Diamond;
/// @param heights Matriz de alturas do mapa;
/// @param roughness Rugosidade 
/// @param d Deslocamento
/// @param map_side Lado do mapa
void diamond (int *heights, int &roughness, int d, int map_side);

/// @brief Função que aplica o algorítmo Square;
/// @param heightsMatriz de alturas do mapa;
/// @param roughness Rugosidade; 
/// @param d Deslocamento;
/// @param map_side Lado do mapa;
void square (int *heights, int &roughness, int d, int map_side);

/// @brief Função que junta as funções Diamond e Square;
/// @param roughness Rugosidade que se deseja para a geração do terreno;
void diamond_square (int roughness);


//SALVAR  MAPA EM ARQUIVO

/// @brief Função que salva o mapa em um arquivo
/// @param archive Arquivo que será salvo o mapa
void save_map (std::string archive);


/// @brief Função que faz o mapa colorido
/// @param paleta Nome do arquivo que terá a paleta
void paint (std::string paleta);

/// @brief Função que faz a sombra do mapa
/// @param image Imagem do mapa que será sombreado
/// @param heights Matriz de alturas do mapa
void darken(ImagePPM image, int heights[]);

};

#endif