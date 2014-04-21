#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {

	int n, i, j, k, cont;
	struct timespec cgt1,cgt2; 
	double ncgt;
	n = atoi(argv[1]); /* tomamos el tamaño de filas y columnas de la matriz */
	int **m1, **m2, **m3; /* declaramos dinamicas las matrices */

	/* Hacemos la reserva de memoria dinamica */
	m1 = (int **) malloc(n * sizeof(int*));
	m2 = (int **) malloc(n * sizeof(int*));
	m3 = (int **) malloc(n * sizeof(int*));

	for(i = 0; i < n; i++){
		m1[i] = (int *) malloc(n * sizeof(int));
		m2[i] = (int *) malloc(n * sizeof(int));
		m3[i] = (int *) malloc(n * sizeof(int));
	}

	if ((m1 == NULL) || (m2 == NULL) || (m3 == NULL)){
		printf("\nError en la reserva de memoria.");
		exit(-1);
	}


	srand(time(NULL));
	/* inicializamos las matrices */
	for(i = 0; i < n; i++){
		for(j = i; j < n; j++){
			m1[i][j] = ((rand() % 4)+1);
			m2[i][j] = ((rand() % 4)+1);
			m3[i][j] = 0;
		}
	}

	
	/* realizamos la multiplicacion */
	clock_gettime(CLOCK_REALTIME,&cgt1);
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			for(k = 0; k < n; k++)
				cont += m1[i][k] * m2[k][j]; 

			m3[i][j] = cont;
			cont = 0;
		}
	}
	clock_gettime(CLOCK_REALTIME,&cgt2);
	ncgt=(double) (cgt2.tv_sec-cgt1.tv_sec)+
		(double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));

	printf("Tiempo(seg.):%11.9f\t",ncgt);
	printf("\n\n");
	printf("Valor (0,0): %d \n", m3[0][0]);
	printf("Valor (n-1,n-1): %d \n", m3[n-1][n-1]);
	printf("\n");

}
