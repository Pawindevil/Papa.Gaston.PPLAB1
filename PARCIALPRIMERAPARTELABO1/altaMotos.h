#ifndef ALTAMOTOS_H_INCLUDED
#define ALTAMOTOS_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int idMoto;
    char marca[20];
    eTipo tipo;
    eColor color;
    int isEmpty;
    int cilindrada;
}eMoto;

typedef struct
{
    int idTrabajo;
    eMoto moto;
    eServicio servicio;
    eFecha fechaTrabajo;
}eTrabajo;

char menu();

int altaMoto(eMoto moto[], int tam, int idMoto);

int bajaMotos(eMoto moto[], int tam);

int modificarMotos(eMoto moto[], int tam);

int mostrarMoto(eMoto moto);

int mostrarMotos(eMoto moto[],int tam);

int buscarLibre(eMoto moto[], int tam);

int buscarMotos(eMoto moto[],int tam,int id);

#endif // ALTAMOTOS_H_INCLUDED
