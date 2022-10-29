#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "avion.h"
#include "tipo.h"
#include "aerolinea.h"
#include "destino.h"
#include "vuelos.h"
#include "piloto.h"
#include "funciones.h"

#define TAM 5
#define TAM_TIPOS 4
#define TAM_AER 5
#define TAM_DES 4
#define TAM_V 5
#define TAM_P 4

int menu();
int menuInfomes();

int main() {

	setbuf(stdout, NULL);
	char seguir = 's';
	int nextId = 100;
	int nextIdVuelos = 200;

	eAvion aviones[TAM];
	eVuelo vuelos[TAM_V];

	eTipo tipos[TAM_TIPOS] = { { 5000, "Jet" }, { 5001, "Helice" }, { 5002,
			"Planeador" }, { 5003, "Carga" } };

	eAerolinea aerolineas[TAM_AER] = { { 1000, "Lan" }, { 1001, "Iberia" }, {
			1002, "Norwegian" }, { 1003, "American" }, { 1004, "Austral" } };

	eDestino destinos[TAM_DES] = { { 20000, "Calafate", 22250 }, { 20001,
			"Miami", 103000 }, { 20002, "Milan", 84400 }, { 20003, "Amsterdam",
			95600 } };

	ePiloto pilotos[TAM_P] = { { 601, "Pepe", 'm' }, { 602, "Rosa", 'f' }, {
			603, "Juan", 'm' }, { 604, "Maria", 'f' } };

	if (!inicializarAvion(aviones, TAM)) {
		printf("Problemas al inicializar");
	}

	do {
		switch (menu()) {

		case 1:

			if (!altaAvion(aviones, TAM, &nextId, aerolineas, TAM_AER, tipos,
			TAM_TIPOS, pilotos, TAM_P)) {

				printf("No se pudo realizar el alta \n");
			} else {

				printf("\n Alta exitosa \n\n");
			}
			break;

		case 2:
			if (!modificarAvion(aviones, TAM, aerolineas, TAM_AER, tipos,
			TAM_TIPOS, pilotos, TAM_P)) {
				printf("No se pudo realizar la modificacion\n");
			} else {
				printf("\n Modificacion exitosa \n");
			}
			break;

		case 3:
			if (!bajaAvion(aviones, TAM, aerolineas, TAM_AER, tipos,
			TAM_TIPOS, pilotos, TAM_P)) {
				printf("No se pudo realizar la baja\n");
			} else {
				printf("\n Baja exitosa \n");
			}
			break;

		case 4:

			if (!ordenarAviones(aviones, TAM)) {

				printf("No se pudo ordenar los aviones\n");

			} else {

				printf("\n Se ordenaron los aviones con exito \n");
				mostrarAviones(aviones, TAM, aerolineas, TAM_AER, tipos,
				TAM_TIPOS, pilotos, TAM_P);
			}
			break;

		case 5:

			if (!mostrarAerolineas(aerolineas, TAM_AER)) {

				printf("No se pudo mostrar las aerolineas\n");

			} else {

				mostrarAerolineas(aerolineas, TAM_AER);
			}

			break;
		case 6:

			if (!mostrarTipos(tipos, TAM_TIPOS)) {

				printf("No se pudo mostrar los tipos de aviones\n");

			} else {

				mostrarAerolineas(aerolineas, TAM_TIPOS);
			}

			break;

		case 7:

			if (!mostrarDestinos(destinos, TAM_DES)) {
				printf("No se pudo mostrar los destinos\n");

			} else {

				mostrarDestinos(destinos, TAM_DES);
			}
			break;

		case 8:
			if (!altaVuelo(vuelos, TAM_V, &nextIdVuelos, aviones, TAM,
					aerolineas, TAM_AER, tipos, TAM_TIPOS, destinos, TAM_DES,
					pilotos, TAM_P)) {

				printf("No se pudo realizar el alta de vuelo \n");
			} else {

				printf("\n Alta vuelo exitos \n\n");
			}
			break;

		case 9:
			if (!mostrarVuelos(vuelos, TAM_V, aviones, TAM, aerolineas, TAM_AER,
					tipos, TAM_TIPOS, destinos, TAM_DES, pilotos, TAM_P)) {
				printf("Error al mostrar vuelos");

			} else {
				mostrarVuelos(vuelos, TAM_V, aviones, TAM, aerolineas, TAM_AER,
						tipos, TAM_TIPOS, destinos, TAM_DES, pilotos, TAM_P);
			}

			break;

		case 10:

			switch (menuInfomes()) {
			case 1:

				if (!mostrarAvionAerolinea(aviones, TAM, aerolineas, TAM_AER,
						tipos, TAM_TIPOS, pilotos, TAM_P)) {
					printf("Error al mostrar");

				} else {
					mostrarAvionAerolinea(aviones, TAM, aerolineas, TAM_AER,
							tipos, TAM_TIPOS, pilotos, TAM_P);
				}

				break;
			case 2:

				if (!mostrarAvionTipo(aviones, TAM, aerolineas, TAM_AER, tipos,
				TAM_TIPOS, pilotos, TAM_P)) {
					printf("Error al mostrar");

				} else {
					mostrarAvionTipo(aviones, TAM, aerolineas, TAM_AER, tipos,
					TAM_TIPOS, pilotos, TAM_P);
				}

				break;

			case 3:
				if (!promedioJetAerolinea(aviones, TAM, aerolineas, TAM_AER,
						tipos, TAM_TIPOS, pilotos, TAM_P)) {
					printf("Error al mostrar");

				} else {
					promedioJetAerolinea(aviones, TAM, aerolineas, TAM_AER,
							tipos, TAM_TIPOS, pilotos, TAM_P);
				}

				break;
			case 4:
				if (!mostrarAvionPorAerolinea(aviones, TAM, aerolineas, TAM_AER,
						tipos, TAM_TIPOS, pilotos, TAM_P)) {
					printf("Error al mostrar");

				} else {
					mostrarAvionPorAerolinea(aviones, TAM, aerolineas, TAM_AER,
							tipos, TAM_TIPOS, pilotos, TAM_P);
				}
				break;
			case 5:
				if (!aerolineaMayorCapacidad(aviones, TAM, aerolineas,
				TAM_AER, tipos, TAM_TIPOS, pilotos, TAM_P)) {
					printf("Error al mostrar");

				} else {
					aerolineaMayorCapacidad(aviones, TAM, aerolineas,
					TAM_AER, tipos, TAM_TIPOS, pilotos, TAM_P);
				}
				break;

			case 6:
				if (!aerolineaMenosAviones(aviones, TAM, aerolineas, TAM_AER,
						tipos, TAM_TIPOS, pilotos, TAM_P)) {
					printf("Error al mostrar");

				} else {
					aerolineaMenosAviones(aviones, TAM, aerolineas, TAM_AER,
							tipos, TAM_TIPOS, pilotos, TAM_P);
				}
				break;
			default:
				printf(">>La opcion ingresada no es valida<<\n"
						"Ingrese una opcion valida de menu!\n\n");
			}

		case 11:
			confirmarSalida(&seguir, "\n\n>> SALIENDO <<");
			break;

		default:
			printf(">>La opcion ingresada no es valida<<\n"
					"Ingrese una opcion valida de menu!\n\n");
		}
	} while (seguir == 's');

}

