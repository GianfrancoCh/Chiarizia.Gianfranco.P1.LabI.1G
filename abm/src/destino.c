#include "destino.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrarDestino(eDestino destino) {
	printf("|| %d | %s | $ %d  ||\n", destino.id, destino.descripcion,
			destino.precio);
}

int mostrarDestinos(eDestino destinos[], int tam) {
	int todoOk = 0;
	if (destinos != NULL && tam > 0) {
		printf("|| ID | DESTINO | PRECIO ||\n");
		for (int i = 0; i < tam; i++) {
			mostrarDestino(destinos[i]);
		}
		todoOk = 1;
	}
	return todoOk;
}

int validarIdDestino(int id, eDestino destinos[], int tam) {

	int esValido = 0;
	if (destinos != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			if (id == destinos[i].id) {
				esValido = 1;
				break;
			}
		}
	}
	return esValido;
}

int cargarDescripcionDestino(eDestino destinos[], int tam, int idDestino,
		char descripcion[]) {

	int todoOk = 0;

	if (destinos != NULL && tam > 0 && descripcion != NULL) {
		for (int i = 0; i < tam; i++) {
			if (destinos[i].id == idDestino) {
				strcpy(descripcion, destinos[i].descripcion);
				todoOk = 1;
				break;
			}
		}
	}
	return todoOk;

}
