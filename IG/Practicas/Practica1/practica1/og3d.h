/************************************************************

Clase para poder dibujar cualquier tipo de objeto (modelo)


Jesús García Manday
*************************************************************/
#ifndef _OG3D_H_
#define _OG3D_H_

#include <vector>
#include "vertex.h"

using namespace std;

class og3d{
	
	private:
		vector<_vertex3f> vertices;
		vector<_vertex3i> caras;

	public:

		og3d();
		og3d(vector<_vertex3f> &v, vector<_vertex3i> &c);
		vector<_vertex3f> & getvertices();
		vector<_vertex3i> & getcaras();
		void setvertices(int pos, int num_vert, float f);
		void setcaras(int p, int i, int c);
		void resizevertices(int m);
		void resizecaras(int m);
		void draw_cube();
		void draw_vertices();
		void draw_alambres(int a, int b, int c);
		void draw_alambres2();
		void draw_caras_liso();
		void draw_caras_ajedrez();
		void draw_caras_ajedrez2();

};

#include "og3d.cc"

#endif
