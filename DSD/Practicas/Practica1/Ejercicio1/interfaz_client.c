/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "interfaz.h"


void
ejercicio1_1(char *host, param arg1, char *op)
{
	CLIENT *clnt;
	int  *result;

#ifndef	DEBUG
	clnt = clnt_create (host, EJERCICIO1, EJERVER, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	switch(*op) {
		case '+':
			result = suma_1(arg1, clnt);
			if (result == (int *) NULL) {
				clnt_perror (clnt, "call failed");
			}
			else
				printf("El resultado de la suma es: %d \n", *result);

			break;

		case '-':
			result = resta_1(arg1, clnt);
			if (result == (int *) NULL) {
				clnt_perror (clnt, "call failed");
			}
			else
				printf("El resultado de la resta es: %d \n", *result);

			break;
		
		case 'x':
			result = multiplica_1(arg1, clnt);
			if (result == (int *) NULL) {
				clnt_perror (clnt, "call failed");
			}
			else
				printf("El resultado de la multiplicacion es: %d \n", *result);
			
			break;
	
		case '/':		
			result = divide_1(arg1, clnt);
			if (result == (int *) NULL) {
				clnt_perror (clnt, "call failed");
			}
			else
				printf("El resultado de la division es: %d \n", *result);

			break;

		default:
			break;
	}

#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host, *oper;
	param args;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}

	host = argv[1];
	args.primero = atoi(argv[2]);
	oper = argv[3];
	args.segundo = atoi(argv[4]);

	ejercicio1_1 (host, args, oper);
	exit (0);
}
