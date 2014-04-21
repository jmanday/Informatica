#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {

	int n, i, j;
	struct timespec cgt1,cgt2; 
	double ncgt;
	n = atoi(argv[1]); /* tomamos el tamaño de filas y columnas de la matriz */
	int m[n][n], v1[n], v3[n]; /* nos creamos la matriz y el vector */

	srand(time(NULL));
	/* inicializamos la matriz y el vector */
	for(i = 0; i < n; i++){
		v1[i] = (rand() % 3) + 1;
		v3[i] = 0;
		for(j = 0; j < n; j++)
			m[i][j] = rand() % (3+1);

	}

	clock_gettime(CLOCK_REALTIME,&cgt1);
	/* realizamos la multiplicacion */
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
