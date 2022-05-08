#include "transformacion.h"


float transformarCelsiusAFahrenheit(float temperatura)
{
	float temperaturaTransformada;

	temperaturaTransformada = (temperatura * 9/5) + 32;

	return temperaturaTransformada;
}
float transformarFahrenheitACelsius(float temperatura)
{
	float temperaturaTransformada;

	temperaturaTransformada = (temperatura - 32)* 5/9 ;

	return temperaturaTransformada;
}
