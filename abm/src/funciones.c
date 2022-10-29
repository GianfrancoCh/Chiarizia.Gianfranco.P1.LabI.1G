#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int confirmarSalida(char *pSalida, char *pMensajeSalida) {
	int retorno = 0;
	char confirma;

	if (pSalida != NULL) {
		printf(" >> ¿Desea salir del menu? <<"
				"\nIngrese [s] para SI o [n] para NO:\n");
		fflush(stdin);
		scanf("%c", &confirma);
		while (confirma != 's' && confirma != 'n') {
			printf("[ERROR] Opcion Invalida");
			printf("\n¿Desea salir del menu?"
					"\nIngrese [s] para SI o [n] para NO:\n");
			fflush(stdin);
			scanf("%c", &confirma);
		}
		if (confirma == 's') {
			*pSalida = 'n';
			printf("%s", pMensajeSalida);
		}

		retorno = 1;
	}

	return retorno;
}

int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos) {

	int retorno = -1;
	int buffer;

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo <= maximo && reintentos >= 0) {
		do {
			printf("%s", mensaje);
			scanf("%d", &buffer);
			if (buffer <= maximo && buffer >= minimo) {

				*pResultado = buffer;
				retorno = buffer;
				break;
			} else {
				printf("%s", mensajeError);
				reintentos--;
			}

		} while (reintentos >= 0);
	}

	return retorno;

}

int ingresarInt(char mensaje[]) {

	int numeroIngresado;

	printf("%s", mensaje);
	scanf("%d", &numeroIngresado);

	return numeroIngresado;
}

