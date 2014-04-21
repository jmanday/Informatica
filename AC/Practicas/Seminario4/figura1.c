#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct {
        int a[5000];
        int b[5000];
}  s;


main(){

	srand(time(NULL));
	/* Inicializamos las variables */
	int i, ii, X1, X2, R[40000], aux1, aux2, aux3, aux4;
	struct timespec cgt1,cgt2; 
	double ncgt;

	for(ii = 0; ii < 5000; ii++){
		s.a[ii] = ((rand() % 10)-5);
		s.b[ii] = ((rand() % 10)-5);
	}
	
	clock_gettime(CLOCK_REALTIME,&cgt1);
	for (ii = 0; ii < 40000; ii++){
    	for(i = 0; i < 5000; i++)
			X1 = 2 * s.a[i] + ii;

		X1 = aux1 + aux2 + aux3 + aux4;

    	for(i = 0; i < 5000; i++)
			X2 = 3 * s.b[i] - ii;


		if (X1 < X2)  
			R[ii] = X1;  
		else  
			R[ii] = X2;
	}
  	clock_gettime(CLOCK_REALTIME,&cgt2);
	ncgt=(double) (cgt2.tv_sec-cgt1.tv_sec)+
		(double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));

	printf("Tiempo(seg.):%11.9f\t",ncgt);
	printf("\n\n");
	printf("Valor de R[%d]: %d",ii-100,R[ii-100]);
	printf("\n");
}
