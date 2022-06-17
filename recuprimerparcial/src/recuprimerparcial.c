//INCLUDE
#include "utn_funciones.h"
#include "Consulta.h"
//DEFINE
#define TAM 20
#define TAM_M 5
//CUERPO
int main(void)
{
	setbuf(stdout,NULL);
	int opciones;
	int contadorConsulta;
	contadorConsulta = 0;

	///Se crea el vector de la estructura
	eConsulta unaConsulta[TAM];
	eMedico unMedico[TAM];
	eFecha unaFecha[TAM];
	///Se inicializan todos los campos en 0
	iniciarEstructura(unaConsulta, TAM);

	HardcodeoMedicos(unMedico, TAM_M);
	///Menu de opciones
	do
	{
		///Menu
		opciones = PedirOpciones("1.ALTA CONSULTA\n2.MODIFICAR CONSULTA\n3.CANCELAR CONSULTA\n4.DIAGNOSTICAR\n5.LISTAR\n6.SALIR\nIngrese una opcion:", "Opcion invalida!!\n");
		///Funcionalidad Menu
		switch (opciones) {
			case 1:
			///Alta Consulta
				if(!altaConsulta(unaConsulta ,unMedico ,unaFecha ,TAM,TAM_M))
				{
					puts("Se dio de alta correctamente!\n");
					contadorConsulta++;
				}
				else
				{
					puts("Error, no se pudo dar de alta!\n");
				}

			break;
			case 2:
			///Modificar Consulta
			if(contadorConsulta > 0)
			{
				modificarConsulta(unaConsulta ,unMedico ,unaFecha ,TAM ,TAM_M ,unaConsulta->id );
			}
			else
			{
				puts("No se ingreso ningun dato!!");
			}
			break;
			case 3:
			///Cancelar Consulta
			if(contadorConsulta > 0)
			{
				if(!eliminarConsulta(unaConsulta, TAM))
				{
					puts("Se elimino el pasajero correctamente");
					contadorConsulta--;
				}
				else
				{
					puts("Error, ID incorrecto o inexistente");
				}
			}
			else
			{
				puts("No se ingreso ningun dato!!");
			}
			break;

			case 4:
			///Diagnosticar Consulta
			if(contadorConsulta > 0)
			{
			}
			else
			{
				puts("No se ingreso ningun dato!!");
			}
			break;
			case 5:
			///Listar
			if(contadorConsulta > 0)
			{
				listarConsulta(unaConsulta,unMedico,unaFecha,TAM,TAM_M);
			}
			else
			{
				puts("No se ingreso ningun dato!!");
			}
			break;
			case 6:
			///Salida Del Programa
				puts("Gracias por usar mi app!! :)\n");
			break;
		}
		system("cls");
	}while(opciones != 6);


	return EXIT_SUCCESS;
}
