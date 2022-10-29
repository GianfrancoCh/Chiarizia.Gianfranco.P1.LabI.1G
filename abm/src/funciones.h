#ifndef FUNCIONES_H_
#define FUNCIONES_H_

int confirmarSalida(char *pSalida, char *pMensajeSalida);
int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos);
int ingresarInt(char mensaje[]);

#endif /* FUNCIONES_H_ */
