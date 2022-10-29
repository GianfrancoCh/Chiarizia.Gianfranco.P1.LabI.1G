#ifndef AEROLINEA_H_
#define AEROLINEA_H_
#define TAM_AER 5

typedef struct {
	int id;
	char descripcion[20];

} eAerolinea;

void mostrarAerolinea(eAerolinea aerolinea);
int mostrarAerolineas(eAerolinea aerolineas[], int tam);
int validarIdAerolinea(int id, eAerolinea aerolineas[], int tam);
int cargarDescripcionAerolinea(eAerolinea aerolineas[], int tam,
		int idAerolinea, char descripcion[]);
#endif /* AEROLINEA_H_ */
