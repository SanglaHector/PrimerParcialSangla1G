#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define TAM 1000
#define TAMMAR 100
#define TAMTRA 100
#define TAMCOL 100
#define TAMSER 100
#define OCUPADO 1
#define VACIO 0

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{

    int id;
    char patente[6];
    int idMarca;
    int idColor;
    int modelo; //año de fabricacion
    int estado;
}eAuto;

typedef struct{
    int id;
    char descripcion[20];
}eMarca;

typedef struct{
    int id;
    char descripcion[20];
    float precio;
}eServicio;

typedef struct{
    int id;//tiket
    char patente;
    int idServicio;
    eFecha fecha;
}eTrabajo;

typedef struct{
    int id;
    char descripcion[20];
}eColor;


int main()
{
    eAuto autos[TAM];
    inicializarE(autos,TAM);
        //***********************************
    eMarca marcas[] ={
        {1000,"Renault"},{1001,"Fiat"},{1002,"Ford"},{1003,"Chevrolet"},{1004,"Peugeot"}
        };
        //************************************
    eColor colores[] ={
        {5000,"Negro"},{5001,"Blanco"},{5002,"Gris"},{5003,"Rojo"},{5004,"Azul"}
    };
        //***********************************
    eServicio servicios[] = {{20000,"Lavado",250},{20001,"Pulido",300},{20002,"Encerado",400},{20003,"Completo",600}
    };
        //**********************************
    int opcion;
do
    {

        printf("1-Alta auto\n");
        printf("2-Modificar auto\n");
        printf("3-Baja auto\n");
        printf("4-Listar autos\n");
        printf("5-Listar marcas\n");
        printf("6.Listar colores\n");
        printf("7.Listar servicios\n");
        printf("8.Alta trabajo\n");
        printf("9.Listar trabajo\n");
        printf("10-Salir\n");
        printf("Ingrese una opcion: ");
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        case 7:

            break;
        case 8:

            break;
        case 9:

            break;
        case 10:
            printf("Hasta luego!\n");
            break;
        default:
            printf("Opcion incorrecta\n");
        }

        system("pause");
        system("cls");

    }
    while(opcion !=10);

    return 0;
}
