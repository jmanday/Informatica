/************************************************************

Clase para poder dibujar cualquier tipo de objeto (modelo)


Jesús García Manday
*************************************************************/
#ifndef _OG3D_H_
#define _OG3D_H_
#define PI 3.14159265

#include <vector>
#include <set>
#include <cmath>
#include "vertex.h"

struct normal{
    int px, py, pz; /* para almacenar los puntos que corresponden a la cara a la que se le calcula la normal */
    _vertex3f normal_cara; /* para almacenar las coordenadas del vector de la normal */
};


using namespace std;

class og3d{

    private:
        vector<_vertex3f> vertices;
        vector<_vertex3i> caras;
        vector<struct normal> normales_caras;
        vector<_vertex3f> normales_vertices;
        vector<_vertex2f> texturas;
        int tam_perfil;

    public:

        og3d();
        og3d(vector<_vertex3f> &v, vector<_vertex3i> &c);
        vector<_vertex3f> & getvertices();
        vector<_vertex3i> & getcaras();
        void setvertices(int pos, int num_vert, float f);
        void setcaras(int p, int i, int c);
        void resizevertices(int m);
        void resizecaras(int m);
        void draw_en_vertices();
        void draw_en_alambres(int a, int b, int c);
        void draw_en_alambres2();
        void draw_caras_liso();
        void draw_caras_ajedrez();
        void draw_caras_ajedrez2();
        void crear_revolucion(int n, int num_grados);
        void vector_normal_caras();
        void vector_normal_vertices();
        void asignar_textura(int n);
        void draw_con_textura_sin_iluminacion();
        void draw_con_textura_con_iluminacion(int mods);
        void draw_sin_textura_sin_iluminacion();
        void draw_sin_textura_con_iluminacion(int mods);

};

#include "og3d.cpp"

#endif
