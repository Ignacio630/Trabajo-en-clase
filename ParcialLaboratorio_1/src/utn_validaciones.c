#include "utn_validaciones.h"


int ValidarCadena(char cadena[])
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


