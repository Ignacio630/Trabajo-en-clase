#include "utn_funciones.h"
#include "utn_validaciones.h"
#include "Consulta.h"
int main(void)
{
	setbuf(stdout,NULL);
	int opciones;

	do
	{
		printf("1.ALTA CONSULTA\n");
		printf("2.MODIFICAR CONSULTA\n");
		printf("3.CANCELAR CONSULTA\n");
		printf("4.DIAGNOSTICAR\n");
		printf("5.LISTAR\n");
		printf("6.SALIR\n");
		opciones = PedirEntero("Ingrese una opcion:", "Opcion invalida!!\n");
		ValidarNumeroMinimoMaximo(opciones, 6, 1, "Opcion invalida!!\n");

		switch (opciones) {
			case 1:

			break;
			case 2:

			break;
			case 3:

			break;
			case 4:

			break;
			case 5:

			break;
			case 6:
				printf("Gracias por usar mi app!! :)\n");
			break;
		}



	}while(opciones != 6);


	return EXIT_SUCCESS;
}
