#ifndef __PALETA
#define __PALETA
#include <string>

/// @brief Tipo que guarda inteiros R, G e B
struct Color {
    int R, G, B;
};

/// @brief Classe que guarda dados de uma paleta de cores, tamanho, matriz do tipo Cor e matriz de alturas
class Paleta {
    int size;
    Color *colors;
    int *heights;


    public:

    /// @brief Construtor com parametros
    /// @param size Tamanho da paleta
    /// @param color  Matriz de cores
    /// @param height Matriz de alturas
    Paleta (int size, Color *color, int *height );

    /// @brief Construtor padrão
    Paleta ();

    /// @brief Destrutor padrão
    ~Paleta (); //Destrutor

    /// @brief Funcão que retorna uma cor dada uma altura
    /// @param height Altura 
    /// @return 
    Color get_color_by_height (int height);

    /// @brief Função que lê dados de um arquivo e salva em uma Paleta
    /// @param arquive Nome do arquivo que será salvo
    void set_by_file (std::string arquive);
    
};

#endif