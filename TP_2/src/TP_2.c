#include "ArrayPassenger.h"
#include "utn_funciones.h"
int main(void)
{
	setbuf(stdout,NULL);

	int opciones;
	Passenger pasajero[TAM];
	initPassengers(pasajero, TAM);

	do{
		opciones = PedirOpciones("1.ALTA\n2.MODIFICAR\n3.BAJA\n4.INFORMAR\n5.ALTA FORZADA\n6.SALIR\nElija una opcion: ", "Ups! Opcion invalida!!\n");
		switch (opciones)
		{
			case 1:
				system("cls");
				if(addPassenger(pasajero, TAM, pasajero->id, pasajero->name,pasajero->lastName,pasajero->price,pasajero->typePassenger,pasajero->flycode)==0)
				{
					puts("Se dio de alta satisfacctoriamente!!");
				}
				else
				{
					puts("No hay mas espacio");
				}
				break;
			case 2:
				system("cls");
				break;
			case 3:
				system("cls");
				break;
			case 4:
				if(pasajero->isEmpty == OCUPADO)
				{
					printPassengers(pasajero, TAM);
				}
				else
				{
					puts("Haga al menos un alta para mostrar el informe");
				}
				system("pause");
				break;
			case 5:

				break;
			default:
			case 6:
				printf("Gracias por usar mi app :)\n");
				break;
				printf("Ups! Opcion invalida!!\n");
			break;
		}
	}while(opciones !=6);





	return EXIT_SUCCESS;
}
