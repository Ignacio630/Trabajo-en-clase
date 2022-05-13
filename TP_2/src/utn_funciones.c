#include "utn_funciones.h"


static int GetInt(int*);
static int GetFloat(int* );
static int esNumerica(char*);
static int esFlotante(char*);

static int esNumerica(char* cadena)
{
	int retorno = -1;
	int i;
	int len;
	len=strlen(cadena);
	if(cadena != NULL && len > 0)
	{
		retorno = 1;
		for(i=0;i<len && cadena[i] != '\0' ;i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i == '-']))
			{
				continue;
			}
			if(cadena[i] > '9' || cadena[i] < '0')
			{
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}
static int GetInt(int* pResultado)
{
	int retorno = -1;
	char bufferString[50];
	if(pResultado != NULL && myGets(bufferString, sizeof(bufferString))== 0 && esNumerica(bufferString))
	{
		retorno = 0;
		*pResultado = atoi(bufferString);
	}
	return retorno;
}

static int esFlotante(char* numero)
{
	int retorno = 1;
	int contadorPunto=0;
	int len;
	len=strlen(numero);
	int i;
	if(numero != NULL && len>0)
	{
		for(i=0; i < len && numero[i] != '\0';i++)
		{
			if(i== 0 && (numero[i]== '+' || numero[i]=='-'))
			{
				continue;
			}
			if(numero[i] < '0' || numero[i] > '9')
			{
				if(contadorPunto==0 && i !=0 && numero[i]=='.')
				{
					contadorPunto++;
					continue;
				}
				else
				{
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}
static int GetFloat(int* pResultado)
{
	int retorno = -1;
	char bufferString[50];
	if(pResultado != NULL && myGets(bufferString, sizeof(bufferString))== 0 && esFlotante(bufferString))
	{
		retorno = 0;
		*pResultado = atof(bufferString);
	}
	return retorno;
}
int myGets(char* cadena, int len)
{
	int retorno = -1;
	char bufferString[4096];

	if(cadena != NULL && len > 0)
	{
		fflush(stdin);
		if(fgets(bufferString, sizeof(bufferString), stdin)!= NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= len)
			{
				strncpy(cadena, bufferString, len);
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

int utn_GetEntero(int* pResultado, char* mensaje, char* MensajeError, int minimo, int maximo, int reintentos)
{
	int retorno;
	retorno = -1;
	int bufferInt;
	do{
		printf("%s", mensaje);
		if(GetInt(&bufferInt)== 0 && bufferInt >= minimo && bufferInt <= maximo )
		{
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}

		printf("%s", MensajeError);
		reintentos++;
	}while(reintentos >= 0);

	return retorno;
}
int utn_GetFlotante(int* pResultado, char* mensaje, char* MensajeError, int minimo, int maximo, int reintentos)
{
	int retorno;
	retorno = -1;
	int bufferFloat;
	do{
		printf("%s", mensaje);
		if(GetFloat(&bufferFloat)== 0 && bufferFloat >= minimo && bufferFloat <= maximo )
		{
			retorno = 0;
			*pResultado = bufferFloat;
			break;
		}

		printf("%s", MensajeError);
		reintentos++;
	}while(reintentos >= 0);

	return retorno;
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
int PedirEntero(char numero[], char mensaje[], char mensajeError[])
{
	int retorno;
	printf(mensaje);
	scanf("%s",numero);
	while(!esNumerica(numero))
	{
		printf("%s",mensajeError);
		printf("%s", mensaje);
		scanf("%s",numero);
	}
	retorno=atoi(numero);
	return retorno;
}
int PedirOpciones(char mensaje[], char mensajeError[])
{
	int retorno;
	char opciones[1000];
	printf(mensaje);
	scanf("%s",opciones);
	while(!esNumerica(opciones))
	{
		printf("%s",mensajeError);
		printf("%s", mensaje);
		scanf("%s",opciones);
	}
	retorno=atoi(opciones);
	return retorno;
}
int PedirFlotante(char numero[], char mensaje[], char mensajeError[])
{
	int retorno;
	printf(mensaje);
	scanf("%s",numero);
	while(esFlotante(numero))
	{
		printf("%s",mensajeError);
		printf("%s",mensaje);
		scanf("%s",numero);
	}
	retorno= atof(numero);
	return retorno;
}
void MostrarCadena(char cadena[])
{
	printf("%s", cadena);
}
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
int ValidarFloatMinimo(float numero, int minimo, char mensaje[])
{
	int retorno;

	if(numero > minimo)
	{
		retorno=0;
	}
	else
	{
		*mensaje = ValidarCadena(mensaje);
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


