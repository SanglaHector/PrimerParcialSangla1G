#include "auto.h"
//*******************************************************************************
void altaE(eAuto vec[], int tam, eMarca vecMar[], int tamMar,eColor colVec[],int tamCol){
    int id;
    int indice = buscarLibre(vec,tam);

    if (indice == -1){
        printf("\nNo hay espacio para agregar empleados.");
    }else{
            id = generarIdAuto();

            pedirDatos(vec,tam,id,vecMar,tamMar,colVec,tamCol);
            vec[id].id = id;
            printf("\nEmpleado ingresado con exito: \n");
            mostrarE(vec[id],vecMar,tamMar,colVec,tamCol);
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
    static int id= 1;

    return id++;
}
//***************************************
void inicializarE(eAuto vec[] , int tam){

    for(int i = 0; i < tam ; i++){

        vec[i].estado = VACIO;
    }
}
//***************************************
void pedirDatos(eAuto vec[], int tam, int indice, eMarca vecMar[], int tamMAr, eColor vecCol[], int tamCol){
    int validar = -1;
    char aux[50];
//*********************VALIDO patente*****************************************
        //validar = -1;
        /*while (validar == -1){
            fflush(stdin);*/
            printf("\nIngrese patente: ");
            scanf("%s", aux);
            /*validar = validarPatente(aux);
            if( validar == -1){
                printf("\nla patente recibe 3 digitos numericos y 3 alfabeticos");
            }
        }*/
        strcpy(vec[indice].patente,aux);
        strcpy(aux," ");

//********************VALIDO modelo****************************************
        validar =-1;
        while ( validar == -1){
            fflush(stdin);
            printf("\nIngrese anio de modelo: ");
            scanf("%s", aux);
            validar = validarInt(1900,2020,aux);
            if( validar == -1){
                printf("\nEl año debe estar entre 1900 y 2020");
            }
        }
        vec[indice].modelo = atoi(aux);
        strcpy(aux," ");

//************************marca**********************************************
    validar = -1;
    while(validar == -1){
            printf("\nIngrese un codigo de marca");
            printf("\n1000.Renault");
            printf("\n1001.Fiat");
            printf("\n1002.Ford");
            printf("\n1003.Chevrolet :");
            printf("\n1004.Peugeot :");
            scanf("%s", aux);
            validar = validarInt(1000,1004,aux);
            if(validar == -1){
                printf("\nPor favor ingrese una opcion correcta.");
            }
    }
    vec[indice].idMarca = atoi(aux);
    strcpy(aux," ");
//************************COLOR**********************************************
    validar = -1;
    while(validar == -1){
            printf("\nIngrese un codigo de color");
            printf("\n5000.Negro");
            printf("\n5001.Blanco");
            printf("\n5002.Gris");
            printf("\n5003.Rojo :");
            printf("\n5004.Azuñ\n :");
            scanf("%s", aux);
            validar = validarInt(5000,5004,aux);
            if(validar == -1){
                printf("\nPor favor ingrese una opcion correcta.");
            }
    }
    vec[indice].idColor = atoi(aux);
    strcpy(aux," ");
//**********************TERIMINE VALIDACION*****************************
            vec[indice].estado = OCUPADO;
            printf("\nDatos ingresados con exito!\n");
}
void mostrarE(eAuto e, eMarca vecMar[], int tamMar, eColor vecCol[], int tamCol){

char marca[20];
char color[20];
   for(int i = 0; i < tamMar; i++){

    if ( vecMar[i].id == e.idMarca){

        strcpy(marca,vecMar[i].descripcion);
    }}

     for(int i = 0; i < tamCol; i++){

    if ( vecCol[i].id == e.idColor){

        strcpy(color,vecCol[i].descripcion);
    }
   }
    printf("\nPatente : %s , Marca: %s , Color: %s , Modelo: %d , Patente: %s Su Id es %d: ",e.patente,marca,color,e.modelo,e.patente,e.id);
}
//***************************************************************************
void bajaE(eAuto vec[], int tam, eMarca vecMar[], int tamMar,eColor vecCol[],  int tamCol){
    int id;
    char patente[6];
    int indice;
    char seguir = 'n';
    printf("\nIngrese la patente del auto que quiera eliminar: ");
    scanf("%s", patente);
    for(int i = 0; i < tam ; i++){

        if(strcmp(patente,vec[i].patente) == 0){
           id = vec[i].id;
           }
    }

    indice = buscarE(vec,tam,id);
    if (indice != -1 && vec[indice].estado == OCUPADO){
        mostrarE(vec[indice],vecMar,tamMar,vecCol,tamCol);
        printf("\nEsta seguro que desea dar de baja este auto? S/N: ");
        fflush(stdin);
        scanf("%c",&seguir);
        seguir = toupper(seguir);
        if( seguir == 'S'){

            vec[indice].estado = VACIO;
            printf("\nEl auto se ha dado de baja con exito.");
        }else {
        printf("\nLa operacion ha sido cancelada.");}

    }else {
        printf("\nEl id ingresado no se encuentra en el sistema.");
    }
}
//************************************************************************************
int buscarE(eAuto vec[], int tam , int clave){
    int indice = -1;
    for(int i = 0; i < tam ; i++){
        if(vec[i].id == clave && vec[i].estado == OCUPADO){
            indice = i;
            break;
        }
    }
    return indice;
}
void modificarE(eAuto vec[], int tam, eMarca vecMar[], int tamMar,eColor vecCol[],  int tamCol){
    int id;
    int indice;
    char patente[6];
    char seguir = 'n';
    printf("\nIngrese la patente del auto que quiera modificar: ");
    scanf("%s", patente);
    for(int i = 0; i < tam ; i++){

        if(strcmp(patente,vec[i].patente) == 0){
           id = vec[i].id;
           }
    }
    indice = buscarE(vec,tam,id);
    if (indice != -1 && vec[indice].estado == OCUPADO){
        mostrarE(vec[indice],vecMar,tamMar,vecCol,tamCol);
        printf("\nDesea modificar este empleado?Ingrese S/N: ");
        fflush(stdin);
        scanf("%c" , &seguir);
        fflush(stdin);
        if(seguir == 's' || seguir == 'S'){

            menuModificar(vec,tam,vecMar,tamMar,vecCol,tamCol,indice);
            mostrarE(vec[indice],vecMar,tamMar,vecCol,tamCol);
        }else{
            printf("\nLa operacion ha sido cancelada");
        }

    }else {
        printf("\nEl legajo ingresado no se encuentra en el sistema.");
    }
}
//**********************************************************************
void menuModificar(eAuto vec[], int tam, eMarca vecMar[], int tamMar,eColor vecCol[],  int tamCol,int indice){

int opcion;
int validar =  -1;
char aux[51];

do{
        system("cls");
    printf("\nIngrese una opcion: ");
    printf("\n1.Modificar Color .\n");
    printf("\n2.Modificar Modelo .\n");
    printf("\n3.Salir .\n");
    scanf("%d", &opcion);

    switch(opcion){
//*******************************************************
    case 1:
           validar = -1;
    while(validar == -1){
            printf("\nIngrese un codigo de color");
            printf("\n5000.Negro");
            printf("\n5001.Blanco");
            printf("\n5002.Gris");
            printf("\n5003.Rojo :");
            printf("\n5004.Azuñ\n :");
            scanf("%s", aux);
            validar = validarInt(5000,5004,aux);
            if(validar == -1){
                printf("\nPor favor ingrese una opcion correcta.");
            }
    }
    vec[indice].idColor = atoi(aux);
    strcpy(aux," ");
        break;
//********************************************************
    case 2:
        validar =-1;
        while ( validar == -1){
            fflush(stdin);
            printf("\nIngrese anio de modelo: ");
            scanf("%s", aux);
            validar = validarInt(1900,2020,aux);
            if( validar == -1){
                printf("\nEl año debe estar entre 1900 y 2020");
            }
        }
        vec[indice].modelo = atoi(aux);
        strcpy(aux," ");


        break;
//*******************************************************
    default:
        printf("\nIngrese una opcion correcta. \n");
        break;

    }
}while(opcion != 3);
}
//********************************************************************
int buscarLleno(eAuto vec[],  int tam){

int estado = -1;
for(int i = 0;i <tam ; i++){

    if (vec[i].estado == OCUPADO){
        estado = OCUPADO;
        break;
    }
}
return estado;
}
//**********************************************************************
void listarAutos(eAuto vec[], int tam, eMarca vecMar[], int tamMar,eColor vecCol[],  int tamCol){

eAuto aux;
for(int i = 0; i < tam-1; i++){
    for(int j = 0; j < tam ; j++){

        if(vec[i].idMarca > vec[j].idMarca ){
            aux = vec[i];
            vec[i] = vec[j];
            vec[j] = aux;

        }
    }
}
for(int i = 0; i < tam-1; i++){
    for(int j = 0; j < tam ; j++){
        if(vec[i].idMarca == vec[j].idMarca){

            if(strcmp(vec[i].patente,vec[j].patente) < 0 ){
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
        }
        }
    }
}
for(int i = 0; i < tam ;i ++){
        if(vec[i].estado == OCUPADO){

            mostrarE(vec[i],vecMar,tamMar,vecCol,tamCol);
        }
}

}
//**********************************************************************************
void listarMarcas(eAuto vec[], int tam, eMarca vecMar[], int tamMar,eColor vecCol[],  int tamCol){

    for(int i = 0; i < tamMar; i++){

        printf("\n%s\n",vecMar[i].descripcion);
    }

}
//*************************************************************************************
void listarColores(eAuto vec[], int tam, eMarca vecMar[], int tamMar,eColor vecCol[],  int tamCol){

        for(int i = 0; i < tamCol; i++){

        printf("\n%s\n",vecCol[i].descripcion);
    }
}
//*******************
void listarServicios( eServicio vecSer[], int tamSer){

        for(int i = 0; i < tamSer; i++){

        printf("\n %s\n", vecSer[i].descripcion);
    }
}
//**********************************
void altaTrabajo(eAuto vec[], int tam,eServicio vecSer[], int tamSer,eTrabajo vecTra[], int tamTra){
    int id;
    char aux[6];
    int validar;
    int indice = buscarLibreTra(vecTra,tamTra);
    vecTra[indice] = indice;

    printf("\nIngrese la patente del auto: ");
    scanf("%s", aux);

    strcpy(vec[indice].patente,aux);

    validar = -1;
    while(validar == -1){
            printf("\nIngrese un codigo de servicio");
            printf("\n20000.Negro");
            printf("\n5001.Blanco");
            printf("\n5002.Gris");
            printf("\n5003.Rojo :");
            printf("\n5004.Azuñ\n :");
            scanf("%s", aux);
            validar = validarInt(5000,5004,aux);
            if(validar == -1){
                printf("\nPor favor ingrese una opcion correcta.");
            }
    }
    vec[indice].idColor = atoi(aux);
    strcpy(aux," ");


}
//*****************************************
int generarIdTrabajos()
{
    static int id= 1;

    return id++;
}
//*****************************************
int buscarLibreTra(eTrabajo vec[], int tam){
    int indice = -1;
    for(int i = 0; i < tam ;  i++){

        if(vec[i].estado == VACIO){
            indice = i;
            break;
        }
    }
    return indice;
}
