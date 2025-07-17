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

    COMENTAR CADA METODOD (FUNCAO) (/** COMECAR  COM ESSE, AO INVES DE SO /*
    @param (nome do arquivo) >> EXPLICAR OQUE EH
    @return >> DIZER OQ RETORNA  

    */

#include "MapHeight.h"
#include <iostream>

int get_random(int number) {
    int limit = 2*number + 1;

    int random = (rand () % (limit));

    return random - number;
}


int map_side (int n) {
    int temp = 0;
    int num = 1;
    while (temp < n) {
        num *= 2;
        temp ++;
    } 
    return (num + 1);}

void Map::diamond (int *heights, int roughness, int d, int map_side) {

    for (int r = 0; r < map_side - d; r += d ) {
        for (int c = 0; c < map_side - d; c += d) {
            
            int p1_r, p1_c, p2_r, p2_c, p3_r, p3_c, p4_r, p4_c;
            p1_r = r;
            p1_c = c;

            p2_r = r;
            p2_c = c + d;

            p3_r = r + d;
            p3_c = c;

            p4_r = r + d;
            p4_c = c + d;

            int sum_heights = heights [map_side*p1_r + p1_c]
                            + heights [map_side*p2_r + p2_c]
                            + heights [map_side*p3_r + p3_c]
                            + heights [map_side*p4_r + p4_c];

            heights [((r + d/2)*map_side) + (c + d/2)] = (sum_heights/4) + get_random(roughness);
        }
    }
    }

void Map::square (int *heights, int roughness, int d, int map_side) {
    int temp_d = d/2;

    for (int r = 0; r < map_side; r += temp_d) {
        for (int c = (r % d == 0) ? temp_d : 0; c < map_side; c += d) {

            int pH_r, pH_c, pML_r, pML_c, pL_r, pL_c, pMR_r, pMR_c, pC_c, pC_r; // PONTO acima, esqueda, baixo e direita
            
            pH_r = r - temp_d;
            pH_c = c;

            pL_r = r + temp_d;
            pL_c = c;

            pML_r = r;
            pML_c = c - temp_d;

            pMR_r = r;
            pMR_c = c + temp_d;

            int point_H, point_ML, point_MR, point_L;

            //Verifica se algum ponto está fora da matriz:
            int out = 0;
            
            point_H = ((pH_r*map_side + pH_c < 0) || (pH_r*map_side + pH_c > (map_side*map_side - 1))) ? 0 && out++ : heights [pH_r*map_side + pH_c];
            point_ML = ((pML_r*map_side + pML_c < 0) || (pML_r*map_side + pML_c > (map_side*map_side-1))) ? 0 && out++ : heights[pML_r*map_side + pML_c];
            point_MR = ((pMR_r*map_side + pMR_c < 0) || (pMR_r*map_side + pMR_c > (map_side*map_side-1))) ? 0 && out++ : heights[pMR_r*map_side + pMR_c];
            point_L = ((pL_r*map_side + pL_c < 0) || (pL_r*map_side + pL_c > (map_side*map_side-1))) ? 0 && out++ : heights [pL_r*map_side + pL_c];


        long sum_heights = point_H + point_L + point_ML + point_MR;
            
            heights [(r)*map_side + c] = (sum_heights /(4 - out)) + get_random(roughness);


    }
}


}


//CONSTRUTORES
Map::Map () {
    this -> side = 3;
    heights = new int [ ( this -> side ) * ( this -> side )];
};             

Map::Map (int N) {
    this -> side = map_side (N);

    heights = new int [ ( this -> side ) * ( this -> side )];

    for (int i = 0; i < (this->side) * (this->side); ++i) {
        heights[i] = 1; // Inicializa todos com zero
    }

};

//DESTRUTOR
Map::~Map() {

if (heights != nullptr) { 
        delete[] heights;
        heights = nullptr;
    }
};

//FUNCOES PARA PRINTAR
int Map::get_side () {return this -> side;};
int Map::get_height (int line, int column) {return heights[line + column*( this -> side)];};


//FUNCOES PARA MUDAR VALORES

void Map::set_map_from_archive (std::string archive) {
    std::ifstream arquivo (archive);

    if (arquivo.is_open ()) {
        arquivo >> this -> side;
        arquivo >> this -> side;

        if (heights != nullptr) { 
        delete[] heights;
        heights = nullptr;
    }

    this -> heights = new int [side*side];
        
        for (int i = 0; i<(side*side); i++) {
            arquivo >> this -> heights[i];
        }
    }

}


//DIAMOND-SQUARE 
void Map::diamond_square () {

    srand(time(NULL));

    int H1, H2, H3, H4;

    H1 = get_random (1000); 

    H2 = get_random (1000);

    H3 = get_random (1000);

    H4 = get_random (1000);

    if (H1 <= 0 & H2 <= 0 & H3<=0 & H4<=0) {
        H3 = 48;

        H1 = 100;
    }

    this -> heights [0] = H1; 

    this -> heights [(side-1)] = H2;
    
    this -> heights [(side-1)*(side)] = H3;

    this -> heights [(side-1)*(side) + (side-1)] = H4;

    int d = side - 1;

    int roughness = (rand () % (600));

    while ( d > 1) {
        
        diamond (heights, roughness, d, side); 
        square (heights, roughness, d, side); 

        roughness /= 2;
        d /= 2; 
    }    



}

void Map::save_map (std::string archive) {
std::ofstream arquivo(archive);

if (arquivo.is_open()) {
    arquivo << Map::get_side () 
            << " "
            << Map::get_side ();

    for (int i = 0; i < Map::get_side ()*Map::get_side() ; i++) {
        if ((i % Map::get_side ()) == 0) { 
            arquivo << '\n';
        }
            arquivo << Map::get_height(i%Map::get_side(), i/Map::get_side()) << "  ";
    }

}
}
void Map::paint (std::string paleta) {
    ImagePPM image (side, side);
    Paleta colors;

    colors.set_by_file (paleta);

    for (int i = 0; i<(side*side); i++) {
        Color color;
        
        color = colors.get_color_by_height (heights[i]);

        image.set_pixel (i/(side), i%(side), color);

        /*
        Color pixel;
        pixel = image.get_pixel (i/(side), i%(side));
        std::cout << pixel.R <<  ' '
                << pixel.G  <<  ' '
                << pixel.B 
                << std::endl; */
    }

    image.save ("image.ppm");
}



void Map::map_image (std::string paleta) {

    for (int i = 0; i<side*side; i++) {
        
    }

}


int main () {

Map map (10); 

map.diamond_square ();

map.save_map ("Map.txt");

map.paint ("Data.txt");

}
