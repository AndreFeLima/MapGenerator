#include "ImagePPM.h"
#include <fstream>
#include <stdexcept>

ImagePPM::ImagePPM (int width, int height) {
    this -> width  = width;
    this -> height = height;

    if (this -> width <= 0 || this -> height <= 0) {
        throw std::invalid_argument ("Dimensões inválidas."); // se a imagem for 0 x 0
    }

    /* 1. aloca vetor de ponteiros (uma entrada por linha)    */
    pixels = new Color * [ this -> height ];

    /* 2. para cada linha, aloca vetor de Colors (colunas)     */
    for (int row = 0; row < this -> height; row++) {
        pixels [ row ] = new Color [ this -> width ];
        /* inicializa cada coluna da linha em preto            */
        for (int col = 0; col < this -> width; col++) {
            pixels [ row ][ col ] = {0, 0, 0};
        }
    }
}

ImagePPM::~ImagePPM () {
    /* libera cada linha individualmente                      */
    for (int row = 0; row < this -> height; row++) {
        delete [] pixels [ row ];
    }
    /* libera o vetor de ponteiros                            */
    delete [] pixels;
}

void ImagePPM::set_pixel (int row, int col, Color color) {
    if (row < 0 || row >= this -> height) { return; }
    if (col < 0 || col >= this -> width ) { return; }
    pixels [ row ][ col ] = color;
}

Color ImagePPM::get_pixel (int row, int col) const {
    if (row < 0 || row >= this -> height) { return {0,0,0}; }
    if (col < 0 || col >= this -> width ) { return {0,0,0}; }
    return pixels [ row ][ col ];
}

void ImagePPM::save (std::string file_name) const {
    std::ofstream file (file_name);
    if (!file.is_open()) {
        throw std::runtime_error ("Não foi possível abrir arquivo.");
    }

    /* Cabeçalho PPM */
    file << "P3\n";
    file << this -> width << " " << this -> height << "\n";
    file << 255 << "\n";

    /* Dados dos pixels em ordem de linhas e colunas           */
    for (int row = 0; row < this -> height; row++) {
        for (int col = 0; col < this -> width; col++) {
            Color c = pixels [ row ][ col ];
            file << c.R << " " << c.G << " " << c.B << " ";
        }
        file << "\n";
    }

    file.close();
}
