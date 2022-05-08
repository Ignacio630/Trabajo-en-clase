/*
 ============================================================================
 Name        : Ignacio Javier Medici
 Division 	 : C

 Ejercicio 4-2:

 Realizar un programa que permita la carga de temperaturas en celsius y fahrenheit ,
 validando que las temperaturas ingresadas estén entre el punto de congelación yebullición del agua para cada tipo de escala.

 Las validaciones se hacen en una biblioteca.
 Las funciones de transformación de fahrenheit a celsius y de celsius a fahrenheit se hacen en otra biblioteca.
 ============================================================================
 */
#include "validacion.h"
#include "transformacion.h"

int main()
{
	setbuf(stdout, NULL);
	float temperaturaDeseada;
	float temperaturaTransformada;
	char temperaturaIngresada;

	printf("Ingrese una temperatura: ");
	scanf("%f", &temperaturaDeseada);

	printf("Que tipo de temperatura desea ingresar 'c' Celsius o 'f' fahrenheit: ");
	fflush(stdin);
	scanf("%c",&temperaturaIngresada);

	temperaturaIngresada = validarCaracter(temperaturaIngresada);
	if(temperaturaIngresada == 'c')
	{
		temperaturaDeseada = validarCelsius(temperaturaDeseada);
		printf("La temperatura en celsius es: %.2f", temperaturaDeseada);
		temperaturaTransformada = transformarCelsiusAFahrenheit(temperaturaDeseada);
		printf("\nLa temperatura en fahrenheit es: %.2f", temperaturaTransformada);
	}
	else
	{
		temperaturaDeseada = validarFahrenheit(temperaturaDeseada);
		printf("La temperatura en fahrenheit es: %.2f", temperaturaDeseada);
		temperaturaTransformada = transformarFahrenheitACelsius(temperaturaDeseada);
		printf("\nLa temperatura en Celsius es: %.2f", temperaturaTransformada);
	}

	return 0;
}














