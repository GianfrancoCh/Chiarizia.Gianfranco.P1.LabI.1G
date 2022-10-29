#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "avion.h"
#include "funciones.h"

int inicializarAvion(eAvion aviones[], int tamA) {
	int todoOk = 0;

	if (aviones != NULL && tamA > 0) {
		for (int i = 0; i < tamA; i++) {
			aviones[i].isEmpty = 1;
		}

		todoOk = 1;
	}
	return todoOk;
}

int buscarLibre(eAvion aviones[], int tamA) {
	int indice = -1;
	for (int i = 0; i < tamA; i++) {
		if (aviones[i].isEmpty) {
			indice = i;
			break;
		}

	}
	return indice;
}

int altaAvion(eAvion aviones[], int tamA, int *pId, eAerolinea aerolineas[],
		int tamAer, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP) {
	int todoOk = 0;
	int indice;
	eAvion auxAvion;

	if (aviones != NULL && tamA > 0) {
		indice = buscarLibre(aviones, tamA);
		if (indice == -1) {
			printf("No hay lugar en el sistema\n");
		} else {

			printf("***** ALTA AVION ******\n");
			auxAvion.id = *pId;
			(*pId)++;

			mostrarAerolineas(aerolineas, tamAer);

			auxAvion.idAerolinea = ingresarInt("Ingrese ID de aerolinea: ");

			while (!validarIdAerolinea(auxAvion.idAerolinea, aerolineas, tamAer)) {

				auxAvion.idAerolinea = ingresarInt(
						"Ingrese ID de aerolinea valido: ");
			}

			mostrarTipos(tipos, tamT);

			auxAvion.idTipo = ingresarInt("Ingrese ID de tipo de avion: ");

			while (!validarIdTipo(auxAvion.idTipo, tipos, tamT)) {
				auxAvion.idTipo = ingresarInt(
						"Ingrese ID de tipo de avion valido: ");
			}

			auxAvion.capacidad = utn_getNumero(&auxAvion.capacidad,
					"Ingrese capacidad [10-300]", "Ingrese capacidad valida",
					10, 300, 5);

			auxAvion.idPiloto = ingresarInt("Ingrese ID de piloto: ");
			while (!validarIdPiloto(auxAvion.idPiloto, pilotos, tamP)) {
				auxAvion.idPiloto = ingresarInt(
						"Ingrese ID de tipo de avion valido: ");
			}

			auxAvion.isEmpty = 0;
			aviones[indice] = auxAvion;
			todoOk = 1;
		}

	}

	return todoOk;
}

void mostrarAvion(eAvion avion, eAerolinea aerolineas[], int tamAer,
		eTipo tipos[], int tamT, ePiloto pilotos[], int tamP) {

	char descTipo[20];
	char descAerolinea[20];
	char nombrePiloto[20];

	cargarDescripcionTipo(tipos, tamT, avion.idTipo, descTipo);
	cargarDescripcionAerolinea(aerolineas, tamAer, avion.idAerolinea,
			descAerolinea);
	cargarNombrePiloto(pilotos, tamP, avion.idPiloto, nombrePiloto);
	printf("||%04d  |   %5s     | %5s  |  %d    | %s  ||\n", avion.id,
			descAerolinea, descTipo, avion.capacidad, nombrePiloto);

}

int mostrarAviones(eAvion aviones[], int tamA, eAerolinea aerolineas[],
		int tamAer, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP) {

	int todoOk = 0;
	if (aviones != NULL && tamA > 0) {
		system("cls");
		printf("-------------     AVIONES   --------------\n");
		printf("------------------------------------------\n");
		printf("||  ID  |  AEROLINEA  |  TIPO | CAPACIDAD | NOMBRE PILOTO||\n");

		for (int i = 0; i < tamA; i++) {
			if (!aviones[i].isEmpty) {
				mostrarAvion(aviones[i], aerolineas, tamAer, tipos, tamT,
						pilotos, tamP);
			}
		}
		todoOk = 1;
	}

	return todoOk;

}

