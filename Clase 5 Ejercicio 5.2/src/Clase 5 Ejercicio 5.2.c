/*
 ============================================================================
 Name        : 2.c
 Author      : 
  Pedir el ingreso de 10 números enteros entre -1000 y 1000. Determinar:

 Cantidad de positivos y negativos.
 Sumatoria de los pares.
 El mayor de los impares.
 Listado de los números ingresados.
 Listado de los números pares.
 Listado de los números de las posiciones impares.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int GetArrayInt(int[] ,int ,char[] ,char[] ,int ,int);

int main(void)
{
	setbuf(stdout,NULL);
	int numeroEntero[MAX];
	int i;

	for(i=0;i<MAX;i++)
	{
		GetArrayInt(numeroEntero ,MAX ,"Ingrese un numero entre -1000 y 1000: " ,"Error, ingreso un numero invalido, por favor reingrese: " ,-1000 ,1000);
	}

	return EXIT_SUCCESS;
}
int GetArrayInt(int entero[] ,int size ,char mensaje[] ,char mensajeError[] ,int minimo ,int maximo)
{
	int retorno= -1;
	int i;
	int bufferInt;
	if(entero != NULL && minimo <= maximo)
	{
		for(i=0;i<size;i++)
		{

		}
	}
	else
	{
		printf("%s", mensajeError);
	}
	return retorno;
}

















