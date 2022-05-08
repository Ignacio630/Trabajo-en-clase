/*
 ============================================================================
 Name        : Ignacio Javier Medici
 Division	 : C
	1. Realizar un párrafo en donde se pueda observar la/s relación/es entre los siguientes términos: vector, estructura repetitiva, dirección de memoria,
	pasaje por valor, pasaje por referencia. No esta permitido realizar definiciones de manual,
	es necesario que el párrafo demuestre las relaciones entre los términos.

	2. Realizar una función que reciba como parámetro una cadena de caracteres. La misma permitirá intercambiar las vocales por un carácter comodín
	que también será recibido como parámetro. La función retornará la cantidad de reemplazos que se llevaron a cabo.

	Realizar una función que reciba y retorne un entero. La función deberá hallar cuántos divisores hay del numero recibido como parámetro entre la unidad y el mismo.
	Realizar Retornará la cantidad encontrada.

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
