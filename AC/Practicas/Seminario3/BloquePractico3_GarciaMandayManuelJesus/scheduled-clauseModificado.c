#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
	#include <omp.h>
#else
	#define omp_get_thread_num() 0
#endif

main(int argc, char **argv) {

	int i, n = 16, chunk, a[n], suma = 0, modificador;
	omp_sched_t kind;

	if(argc < 3) {
		fprintf(stderr,"\nFalta iteraciones o chunk \n");
		exit(-1);
	}

	n = atoi(argv[1]); 
	if (n > 200) 
		n = 200; 

	chunk = atoi(argv[2]);

	for (i = 0; i < n; i++)
		a[i] = i;
	
	#pragma omp parallel 		
	{

		#pragma omp master 
		{
			printf("Dentro del parallel dyn-var: %d \n",omp_get_dynamic());
			printf("Dentro del parallel nthreads-var: %d \n",omp_get_num_threads());
			printf("Dentro del parallel thread-limit-var: %d \n",omp_get_max_threads());
			omp_get_schedule(&kind,&modificador);
			printf("Dentro del parallel run-sched-var: %d \n", kind);
		}	

		#pragma omp for firstprivate(suma) lastprivate(suma) schedule(dynamic,chunk)
		for (i = 0; i < n; i++)
		{ 
			suma = suma + a[i];
			printf(" thread %d suma a[%d]=%d suma=%d \n", omp_get_thread_num(),i,a[i],suma);
		}
	}

	printf("Fuera de 'parallel for' suma=%d\n",suma);
	printf("Despues del parallel dyn-var: %d \n",omp_get_dynamic());
	printf("Despues del parallel nthreads-var: %d \n",omp_get_num_threads());
	printf("Despues del parallel thread-limit-var: %d \n",omp_get_max_threads());
	omp_get_schedule(&kind,&modificador);
	printf("Despues del parallel run-sched-var: %d \n", kind);

}


