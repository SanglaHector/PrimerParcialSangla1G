#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "fecha.h"
/*#include "auto.h"
#include "Colores.h"
#include "Servicios.h"
#include "validaciones.h"
#include "Marca.h"*/
#define TAM 7
#define OCUPADO 1
#define VACIO 0

typedef struct{
    int id;//tiket
    char patente[6];
    int idServicio;
    eFecha fecha;
    int estado;
}eTrabajo;

