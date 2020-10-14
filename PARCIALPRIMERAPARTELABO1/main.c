#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "altaMotos.h"

#define TAM_T 4
#define TAM_C 5
#define TAM_S 4
#define TAM_M 10
#define TAM_J 10


//ABM MOTOS




int main()
{


    char seguir = 's';
    char confirma;
    int idProxMoto=3000;
    int proximoIdTipo=1000;
    int proximoIdColor=10000;
    int proximoIdServicio=20000;
    int idProxTrabajo=0;
    eTipo tipo[TAM_T];
    eColor color[TAM_C];
    eServicio servicio[TAM_S];
    eMoto moto[TAM_M];
    //eTrabajo unTrabajo[TAM_J];
    proximoIdTipo+=harcodearTipos(tipo, TAM_T, 4);
    proximoIdColor+=harcodearColor(color, TAM_C, 5);
    proximoIdServicio+=harcodearServicios(servicio, TAM_S, 4);


    do
    {
        switch(menu())
        {

        case 'a':
            altaMoto(moto, TAM_M, idProxMoto);
            if(altaMoto(moto, TAM_M, idProxMoto)==0)
            {
                idProxMoto++;
                printf("Alta exitosa!!!!\n\n");
            }
            else
            {
                printf("Problema al realizar el alta.....\n");
            }
            break;
        case 'b':
        bajaMotos(moto, TAM_M);

            break;
        case 'c':
            modificarMoto(moto, TAM_M);

            break;
        case 'e':
            mostrarTipos(tipo, TAM_T);
            break;
        case 'f':
            mostrarColores(color, TAM_C);
            break;
        case 'g':
            mostrarServicios(servicio, TAM_S);
            break;
        /*case 'h':
            altaTrabajo;
        if(altaTrabajo(unTrabajo, TAM_J, idProxTrabajo)==0)
            {
                idProxTrabajo++;
                printf("Alta exitosa!!!!\n\n");
            }
            else
            {
                printf("Problema al realizar el alta.....\n");
            }
            break;
        case 'i':
                mostrarTrabajos(unTrabajo, TAM_J);
            break;*/



        case 'x':
            printf("Confirma salida?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }

            break;
        default:
            printf("Opcion invalida!!!\n");

        }

        system("pause");

    }
    while( seguir == 's');


    return 0;
}




