#include "vuelos.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int buscarLibreVuelo(eVuelo vuelos[], int tamV) {

	int indice = -1;
	for (int i = 0; i < tamV; i++) {
		if (vuelos[i].isEmpty) {
			indice = i;
			break;
		}
	}
	return indice;
}

int altaVuelo(eVuelo vuelos[], int tamV, int *pId, eAvion aviones[], int tamA,
		eAerolinea aerolineas[], int tamAer, eTipo tipos[], int tamT,
		eDestino destinos[], int tamD, ePiloto pilotos[], int tamP) {

	int todoOk = 0;
	int indice;
	eVuelo auxVuelo;

	if (vuelos != NULL && tamV > 0) {

		indice = buscarLibreVuelo(vuelos, tamV);

		if (indice == -1) {
			printf("No hay lugar en el sistema\n");
		} else {

			printf("***** ALTA VUELO ******\n");
			auxVuelo.id = *pId;
			(*pId)++;

			mostrarDestinos(destinos, tamD);

			auxVuelo.idDestino = ingresarInt("Ingrese ID de destino: ");

			while (!validarIdDestino(auxVuelo.idDestino, destinos, tamD)) {

				auxVuelo.idDestino = ingresarInt(
						"Ingrese ID de destino valido: ");
			}

			mostrarAviones(aviones, tamA, aerolineas, tamAer, tipos, tamT,
					pilotos, tamP);

			auxVuelo.idAvion = ingresarInt("Ingrese ID de avion: ");

			while (!validarIdAvion(auxVuelo.idAvion, aviones, tamA)) {
				auxVuelo.idAvion = ingresarInt(
						"Ingrese ID de tipo de avion valido: ");
			}

			auxVuelo.fecha.dia = utn_getNumero(&auxVuelo.fecha.dia,
					"Ingrese dia [1-31]", "Ingrese dia valido", 1, 31, 10);
			auxVuelo.fecha.mes = utn_getNumero(&auxVuelo.fecha.mes,
					"Ingrese mes [1-12]", "Ingrese mes valido", 1, 12, 10);
			auxVuelo.fecha.anio = utn_getNumero(&auxVuelo.fecha.anio,
					"Ingrese año [2022-2024]", "Ingrese anio valido", 2022,
					2024, 10);

			auxVuelo.isEmpty = 0;
			vuelos[indice] = auxVuelo;
			todoOk = 1;
		}

	}

	return todoOk;
}

void mostrarVuelo(eVuelo vuelo, eAvion aviones[], int tamA,
		eAerolinea aerolineas[], int tamAer, eTipo tipos[], int tamT,
		eDestino destinos[], int tamD, ePiloto pilotos[], int tamP) {

	char descripcionDest[25];
	cargarDescripcionDestino(destinos, tamD, vuelo.idDestino, descripcionDest);

	printf("||%04d | %04d |   %5s   |  %d/%d/%d  ||\n", vuelo.id, vuelo.idAvion,
			descripcionDest, vuelo.fecha.dia, vuelo.fecha.mes,
			vuelo.fecha.anio);
}

int mostrarVuelos(eVuelo vuelos[], int tamV, eAvion aviones[], int tamA,
		eAerolinea aerolineas[], int tamAer, eTipo tipos[], int tamT,
		eDestino destinos[], int tamD, ePiloto pilotos[], int tamP) {
	int todoOk = 0;

	if (vuelos != NULL && tamV > 0) {
		system("cls");
		printf("-------------     VUELOS   --------------\n");
		printf("------------------------------------------\n");
		printf("||  ID VUELO |  ID AVION   |  DESTINO | FECHA ||\n");

		for (int i = 0; i < tamV; i++) {
			if (!vuelos[i].isEmpty) {

				mostrarVuelo(vuelos[i], aviones, tamA, aerolineas, tamAer,
						tipos, tamT, destinos, tamD, pilotos, tamP);
			}
		}
		todoOk = 1;
	}

	return todoOk;

}

