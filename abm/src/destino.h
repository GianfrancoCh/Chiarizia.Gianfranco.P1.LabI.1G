#ifndef DESTINO_H_
#define DESTINO_H_

typedef struct {
	int id;
	char descripcion[25];
	int precio;

} eDestino;

void mostrarDestino(eDestino destino);
int mostrarDestinos(eDestino destinos[], int tam);
int validarIdDestino(int id, eDestino destinos[], int tam);
int cargarDescripcionDestino(eDestino destinos[], int tam, int idDestino,
		char descripcion[]);

#endif /* DESTINO_H_ */
