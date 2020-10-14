#ifndef DATASTOREMOTOS_H_INCLUDED
#define DATASTOREMOTOS_H_INCLUDED


    char descTipo[10][20]={
    "Enduro",
    "Chopera",
    "Scooter",
    "Ciclomotor"
    };

    int idTipo[]={
    1000,
    1001,
    1002,
    1003
    };

    char colores[10][20]={
    "Gris",
    "Negro",
    "Blanco",
    "Azul",
    "Rojo"
    };

    int idColor[]={
    10000,
    10001,
    10002,
    10003,
    10004
    };

    int precioServicios[]={250,300,17,190};

    char nombreServicios[4][25]={
    "Limpieza",
    "Ajuste",
    "Balanceo",
    "Cadena"
    };

    int idServicios[]={
    20000,
    20001,
    20002,
    20003
    };


    eServicio servicio[TAM]={
    {20000, "Limpieza", 250},
    {20001, "Ajuste", 300},
    {20002, "Balanceo", 17},
    {20003, "Cadena", 250}
    };

#endif // DATASTOREMOTOS_H_INCLUDED
