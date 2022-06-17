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
struct
{
	int id;
	char nombre[50];
	char especialidad[20];
	int estado;
}typedef eMedico;
struct
{
	int dia;
	int mes;
	int anio;
}typedef eFecha;
struct
{
	int id;
	char nombre[50];
	eFecha fecha;
	int diagnostico;
	int estado;
	eMedico medico[5];
}typedef eConsulta;
///Funcionalidad
void iniciarEstructura(eConsulta [], int);
int BuscarLibre(eConsulta [], int );
int BuscarPorIDMedico(eMedico[], int , int );

int HardcodeConsultas(eConsulta [], int);
int HardcodeoMedicos(eMedico [], int);
void menuDiagnostico(eConsulta [], int );
void listarMedicos(eMedico [], int );
/// ABM
int altaConsulta(eConsulta[] ,eMedico[] ,eFecha[] ,int ,int );
int modificarConsulta(eConsulta[] ,eMedico[] ,eFecha[] ,int ,int ,int );
int eliminarConsulta(eConsulta [], int);
void listarConsulta(eConsulta[],eMedico[],eFecha[],int,int);
#endif /* CONSULTA_H_ */
