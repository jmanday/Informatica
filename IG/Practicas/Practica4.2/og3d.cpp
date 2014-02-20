
#include "og3d.h"


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

void og3d::draw_en_vertices()
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

void og3d::draw_en_alambres(int a, int b, int c)
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

/********************************************************/

void og3d::draw_en_alambres2()
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

        int tama = 0;
        tam_perfil = vertices.size();
        _vertex3f vaux;
        _vertex3i vaux2, vaux3;
        vector<_vertex3f> v;
        set<int>::iterator ret;
	set<int> pto_eje_revol;


        /* Creamos todos los vertices */
        for(int i = 0; i < n; i++){
            for(int j = tama; j < (int)vertices.size(); j++){
		if((vertices[j].x == 0.0) && (j < tam_perfil))
		  pto_eje_revol.insert(j);
		
                vaux.x = (vertices[j].x * cos((((2*PI)*num_grados)/360)/(float)n)) + (vertices[j].z * sin((((2*PI)*num_grados)/360)/(float)n));
                vaux.y = vertices[j].y;
                vaux.z = (-vertices[j].x * sin((((2*PI)*num_grados)/360)/(float)n)) + (vertices[j].z * cos((((2*PI)*num_grados)/360)/(float)n));

                v.push_back(vaux);
                tama++;
            }

            for(int c = 0; c < (int)v.size(); c++)
                vertices.push_back(v[c]);

            v.clear();

        }


        /* Creamos todas las caras */
        caras.clear();
        int tam_perfil2 = (int)vertices.size();

        for(int i = 0; i < tam_perfil - 1; i++){
            for(int j = 0; j <= n; j++){
                vaux2.x = (j * tam_perfil) + i;
                vaux2.y = vaux2.x + 1;
                vaux2.z = (vaux2.y + tam_perfil) % tam_perfil2;

		/* para evitar triangulos degenerados */
        ret = pto_eje_revol.find(vaux2.y % tam_perfil);
		if(ret == pto_eje_revol.end())
		  caras.push_back(vaux2);

                vaux3.x = vaux2.z;
                vaux3.y = vaux3.x - 1;
                vaux3.z = vaux2.x;

		/* para evitar triangulos degenerados */
        ret = pto_eje_revol.find(vaux3.z % tam_perfil);
		if(ret == pto_eje_revol.end())
		  caras.push_back(vaux3);
            }

        }
        
}

/********************************************************/

void og3d::vector_normal_caras(){

    _vertex3f p0, p1, p2, vA, vB, aux;
    struct normal v;
    double modulo;
	
	normales_caras.clear();

    for(int m = 0; m < (int)caras.size(); m++){
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
        aux.x = (vA.y*vB.z) - (vA.z*vB.y);
        aux.y = - ((vA.x*vB.z) - (vA.z*vB.x));
        aux.z = (vA.x*vB.y) - (vA.y*vB.x);

        //normalizo los calculos
        modulo = sqrt(pow((aux.x),2) + pow((aux.y),2) + pow((aux.z),2));
        v.normal_cara.x = aux.x / modulo;
        v.normal_cara.y = aux.y / modulo;
        v.normal_cara.z = aux.z / modulo;

        normales_caras.push_back(v);

    }

}


/********************************************************/

