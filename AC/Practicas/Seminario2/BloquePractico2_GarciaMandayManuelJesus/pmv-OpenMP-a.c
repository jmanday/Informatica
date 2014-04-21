#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <omp.h>

int main(int argc, char **argv) {

	int n, i, j;
	struct timespec cgt1,cgt2; 
	double ncgt;
	n = atoi(argv[1]); /* tomamos el tamaño de filas y columnas de la matriz */
	int *v1, *v3, **m; /* declaramos dinamicas los vectores y la matriz */

	/* Hacemos la reserva de memoria dinamica */
	n = atoi(argv[1]);
	v1 = (int *) malloc(n * sizeof(int));
	v3 = (int *) malloc(n * sizeof(int));
	m = (int **) malloc(n * sizeof(int*));
	for(i = 0; i < n; i++)
		m[i] = (int *) malloc(n * sizeof(int));

	if ((v1 == NULL) || (v3 == NULL) || (m == NULL)){
		printf("\nError en la reserva de memoria.");
		exit(-1);
	}

	srand(time(NULL));
	/* inicializamos la matriz y el vector */
	#pragma omp parallel for private(i) private(j) shared(n) shared(m) shared(v1) shared(v3) default(none)
	for(i = 0; i < n; i++){
		v1[i] = (rand() % 3) + 1;
		v3[i] = 0;
		for(j = 0; j < n; j++)
			m[i][j] = rand() % (3+1);
	}

	clock_gettime(CLOCK_REALTIME,&cgt1);
	/* realizamos la multiplicacion */
	#pragma omp parallel for private(i) private(j) shared(n) shared(m) shared(v1) shared(v3) default(none)
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++)
			v3[i] += m[i][j] * v1[j]; 
	}

	clock_gettime(CLOCK_REALTIME,&cgt2);
	ncgt=(double) (cgt2.tv_sec-cgt1.tv_sec)+
		(double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));

	printf("Tiempo(seg.):%11.9f\t / Tamaño Vector:%u\n",ncgt,n);
	printf("Vector resultante del producto: ");
	for(i = 0; i < n; i++)
		printf("%d ", v3[i]);
	printf("\n");

}
