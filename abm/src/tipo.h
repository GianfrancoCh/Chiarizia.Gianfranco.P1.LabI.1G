#ifndef TIPO_H_
#define TIPO_H_
#define TAM_TIPO 4

typedef struct {
	int id;
	char descripcion[20];

} eTipo;

void mostrarTipo(eTipo tipo);
int mostrarTipos(eTipo tipos[], int tam);
int validarIdTipo(int id, eTipo tipos[], int tam);
int cargarDescripcionTipo(eTipo tipos[], int tam, int idTipo,
		char descripcion[]);

#endif /* TIPO_H_ */
