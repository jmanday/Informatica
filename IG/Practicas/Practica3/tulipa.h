/************************************************************

Clase para poder dibujar un objeto de tipo tulipa (modelo)


Jesús García Manday
*************************************************************/
#ifndef _TULIPA_H_
#define _TULIPA_H_

#include "og3d.h"
#include <GL/glut.h>

using namespace std;

class tulipa : public og3d {

    private:
        og3d tulipa_base;

    public:
        tulipa();
        void draw(int m);
        void draw_vertices();
        void draw_alambres();
        void draw_liso();
        void draw_ajedrez();
};


#include "tulipa.cpp"

#endif