int menu() {

	int opcion;

	printf("      ***** MENU INFORMES *****    \n\n");
	printf("1- Alta avion\n");
	printf("2- Modificar avion\n");
	printf("3- Baja avion\n");
	printf("4- Listar aviones\n");
	printf("5- Listar aerolineas\n");
	printf("6- Listar tipos\n");
	printf("7- Listar destinos\n");
	printf("8- Alta  vuelo \n");
	printf("9- Listar vuelos\n");
	printf("10- Menu informes. \n");
	printf("11- Salir. \n");
	printf("Ingrese una opcion: \n");
	scanf("%d", &opcion);

	return opcion;
}

int menuInformes() {

	int opcion;

	printf("   *** ABM AVIONES *** \n\n");
	printf("1- Mostrar aviones de una aerolinea seleccionada\n");
	printf("2- Mostrar aviones de un tipo\n");
	printf("3- Promedio aviones jet sobre aviones una aerolinea\n");
	printf("4- Mostrar aviones separados por aerolinea\n");
	printf("5- Mostrar aerolineas con mas capacidad\n");
	printf("6- Aerolinea con menos cantidad de aviones\n");
	printf("7- Pedir avion y mostrar sus vuelos\n");
	printf("8- Pedir avion e informar costo de todos los vuelos que realizo\n");
	printf("9- Pedir destino y mostrar aviones de ese destino y cuando\n");
	printf("10- Pedir fecha y mostrar vuelos realizados en la misma. \n");
	printf("11- Salir. \n");
	printf("Ingrese una opcion: \n");
	scanf("%d", &opcion);

	return opcion;
}

