#ifndef __PALETA
#define __PALETA

struct Color {
    int R, G, B;
};


class Paleta {
    int size;
    Color colors[100];
    int hights[100];

    public:
    Paleta () {};

    int get_size () {};
    Color get_color (int i) {};
    int get_hight (int i) {};
    int get_color_by_hight (int hight) {};
    int get_from_arquive (std::string arquive) {};
    
};








#endif