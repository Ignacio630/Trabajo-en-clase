/*
 ============================================================================
 Name        : Ignacio Javier Medici
 Division	 : C
	1. Realizar un p�rrafo en donde se pueda observar la/s relaci�n/es entre los siguientes t�rminos: vector, estructura repetitiva, direcci�n de memoria,
	pasaje por valor, pasaje por referencia. No esta permitido realizar definiciones de manual,
	es necesario que el p�rrafo demuestre las relaciones entre los t�rminos.

	2. Realizar una funci�n que reciba como par�metro una cadena de caracteres. La misma permitir� intercambiar las vocales por un car�cter comod�n
	que tambi�n ser� recibido como par�metro. La funci�n retornar� la cantidad de reemplazos que se llevaron a cabo.

	Realizar una funci�n que reciba y retorne un entero. La funci�n deber� hallar cu�ntos divisores hay del numero recibido como par�metro entre la unidad y el mismo.
	Realizar Retornar� la cantidad encontrada.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int recibirCadena(char[],int,char);
int divisoresEntero(int );
int main(void)
{
	/*
	 *
	 *
	 *
	 *
	 * */
	setbuf(stdout, NULL);

	int numero;
	printf("Ingrese un numero:");
	scanf("%d", &numero);

	numero = divisoresEntero(numero);

	printf("%d", numero);
	return EXIT_SUCCESS;
}
int divisoresEntero(int enteroIngresado)
{
	int i;
	int contadorDivisiores;
	contadorDivisiores = 0;
	for(i=1; i<=enteroIngresado;i++)
	{
		if(enteroIngresado % i == 0)
		{
			printf("Divisor de:%d y la cantidad es:%d\n",enteroIngresado, i);
			contadorDivisiores++;
		}
	}
	printf("\nLa cantidad de divisores posibles es: %d\n", contadorDivisiores);
	return contadorDivisiores;
}
int recibirCadena(char cadena[],int size,char comodin)
{
	int contadorReemplazos;
	char vocales[10] = "aeiouAEIOU";
	int i;
	int j;

	contadorReemplazos = 0;
	for(i=0; i < size;i++)
	{
		for(j=0;j<10;j++)
		{
			if(cadena[i] == vocales[j])
			{
				cadena[i] = comodin;
				contadorReemplazos++;
			}
		}
	}
	return contadorReemplazos;
}
