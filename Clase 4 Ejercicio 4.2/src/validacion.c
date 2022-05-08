#include "validacion.h"
float validarCelsius(float aValidar)
{
	while(aValidar < 0 || aValidar > 100)
	{
		printf("Error, las temperaturas en celsius invalida ingrese en un rango de 0, a 100\n");
		printf("Ingrese una temperatura: ");
		scanf("%f", &aValidar);
	}
	return aValidar;
}
float validarFahrenheit(float aValidar)
{
	while(aValidar < 32 || aValidar > 212)
	{
		printf("Error, las temperaturas en fahrenheit invalida ingrese en un rango de 32, a 212\n");
		printf("Ingrese una temperatura: ");
		scanf("%f", &aValidar);
	}
	return aValidar;
}
int validarCaracter(char caracter)
{
	while(caracter != 'c' && caracter != 'f')
	{
		printf("Error, ingrese un caracter valido 'c' o 'f' \n");
		printf("Que tipo de temperatura desea ingresar 'c' Celsius o 'f' fahrenheit: ");
		fflush(stdin);
		scanf("%c", &caracter);
	}

	return caracter;
}

