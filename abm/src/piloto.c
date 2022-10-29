#include "piloto.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrarPiloto(ePiloto piloto) {

	printf("|| %d | %10s ||\n", piloto.id, piloto.nombre, piloto.sexo);
}

int mostrarPilotos(ePiloto pilotos[], int tamP) {

	int todoOk = 0;

	if (pilotos != NULL && tamP > 0) {
		printf("\n====================================================\n");
		printf("|| ID   |  NOMBRE | SEXO ||\n");
		for (int i = 0; i < tamP; i++) {
			mostrarPiloto(pilotos[i]);
		}
		todoOk = 1;
	}
	return todoOk;
}

int validarIdPiloto(int id, ePiloto pilotos[], int tamP) {

	int esValido = 0;
	if (pilotos != NULL && tamP > 0) {
		for (int i = 0; i < tamP; i++) {
			if (id == pilotos[i].id) {
				esValido = 1;
				break;
			}
		}
	}
	return esValido;

}

int cargarNombrePiloto(ePiloto pilotos[], int tamP, int idPiloto,
		char descripcion[]) {

	int todoOk = 0;

	if (pilotos != NULL && tamP > 0 && descripcion != NULL) {
		for (int i = 0; i < tamP; i++) {
			if (pilotos[i].id == idPiloto) {
				strcpy(descripcion, pilotos[i].nombre);
				todoOk = 1;
				break;
			}
		}
	}
	return todoOk;

}
