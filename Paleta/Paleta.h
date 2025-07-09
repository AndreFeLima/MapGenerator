#ifndef __PALETA
#define __PALETA
#include <string>

struct Color {
    int R, G, B;
};


class Paleta {
    int size;
    Color *colors;
    int *heights;


    public:
    Paleta (int size, Color color[100], int height [100] = {0});
    Paleta ();
    ~Paleta (); //Destrutor

    Color get_color_by_height (int height);

    void set_by_archive (std::string arquive);
    
};









#endif