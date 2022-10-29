#ifndef PILOTO_H_
#define PILOTO_H_

typedef struct {

	int id;
	char nombre[20];
	char sexo;
} ePiloto;

void mostrarPiloto(ePiloto piloto);
int mostrarPilotos(ePiloto pilotos[], int tamP);
int validarIdPiloto(int id, ePiloto pilotos[], int tamP);
int cargarNombrePiloto(ePiloto pilotos[], int tamP, int idPiloto,
		char descripcion[]);
#endif /* PILOTO_H_ */
