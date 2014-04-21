#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

main(int argc, char* argv[]){

	int i, n, k, *v1, *v2;
	struct timespec cgt1,cgt2; 
	double ncgt;
	n = atoi(argv[1]); // tamaño del vector
	k = atoi(argv[2]); // constante de multiplicación

	/* reservamos memoria para los vectores */
	v1 = (int*) malloc(n * sizeof(int));
	v2 = (int*) malloc(n * sizeof(int));

	srand(time(NULL));
	/* inicializamos v1 */
	for(i = 0; i < n; i++)
		v1[i] = ((rand() % 5)+1);

	/* realizamos la multiplicación */
	clock_gettime(CLOCK_REALTIME,&cgt1);
	for(i = 0; i < n; i++)
		v2[i] = v1[i] * k + v2[i];

	clock_gettime(CLOCK_REALTIME,&cgt2);
	ncgt=(double) (cgt2.tv_sec-cgt1.tv_sec)+
		(double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));

	printf("Tiempo(seg.):%11.9f\t",ncgt);
	printf("\n\n");

}