int bajaAvion(eAvion aviones[], int tamA, eAerolinea aerolineas[], int tamAer,
		eTipo tipos[], int tamT, ePiloto pilotos[], int tamP) {
	int indice;
	int todoOk = 0;
	int id;
	char confirma;
	if (aviones != NULL && tamA > 0) {
		system("cls");
		printf("*** BAJA AVION *** \n\n");
		id = ingresarInt("Ingrese ID para generar baja: \n");
		indice = (buscarAvionId(aviones, tamA, id));
		if (indice == -1) {
			printf("El ID: %d no esta registrado", id);
		} else {
			mostrarAvion(aviones[indice], aerolineas, tamAer, tipos, tamT,
					pilotos, tamP);
			printf("Confirma baja? [s/n]");
			fflush(stdin);
			scanf("%c", &confirma);
			confirma = tolower(confirma);
			if (confirma == 's') {
				aviones[indice].isEmpty = 1;
				todoOk = 1;
			} else {
				printf("Baja cancelada");
			}
		}

	}

	return todoOk;
}

int modificarAvion(eAvion aviones[], int tamA, eAerolinea aerolineas[],
		int tamAer, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP) {

	int indice;
	int todoOk = 0;
	int id;
	char confirma;
	int auxT;
	int auxC;
	int auxP;
	char seguir;

	if (aviones != NULL && tamA > 0) {
		system("cls");
		printf("*** MODIFICAR AVION *** \n\n");
		id = ingresarInt("Ingrese ID de avion a modificar");
		indice = (buscarAvionId(aviones, tamA, id));
		if (indice == -1) {

			printf("El ID: %d no esta registrado en el sistema", id);

		} else {

			mostrarAvion(aviones[indice], aerolineas, tamAer, tipos, tamT,
					pilotos, tamP);

			printf("Confirma modificacion?");
			fflush(stdin);
			scanf("%c", &confirma);
			confirma = tolower(confirma);
			if (confirma == 's') {

				do {
					switch (menuModificacion()) {
					case 1:
						mostrarTipos(tipos, tamT);

						auxT = ingresarInt("Ingrese ID de tipo de avion: ");

						while (!validarIdTipo(auxT, tipos, tamT)) {
							auxT = ingresarInt(
									"Ingrese ID de tipo de avion valido: ");
						}
						break;
					case 2:
						auxC = utn_getNumero(&auxC,
								"Ingrese capacidad [10-300]",
								"Ingrese capacidad valida", 10, 300, 5);
						break;
					case 3:
						auxP = ingresarInt("Ingrese ID piloto: ");
						while (!validarIdPiloto(auxP, pilotos, tamP)) {

							auxP = ingresarInt(
									"Ingrese ID de tipo de avion valido: ");
						}
						break;
					case 4:

						seguir = 'n';

						break;
					default:
						printf("Error! Opcion invalida");
					}
				} while (seguir == 's');

				todoOk = 1;
			} else {
				printf("Modificacion cancelada");
			}
		}
	}
	return todoOk;
}

int buscarAvionId(eAvion aviones[], int tamA, int id) {

	int indice = -1;
	for (int i = 0; i < tamA; i++) {

		if (!aviones[i].isEmpty && aviones[i].id == id) {
			indice = i;
			break;
		}
	}

	return indice;
}

int menuModificacion() {

	int opcion;

	printf("¿Que desea modificar?");
	printf("1- Tipo\n");
	printf("2- Capacidad\n");
	printf("3- Piloto");
	printf("4- Salir\n");
	printf("Ingrese opcion: \n");
	scanf("%d", &opcion);

	return opcion;
}

int ordenarAviones(eAvion aviones[], int tamA) {
	int todoOk = 0;
	eAvion auxAvion;

	if (aviones != NULL && tamA > 0) {
		for (int i = 0; i < tamA - 1; i++) {
			for (int j = i + 1; j < tamA; j++) {
				if (aviones[i].idAerolinea > aviones[j].idAerolinea
						|| (aviones[i].idAerolinea == aviones[j].idAerolinea
								&& aviones[i].capacidad > aviones[j].capacidad)) {
					auxAvion = aviones[i];
					aviones[i] = aviones[j];
					aviones[j] = auxAvion;
				}
			}
		}

		todoOk = 1;
	}

	return todoOk;
}

