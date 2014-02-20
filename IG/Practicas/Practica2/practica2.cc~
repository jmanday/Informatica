//**************************************************************************
// Práctica 2
//
// Domingo Martin Perandres 2013
//
// GPL
//**************************************************************************

#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include <vector>
#include "file_ply_stl.h"
#include "og3d.h"

// tamaño de los ejes
const int AXIS_SIZE=5000;

// nombe del fichero
char * nom_fic1, * nom_fic2;

// para cambiar de tipo de dibujo [1-puntos, 2-alambres, 3-caras_lisa, 4-caras_ajedrez]
int valor = 0;
int ultimo = 0;

// para el el número de lados longitudinales (número de vueltas)
int n = 0;

// para los grados
int num_grados = 0;

vector<og3d> vobj;

// variables que definen la posicion de la camara en coordenadas polares
GLfloat Observer_distance;
GLfloat Observer_angle_x;
GLfloat Observer_angle_y;

// variables que controlan la ventana y la transformacion de perspectiva
GLfloat Window_width,Window_height,Front_plane,Back_plane;

// variables que determninan la posicion y tamaño de la ventana X
int UI_window_pos_x=50,UI_window_pos_y=50,UI_window_width=500,UI_window_height=500;

//**************************************************************************
//
//***************************************************************************

void clear_window()
{

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}


//**************************************************************************
// Funcion para definir la transformación de proyeccion
//***************************************************************************

void change_projection()
{

glMatrixMode(GL_PROJECTION);
glLoadIdentity();

// formato(x_minimo,x_maximo, y_minimo, y_maximo,Front_plane, plano_traser)
//  Front_plane>0  Back_plane>PlanoDelantero)
glFrustum(-Window_width,Window_width,-Window_height,Window_height,Front_plane,Back_plane);
}

//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************

void change_observer()
{

// posicion del observador
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glTranslatef(0,0,-Observer_distance);
glRotatef(Observer_angle_x,1,0,0);
glRotatef(Observer_angle_y,0,1,0);
}

//**************************************************************************
// Funcion que dibuja los ejes utilizando la primitiva grafica de lineas
//***************************************************************************

void draw_axis()
{
glBegin(GL_LINES);
// eje X, color rojo
glColor3f(1,0,0);
glVertex3f(-AXIS_SIZE,0,0);
glVertex3f(AXIS_SIZE,0,0);
// eje Y, color verde
glColor3f(0,1,0);
glVertex3f(0,-AXIS_SIZE,0);
glVertex3f(0,AXIS_SIZE,0);
// eje Z, color azul
glColor3f(0,0,1);
glVertex3f(0,0,-AXIS_SIZE);
glVertex3f(0,0,AXIS_SIZE);
glEnd();
}


//**************************************************************************
// Funcion que dibuja los objetos
//***************************************************************************

void draw_objects(vector<og3d> vobj){	

	//obj1.crear_revolucion(n);

	switch(valor){
		case 0:
			ultimo = 0;
			vobj[0].draw_alambres(1, 0, 0);
			break;
		case 1:
			ultimo = 1;
			vobj[1].draw_alambres(1, 0, 0);
			break;
		case 2:
			ultimo = 2;
			vobj[2].draw_alambres(1, 0, 0);
			break;
		case 3:
			ultimo = 3;
			vobj[3].draw_alambres(1, 0, 0);
			break;
		case 4:
			ultimo = 4;
			vobj[4].draw_alambres(1, 0, 0);			
			break;
		case 5:
			vobj[ultimo].draw_caras_liso();
			break;
		case 6:
			vobj[ultimo].draw_caras_ajedrez();
			break;
		default:
			break;
	}
}


//**************************************************************************
//
//***************************************************************************

void draw_scene()
{

	clear_window();
	change_observer();
	draw_axis();
	draw_objects(vobj);
	glutSwapBuffers();
}



//***************************************************************************
// Funcion llamada cuando se produce un cambio en el tamaño de la ventana
//
// el evento manda a la funcion:
// nuevo ancho
// nuevo alto
//***************************************************************************

void change_window_size(int Ancho1,int Alto1)
{
	change_projection();
	glViewport(0,0,Ancho1,Alto1);
	glutPostRedisplay();
}


//***************************************************************************
// Funcion llamada cuando se produce aprieta una tecla normal
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton
//***************************************************************************

void normal_keys(unsigned char Tecla1,int x,int y)
{

	if (toupper(Tecla1)=='Q') exit(0);
}

