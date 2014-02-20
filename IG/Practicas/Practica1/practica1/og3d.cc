#include <og3d.h>


/********************************************************/

og3d::og3d(){}


/********************************************************/

og3d::og3d(vector<_vertex3f> &v, vector<_vertex3i> &c){

	vertices = v;
	caras = c;
}

/********************************************************/

vector<_vertex3f> & og3d::getvertices(){

	return vertices;
}

/********************************************************/

vector<_vertex3i> & og3d::getcaras(){

	return caras;
}

/********************************************************/

void og3d::setvertices(int pos, int num_vert, float f){

	if (pos%3 == 0)	
		vertices[num_vert].x = f;
	else{
		if (pos%3 == 1)
			vertices[num_vert].y = f;
		else
			vertices[num_vert].z = f;
	}
}

/********************************************************/

void og3d::setcaras(int pos, int i, int pto){

	if(pos%3 == 0)
		caras[i].x = pto;
	else{
		if(pos%3 == 1)
			caras[i].y = pto;
		else
			caras[i].z = pto;
	}
}

/********************************************************/

void og3d::resizevertices(int m){

	vertices.resize(m);
}

/********************************************************/

void og3d::resizecaras(int m){

	caras.resize(m);
}

/********************************************************/

//**************************************************************************
// Funcion para dibujar vertices
//***************************************************************************

void og3d::draw_vertices()
{
	
	glColor3f(0,1,0);
	glPointSize(2);

	glBegin(GL_POINTS);
	for(unsigned i = 0; i < vertices.size(); i++){			
		glVertex3f(vertices.at(i).x, vertices.at(i).y, vertices.at(i).z);
	}
	glEnd();
	
}

//**************************************************************************
// Funcion para dibujar alambres
//***************************************************************************

void og3d::draw_alambres(int a, int b, int c)
{
	
	glColor3f(a,b,c);
	glPointSize(2);
	int v1, v2, v3;

	glBegin(GL_LINES);
	for(unsigned i = 0; i < caras.size(); i++){
		v1 = caras.at(i).x;
		v2 = caras.at(i).y;
		v3 = caras.at(i).z;	

		
		int vert[3] = {v1, v2, v3};	
		for(int j = 0; j < 3; j++){
			if(j == 2){
				glVertex3f(vertices.at(vert[j]).x, vertices.at(vert[j]).y, vertices.at(vert[j]).z);
				glVertex3f(vertices.at(vert[j-2]).x, vertices.at(vert[j-2]).y, vertices.at(vert[j-2]).z);
			}
			else{
				glVertex3f(vertices.at(vert[j]).x, vertices.at(vert[j]).y, vertices.at(vert[j]).z);
				glVertex3f(vertices.at(vert[j+1]).x, vertices.at(vert[j+1]).y, vertices.at(vert[j+1]).z);
			}
		}
			
	}
	glEnd();
		
}

void og3d::draw_alambres2()
{
	
	glColor3f(0,1,0);
	glPointSize(2);
	int v1, v2, v3;

	glBegin(GL_LINES);
	for(unsigned i = 0; i < caras.size(); i++){
		v1 = caras.at(i).x;
		v2 = caras.at(i).y;
		v3 = caras.at(i).z;	

		
		int vert[3] = {v1, v2, v3};			
		for(int j = 0; j < 3; j++){
			if(vertices.at(vert[j]).x > 0 && vertices.at(vert[j]).x){ // solo mostramos las caras que estan en el lado positivo del eje x
				if(j == 2){
					glVertex3f(vertices.at(vert[j]).x, vertices.at(vert[j]).y, vertices.at(vert[j]).z);
					glVertex3f(vertices.at(vert[j-2]).x, vertices.at(vert[j-2]).y, vertices.at(vert[j-2]).z);
				}
				else{
					glVertex3f(vertices.at(vert[j]).x, vertices.at(vert[j]).y, vertices.at(vert[j]).z);
					glVertex3f(vertices.at(vert[j+1]).x, vertices.at(vert[j+1]).y, vertices.at(vert[j+1]).z);
				}
			}
		}
			
	}
	glEnd();
		
}

//**************************************************************************
// Funcion para dibujar caras (liso)
//***************************************************************************

void og3d::draw_caras_liso()
{
	
	glPointSize(2);
	glColor3f(0,0,1);
	int v1, v2, v3;

	glBegin(GL_TRIANGLES);
	for(unsigned i = 0; i < caras.size(); i++){
		v1 = caras.at(i).x;
		v2 = caras.at(i).y;
		v3 = caras.at(i).z;			
					
		glVertex3f(vertices.at(v1).x, vertices.at(v1).y, vertices.at(v1).z);

		glVertex3f(vertices.at(v2).x, vertices.at(v2).y, vertices.at(v2).z);

		glVertex3f(vertices.at(v3).x, vertices.at(v3).y, vertices.at(v3).z);
		
	}
	glEnd();
		
}


//**************************************************************************
// Funcion para dibujar caras (ajedrez)
//***************************************************************************
void og3d::draw_caras_ajedrez()
{
	
	glPointSize(2);
	int v1, v2, v3;

	glBegin(GL_TRIANGLES);
	for(unsigned i = 0; i < caras.size(); i++){
		if(i%2 == 0)
			glColor3f(0,0,1);
		else
			glColor3f(0.5,0.5,0.5);

		v1 = caras.at(i).x;
		v2 = caras.at(i).y;
		v3 = caras.at(i).z;	
					
		glVertex3f(vertices.at(v1).x, vertices.at(v1).y, vertices.at(v1).z);

		glVertex3f(vertices.at(v2).x, vertices.at(v2).y, vertices.at(v2).z);

		glVertex3f(vertices.at(v3).x, vertices.at(v3).y, vertices.at(v3).z);
		
	}
	glEnd();
		
}


void og3d::draw_caras_ajedrez2()
{
	
	glPointSize(2);
	int v1, v2, v3;

	glBegin(GL_TRIANGLES);
	for(unsigned i = 0; i < caras.size(); i++){
		if(i%2 == 0)
			glColor3f(0,0,1);
		else
			glColor3f(0.5,0.5,0.5);

		v1 = caras.at(i).x;
		v2 = caras.at(i).y;
		v3 = caras.at(i).z;	

		if(vertices.at(v1).x > 0 && vertices.at(v2).x && vertices.at(v3).x){	 // solo mostramos las caras que estan en el lado positivo del eje x	
					
			glVertex3f(vertices.at(v1).x, vertices.at(v1).y, vertices.at(v1).z);

			glVertex3f(vertices.at(v2).x, vertices.at(v2).y, vertices.at(v2).z);

			glVertex3f(vertices.at(v3).x, vertices.at(v3).y, vertices.at(v3).z);
		}
		
	}
	glEnd();
		
}
