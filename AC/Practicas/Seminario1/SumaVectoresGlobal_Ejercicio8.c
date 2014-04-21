/* SumaVectoresC.c
Suma de dos vectores: v3 = v1 + v2

Para compilar usar (-lrt: real time library):
gcc -O2 SumaVectores.c -o SumaVectores -lrt

Para ejecutar use: SumaVectoresC longitud
*/

#include <stdlib.h> // biblioteca con funciones atoi(), malloc() y free()
#include <stdio.h> // biblioteca donde se encuentra la función printf()
#include <time.h> // biblioteca donde se encuentra la función clock_gettime()
#include <omp.h> // biblioteca donde se encuentran las funciones y directivas de openMP

#define VECTOR_GLOBAL// descomentar para que los vectores sean variables ...
					// globales (su longitud no estará limitada por el ...
					// tamaño de la pila del programa)


#ifdef VECTOR_GLOBAL
#define MAX 10000000

double v1[MAX], v2[MAX], v3[MAX];
int tama;
#endif

void inicializaVector1(){
	
	int i;
	for(i = 0; i < tama; i++)
		v1[i] = tama*0.1+i*0.1;

}

void inicializaVector2(){
	
	int i;
	for(i = 0; i < tama; i++)
 		v2[i] = tama*0.1-i*0.1; 

}


int main(int argc, char** argv){

	int i, k, m, l, c;
	struct timespec cgt1,cgt2; 
	double t1, t2, tfin; //para tiempo de ejecución
											

	if (argc<2){//Leer argumento de entrada (no de componentes del vector)
		printf("Faltan no componentes del vector\n");
		exit(-1);
	}

	unsigned int N = atoi(argv[1]); // Máximo N =2^32-1=4294967295 (sizeof(unsigned int) = 4 B)
	tama = N;
	c = N/4 + 1;

	// Dividimos la inicializacion en secciones
	#pragma omp parallel sections
	{
		#pragma omp section
			(void) inicializaVector1();		
		#pragma omp section
			(void) inicializaVector2();
	}


	t1 = omp_get_wtime();
	//Calcular suma de vectores en secciones
	#pragma omp parallel sections
	{
		#pragma omp section
			for(i = 0; i < c; i++)
				v3[i] = v1[i] + v2[i];
		#pragma omp section
			for(k = c; k < 2*c ; k++)
				v3[k] = v1[k] + v2[k];
		#pragma omp section
			for(m = 2*c; m < 3*c; m++)
				v3[m] = v1[m] + v2[m];
		#pragma omp section
			for(l = 3*c; l < N; l++)
				v3[l] = v1[l] + v2[l];
	}
	t2 = omp_get_wtime();
	tfin = t2 - t1;


	//Imprimir resultado de la suma y el tiempo de ejecución
	#ifdef PRINTF_ALL
		printf("Tiempo(seg.):%11.9f\t / Tamaño Vectores:%u\n",tfin,N);
	#else
		printf("\nTiempo(seg.):%11.9f\t Tamaño Vectores:%u\t\n\n", tfin, N);
		if(N < 12){ /* Solo imprimimos todos los resultados del vector resultante para valores pequeños, como se indica en el apartado 3) del ejercicio */
			printf("Suma del vector resultante v3\n\n");
			for(i=0; i < N; i++)
				printf("V3[%d]==%8.6f\n", i,v3[i]);
		}
		else{
			printf("V1[0]==%8.6f\t\tV2[0]==%8.6f\t\tV3[0]==%8.6f\n\n", v1[0], v2[0], v3[0]);
			printf("V1[N-1]==%8.6f\t\tV2[N-1]==%8.6f\t\tV3[N-1]==%8.6f\n\n", v1[N-1], v2[N-1], v3[N-1]);
		}

	#endif

	return 0;

}



