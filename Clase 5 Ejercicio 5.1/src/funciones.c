#include "funciones.h"



int sumaArrays(int cadenaNumeros[], int TAM)
{
	int sumaArrays;

	sumaArrays = 0;

	for(int i=0; i<TAM;i++)
	{
		printf("Ingrese un numero: ");
		fflush(stdin);
		scanf("%d", &cadenaNumeros[i]);
		sumaArrays += cadenaNumeros[i];
	}

	return sumaArrays;
}
