#include "lampara.h"


/********************************************************/
lampara::lampara(){
    float vpuntos[] = {0.0, 0.5, 0.0, 2.5, 0.5, 0.0, 2.5, -0.5, 0.0, 0.0, -0.5, 0.0};

    lampara_base.resizevertices(4);

    for(int i = 0, k = 0; i < 4; i++)
        for(int j = 0; j < 3; j++, k++)
            lampara_base.setvertices(j,i,vpuntos[k]);

    lampara_base.crear_revolucion(14,360);
}


/*********************************************************/
void lampara::draw(int m, float a, float a2, float a3){
    brazo_inferior b;

    if(a > 90)
        a = 90;

    if(a < -90)
        a = -90;

    switch(m){
        case 0:
            glPushMatrix();
                glPushMatrix();
                    glTranslatef(0,1,0);
                    glRotatef(a,0,0,1);
                    b.draw(m,a2,a3);
                glPopMatrix();
                glTranslatef(0,0.5,0);
                draw_vertices();
            glPopMatrix();
            break;
        case 1:
            glPushMatrix();
                glPushMatrix();
                    glTranslatef(0,1,0);
                    glRotatef(a,0,0,1);
                    b.draw(m,a2,a3);
                glPopMatrix();
                glTranslatef(0,0.5,0);
                draw_alambres();
            glPopMatrix();
            break;
        case 2:
            glPushMatrix();
                glPushMatrix();
                    glTranslatef(0,1,0);
                    glRotatef(a,0,0,1);
                    b.draw(m,a2,a3);
                glPopMatrix();
                glTranslatef(0,0.5,0);
                draw_liso();
            glPopMatrix();
            break;
        case 3:
            glPushMatrix();
                glPushMatrix();
                    glTranslatef(0,1,0);
                    glRotatef(a,0,0,1);
                    b.draw(m,a2,a3);
                glPopMatrix();
                glTranslatef(0,0.5,0);
                draw_ajedrez();
            glPopMatrix();
            break;
        default:
            break;
    }
}


/*********************************************************/
void lampara::draw_vertices()
{

    glColor3f(0,1,0);
    glPointSize(5);

    glBegin(GL_POINTS);
        for(unsigned i = 0; i < lampara_base.getvertices().size(); i++){
            glVertex3f(lampara_base.getvertices().at(i).x, lampara_base.getvertices().at(i).y, lampara_base.getvertices().at(i).z);
        }
    glEnd();

}


/*********************************************************/
void lampara::draw_alambres(){

    glColor3f(0,1,0);
    glPointSize(2);
    int v1, v2, v3;

    glBegin(GL_LINES);
    for(unsigned i = 0; i < lampara_base.getcaras().size(); i++){
        v1 = lampara_base.getcaras().at(i).x;
        v2 = lampara_base.getcaras().at(i).y;
        v3 = lampara_base.getcaras().at(i).z;


        int vert[3] = {v1, v2, v3};
        for(int j = 0; j < 3; j++){
            if(j == 2){
                glVertex3f(lampara_base.getvertices().at(vert[j]).x, lampara_base.getvertices().at(vert[j]).y, lampara_base.getvertices().at(vert[j]).z);
                glVertex3f(lampara_base.getvertices().at(vert[j-2]).x, lampara_base.getvertices().at(vert[j-2]).y, lampara_base.getvertices().at(vert[j-2]).z);
            }
            else{
                glVertex3f(lampara_base.getvertices().at(vert[j]).x, lampara_base.getvertices().at(vert[j]).y, lampara_base.getvertices().at(vert[j]).z);
                glVertex3f(lampara_base.getvertices().at(vert[j+1]).x, lampara_base.getvertices().at(vert[j+1]).y, lampara_base.getvertices().at(vert[j+1]).z);
            }
        }

    }
    glEnd();
}


/*********************************************************/
void lampara::draw_liso() {

    glPointSize(2);
    glColor3f(0,0,1);
    int v1, v2, v3;

    glBegin(GL_TRIANGLES);
    for(unsigned i = 0; i < lampara_base.getcaras().size(); i++){
        v1 = lampara_base.getcaras().at(i).x;
        v2 = lampara_base.getcaras().at(i).y;
        v3 = lampara_base.getcaras().at(i).z;

        glVertex3f(lampara_base.getvertices().at(v1).x, lampara_base.getvertices().at(v1).y, lampara_base.getvertices().at(v1).z);

        glVertex3f(lampara_base.getvertices().at(v2).x, lampara_base.getvertices().at(v2).y, lampara_base.getvertices().at(v2).z);

        glVertex3f(lampara_base.getvertices().at(v3).x, lampara_base.getvertices().at(v3).y, lampara_base.getvertices().at(v3).z);

    }
    glEnd();

}


/***********************************************************/
void lampara::draw_ajedrez(){

    glPointSize(2);
    int v1, v2, v3;

    glBegin(GL_TRIANGLES);
    for(unsigned i = 0; i < lampara_base.getcaras().size(); i++){
        if(i%3 == 0)
            glColor3f(0,0,1);
        else
            glColor3f(0.5,0.5,0.5);

        v1 = lampara_base.getcaras().at(i).x;
        v2 = lampara_base.getcaras().at(i).y;
        v3 = lampara_base.getcaras().at(i).z;

        glVertex3f(lampara_base.getvertices().at(v1).x, lampara_base.getvertices().at(v1).y, lampara_base.getvertices().at(v1).z);

        glVertex3f(lampara_base.getvertices().at(v2).x, lampara_base.getvertices().at(v2).y, lampara_base.getvertices().at(v2).z);

        glVertex3f(lampara_base.getvertices().at(v3).x, lampara_base.getvertices().at(v3).y, lampara_base.getvertices().at(v3).z);

    }
    glEnd();

}
