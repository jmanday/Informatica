/************************************************************

Clase para poder dibujar un objeto de tipo brazo inferior (modelo)


Jesús García Manday
*************************************************************/
#ifndef _BRAZO_INFERIOR_H_
#define _BRAZO_INFERIOR_H_

#include "og3d.h"
#include "brazo_superior.h"
#include <GL/glut.h>

using namespace std;

class brazo_inferior : public og3d {

    private:
        og3d brazo_base;

    public:
        brazo_inferior();
        void draw(int m, float a, float b);
        void draw_vertices();
        void draw_alambres();
        void draw_liso();
        void draw_ajedrez();
};


#include "brazo_inferior.cpp"

#endif
