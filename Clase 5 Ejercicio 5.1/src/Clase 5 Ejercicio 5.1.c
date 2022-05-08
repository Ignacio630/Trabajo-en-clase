/*
 ============================================================================
 Name        : 1.c
 Author      : 
 Ejercicio 5-1:
 Pedir el ingreso de 5 números. Mostrarlos y calcular y
 mostrar la sumatoria de los mismos.
 ============================================================================
 */
#include "funciones.h"
#define TAM 5
int main(void) {
	setbuf(stdout, NULL);
	int numero[TAM];
	int suma;

	suma = sumaArrays(numero, TAM);

	printf("La suma de los numeros es: %d", suma);

	return EXIT_SUCCESS;
}