int validarIdAvion(int id, eAvion aviones[], int tamA) {

	int esValido = 0;
	if (aviones != NULL && tamA > 0) {
		for (int i = 0; i < tamA; i++) {
			if (id == aviones[i].id) {
				esValido = 1;
				break;
			}
		}
	}
	return esValido;

}

int mostrarAvionAerolinea(eAvion aviones[], int tamA, eAerolinea aerolineas[],
		int tamAer, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP) {

	int todoOk = 0;
	int idAero;

	if (aviones != NULL && tamA > 0) {
		system("cls");

		mostrarAerolineas(aerolineas, tamAer);
		idAero = ingresarInt("Ingresar ID aerolinea a mostrar aviones: ");
		while (!validarIdAerolinea(idAero, aerolineas, tamAer)) {
			idAero = ingresarInt("Error, ingrese ID aerolinea valido : ");
		}

		mostrarAvionesIdAerolinea(aviones, tamA, aerolineas, tamAer, tipos,
				tamT, pilotos, tamP, idAero);
		todoOk = 1;
	}
	return todoOk;
}

int mostrarAvionesIdAerolinea(eAvion aviones[], int tamA,
		eAerolinea aerolineas[], int tamAer, eTipo tipos[], int tamT,
		ePiloto pilotos[], int tamP, int idAero) {
	int todoOk = 0;
	char aeroBuscada[20];
	int flagNada = 1;
	if (aviones != NULL && tamA > 0) {
		for (int i = 0; i < tamA; i++) {
			if (aviones[i].isEmpty == 0 && aviones[i].idAerolinea == idAero) {
				mostrarAvion(aviones[i], aerolineas, tamAer, tipos, tamT,
						pilotos, tamP);
				flagNada = 0;
			}
		}
		if (flagNada) {
			cargarDescripcionAerolinea(aerolineas, tamAer, idAero, aeroBuscada);
			printf("No hay notebooks de este tipo  : %s \n", aeroBuscada);
		}
		todoOk = 1;
	}
	return todoOk;
}

int mostrarAvionTipo(eAvion aviones[], int tamA, eAerolinea aerolineas[],
		int tamAer, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP) {

	int todoOk = 0;
	int idTipo;

	if (aviones != NULL && tamA > 0) {
		system("cls");

		mostrarAerolineas(aerolineas, tamAer);
		idTipo = ingresarInt("Ingresar ID de tipo a mostrar aviones: ");
		while (!validarIdTipo(idTipo, tipos, tamT)) {

			idTipo = ingresarInt("ERROR, ingresar ID tipo valido: ");
		}

		mostrarAvionIdTipo(aviones, tamA, aerolineas, tamAer, tipos, tamT,
				pilotos, tamP, idTipo);
		todoOk = 1;
	}
	return todoOk;
}

int mostrarAvionIdTipo(eAvion aviones[], int tamA, eAerolinea aerolineas[],
		int tamAer, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP,
		int idTipo) {

	int todoOk = 0;
	char tipoBuscado[20];
	int flagNada = 1;

	if (aviones != NULL && tamA > 0) {
		for (int i = 0; i < tamA; i++) {
			if (aviones[i].isEmpty == 0 && aviones[i].idAerolinea == idTipo) {
				mostrarAvion(aviones[i], aerolineas, tamAer, tipos, tamT,
						pilotos, tamP);
				flagNada = 0;
			}
		}
		if (flagNada) {
			cargarDescripcionTipo(tipos, tamT, idTipo, tipoBuscado);
			printf("No hay notebooks de este tipo  : %s \n", tipoBuscado);
		}
		todoOk = 1;
	}
	return todoOk;
}

