#include "ArrayPassenger.h"
#include "utn_funciones.h"
int main(void)
{
	setbuf(stdout,NULL);

	int opciones;
	Passenger pasajero[TAM];

	initPassengers(pasajero, TAM);
	int contadorPasajeros=0;
	do{
		opciones = PedirOpciones("1.ALTA\n2.MODIFICAR\n3.BAJA\n4.INFORMAR\n5.ALTA FORZADA\n6.SALIR\nElija una opcion: ", "Ups! Opcion invalida!!\n");
		switch (opciones)
		{
			case 1:
				system("cls");
				if(addPassenger(&pasajero, TAM, pasajero->id, pasajero->name, pasajero->lastName, pasajero->price, pasajero->typePassenger, pasajero->flycode)==0)
				{
					puts("Se dio de alta satisfacctoriamente!!");
					contadorPasajeros++;
				}
				else
				{
					puts("No hay mas espacio");
				}
				break;
			case 2:
				if(contadorPasajeros)
				{
					modifyPassenger(pasajero, TAM, pasajero->id);
				}
				else
				{
					puts("No existe pasajero a modificar!");
				}
				system("cls");
				break;
			case 3:
				if(contadorPasajeros>0)
				{
					removePassenger(pasajero, TAM, pasajero->id);
					puts("Se dio de baja exitosamente");
					contadorPasajeros--;
				}
				else
				{
					puts("Error no existe pasajero para eliminar");
				}
				system("cls");
				break;
			case 4:
				if(contadorPasajeros >0)
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
				printf("%d\n", contadorPasajeros);
				break;

			case 6:
				printf("Gracias por usar mi app :)\n");
				break;

			default:
				printf("Ups! Opcion invalida!!\n");
			break;
		}
	}while(opciones !=6);

	return EXIT_SUCCESS;
}
