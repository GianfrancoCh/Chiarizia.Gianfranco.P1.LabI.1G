#ifndef AVION_H_
#define AVION_H_
#include "aerolinea.h"
#include "tipo.h"
#include "piloto.h"
#include "funciones.h"
#define TAM 5

typedef struct {
	int id;
	int idAerolinea;
	int idTipo;
	int capacidad;
	int idPiloto;
	int isEmpty; // 1 esta vacio, 0 esta lleno

} eAvion;

int inicializarAvion(eAvion aviones[], int tam);
int buscarLibre(eAvion aviones[], int tam);
int altaAvion(eAvion aviones[], int tamA, int *pId, eAerolinea aerolineas[],
		int tamAer, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP);
void mostrarAvion(eAvion avion, eAerolinea aerolineas[], int tamAer,
		eTipo tipos[], int tamT, ePiloto pilotos[], int tamP);
int mostrarAviones(eAvion aviones[], int tamA, eAerolinea aerolineas[],
		int tamAer, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP);
int bajaAvion(eAvion aviones[], int tamA, eAerolinea aerolineas[], int tamAer,
		eTipo tipos[], int tamT, ePiloto pilotos[], int tamP);
int modificarAvion(eAvion aviones[], int tamA, eAerolinea aerolineas[],
		int tamAer, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP);
int buscarAvionId(eAvion aviones[], int tam, int id);
int menuModificacion();
int ordenarAviones(eAvion aviones[], int tamA);
int validarIdAvion(int id, eAvion aviones[], int tamA);
int mostrarAvionAerolinea(eAvion aviones[], int tamA, eAerolinea aerolineas[],
		int tamAer, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP);
int mostrarAvionesIdAerolinea(eAvion aviones[], int tamA,
		eAerolinea aerolineas[], int tamAer, eTipo tipos[], int tamT,
		ePiloto pilotos[], int tamP, int idAero);
int mostrarAvionTipo(eAvion aviones[], int tamA, eAerolinea aerolineas[],
		int tamAer, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP);
int mostrarAvionIdTipo(eAvion aviones[], int tamA, eAerolinea aerolineas[],
		int tamAer, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP,
		int idTipo);
int mostrarAvionPorAerolinea(eAvion aviones[], int tamA,
		eAerolinea aerolineas[], int tamAer, eTipo tipos[], int tamT,
		ePiloto pilotos[], int tamP);
int promedioJetAerolinea(eAvion aviones[], int tamA, eAerolinea aerolineas[],
		int tamAer, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP);
int aerolineaMayorCapacidad(eAvion aviones[], int tamA, eAerolinea aerolineas[],
		int tamAer, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP);
int aerolineaMenosAviones(eAvion aviones[], int tamA, eAerolinea aerolineas[],
		int tamAer, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP);
#endif /* AVION_H_ */