int promedioJetAerolinea(eAvion aviones[], int tamA, eAerolinea aerolineas[],
		int tamAer, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP) {

	int todoOk = 0;
	int contJet = 0;
	int contLan = 0;
	float promedio;
	if (aviones != NULL && tamA > 0) {

		for (int i = 0; i < tamA; i++) {
			if (aviones[i].idTipo == 5000) {
				contJet++;
			}
		}
		for (int i = 0; i < tamA; i++) {
			if (aviones[i].idAerolinea == 1000) {
				contLan++;
			}
		}
		promedio = ((float) contJet / contLan) * 100;

		printf("---- INFORME PROMEDIO AVIONES JET EN LAN ---- ");
		if (contJet == 0 || contLan == 0) {
			printf("No hay aviones tipo jet en LAN ");
		} else {
			printf("El promedio de los aviones JET en LAN es de %.2f",
					promedio);
		}
		todoOk = 1;
	}
	return todoOk;
}

int mostrarAvionPorAerolinea(eAvion aviones[], int tamA,
		eAerolinea aerolineas[], int tamAer, eTipo tipos[], int tamT,
		ePiloto pilotos[], int tamP) {
	int todoOk = 0;
	if (aviones != NULL && tamA > 0) {
		system("cls");
		printf("  ---- AVIONES POR AEROLINEAS ------ \n");
		for (int i = 0; i < tamAer; i++) {
			printf("\n");
			printf("AEROLINEA: %s\n", aerolineas[i].descripcion);
			mostrarAvionesIdAerolinea(aviones, tamA, aerolineas, tamAer, tipos,
					tamT, pilotos, tamP, aerolineas[i].id);
		}
		todoOk = 1;
	}
	return todoOk;
}

int aerolineaMayorCapacidad(eAvion aviones[], int tamA, eAerolinea aerolineas[],
		int tamAer, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP) {

	int todoOk = 0;
	int acumulador[tamAer];
	int mayor;
	int flagMayor = 1;

	if (aviones != NULL && tamA > 0) {
		system("cls");
		printf("       **** INFORME AEROLINEA/S MAYOR CAPACIDAD****     \n");

		for (int i = 0; i < tamAer; i++) {

			acumulador[i] = 0;

		}

		for (int i = 0; i < tamAer; i++) {
			for (int j = 0; j < tamA; j++) {
				if (aviones[j].isEmpty == 0
						&& aviones[j].idAerolinea == aerolineas[i].id) {

					acumulador[i] = acumulador[i] + aviones[j].capacidad;
				}
			}
		}

		for (int i = 0; i < tamAer; i++) {
			if (flagMayor == 1 || acumulador[i] > mayor) {
				mayor = acumulador[i];
				flagMayor = 0;
			}
		}

		for (int i = 0; i < tamAer; i++) {
			if (acumulador[i] == mayor) {
				printf("Las aerolineas con mas capacidad son: %s\n",
						aerolineas[i].descripcion);
			}
		}
		printf("La capacidad es de %d \n", mayor);

		todoOk = 1;
	}
	return todoOk;
}

int aerolineaMenosAviones(eAvion aviones[], int tamA, eAerolinea aerolineas[],
		int tamAer, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP) {

	int todoOk = 0;
	int contadores[tamAer];
	int menor;
	int flagMenor = 1;

	if (aviones != NULL && tamA > 0) {
		system("cls");
		printf("       **** INFORME AEROLINEA/S MENOS AVIONES****     \n");

		for (int i = 0; i < tamAer; i++) {

			contadores[i] = 0;

		}

		for (int i = 0; i < tamAer; i++) {
			for (int j = 0; j < tamA; j++) {
				if (aviones[j].isEmpty == 0
						&& aviones[j].id == aerolineas[i].id) {
					contadores[j]++;
				}
			}
		}

		for (int i = 0; i < tamAer; i++) {
			if (flagMenor == 1 || contadores[i] < menor) {
				menor = contadores[i];
				flagMenor = 0;
			}
		}

		for (int i = 0; i < tamAer; i++) {
			if (contadores[i] == menor) {
				printf("Las aerolineas con menos aviones son: %s\n",
						aerolineas[i].descripcion);
			}
		}
		printf("La cantidad de aviones es de %d \n", menor);

		todoOk = 1;
	}
	return todoOk;
}

