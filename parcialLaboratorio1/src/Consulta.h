#ifndef CONSULTA_H_
#define CONSULTA_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct{
	int idConsulta;
	char nombrePaciente[50];
	char diagnostico[3];
} sConsulta;

sConsulta AltaConsulta(sConsulta );
#endif /* CONSULTA_H_ */
