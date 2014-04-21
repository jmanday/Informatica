#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {

	int n, i, j, k;
	struct timespec cgt1,cgt2; 
	double ncgt;
	n = atoi(argv[1]); /* tomamos el tamaño de filas y columnas de la matriz */
	int *v1, *v3, **m; /* declaramos dinamicas los vectores y la matriz */

	/* Hacemos la reserva de memoria dinamica */
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
	for(i = 0; i < n; i++){
		v1[i] = (rand() % 3) + 1;
		v3[i] = 0;
		for(j = 0; j < n; j++){
			if(i == 0)
				m[i][j] = ((rand() % 4)+1);
			else{
				while(i != j){
					m[i][j] = 0;
					j++;
				}
				
				while(j < n){
					m[i][j] = ((rand() % 4)+1);
					j++;
				}
			}
		}
	}

	
	/* realizamos la multiplicacion */
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++)
			v3[i] += m[i][j] * v1[j]; 
	}

	printf("Valor (0,0): %d \n", m[0][0]);
	printf("Valor (n-1,n-1): %d \n", m[n-1][n-1]);
	printf("\n");

}
