#include "ArrayPassenger.h"
#include "utn_funciones.h"
int main(void)
{
	setbuf(stdout,NULL);

	int opciones;
	Passenger pasajero[TAM];
	initPassengers(pasajero, TAM);

	do{
		opciones = PedirOpciones("1.ALTA\n2.MODIFICAR\n3.BAJA\n4.INFORMAR\n5.SALIR\nElija una opcion: ", "Ups! Opcion invalida!!\n");
		switch (opciones)
		{
			case 1:
				system("cls");
				if(pasajero->isEmpty==LIBRE)
				{
					addPassenger(pasajero, TAM, pasajero->id, pasajero->name,pasajero->lastName,pasajero->price,pasajero->typePassenger,pasajero->flycode);
				}
				else
				{
					printf("No hay mas espacio\n");
				}
				break;
			case 2:
				system("cls");
				break;
			case 3:
				system("cls");
				break;
			case 4:
				printPassengers(pasajero, TAM);
				system("pause");
				break;
			case 5:
				printf("Gracias por usar mi app :)\n");
				break;
			default:
				printf("Ups! Opcion invalida!!\n");
			break;
		}
	}while(opciones !=5);





	return EXIT_SUCCESS;
}
