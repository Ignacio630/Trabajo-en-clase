#include "utn_validaciones.h"

void PedirCadena(char cadena[],char mensaje[])
{
	printf(mensaje);
	scanf("%s",cadena);
	while(!ValidarUnaCadena(cadena))
	{
		printf("Ups! a ocurrido un error!\n");
		printf(mensaje);
		scanf("%s",cadena);
	}
}

int ValidarUnaCadena(char cadena[])
{
	int retorno=1;
	int len;
	if(cadena!=NULL)
	{
		len=strlen(cadena);
		for(int i=0;i<len;i++)
		{
			if(!isalpha(cadena[i]))
			{
				retorno=0;
			}
		}
	}
	return retorno;
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

int ValidarNumero(char numero[])
{
	int retorno=1;
	int len;
	if(numero!=NULL){
		len=strlen(numero);
		for(int i=0;i<len;i++)
		{
			if(!isdigit(numero[i])){
				retorno=0;
				break;
			}
		}
	}
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
int ValidarNumeroMinimoMaximo(int numero, int maximo, int minimo, char mensaje[])
{
	int retorno;
	if(numero <= maximo && numero >= minimo)
	{
		retorno = 0;
	}
	else
	{
		retorno = -1;
		printf("%s", mensaje);
	}

	return retorno;
}
int ValidarParidad(int numeroIngresado)
{
	int resultado;

	resultado = -1;

	if(numeroIngresado % 2 == 0)
	{
		printf("Es par\n");
	}
	else
	{
		printf("Es impar\n");
	}

	return resultado;
}


