/// @file ImagePPM.h
/// @brief Cria imagens no formato PPM (P3) utilizando matriz 2D de pixels.

#ifndef __IMAGEPPM
#define __IMAGEPPM

#include <string>
//#include "../Paleta/Paleta.cpp" Acessa pastas diferentes
#include "Paleta.h"

/// @class ImagePPM
/// @brief Gerencia uma imagem PPM em memória e fornece funções para manipulação e gravação em disco.
class ImagePPM {
    int   width;          ///< Número de colunas (largura da imagem)
    int   height;         ///< Número de linhas (altura da imagem)
    Color **pixels;       ///< Matriz dinâmica de pixels [linha][coluna]

public:
    /**
     * @brief Construtor que inicializa a imagem com dimensões especificadas.
     * @param width Largura da imagem em pixels (número de colunas).
     * @param height Altura da imagem em pixels (número de linhas).
     * @throws std::invalid_argument Se width ou height forem menores ou iguais a zero.
     */
    ImagePPM(int width, int height);

    /**
     * @brief Destrutor que libera a memória alocada para os pixels.
     */
    ~ImagePPM();

/* Cópia proibida para evitar dois objetos liberando o mesmo bloco */
ImagePPM (const ImagePPM &) = delete;
ImagePPM & operator= (const ImagePPM &) = delete;

/* ACESSO A PIXELS */
void  set_pixel (int row, int col, Color color);
Color get_pixel (int row, int col) const;

    /**
     * @brief Retorna a largura da imagem.
     * @return Número de colunas.
     */
    int get_width() const { return width; }

    /**
     * @brief Retorna a altura da imagem.
     * @return Número de linhas.
     */
    int get_height() const { return height; }

    /**
     * @brief Salva a imagem em disco no formato PPM ASCII (P3).
     * @param file_name Caminho e nome do arquivo de saída.
     * @throws std::runtime_error Se não for possível abrir o arquivo.
     */
    void save(std::string file_name) const;
};

#endif // __IMAGEPPM