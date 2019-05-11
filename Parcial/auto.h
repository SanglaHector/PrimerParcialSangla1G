#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define TAM 7
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
    int modelo;
    int estado; //año de fabricacion
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

//***************************************************************
/**
**/
void altaE(eAuto vec[], int tam, eMarca marVec[], int marSec,eColor colVec[],int tamCol);
//********************************************************************
/**
**/
int buscarLibre(eAuto vec[], int tam);
//*****************
/**
**/
int generarIdAuto();
//**************
/**
**/
void inicializarE(eAuto vec[], int tam);
//*******************************
/**
**/
void pedirDatos(eAuto vec[], int tam, int indice, eMarca vecMar[], int tamMar, eColor vecCol[], int tamCol);
//********************************
/**
**/
//*********************************
void mostrarE(eAuto e, eMarca vecMar[], int tamMar, eColor vecCol[], int tamCol);
//************************************
/**
**/
void bajaE(eAuto vec[], int tam, eMarca vecMar[], int tamMar,eColor vecCol[],  int tamCol);
//*********************
/**
**/
int buscarE(eAuto vec[], int tam , int clave);
//***************************
/**
**/
void modificarE(eAuto vec[], int tam, eMarca vecMar[], int tamMar,eColor vecCol[],  int tamCol);
/**
**/
void menuModificar(eAuto vec[], int tam, eMarca vecMar[], int tamMar,eColor vecCol[],  int tamCol,int indice);
/**
**/

