#include "aerolinea.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrarAerolinea(eAerolinea aerolinea) {
	printf("|| %d | %10s ||\n", aerolinea.id, aerolinea.descripcion);
}

int mostrarAerolineas(eAerolinea aerolineas[], int tam) {
	int todoOk = 0;

	if (aerolineas != NULL && tam > 0) {
		printf("\n====================================================\n");
		printf("|| ID   |  AEROLINEA ||\n");
		for (int i = 0; i < tam; i++) {
			mostrarAerolinea(aerolineas[i]);
		}
		todoOk = 1;
	}
	return todoOk;
}

int validarIdAerolinea(int id, eAerolinea aerolineas[], int tam) {

	int esValido = 0;
	if (aerolineas != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			if (id == aerolineas[i].id) {
				esValido = 1;
				break;
			}
		}
	}
	return esValido;

}

int cargarDescripcionAerolinea(eAerolinea aerolineas[], int tam,
		int idAerolinea, char descripcion[]) {

	int todoOk = 0;

	if (aerolineas != NULL && tam > 0 && descripcion != NULL) {
		for (int i = 0; i < tam; i++) {
			if (aerolineas[i].id == idAerolinea) {
				strcpy(descripcion, aerolineas[i].descripcion);
				todoOk = 1;
				break;
			}
		}
	}
	return todoOk;

}

