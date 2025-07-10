#include "ImagePPM.h"     // cabeçalho da classe

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