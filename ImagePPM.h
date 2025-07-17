/*
    CRIAÇÃO DE IMAGENS NO FORMATO PPM (P3) – VERSÃO MATRIZ 2-D

    Guardamos a imagem como um vetor de ponteiros, onde cada ponteiro
    representa uma linha:

        pixels [ linha ] → vetor de Color de tamanho = width
*/

#ifndef __IMAGEPPM
#define __IMAGEPPM

#include <string>
//#include "../Paleta/Paleta.cpp" Acessa pastas diferentes
#include "Paleta.h"

class ImagePPM {
int   width;          // número de colunas
int   height;         // número de linhas
Color **pixels;       // ponteiro para vetor de linhas (cada linha é Color*)

public:
/* CONSTRUTOR / DESTRUTOR */
ImagePPM (int width, int height);
~ImagePPM ();

/* Cópia proibida para evitar dois objetos liberando o mesmo bloco */
ImagePPM (const ImagePPM &) = delete;
ImagePPM & operator= (const ImagePPM &) = delete;

/* ACESSO A PIXELS */
void  set_pixel (int row, int col, Color color);
Color get_pixel (int row, int col) const;

// Tranforma tudo que estava na memoria em um arquivo .ppm
void save (std::string file_name) const;
};

#endif   // __IMAGEPPM
