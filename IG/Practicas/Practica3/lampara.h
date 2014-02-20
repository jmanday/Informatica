/************************************************************

Clase para poder dibujar un objeto de tipo lampara (modelo)


Jesús García Manday
*************************************************************/
#ifndef _LAMPARA_H_
#define _LAMPARA_H_

#include "og3d.h"
#include "brazo_inferior.h"
#include <GL/glut.h>

using namespace std;

class lampara : public og3d {

    private:
        og3d lampara_base;

    public:
        lampara();
        void draw(int m, float a, float b, float c);
        void draw_vertices();
        void draw_alambres();
        void draw_liso();
        void draw_ajedrez();
};


#include "lampara.cpp"

#endif
