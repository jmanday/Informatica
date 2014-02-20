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
	glPointSize(7);

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
	vector<_vertex3i> vaux, vaux2;

	glBegin(GL_TRIANGLES);
	for(unsigned i = 0; i < caras.size(); i++){
		if(i%1 == 0)
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

/********************************************************/

void og3d::crear_revolucion(int n, int num_grados){
		
		int tama = 0, m, h, h2, cont = 0, cont_aux = 0, tam_perfil2 = vertices.size();
		_vertex3f vaux;
		_vertex3i vaux2, vaux3;
		vector<_vertex3f> v;
		vector<int> vcar;


		/* Creamos todos los vertices */	
		for(int i = 0; i < n-1; i++){
			for(int j = tama; j < vertices.size(); j++){	
				if((vertices[j].x != 0) && ((j > 0) || (j < tam_perfil2 - 1))){	
					vaux.x = (vertices[j].x * cos((((2*PI)*num_grados)/360)/(float)n)) + (vertices[j].z * sin((((2*PI)*num_grados)/360)/(float)n));
					vaux.y = vertices[j].y;
					vaux.z = (-vertices[j].x * sin((((2*PI)*num_grados)/360)/(float)n)) + (vertices[j].z * cos((((2*PI)*num_grados)/360)/(float)n));
					
					v.push_back(vaux);
					cont++;
					
				}	
				else
					vcar.push_back(j);							
			}				
			
			for(int c = 0; c < v.size(); c++)
				vertices.push_back(v[c]);		
			
			v.clear();	
			tama = (vertices.size() - cont);
			cont = 0;	
	
		}

		cout << vertices.size() << endl;
					
		/* Creamos las caras */
		int tam_vert = vertices.size();
		int tam_perfil = tam_perfil2 - vcar.size(); /* tamaño del perfil quitando los puntos superior e inferior */
		int s3 = 0;

		if(vcar.size() > 0){
			if(vcar[0] == 0)
				s3 = 1;
		}

		caras.clear(); //para eliminar la que puse en el fichero ply para que me lo pudiera leer	
		
		for(int d = 0; d < tam_perfil - 1; d++){
			for(int s = 0, aux = 0; s < n - 1; s++){
				vaux2.x = s3 % tam_vert;	
				
				if(s == 0){
					if((vcar.size() == 2) || ((vcar.size() > 0) && (vcar[0] == tam_perfil)))
						vaux2.y = (vaux2.x + tam_perfil + 1) % tam_vert;
					else
						vaux2.y = (vaux2.x + tam_perfil) % tam_vert;
				}
				else
					vaux2.y = (vaux2.x + tam_perfil) % tam_vert;	
	
				vaux2.z = (vaux2.y + 1) % tam_vert;
				
				caras.push_back(vaux2); //primer triangulo

				vaux3.x = vaux2.x;
				vaux3.y = vaux2.z;
				vaux3.z = s3 + 1;
				
				caras.push_back(vaux3); //segundo triangulo

				s3 = vaux2.y;
			}
		}
		

		/* Completamos las caras uniendo la primera y la ultima si el giro es de 360º */
		if((num_grados == 360) && (tam_perfil > 1)){
			vaux2.x = vaux2.x + tam_perfil;
			if((vcar.size() > 0) && (vcar[0] == 0)){
				vaux2.y = (vaux2.y + tam_perfil + 1)%tam_vert;
				vaux2.z = (vaux2.z + tam_perfil + 1)%tam_vert;
			}
			else{
				vaux2.y = (vaux2.y + tam_perfil)%tam_vert;
				vaux2.z = (vaux2.z + tam_perfil)%tam_vert;
			}
			
			caras.push_back(vaux2);

			vaux3.x = (vaux3.x + tam_perfil)%tam_vert;
			if((vcar.size() > 0) && (vcar[0] == 0))
				vaux3.y = (vaux3.y + tam_perfil + 1)%tam_vert;
			else
				vaux3.y = (vaux3.y + tam_perfil)%tam_vert;
			vaux3.z = (vaux3.z + tam_perfil)%tam_vert;

			caras.push_back(vaux3);
		}
			


		/* Creamos las tapas */
		int tam_perfil3 = tam_perfil + vcar.size(); /* puntos del primer perfil incluyendo los de la tapa */
		
		for(int l = 0, l3 = 0, l2 = 1; l < n - 1; l++, l3++, l2++){
			if(vcar.size() > 0){				
				vaux2.x = 0;				
				vaux2.y = (tam_perfil3 + (tam_perfil * l3)) % tam_vert;	
			
				if(l == 0)
					vaux2.z = ((vaux2.y - (tam_perfil3 - 1) + tam_vert)) % tam_vert;
				else
					vaux2.z = (vaux2.y - tam_perfil) % tam_vert;				

				vaux3.x = tam_perfil3 - 1;		
				vaux3.y = (vaux3.x + (tam_perfil * l2)) % tam_vert;

				if(l == 0)
					vaux3.z = vaux3.x - 1;
				else
					vaux3.z = vaux3.y - tam_perfil;

				if(vcar.size() == 2){
					caras.push_back(vaux2);
					caras.push_back(vaux3);	
				}
				else{
					if(vcar[0] == 0)
						caras.push_back(vaux2);
					else
						caras.push_back(vaux3);
				}
			}					
		}

		/* Completamos las tapas uniendo la primera y la ultima si el giro es de 360º */
		if(num_grados == 360){
			if(vcar.size() == 1){
				if(vcar[0] == 0){
					vaux2.x = vcar[0];
					vaux2.y = vaux2.x + 1;
					vaux2.z = tam_vert - tam_perfil;

					caras.push_back(vaux2);
				}	
				else{
					vaux2.x = tam_perfil2 - 1;
					vaux2.y = vaux2.x - 1;
					vaux2.z = tam_vert - 1;

					caras.push_back(vaux2);
				}			
			}
			else{
				if(vcar.size() == 2){
					vaux2.x = vcar[0];
					vaux2.y = tam_vert - tam_perfil;
					vaux2.z = vaux2.x + 1;

					caras.push_back(vaux2);

					if(tam_perfil == 1){
						vaux2.x = tam_perfil2 - tam_perfil;
						vaux2.y = tam_vert - tam_perfil;
						vaux2.z = vaux2.x - 1;

						caras.push_back(vaux2);
					}
					else{
						vaux3.x = tam_perfil2 - 1;
						vaux3.y = tam_vert - 1;
						vaux3.z = vaux3.x - 1;

						caras.push_back(vaux3);
					}
				}
			}			
		}
		
		cout << endl << caras.size() << endl;
}

/********************************************************/

void og3d::vector_normal_caras(){

		_vertex3f p0, p1, p2, vA, vB;	
		struct normal v;

		for(int m = 0; m < caras.size(); m++){
			v.px = caras[m].x;
			v.py = caras[m].y;
			v.pz = caras[m].z;
			
			p0 = vertices[caras[m].x];
			p1 = vertices[caras[m].y];
			p2 = vertices[caras[m].z]; 

			vA.x = p1.x - p0.x;
			vA.y = p1.y - p0.y;
			vA.z = p1.z - p0.z;

			vB.x = p2.x - p0.x;
			vB.y = p2.y - p0.y;
			vB.z = p2.z - p0.z;

			//cálculo del producto vectorial entre vA y vB
			v.normal_cara.x = (vA.y*vB.z) - (vB.y*vA.z);
			v.normal_cara.y = - ((vA.x*vB.z) - (vB.x*vA.z));
			v.normal_cara.z = (vA.x*vB.y) - (vB.x*vA.y);			

			normales_caras.push_back(v);

		}
}


/********************************************************/

void og3d::vector_normal_puntos(){

		int cont = 0;
		_vertex3f aux;
		
		for(int m = 0; m < vertices.size(); m++){
			for(int n = 0; n < normales_caras.size(); n++){
				if((m == normales_caras[n].px) || (m == normales_caras[n].py) || (m == normales_caras[n].pz)){
					aux.x += normales_caras[n].normal_cara.x;
					aux.y += normales_caras[n].normal_cara.y;
					aux.z += normales_caras[n].normal_cara.z;

					cont++;
				}
			}

			aux.x = aux.x/cont;
			aux.y = aux.y/cont;
			aux.z = aux.z/cont;

			normales_puntos.push_back(aux);

			cont = 0;
			aux.x = aux.y = aux.z = 0.0;
			
		}
}
			

