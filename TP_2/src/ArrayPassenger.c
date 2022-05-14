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

	if(list != NULL && len >= 0)
	{
		if(banderaLibre >= 0)
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
				list[banderaLibre].id= incrementalID();
				list[banderaLibre].isEmpty = OCUPADO;
				retorno = 0;
			}
	}
	return retorno;
}
//int AltaForzada(Passenger* list, int len)
//{
//	int retorno;
//	retorno=-1;
//	list->name={{"Juan"},{"Maria"},{"Alberto"},{"Pedro"},{"Abril"}};
//
//
//	return retorno;
//}
int printPassenger(Passenger* list)
{
	int retorno;
	retorno =-1;
	if(list != NULL)
	{
		printf("%d",list->isEmpty);
		retorno=0;
	}
	return retorno;
}
int printPassengers(Passenger* list,int len)
{
	int i;
	system("cls");
	puts("--------------------------------------------!INFORME PASAJEROS!----------------------------------------------");
	puts("Id: \t Nombre \t Apellido\t Precio \t Clase \t Codigo de vuelo\n");
	for(i=0;i<len;i++)
	{
		if(list[i].isEmpty== OCUPADO)
		{
			printf("|%-6d |%-9s| |%-14s| %15.2f| %15d| %10s|\n",list[i].id ,list[i].name, list[i].lastName,list[i].price, list[i].typePassenger, list[i].flycode);
		}
	}
	return 0;
}

