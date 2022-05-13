#include "ArrayPassenger.h"

static int idIncremental=1000;
static int incrementalID(void);
static int incrementalID(void){
	return idIncremental++;
}
int FindFree(Passenger list[],int len)
{
	int retorno;
	int i;
	retorno = -1;
	if(list !=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == LIBRE)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
int initPassengers(Passenger* list, int tam)
{
	int retorno;
	int i;
	retorno= -1;

	if(list!=NULL && tam>0)
	{
		for(i=0;i<tam;i++)
		{
			list[i].isEmpty=LIBRE;
			list[i].id = 0;
			retorno = 0;
		}
	}
	return retorno;
}
int addPassenger(Passenger* list, int len, int id, char name[], char lastName[], float price, int typePassenger, char flycode[])
{
	int retorno;
	retorno = -1;
	int banderaLibre;
	banderaLibre = FindFree(list, len);

	if(banderaLibre != -1)
	{
		for()
		{
			printf("Ingrese el nombre del pasajero: ");
			scanf("%s", name);
			fflush(stdin);
			printf("Ingrese el apelido del pasajero: ");
			fflush(stdin);
			scanf("%s", lastName);
			printf("Ingrese el precio del pasaje: ");
			scanf("%f", &price);
			printf("Ingrese el tipo de pasajero: ");
			scanf("%d", &typePassenger);
			printf("Ingrese el codigo de vuelo: ");
			fflush(stdin);
			scanf("%s", flycode);

			list->id = incrementalID();

			list->isEmpty = OCUPADO;

		}

		retorno = 1;
	}

	return retorno;
}

int printPassenger(Passenger* list)
{
	printf("estado:%d\n",list->isEmpty);
	return 0;
}
int printPassengers(Passenger* list,int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		printf("id: %d estado:%d\n",list[i].id ,list[i].isEmpty);
	}
	return 0;
}