void og3d::vector_normal_vertices(){

    int cont = 0;
    _vertex3f aux;
	
	normales_vertices.clear();

    for(int m = 0; m < (int)vertices.size(); m++){
        for(int n = 0; n < (int)normales_caras.size(); n++){
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

        normales_vertices.push_back(aux);

        cont = 0;
        aux.x = aux.y = aux.z = 0.0;

    }
}


/*********************************************************/

void og3d::asignar_textura(int num){
    float aux_cv = 0.0, aux_cu = 0.0, distancia;
    _vertex2f text_aux;
    int pto = 0;    
    vector<float> aux_distancia;
    texturas.clear();
    
    for(int n = 0; n < vertices.size(); n += tam_perfil){
      for(int m = 0; m < tam_perfil; m++, pto++){
	if(m == 0){
	  text_aux.x = aux_cu;
	  text_aux.y = aux_cv;	  	  
	}
	else{
	  if(m == tam_perfil - 1){
	    text_aux.x = aux_cu;
	    text_aux.y = 1.0;	    
	  }
	  else{
	    // Calculo la distancia solo la primera vez ya que despues es la misma siempre
	    if(n < tam_perfil){
	      distancia = sqrt(pow((vertices[pto].x - vertices[pto - 1].x), 2) + pow((vertices[pto].y - vertices[pto - 1].y), 2));	      
	      aux_distancia.push_back(distancia / 10.0);
	    }
	    
	    text_aux.x = aux_cu;
	    text_aux.y = aux_distancia.at(m - 1);
	  }
	}
	
	texturas.push_back(text_aux);
      }
      
      aux_cu = aux_cu + (1.0 / num);
    }        
    
}


/*********************************************************/

void og3d::draw_con_textura_con_iluminacion(int v){

    // Activo el parámetro GL_MODULATE para la iluminación
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    //Activo la fuente de luz
    //glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);

    glBegin(GL_TRIANGLES);
    int p1, p2, p3;
    

    if (v == 1){
        glShadeModel(GL_SMOOTH);
        for(unsigned i = 0; i < caras.size(); i++){
            p1 = caras.at(i).x;
            p2 = caras.at(i).y;
            p3 = caras.at(i).z;
		
		
            glNormal3f(normales_vertices.at(p1).x, normales_vertices.at(p1).y, normales_vertices.at(p1).z);
            glTexCoord2d(texturas.at(p1).x, texturas.at(p1).y);
            glVertex3f(vertices.at(p1).x, vertices.at(p1).y, vertices.at(p1).z);

            glNormal3f(normales_vertices.at(p2).x, normales_vertices.at(p2).y, normales_vertices.at(p2).z);
            glTexCoord2d(texturas.at(p2).x, texturas.at(p2).y);
            glVertex3f(vertices.at(p2).x, vertices.at(p2).y, vertices.at(p2).z);

            glNormal3f(normales_vertices.at(p3).x, normales_vertices.at(p3).y, normales_vertices.at(p3).z);
            glTexCoord2d(texturas.at(p3).x, texturas.at(p3).y);
            glVertex3f(vertices.at(p3).x, vertices.at(p3).y, vertices.at(p3).z);
	
        }
    }
    else{
        glShadeModel(GL_FLAT);
        for(unsigned i = 0; i < caras.size(); i++){
            p1 = caras.at(i).x;
            p2 = caras.at(i).y;
            p3 = caras.at(i).z;

            glNormal3f(normales_caras.at(i).normal_cara.x, normales_caras.at(i).normal_cara.y, normales_caras.at(i).normal_cara.z);
            glTexCoord2d(texturas.at(p1).x, texturas.at(p1).y);
            glVertex3f(vertices.at(p1).x, vertices.at(p1).y, vertices.at(p1).z);
            glTexCoord2d(texturas.at(p2).x, texturas.at(p2).y);
            glVertex3f(vertices.at(p2).x, vertices.at(p2).y, vertices.at(p2).z);
            glTexCoord2d(texturas.at(p3).x, texturas.at(p3).y);
            glVertex3f(vertices.at(p3).x, vertices.at(p3).y, vertices.at(p3).z);

        }
    }
    
    glEnd();
    
    //Desactivo las luces
    //glDisable(GL_LIGHT0);
    glDisable(GL_LIGHT1);
    glDisable(GL_LIGHTING);

    //Desactivo la textura
    glDisable(GL_TEXTURE_2D);
  
}


/*********************************************************/

void og3d::draw_con_textura_sin_iluminacion(){

    glBegin(GL_TRIANGLES);
    int p1, p2, p3;

    //Desactivo la iluminación
    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHT1);
    glDisable(GL_LIGHTING);

    for(unsigned i = 0; i < caras.size(); i++){
        p1 = caras.at(i).x;
        p2 = caras.at(i).y;
        p3 = caras.at(i).z;

        glTexCoord2d(texturas.at(p1).x, texturas.at(p1).y);
        glVertex3f(vertices.at(p1).x, vertices.at(p1).y, vertices.at(p1).z);

        glTexCoord2d(texturas.at(p2).x, texturas.at(p2).y);
        glVertex3f(vertices.at(p2).x, vertices.at(p2).y, vertices.at(p2).z);

        glTexCoord2d(texturas.at(p3).x, texturas.at(p3).y);
        glVertex3f(vertices.at(p3).x, vertices.at(p3).y, vertices.at(p3).z);

    }

    glEnd();

    //Desactivo la textura
    glDisable(GL_TEXTURE_2D);

}


