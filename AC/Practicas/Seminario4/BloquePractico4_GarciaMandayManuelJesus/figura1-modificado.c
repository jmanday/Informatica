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
	int i, ii, X1, X2, R[40000];
	struct timespec cgt1,cgt2; 
	double ncgt;

	for(ii = 0; ii < 5000; ii++){
		s.a[ii] = ((rand() % 10)-5);
		s.b[ii] = ((rand() % 10)-5);
	}
	
	clock_gettime(CLOCK_REALTIME,&cgt1);
	for (ii = 0; ii < 40000; ii++){
    	for(i = 0; i < 5000; i+=8){ 
			X1 = 2 * s.a[i] + ii;
			X1 = 2 * s.a[i+1] + ii;
			X1 = 2 * s.a[i+2] + ii;
			X1 = 2 * s.a[i+3] + ii;
			X1 = 2 * s.a[i+4] + ii;
			X1 = 2 * s.a[i+5] + ii;
			X1 = 2 * s.a[i+6] + ii;
			X1 = 2 * s.a[i+7] + ii;
		}

    	for(i = 0; i < 5000; i+=8){
			X2 = 3 * s.b[i] - ii;
			X2 = 3 * s.b[i+1] - ii;
			X2 = 3 * s.b[i+2] - ii;
			X2 = 3 * s.b[i+3] - ii;
			X2 = 3 * s.b[i+4] - ii;
			X2 = 3 * s.b[i+5] - ii;
			X2 = 3 * s.b[i+6] - ii;
			X2 = 3 * s.b[i+7] - ii;
		}

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
