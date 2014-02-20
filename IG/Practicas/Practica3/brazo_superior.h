/************************************************************

Clase para poder dibujar un objeto de tipo brazo superior (modelo)


Jesús García Manday
*************************************************************/
#ifndef _BRAZO_SUPERIOR_H_
#define _BRAZO_SUPERIOR_H_

#include "og3d.h"
#include "tulipa.h"
#include <GL/glut.h>

using namespace std;

class brazo_superior : public og3d {

    private:
        og3d brazo_base;

    public:
        brazo_superior();
        void draw(int m, float a);
        void draw_vertices();
        void draw_alambres();
        void draw_liso();
        void draw_ajedrez();
};


#include "brazo_superior.cpp"

#endif
