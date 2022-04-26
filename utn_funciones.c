/*
 * biblioteca.c
 *
 *  Created on: 13 abr. 2022
 *      Author: Ignacio javier Medici
 */

#include "utn_funciones.h"

static int EsNumerica(char* cadena);
static int GetInt(int* pResultado);
static int MyGets(char* cadena , int longitud);
int utn_GetNumero(char* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int buffer;
	
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			if(GetInt(&buffer) == 0 && buffer >= minimo && buffer <= maxiomo)
			{
				*pResultado = buffer;
				retorno = 0;
				break;
			}
			reintentos--;
			printf("%s", mensajeError");
		}while(reintentos >= 0);     
	}
	return retorno;
}

