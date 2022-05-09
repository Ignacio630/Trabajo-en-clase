#ifndef CONSULTA_H_
#define CONSULTA_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

///Define
#define LIBRE 0
#define OCUPADO 1
#define GRIPE 0
#define COVID 1
#define PREINFARTO 2
///Estructura
typedef struct{
	char gripeA;
	char covid19;
	char preInfarto;
}sDiagnostico;
typedef struct{
	int idMedico;
	char nombreMedico[50];
	char especialidad[20];
} sMedico;
typedef struct{
	int dia;
	int mes;
	int anio;
}sFecha;
typedef struct{
	int idConsulta;
	char nombrePaciente[50];
	char dignostico;
	int estado;
	sFecha fecha;
	sMedico medico;
} sConsulta;

///Funcionalidad
void iniciarEstructura(sConsulta consulta[], int);
void HardcodeConsultas(sConsulta consulta[], int);
void HardcodemMedicos(sMedico medicos[], int);
int BuscarLibre(sConsulta consulta[], int );
/// ABM
int AltaConsulta(sConsulta consulta[], int);
sConsulta CargarUnaConsulta();

#endif /* CONSULTA_H_ */
