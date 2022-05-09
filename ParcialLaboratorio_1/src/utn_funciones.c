#include "utn_funciones.h"

static int GetInt(int*);
static int esNumerica(char* , int );


static int myGets(char* cadena, int longitud)
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
int utn_GetString(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos)
{
	int retorno;
	char bufferStr[4096];
	retorno = -1;
	do
	{
		if(pResultado != NULL && myGets(bufferStr, sizeof(bufferStr)) == 0)
		{

		}
	}while(reintentos >= 0);


	return retorno;
}



int utn_GetEntero(int pResultado[], char mensaje[], char MensajeError[], int minimo, int maximo, int reintentos)
{
	int retorno;
	retorno = -1;
	int bufferInt;
	do{
		printf("%s", mensaje);
		if(GetInt(&bufferInt)== 0 && bufferInt >= minimo && bufferInt <= maximo )
		{
			retorno = 0;
			pResultado = bufferInt;
			break;
		}

		printf("%s", MensajeError);
		reintentos++;
	}while(reintentos >= 0);

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
void PedirCadena(char cadena[],char mensaje[])
{
	printf(mensaje);
	fflush(stdin);
	scanf("%s",cadena);
	while(!ValidarCadena(cadena))
	{
		printf("Ups! a ocurrido un error!\n");
		printf(mensaje);
		fflush(stdin);
		scanf("%s",cadena);
	}
}

int PedirEntero(char mensaje[], char mensajeError[])
{
	int retorno;
	char numero[1000];
	printf(mensaje);
	scanf("%s",numero);
	while(!ValidarNumero(numero))
	{
		printf("%s",mensajeError);
		printf("%s", mensaje);
		scanf("%s",numero);
	}
	retorno=atoi(numero);
	return retorno;
}
int PedirFlotante(char mensaje[])
{
	int retorno;
	char numero[1000];
	printf(mensaje);
	scanf("%s",numero);
	while(!ValidarNumero(numero))
	{
		printf("Ups! a ocurrido un error! \n");
		printf(mensaje);
		scanf("%s",numero);
	}
	retorno=atof(numero);
	return retorno;
}
void MostrarCadena(char cadena[])
{
	printf("%s", cadena);
}


