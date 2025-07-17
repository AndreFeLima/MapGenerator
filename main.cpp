#include "Paleta.h"
#include "ImagePPM.h"     // cabeçalho da classe
#include "MapHeight.h"

void Map::paint (std::string paleta) { //LEMBRAR DE TIRAR 
    ImagePPM image (side, side);
    Paleta colors;

    colors.set_by_file (paleta);

    for (int i = 0; i<(side*side); i++) {
        Color color;
        
        color = colors.get_color_by_height (heights[i]);

        image.set_pixel (i/(side*side), i%(side*side), color);
    }

    image.save ("image.ppm");
}

void Map::darken( ImagePPM image, int hights[]) {
    for (int i = 0; i<side; i++) {
        for (int i = 0; i<side/2; i++) {


        }
    }

}



int main () {

    /* 1. cria imagem 2x1 */
    ImagePPM img ( 2 , 1 );

    /* 2. define cores dos dois pixels */
    img.set_pixel ( 0 , 0 , { 255 , 0   , 0   } );   // vermelho
    img.set_pixel ( 0 , 1 , { 0   , 255 , 0   } );   // verde

    /* 3. grava no arquivo teste.ppm */
    img.save ( "teste.ppm" );

    return 0;
}