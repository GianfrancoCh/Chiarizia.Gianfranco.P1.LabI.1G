#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tipo.h"

void mostrarTipo(eTipo tipo) {
	printf("||%d | %10s ||\n", tipo.id, tipo.descripcion);
}

int mostrarTipos(eTipo tipos[], int tam) {
	int todoOk = 0;

	if (tipos != NULL && tam > 0) {
		printf("|| ID  |    TIPO  ||\n");
		for (int i = 0; i < tam; i++) {
			mostrarTipo(tipos[i]);
		}
		todoOk = 1;
	}
	return todoOk;
}

int validarIdTipo(int id, eTipo tipos[], int tam) {

	int esValido = 0;
	if (tipos != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			if (id == tipos[i].id) {
				esValido = 1;
				break;
			}
		}
	}
	return esValido;
}

int cargarDescripcionTipo(eTipo tipos[], int tam, int idTipo,
		char descripcion[]) {

	int todoOk = 0;

	if (tipos != NULL && tam > 0 && descripcion != NULL) {
		for (int i = 0; i < tam; i++) {
			if (tipos[i].id == idTipo) {
				strcpy(descripcion, tipos[i].descripcion);
				todoOk = 1;
				break;
			}
		}
	}
	return todoOk;

}

