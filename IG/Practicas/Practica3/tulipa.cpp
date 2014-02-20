
#include "tulipa.h"


/********************************************************/
tulipa::tulipa(){

    float vpuntos[] = {0.0, 1.0, 0.0, 0.5, 1.0, 0.0, 0.5, 0.5, 0.0, 1.0, 0.0, 0.0};

    tulipa_base.resizevertices(4);

    for(int i = 0, k = 0; i < 4; i++)
        for(int j = 0; j < 3; j++, k++)
            tulipa_base.setvertices(j,i,vpuntos[k]);

    tulipa_base.crear_revolucion(4,360);

}


/*********************************************************/
void tulipa::draw(int m){

    switch(m){
        case 0:
            glPushMatrix();
                glTranslatef(0,1,0);
                glRotatef(180,1,0,0);
                draw_vertices();
            glPopMatrix();
            break;
        case 1:
            glPushMatrix();
                glTranslatef(0,1,0);
                glRotatef(180,1,0,0);
                draw_alambres();
            glPopMatrix();
            break;
        case 2:
            glPushMatrix();
                glTranslatef(0,1,0);
                glRotatef(180,1,0,0);
                draw_liso();
            glPopMatrix();
            break;
        case 3:
            glPushMatrix();
                glTranslatef(0,1,0);
                glRotatef(180,1,0,0);
                draw_ajedrez();
            glPopMatrix();
            break;
        default:
            break;
    }
}


/*********************************************************/

void tulipa::draw_vertices()
{

    glColor3f(0,1,0);
    glPointSize(5);

    glBegin(GL_POINTS);
        for(unsigned i = 0; i < tulipa_base.getvertices().size(); i++){
            glVertex3f(tulipa_base.getvertices().at(i).x, tulipa_base.getvertices().at(i).y, tulipa_base.getvertices().at(i).z);
        }
    glEnd();

}


/*********************************************************/
void tulipa::draw_alambres(){

    glColor3f(0,1,0);
    glPointSize(2);
    int v1, v2, v3;

    glBegin(GL_LINES);
    for(unsigned i = 0; i < tulipa_base.getcaras().size(); i++){
        v1 = tulipa_base.getcaras().at(i).x;
        v2 = tulipa_base.getcaras().at(i).y;
        v3 = tulipa_base.getcaras().at(i).z;


        int vert[3] = {v1, v2, v3};
        for(int j = 0; j < 3; j++){
            if(j == 2){
                glVertex3f(tulipa_base.getvertices().at(vert[j]).x, tulipa_base.getvertices().at(vert[j]).y, tulipa_base.getvertices().at(vert[j]).z);
                glVertex3f(tulipa_base.getvertices().at(vert[j-2]).x, tulipa_base.getvertices().at(vert[j-2]).y, tulipa_base.getvertices().at(vert[j-2]).z);
            }
            else{
                glVertex3f(tulipa_base.getvertices().at(vert[j]).x, tulipa_base.getvertices().at(vert[j]).y, tulipa_base.getvertices().at(vert[j]).z);
                glVertex3f(tulipa_base.getvertices().at(vert[j+1]).x, tulipa_base.getvertices().at(vert[j+1]).y, tulipa_base.getvertices().at(vert[j+1]).z);
            }
        }

    }
    glEnd();
}


/*********************************************************/
void tulipa::draw_liso() {

    glPointSize(2);
    glColor3f(0,0,1);
    int v1, v2, v3;

    glBegin(GL_TRIANGLES);
    for(unsigned i = 0; i < tulipa_base.getcaras().size(); i++){
        v1 = tulipa_base.getcaras().at(i).x;
        v2 = tulipa_base.getcaras().at(i).y;
        v3 = tulipa_base.getcaras().at(i).z;

        glVertex3f(tulipa_base.getvertices().at(v1).x, tulipa_base.getvertices().at(v1).y, tulipa_base.getvertices().at(v1).z);

        glVertex3f(tulipa_base.getvertices().at(v2).x, tulipa_base.getvertices().at(v2).y, tulipa_base.getvertices().at(v2).z);

        glVertex3f(tulipa_base.getvertices().at(v3).x, tulipa_base.getvertices().at(v3).y, tulipa_base.getvertices().at(v3).z);

    }
    glEnd();

}


/***********************************************************/
void tulipa::draw_ajedrez(){

    glPointSize(2);
    int v1, v2, v3;

    glBegin(GL_TRIANGLES);
    for(unsigned i = 0; i < tulipa_base.getcaras().size(); i++){
        if(i%3 == 0)
            glColor3f(0,0,1);
        else
            glColor3f(0.5,0.5,0.5);

        v1 = tulipa_base.getcaras().at(i).x;
        v2 = tulipa_base.getcaras().at(i).y;
        v3 = tulipa_base.getcaras().at(i).z;

        glVertex3f(tulipa_base.getvertices().at(v1).x, tulipa_base.getvertices().at(v1).y, tulipa_base.getvertices().at(v1).z);

        glVertex3f(tulipa_base.getvertices().at(v2).x, tulipa_base.getvertices().at(v2).y, tulipa_base.getvertices().at(v2).z);

        glVertex3f(tulipa_base.getvertices().at(v3).x, tulipa_base.getvertices().at(v3).y, tulipa_base.getvertices().at(v3).z);

    }
    glEnd();

}
