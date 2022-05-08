#include "utn_funciones.h"

static int GetInt(int*);
static int esNumerica(char* , int );


	int myGets(char* cadena, int longitud)
	{
		int retorno = -1;
		char bufferString[4096];

		if(cadena != NULL && longitud > 0)
		{
			fflush(stdin);
			if(fgets(bufferString, sizeof(bufferString), stdin)!= NULL)
			{
				if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
				{
					bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
				}
				if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
				{
					strncpy(cadena, bufferString, longitud);
					retorno = 0;
				}
			}
		}

		return retorno;
	}
	static int esNumerica(char* cadena, int limite)
	{
		int rtn = -1;
		int i;

		if(cadena != NULL && limite > 0)
		{
			rtn = 1;
			for(i=0;i<limite && cadena[i] != '\0' ;i++)
			{
				if(i==0 && (cadena[i] == '+' || cadena[i == '-']))
				{
					continue;
				}
				if(cadena[i] > '9' || cadena[i] < '0')
				{
					rtn = 0;
					break;
				}
			}
		}

		return rtn;
	}
	static int GetInt(int* pResultado)
	{
		int rtn = -1;
		char bufferString[50];
		if(pResultado != NULL && myGets(bufferString, sizeof(bufferString))== 0 && esNumerica(bufferString,sizeof(bufferString)))
		{
			rtn = 0;
			*pResultado = atoi(bufferString);
		}
		return rtn;
	}

	int utn_GetEntero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
	{
		int rtn = -1;
		int bufferInt;
		do
		{
			printf("%s", mensaje);
			if(GetInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo)
			{
				rtn = 0;
				*pResultado = bufferInt;
				break;
			}
			printf("%s", mensajeError);

			reintentos--;
		}while(reintentos >= 0);

		return rtn;
	}

	void MostrarCadena(char cadena[])
	{
		printf("%s", cadena);
	}


