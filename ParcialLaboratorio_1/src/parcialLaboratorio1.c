#include "utn_funciones.h"
#include "utn_validaciones.h"
#include "Consulta.h"
#define TAM 20
int main(void)
{
	setbuf(stdout,NULL);
	int opciones;

	///Se crea el vector de la estructura
	sConsulta unaConsulta[TAM];

	///Se inicializan todos los campos en 0
	iniciarEstructura(unaConsulta, TAM);
	///Menu de opciones
	do
	{
		///Menu
		printf("1.ALTA CONSULTA\n");
		printf("2.MODIFICAR CONSULTA\n");
		printf("3.CANCELAR CONSULTA\n");
		printf("4.DIAGNOSTICAR\n");
		printf("5.LISTAR\n");
		printf("6.SALIR\n");
		opciones = PedirEntero("Ingrese una opcion:", "Opcion invalida!!\n");
		ValidarNumeroMinimoMaximo(opciones, 6, 1, "Opcion invalida!!\n");
		///Funcionalidad Menu
		switch (opciones) {
			case 1:
			///Alta Consulta

				if(AltaConsulta(unaConsulta, TAM)!= -1)
				{
					printf("Se dio de alta correctamente!\n");
				}
				else
				{

					printf("Error, no se pudo dar de alta!\n");
				}

			break;
			case 2:
			///Modificar Consulta
			break;
			case 3:
			///Cancelar Consulta
			break;
			case 4:
			///Diagnosticar Consulta
			break;
			case 5:
			///Listar
			break;
			case 6:
			///Salida Del Programa
				printf("Gracias por usar mi app!! :)\n");
			break;
		}



	}while(opciones != 6);

	system("cls");
	return EXIT_SUCCESS;
}
