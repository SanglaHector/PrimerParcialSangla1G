#include "Estructura.h"
//*******************************************************************************
void altaE(eAuto vec[], int tam, eMarca marVec[], int marSec,eColor colVec,int tamCol){
    int id;
    int validar;
    char aux[20];
    int indice = buscarLibre(vec,tam);

    if (indice == -1){
        printf("\nNo hay espacio para agregar empleados.");
    }else{
            id = generarIdAuto();
            //pedirDatos(vec,tam,id);
            printf("\nEmpleado ingresado con exito: \n");
//            mostrarE(vec[id],marVec,tamSec);


        }
    }
//**************************************************************************************************************
int buscarLibre(eAuto vec[], int tam){
    int indice = -1;
    for(int i = 0; i < tam ;  i++){

        if(vec[i].estado == VACIO){
            indice = i;
            break;
        }
    }
    return indice;
}
int generarIdAuto()
{
    static int id=0;

    return id++;
}
//***************************************
void inicializarE(eAuto vec[] , int tam){

    for(int i = 0; i < tam ; i++){

        vec[i].estado = VACIO;
    }
}

