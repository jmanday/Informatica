#include "brazo_superior.h"


/********************************************************/
brazo_superior::brazo_superior(){
    float vpuntos[] = {0.25, 1.5, 0.0, 0.25, -1.5, 0.0};

    brazo_base.resizevertices(2);

    for(int i = 0, k = 0; i < 2; i++)
        for(int j = 0; j < 3; j++, k++)
            brazo_base.setvertices(j,i,vpuntos[k]);

    brazo_base.crear_revolucion(14,360);
}


/*********************************************************/
void brazo_superior::draw(int m, float a){
    tulipa t;

    if(a > 90)
        a = 90;

    if(a < -90)
        a = -90;

    switch(m){
        case 0:
            glPushMatrix();
                glPushMatrix();
                    glTranslatef(0,3,0);
                    glRotatef(a,0,0,1);
                    t.draw(m);
                glPopMatrix();
                glTranslatef(0,1.5,0);
                draw_vertices();
            glPopMatrix();
            break;
        case 1:
            glPushMatrix();
                glPushMatrix();
                    glTranslatef(0,3,0);
                    glRotatef(a,0,0,1);
                    t.draw(m);
                glPopMatrix();
                glTranslatef(0,1.5,0);
                draw_alambres();
            glPopMatrix();
            break;
        case 2:
            glPushMatrix();
                glPushMatrix();
                    glTranslatef(0,3,0);
                    glRotatef(a,0,0,1);
                    t.draw(m);
                glPopMatrix();
                glTranslatef(0,1.5,0);
                draw_liso();
            glPopMatrix();
            break;
        case 3:
            glPushMatrix();
                glPushMatrix();
                    glTranslatef(0,3,0);
                    glRotatef(a,0,0,1);
                    t.draw(m);
                glPopMatrix();
                glTranslatef(0,1.5,0);
                draw_ajedrez();
            glPopMatrix();
            break;
        default:
            break;
    }
}


/*********************************************************/
void brazo_superior::draw_vertices()
{

    glColor3f(0,1,0);
    glPointSize(5);

    glBegin(GL_POINTS);
        for(unsigned i = 0; i < brazo_base.getvertices().size(); i++){
            glVertex3f(brazo_base.getvertices().at(i).x, brazo_base.getvertices().at(i).y, brazo_base.getvertices().at(i).z);
        }
    glEnd();

}


/*********************************************************/
void brazo_superior::draw_alambres(){

    glColor3f(0,1,0);
    glPointSize(2);
    int v1, v2, v3;

    glBegin(GL_LINES);
    for(unsigned i = 0; i < brazo_base.getcaras().size(); i++){
        v1 = brazo_base.getcaras().at(i).x;
        v2 = brazo_base.getcaras().at(i).y;
        v3 = brazo_base.getcaras().at(i).z;


        int vert[3] = {v1, v2, v3};
        for(int j = 0; j < 3; j++){
            if(j == 2){
                glVertex3f(brazo_base.getvertices().at(vert[j]).x, brazo_base.getvertices().at(vert[j]).y, brazo_base.getvertices().at(vert[j]).z);
                glVertex3f(brazo_base.getvertices().at(vert[j-2]).x, brazo_base.getvertices().at(vert[j-2]).y, brazo_base.getvertices().at(vert[j-2]).z);
            }
            else{
                glVertex3f(brazo_base.getvertices().at(vert[j]).x, brazo_base.getvertices().at(vert[j]).y, brazo_base.getvertices().at(vert[j]).z);
                glVertex3f(brazo_base.getvertices().at(vert[j+1]).x, brazo_base.getvertices().at(vert[j+1]).y, brazo_base.getvertices().at(vert[j+1]).z);
            }
        }

    }
    glEnd();
}


/*********************************************************/
void brazo_superior::draw_liso() {

    glPointSize(2);
    glColor3f(0,0,1);
    int v1, v2, v3;

    glBegin(GL_TRIANGLES);
    for(unsigned i = 0; i < brazo_base.getcaras().size(); i++){
        v1 = brazo_base.getcaras().at(i).x;
        v2 = brazo_base.getcaras().at(i).y;
        v3 = brazo_base.getcaras().at(i).z;

        glVertex3f(brazo_base.getvertices().at(v1).x, brazo_base.getvertices().at(v1).y, brazo_base.getvertices().at(v1).z);

        glVertex3f(brazo_base.getvertices().at(v2).x, brazo_base.getvertices().at(v2).y, brazo_base.getvertices().at(v2).z);

        glVertex3f(brazo_base.getvertices().at(v3).x, brazo_base.getvertices().at(v3).y, brazo_base.getvertices().at(v3).z);

    }
    glEnd();

}


/***********************************************************/
void brazo_superior::draw_ajedrez(){

    glPointSize(2);
    int v1, v2, v3;

    glBegin(GL_TRIANGLES);
    for(unsigned i = 0; i < brazo_base.getcaras().size(); i++){
        if(i%3 == 0)
            glColor3f(0,0,1);
        else
            glColor3f(0.5,0.5,0.5);

        v1 = brazo_base.getcaras().at(i).x;
        v2 = brazo_base.getcaras().at(i).y;
        v3 = brazo_base.getcaras().at(i).z;

        glVertex3f(brazo_base.getvertices().at(v1).x, brazo_base.getvertices().at(v1).y, brazo_base.getvertices().at(v1).z);

        glVertex3f(brazo_base.getvertices().at(v2).x, brazo_base.getvertices().at(v2).y, brazo_base.getvertices().at(v2).z);

        glVertex3f(brazo_base.getvertices().at(v3).x, brazo_base.getvertices().at(v3).y, brazo_base.getvertices().at(v3).z);

    }
    glEnd();

}

