#include "Consulta.h"
#include "utn_validaciones.h"
static int IdConsultas();
static int IdConsultas()
{
	static int idIncremental = 0;
	return idIncremental++;
}

void iniciarEstructura(sConsulta consulta[], int tam)
{
	int i;
	if(consulta != NULL && tam > 0)
	{
		for(i=0; i<tam;i++)
		{
			consulta[i].estado = LIBRE;
		}
	}
}

int AltaConsulta(sConsulta consulta[], int tam)
{
	int retorno;
	int index;
	retorno = -1;
	if (consulta != NULL)
	{
		if (tam >= 0)
		{
			index = BuscarLibre(consulta, tam);
			if (index != -1)
			{
				PedirCadena(consulta[index].nombrePaciente, "Ingrese el nombre del paciente: ");
				retorno = 0;
			}
		}
	}

	return retorno;
}

void HardcodeConsultas(sConsulta consulta[], int tam)
{
	int i;
	int idConsulta[] = {1001,1002,1003};
	char nombrePaciente[][50] = {"Carlos","Emanuel","Ezekiel"};
	int estado[3] = {LIBRE, LIBRE, OCUPADO};

	for(i=0;i<tam;i++)
	{
		consulta[i].idConsulta = idConsulta[i];
		strcpy(consulta[i].nombrePaciente,nombrePaciente[i]);
		consulta[i].estado = estado[i];
	}
}
int ImprimirConsulta(sConsulta unaConsulta[])
{
	int retorno;
	retorno = -1;
	if(unaConsulta != NULL && unaConsulta->estado == LIBRE)
	{
		printf("Id: %d\nNombre: %s\n Diagnostico: %s\n Id Medico: %d Nombre Medico: %s\n", unaConsulta->idConsulta,
													   unaConsulta->nombrePaciente,
													   unaConsulta->dignostico,
													   unaConsulta->medico.idMedico,
													   unaConsulta->medico.nombreMedico);
		retorno = 0;
	}
	return retorno;
}
int ImprimirConsultas(sConsulta consultas[], tam)
{
	int retorno;
	int i;
	retorno = -1;
	if(consultas != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			ImprimirConsulta(&unaConsulta[i]);
		}
	}
	return retorno;
}
int BuscarLibre(sConsulta consulta[], int tam)
{
	int i;
	int index;
	index = -1;

	for (i=0;i<tam;++i)
	{
		if(consulta[i].estado == LIBRE)
		{
			index = i;
			break;
		}
	}
	return index;
}
int BuscarPorID(sConsulta consulta[], int tam, int id)
{
	int retorno;
	int i;

	retorno  = -1;
	if (consulta != NULL && tam > 0)
	{
		for (i = 0; i < tam; i++)
		{
			if (consulta[i].idConsulta == id && consulta[i].estado == OCUPADO)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}