//***************************************************************************
// Funcion llamada cuando se produce aprieta una tecla especial
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton

//***************************************************************************

void special_keys(int Tecla1,int x,int y)
{

	switch (Tecla1){
		case GLUT_KEY_LEFT:Observer_angle_y--;break;
		case GLUT_KEY_RIGHT:Observer_angle_y++;break;
		case GLUT_KEY_UP:Observer_angle_x--;break;
		case GLUT_KEY_DOWN:Observer_angle_x++;break;
		case GLUT_KEY_PAGE_UP:Observer_distance*=1.2;break;
		case GLUT_KEY_PAGE_DOWN:Observer_distance/=1.2;break;
		case GLUT_KEY_F1:valor = 0;break;
		case GLUT_KEY_F2:valor = 1;break;
		case GLUT_KEY_F3:valor = 2;break;
		case GLUT_KEY_F4:valor = 3;break;
		case GLUT_KEY_F5:valor = 4;break;
		case GLUT_KEY_F6:valor = 5;break;
		case GLUT_KEY_F7:valor = 6;break;
		}

	glutPostRedisplay();
}



//***************************************************************************
// Funcion de incializacion
//***************************************************************************

void initialize(void)
{
// se inicalizan la ventana y los planos de corte
Window_width=.5;
Window_height=.5;
Front_plane=1;
Back_plane=1000;

// se inicia la posicion del observador, en el eje z
Observer_distance=22*Front_plane;
Observer_angle_x=0;
Observer_angle_y=0;

// se indica cual sera el color para limpiar la ventana	(r,v,a,al)
// blanco=(1,1,1,1) rojo=(1,0,0,1), ...
glClearColor(1,1,1,1);

// se habilita el z-bufer
glEnable(GL_DEPTH_TEST);
change_projection();
glViewport(0,0,UI_window_width,UI_window_height);
}


//***************************************************************************
// Programa principal
//
// Se encarga de iniciar la ventana, asignar las funciones e comenzar el
// bucle de eventos
//***************************************************************************

int main(int argc, char **argv)
{
    // se llama a la inicialización de glut
    glutInit(&argc, argv);

    // se indica las caracteristicas que se desean para la visualización con OpenGL
    // Las posibilidades son:
    // GLUT_SIMPLE -> memoria de imagen simple
    // GLUT_DOUBLE -> memoria de imagen doble
    // GLUT_INDEX -> memoria de imagen con color indizado
    // GLUT_RGB -> memoria de imagen con componentes rojo, verde y azul para cada pixel
    // GLUT_RGBA -> memoria de imagen con componentes rojo, verde, azul y alfa para cada pixel
    // GLUT_DEPTH -> memoria de profundidad o z-bufer
    // GLUT_STENCIL -> memoria de estarcido
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    // posicion de la esquina inferior izquierdad de la ventana
    glutInitWindowPosition(UI_window_pos_x,UI_window_pos_y);

    // tamaño de la ventana (ancho y alto)
    glutInitWindowSize(UI_window_width,UI_window_height);

    // llamada para crear la ventana, indicando el titulo (no se visualiza hasta que se llama
    // al bucle de eventos)
    glutCreateWindow("Práctica 1");	

    /* nombre de los dos ficheros que introduzco que quiero visualizar */
	//nom_fic1 = argv[1];
	//nom_fic2 = argv[2];
	num_grados = atoi(argv[7]);

	/* número de lados longitunidales */
	n = atoi(argv[6]);
	if (n < 3){
		cout << "\nDebe ser mayor o igual a 3\n";
		exit(0);
	}

	// tratamos el fichero ply
	_file_ply Ply;
	og3d obj1;

	for(int i = 1; i < argc - 2; i++){
		nom_fic1 = argv[i];
		Ply.open(nom_fic1);
		Ply.read(obj1);
		Ply.close();
		obj1.crear_revolucion(n, num_grados);
		vobj.push_back(obj1);
	}

	// asignación de la funcion llamada "dibujar" al evento de dibujo
    glutDisplayFunc(draw_scene);
    // asignación de la funcion llamada "cambiar_tamanio_ventana" al evento correspondiente
    glutReshapeFunc(change_window_size);
    // asignación de la funcion llamada "tecla_normal" al evento correspondiente
    glutKeyboardFunc(normal_keys);
    // asignación de la funcion llamada "tecla_Especial" al evento correspondiente
    glutSpecialFunc(special_keys);

    // funcion de inicialización
    initialize();

    // inicio del bucle de eventos
    glutMainLoop();
    return 0;
}
