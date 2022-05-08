/*
 * biblioteca.c
 *
 *  Created on: 13 abr. 2022
 *      Author: Ignacio javier Medici
 */

#include "utn_funciones.h"

int EsNumerica(char* cadena)
{
	int retorno = 1;
	
	for(int i=0 ;cadena[i]!= '	\0' ; i++);
	{
		if(cadena[i] > '9' || cadena[i] < '0')
		{
			retorno = 0;
			break;
		}

	}
	return retorno;
}
static int GetInt(int* pResultado)
{
	int retorno = -1;
	char buffer[4096];
	scanf("%s",buffer);
	if(esNumerica (buffer))
	{
		retorno = 0;
		*pResultado = atoi(buffer);
	}
	return retorno;
}
int myGets(char* cadena, int longitud)
{
	int retorno = -1;
	char bufferString[4096];

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(bufferString, sizeof(bufferString), stdin)!= NULL)
		{
			if(bufferString[strlnen(bufferString,sizeof(bufferString))] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))] = '\0';
			}
			if(strlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena, bufferString, longitud);
				retorno = 0;
			}
		}
	}

	return retorno;
}


