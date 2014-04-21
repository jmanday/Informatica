#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {

	int n, i, j, k, nump;
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

	/* obtenemos el numero de procesadores para obligar a que se use el maximo número de threads posible */
	nump = omp_get_num_procs();

	
	/* inicializamos las matrices */
	clock_gettime(CLOCK_REALTIME,&cgt1);	
	#pragma omp parallel for shared(m1,m2,m3) private(i,j) num_threads(nump) schedule(guided) 
	for(i = 0; i < n; i++){	 									                               			
		for(j = 0; j < n; j++){																
			m1[i][j] = ((rand() % 4)+1);
			m2[i][j] = ((rand() % 4)+1);
			m3[i][j] = 0;			
		}
	}
	clock_gettime(CLOCK_REALTIME,&cgt2);
	ncgt=(double) (cgt2.tv_sec-cgt1.tv_sec)+
		(double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));

	printf("Tiempo de inicializacion(seg.):%11.9f\t / Tamaño Vector:%u\n",ncgt,n);
	printf("\n");

	

	/* realizamos la multiplicacion */
	clock_gettime(CLOCK_REALTIME,&cgt1);
	#pragma omp parallel for shared(m1,m2,m3) private(i,j) num_threads(nump) schedule(guided)
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++)			
			m3[i][j] += m1[i][j] * m2[i][j]; 
	}
	clock_gettime(CLOCK_REALTIME,&cgt2);
	ncgt=(double) (cgt2.tv_sec-cgt1.tv_sec)+
		(double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));

	printf("Tiempo de multiplicacion(seg.):%11.9f\t / Tamaño Vector:%u\n",ncgt,n);
	printf("\n\n\n");
	

	printf("Valor (0,0): %d \n", m3[0][0]);
	printf("Valor (n-1,n-1): %d \n", m3[n-1][n-1]);
	printf("\n");

}
