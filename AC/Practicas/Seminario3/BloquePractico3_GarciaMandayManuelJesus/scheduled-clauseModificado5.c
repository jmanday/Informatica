#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
	#include <omp.h>
#else
	#define omp_get_thread_num() 0
#endif

main(int argc, char **argv) {

	int i, n = 16, chunk, suma = 0, j = 0, modificador;
	omp_sched_t kind;

	if(argc < 3) {
		fprintf(stderr,"\nFalta iteraciones o chunk \n");
		exit(-1);
	}

	n = atoi(argv[1]); 
	if (n > 200) 
		n = 200; 
	int a[n];
	chunk = atoi(argv[2]);

	for (i = 0; i < n; i++)
		a[i] = i;
	
	printf("Antes de la modificacion dyn-var: %d \n",omp_get_dynamic());
	printf("Antes de la modificacion nthreads-var: %d \n",omp_get_num_threads());
	omp_get_schedule(&kind,&modificador);
	printf("Antes de la modificacion run-sched-var: %d \n",kind);
	omp_set_dynamic(0);
	omp_set_num_threads(2);
	omp_set_schedule(1,modificador);
	#pragma omp parallel 
	{	
	
		#pragma omp for firstprivate(suma) lastprivate(suma) schedule(dynamic,chunk)
		for (i = 0; i < n; i++)
		{ 
			suma = suma + a[i];
			printf(" thread %d suma a[%d]=%d suma=%d \n", omp_get_thread_num(),i,a[i],suma);
		}

		#pragma omp master
		{
			printf("Despues de la modificacion dyn-var: %d \n",omp_get_dynamic());
			printf("Despues de la modificacion nthreads-var: %d \n",omp_get_num_threads());
			omp_get_schedule(&kind,&modificador);
			printf("Despues de la modificacion run-sched-var: %d \n",kind);
		}
			
	}	

	printf("Fuera de 'parallel for' suma=%d\n",suma);
		
}



