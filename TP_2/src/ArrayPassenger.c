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
	int opciones;
	banderaLibre = FindFree(list, len);
	if(list != NULL && len >= 0)
	{
		if(banderaLibre >= 0)
			{
				PedirCadena(name, "Ingrese el nombre del pasajero:");
				PedirCadena(lastName, "Ingrese el apellido del pasajero:");
				utn_GetFlotante(&price, "Ingrese el precio del pasaje: ", "Error, el numero ingresado no es un flotante", 0, 4000000, 99);
				printf("Ingrese el tipo de vuelo\n");
				do{
					opciones = PedirOpciones("1.TURISTA\n2.PREMIUN\n3.EJECUTIVO\nElija una opcion:","Error");
					switch (opciones) {
						case 1:
							list->typePassenger = COMERCIAL;
							break;
						case 2:
							list->typePassenger = PREMIUN;
							break;
						case 3:
							list->typePassenger = EJECUTIVO;
							break;
						default:
							puts("Ups! Opcion invalida!!\n");
							break;
					}
				}while(opciones != 3);
				utn_GetEntero(&typePassenger, "1.TURISTA\n2.PREMIUN\n3.EJECUTIVO\nIngrese el tipo de pasajero:", "Error, tipo de pasajero invalido", 1, 3, 99);
				PedirCadena(flycode, "Ingrese el codigo de vuelo: ");
				list[banderaLibre].id= incrementalID();
				list[banderaLibre].isEmpty = OCUPADO;
				retorno = 0;
			}
	}
	return retorno;
}
int findPassengerById(Passenger* list ,int len,int id)
{
	int retorno;
	int i;

	retorno = -1;
	if(list !=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].id == id)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
int modifyPassenger(Passenger* list, int len, int id)
{
	int bandera = 0;
	int i;
	int opciones;
	utn_GetEntero(&id, "Ingrese el id del pasajero que queire modificar: ", "Error, pasajero no encontrado!\n", 0, 2000, 99);
	for(i=0;i<len;i++)
	{
		if(list[i].isEmpty == OCUPADO && list[i].id == id)
		{
			do
			{
				opciones = PedirOpciones("1.Modificar nombre\n2.Modificar apellido\n3.Modificar precio\n4.Modificar tipo de vuelo\n5.Modificar codigo de vuelo\n6.Salir\n", "Error, opcion invalida");
				switch (opciones)
				{
					case 1:
						PedirCadena(list[i].name, "Ingrese la modificacion del nombre:");
						bandera=1;
						break;
					case 2:
						PedirCadena(list[i].lastName, "Ingrese la modificacion del apellido: ");
						bandera=1;
						break;
					case 3:
						printf("Ingrese la modificacion del precio:$");
						scanf("%f", &list[i].price);
						bandera=1;
						break;
					case 4:
						printf("Ingrese la modificacion del tipo de pasajero:");
						scanf("%d", &list[i].typePassenger);
						bandera=1;
						break;
					case 5:
						PedirCadena(list[i].flycode, "Ingrese la modificacion del codigo de vuelo:");
						bandera=1;
						break;
					case 6:
						puts("Modificacion exitosa!");
						break;
					default:
						printf("Ups! Opcion invalida!!\n");
					break;
				}

			}while(opciones != 6);

		}
	}
	return bandera;
}
int removePassenger(Passenger* list, int len, int id)
{
	int i;
	char opcion;
	int flag=0;
	utn_GetEntero(&id, "Ingrese el id del pasajero que quiere remover :", "Error", 0, 2000, 99);
	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].id == id && list[i].isEmpty == OCUPADO)
			{
				printf("Esta seguro que desea eliminar este pasajero?? s/n: ");
				fflush(stdin);
				scanf("%c", &opcion);
				while(opcion != 's' && opcion != 'n')
				{
					printf("Ingrese s si queire eliminar o n si no quiere: ");
					fflush(stdin);
					scanf("%c", &opcion);
				}
				if(opcion == 's')
				{
					list[i].isEmpty = LIBRE;
					flag=1;
				}
			}
		}
	}
	return flag;
}
//int AltaForzada(Passenger* pasajero, Passenger* list, int len)
//{
//	int retorno;
//	int i;
//	char nombre;
//	retorno=-1;
//
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
		printf("%d",list->id);
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