/*********************************************************/

void og3d::draw_sin_textura_con_iluminacion(int v){

    // Activo el parámetro GL_MODULATE para la iluminación
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    //Activo la fuente de luz
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);

    //Desabilitar las coordenadas de textura automáticas
    glDisable(GL_TEXTURE_GEN_T);
    glDisable(GL_TEXTURE_GEN_S);

    //Desactivo la textura
    glDisable(GL_TEXTURE_2D);

    glBegin(GL_TRIANGLES);
    int p1, p2, p3;

    if (v == 1){
        glShadeModel(GL_SMOOTH);
        for(unsigned i = 0; i < caras.size(); i++){
            p1 = caras.at(i).x;
            p2 = caras.at(i).y;
            p3 = caras.at(i).z;


            glNormal3f(normales_vertices.at(p1).x, normales_vertices.at(p1).y, normales_vertices.at(p1).z);
            //glTexCoord2d(texturas.at(p1).x, texturas.at(p1).y);
            glVertex3f(vertices.at(p1).x, vertices.at(p1).y, vertices.at(p1).z);

            glNormal3f(normales_vertices.at(p2).x, normales_vertices.at(p2).y, normales_vertices.at(p2).z);
            //glTexCoord2d(texturas.at(p2).x, texturas.at(p2).y);
            glVertex3f(vertices.at(p2).x, vertices.at(p2).y, vertices.at(p2).z);

            glNormal3f(normales_vertices.at(p3).x, normales_vertices.at(p3).y, normales_vertices.at(p3).z);
            //glTexCoord2d(texturas.at(p3).x, texturas.at(p3).y);
            glVertex3f(vertices.at(p3).x, vertices.at(p3).y, vertices.at(p3).z);

        }
    }
    else{
        glShadeModel(GL_FLAT);
        for(unsigned i = 0; i < caras.size(); i++){
            p1 = caras.at(i).x;
            p2 = caras.at(i).y;
            p3 = caras.at(i).z;

            glNormal3f(normales_caras.at(i).normal_cara.x, normales_caras.at(i).normal_cara.y, normales_caras.at(i).normal_cara.z);
            //glTexCoord2d(texturas.at(p1).x, texturas.at(p1).y);
            glVertex3f(vertices.at(p1).x, vertices.at(p1).y, vertices.at(p1).z);
            //glTexCoord2d(texturas.at(p2).x, texturas.at(p2).y);
            glVertex3f(vertices.at(p2).x, vertices.at(p2).y, vertices.at(p2).z);
            //glTexCoord2d(texturas.at(p3).x, texturas.at(p3).y);
            glVertex3f(vertices.at(p3).x, vertices.at(p3).y, vertices.at(p3).z);

        }
    }

    glEnd();

    //Desactivo las luces
    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHT1);
    glDisable(GL_LIGHTING);

}


/**********************************************************/

void og3d::draw_sin_textura_sin_iluminacion(){

    //Desactivo las luces
    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHT1);
    glDisable(GL_LIGHTING);

    //Desabilitar las coordenadas de textura automáticas
    glDisable(GL_TEXTURE_GEN_T);
    glDisable(GL_TEXTURE_GEN_S);

    //Desactivo la textura
    glDisable(GL_TEXTURE_2D);

    glBegin(GL_TRIANGLES);
    int p1, p2, p3;

    for(unsigned i = 0; i < caras.size(); i++){
        p1 = caras.at(i).x;
        p2 = caras.at(i).y;
        p3 = caras.at(i).z;

        //glTexCoord2d(texturas.at(p1).x, texturas.at(p1).y);
        glVertex3f(vertices.at(p1).x, vertices.at(p1).y, vertices.at(p1).z);

        //glTexCoord2d(texturas.at(p2).x, texturas.at(p2).y);
        glVertex3f(vertices.at(p2).x, vertices.at(p2).y, vertices.at(p2).z);

        //glTexCoord2d(texturas.at(p3).x, texturas.at(p3).y);
        glVertex3f(vertices.at(p3).x, vertices.at(p3).y, vertices.at(p3).z);

    }

    glEnd();

}
