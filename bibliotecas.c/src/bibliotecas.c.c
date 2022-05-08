/*
 ============================================================================
 Name        : c.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "utn_funciones.h"
#include "utn_validaciones.h"
#define TAM 10

int main(void) {
	setbuf(stdout, NULL);

	int entero;
	float flotante;

	PedirEntero("Ingrese un entero: ");
	PedirFlotante("Ingrese un entero flotante:");

	ValidarParidad(entero);
	ValidarParidad(flotante);

	return EXIT_SUCCESS;
}
