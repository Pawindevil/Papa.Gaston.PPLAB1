#include "altaMotos.h"
#include "dataStoreMotos.h"
#include "harcodeomotos.h"
char menu()
{
    char opcion;
    system("cls");

    printf(" *****SERVICE MOTOS*****\n");
    printf("                       \n");
    printf("  a ALTA MOTO          \n");
    printf("  b MODIFICAR MOTO     \n");
    printf("  c BAJA MOTO          \n");
    printf("  d LISTAR MOTOS       \n");
    printf("  e LISTAR TIPOS       \n");
    printf("  f LISTAR COLORES     \n");
    printf("  g LISTAR SERVICIOS   \n");
    printf("  h ALTA TRABAJO       \n");
    printf("  i LISTAR TRABAJOS    \n");
    printf("  X Salir              \n");
    printf("                       \n");
    printf(" ***********************\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    opcion = tolower(getchar());

    return opcion;
}

int altaMoto(eMoto moto[], int tam, int idMoto)
{
    int error=1;
    eMoto nuevaMoto;//auxiliar para cargar una nueva persona
    int indice;


    if(moto != NULL && tam > 0 && idMoto>0)//validacion de datos de entrada
    {
        indice = buscarLibre(moto, tam); //se le da a indice el valor que retorna la funcion buscarLibre
        if(indice==-1)//Si indice es menor a 0
        {
            printf("No hay lugar, sistema completo\n");
        }
        else //Si no....
        {
            nuevaMoto.idMoto = idMoto;//1Se toma el dato de nuevo legajo que se da al principio y se le asigna

            nuevaMoto.isEmpty=0;//2Se declara isEmpty en 0 para indicar que el indice esta cargado

            printf("Ingrese Marca: ");
            fflush(stdin);
            gets(nuevaMoto.marca);//3se guarda la marca

            printf("Ingrese Tipo (1000 a 1004): ");
            fflush(stdin);
            gets(nuevaMoto.tipo.idTipo);//4se guarda el tipo



            printf("Ingrese un id de color (1000 a 1004): ");
            scanf("%d", &nuevaMoto.color.idColor);//5se guarda el color

            printf("Ingrese una cilindrada(50, 125, 500, 600, 750): ");
            scanf("%d", &nuevaMoto.cilindrada);

            moto[indice]=nuevaMoto;//Se pasan todos los datos guardados en el auxiliar hacia el vector usando la variable indice para marcar el lugar del indice
            error =0;//se retornan 0 errores
        }


    }

    return error;
}

int altaTrabajo(eTrabajo trabajo, int tam, int idTrabajo)
{
    int error=1;
    eTrabajo nuevoTrabajo;
    int indice;



            nuevoTrabajo.idTrabajo = idTrabajo;

            mostrarMotos(moto, tam);

            printf("Ingrese ID de moto : ");
            fflush(stdin);
            gets(nuevaMoto.marca);

            printf("Ingrese Tipo (1000 a 1004): ");
            fflush(stdin);
            gets(nuevaMoto.tipo.idTipo);



            printf("Ingrese un id de moto (1000 a 1004): ");
            scanf("%d", &nuevaMoto.color.idColor);

            printf("Ingrese una cilindrada(50, 125, 500, 600, 750): ");
            scanf("%d", &nuevaMoto.cilindrada);

            moto[indice]=nuevaMoto;
            error =0;
        }


    }

    return error;
}

int mostrarMoto(eMoto moto[])

{
    printf("    %5d      %12s       %12s        %12s    %5d\n", moto.idMoto ,moto.marca, moto.tipo, moto.color, moto.cilindrada);//Imprime los datos de la moto segun su posicion en el vector


    return 0;
}

int mostrarMotos(eMoto moto[],int tam)

{

    int retorno=1;
    int flag=0;

    if(moto != NULL && tam > 0 )
    {
        retorno=0;

        printf("***LISTADO DE MOTOS***\n");
        printf("ID      MARCA    TIPO    COLOR   CILINDRADA\n");
        printf("------------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {

            if(moto[i].isEmpty == 0)
            {

                mostrarMoto(moto[i]);
                flag=1;// FLAG PARA VER SI TODOS ESTAN VACIOS


            }



        }

        if(!flag)
        {

            printf("No hay motos para mostrar en la lista \n");


        }


    }


    return retorno;


}

int bajaMotos(eMoto moto[], int tam)
{
    int retorno = 1;
    int aux;
    int indice;
    char rta;
    mostrarMotos(moto, tam);

    printf("Ingrese el ID que desea borrar : \n");
    scanf("%d",&aux);

    if((indice=buscarMotos(moto,tam,aux)) != -1)
    {

        if(moto != NULL && tam > 0)
        {
            system("cls");
            printf("***BAJA DE MOTOS***\n");
            mostrarPersonas(moto, tam);
            printf("Confirma la baja? s/n");
            fflush(stdin);
            scanf("%c",&rta);
            if(rta == 's')
            {

                moto[indice].isEmpty=1;
                retorno = 0;

            }
            else
            {
                retorno = 2;
            }


        }





    }
    else
    {
        printf("ID mal ingresado\n");
    }



    return retorno;


}
int modificarMotos(eMoto moto[], int tam)
{
    int retorno = 1;
    int aux;
    int indice;
    int opcion;
    char auxColor[100];

    float auxCil;


    if(moto != NULL && tam > 0 )
    {

            system("cls");

            mostrarMotos(moto, tam);


        printf("Ingrese el ID que desea modificar : \n");
        scanf("%d",&aux);

        if((indice=buscarMotos(moto,tam,aux)) != -1)
        {


            printf("Que desea modificar : \n");
            printf("1_Color\n");
            printf("2_Cilindrada\n");


            printf("Ingrese una opcion\n");
            fflush(stdin);
            scanf("%d",&opcion);

            switch(opcion)
            {

            case 1 :

                printf("Ingrese nuevo ncolor : \n");
                fflush(stdin);
                fgets(auxColor,sizeof(auxColor),stdin);
                strncpy(moto[indice].color,auxColor,sizeof(moto[indice].color));



                break;



            case 2:
                printf("Ingrese nueva cilindrada: \n");
                fflush(stdin);
                scanf("%f", &auxCil);
                moto[indice].cilindrada=auxCil;

                break;




            }

        }
        else
        {
            printf("NO HAY ID\n");
        }









    }





    return retorno;


}


int buscarLibre(eMoto moto[], int tam)
{
    int indice=-1;//Dentro del tamaño de la funcion el indice puede ser 0 o mayor
    for(int i=0; i<tam; i++)
    {
        if(moto[i].isEmpty==1)//Cuando el valor de i sea ==1(lugar vacio) indice va a valer la direccion vacia del vector
        {
            indice=i;
            break;
        }
    }
    return indice;//retorna el valor del indice vacio en el vector
}

int buscarMotos(eMoto moto[],int tam,int id)
{
    int retorno = -1;

    for(int i=0; i<tam; i++)
    {
        if(moto[i].idMoto == id && !moto[i].isEmpty)
        {

            retorno= i;
            break;

        }


    }



    return retorno;
}
