#ifndef VUELOS_H_
#define VUELOS_H_

#include "piloto.h"
#include "aerolinea.h"
#include "avion.h"
#include "tipo.h"
#include "destino.h"
#include "funciones.h"

typedef struct {
	int dia;
	int mes;
	int anio;

} eFecha;

typedef struct {
	int id;
	int idAvion;
	int idDestino;
	eFecha fecha;
	int isEmpty; // 1 esta vacio, 0 esta lleno

} eVuelo;

int buscarLibreVuelo(eVuelo vuelos[], int tamV);

int altaVuelo(eVuelo vuelos[], int tamV, int *pId, eAvion aviones[], int tamA,
		eAerolinea aerolineas[], int tamAer, eTipo tipos[], int tamT,
		eDestino destinos[], int tamD, ePiloto pilotos[], int tamP);

void mostrarVuelo(eVuelo vuelo, eAvion aviones[], int tamA,
		eAerolinea aerolineas[], int tamAer, eTipo tipos[], int tamT,
		eDestino destinos[], int tamD, ePiloto pilotos[], int tamP);

int mostrarVuelos(eVuelo vuelos[], int tamV, eAvion aviones[], int tamA,
		eAerolinea aerolineas[], int tamAer, eTipo tipos[], int tamT,
		eDestino destinos[], int tamD, ePiloto pilotos[], int tamP);

#endif /* VUELOS_H_ */
