#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv) {

	int n, i, j, k, num, chunk;
	struct timespec cgt1,cgt2,cgt3,cgt4,cgt5,cgt6; 
	double ncgt;
	n = atoi(argv[1]); /* tomamos el tamaño de filas y columnas de la matriz */
	int *v1, *v3, **m; /* declaramos dinamicas los vectores y la matriz */
	chunk = atoi(argv[2]); /* para el numero de iteraciones */

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

	/* Para que el numero de threads coincida con el número de cores */
	num = omp_get_num_procs();


	/* realizamos la multiplicacion con planificador static*/
	clock_gettime(CLOCK_REALTIME,&cgt1);
	#pragma omp parallel for shared(m,v1,v3) private(i,j) num_threads(num) schedule(static,chunk)
	for(i = 0; i < n; i++)	
		for(j = i; j < n; j++)
			v3[i] += m[i][j] * v1[j]; 
	

	clock_gettime(CLOCK_REALTIME,&cgt2);
	ncgt=(double) (cgt2.tv_sec-cgt1.tv_sec)+
		(double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));

	printf("Planificador static: \n");
	printf("Tiempo(seg.):%11.9f\t / Tamaño Vector:%u\n",ncgt,n);
	printf("\n\n");



	/* realizamos la multiplicacion con planificador dynamic*/
	ncgt = 0.0;
	clock_gettime(CLOCK_REALTIME,&cgt3);
	#pragma omp parallel for shared(m,v1,v3) private(i,j) num_threads(num) schedule(dynamic,chunk)
	for(i = 0; i < n; i++)	
		for(j = i; j < n; j++)
			v3[i] += m[i][j] * v1[j];  
	

	clock_gettime(CLOCK_REALTIME,&cgt4);
	ncgt=(double) (cgt4.tv_sec-cgt3.tv_sec)+
		(double) ((cgt4.tv_nsec-cgt3.tv_nsec)/(1.e+9));

	printf("Planificador dynamic: \n");
	printf("Tiempo(seg.):%11.9f\t / Tamaño Vector:%u\n",ncgt,n);
	printf("\n\n");


	/* realizamos la multiplicacion con planificador guided*/
	ncgt = 0.0;
	clock_gettime(CLOCK_REALTIME,&cgt5);
	#pragma omp parallel for shared(m,v1,v3) private(i,j) num_threads(num) schedule(guided,chunk)
	for(i = 0; i < n; i++)	
		for(j = i; j < n; j++)
			v3[i] += m[i][j] * v1[j]; 
	

	clock_gettime(CLOCK_REALTIME,&cgt6);
	ncgt=(double) (cgt6.tv_sec-cgt5.tv_sec)+
		(double) ((cgt6.tv_nsec-cgt5.tv_nsec)/(1.e+9));

	printf("Planificador guided: \n");
	printf("Tiempo(seg.):%11.9f\t / Tamaño Vector:%u\n",ncgt,n);
	printf("\n\nValor (0,0): %d \n", m[0][0]);
	printf("Valor (n-1,n-1): %d \n", m[n-1][n-1]);
	printf("\n\n");

}
