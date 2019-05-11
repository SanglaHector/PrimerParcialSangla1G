#include "validaciones.h"
//**************************************************************************************************************
int validarNombre(char nombre[]){

int retorno =  -1;
int todoOk = 0;
    for(int i=0; i<strlen(nombre); i++)
    {
        if(isalpha(nombre[i]) == 0 ){

            todoOk = -1;
        }
    }
    if (todoOk == 0){
        retorno = 1;
    }
return retorno;
}
//***********************************************************************************************************
int validarInt(int min, int max ,char num[]){
    int validar = -1;
    int numero = 0;
    validar = isDigit(num);
    if (validar == 1){

        numero = charToInt(num);

        if (numero != 0 && numero >= min && numero <= max){
            validar = 1;
        }else {
        validar  =-1;
        }
    }
    return validar;
}
//**************************************************************************************************************
int validarFloat(int min, int max, char num[]){
    int validar = -1;
    float numero =0;
    int paraCompa = 0;
    validar = isDigit(num);
    if(validar == 1){


        numero = charToFloat(num);
        paraCompa = (int)numero;


        if (paraCompa <= min || paraCompa >= max ){
            validar = -1;
        }else{
        validar = 1;}
    }


    return validar;
}
//**************************************************************************************************************
int isDigit(char numero[]){
    int validar = -1;
    int todoOk = 1;

    for(int i = 0;i < strlen(numero); i++){
        if( isdigit(numero[i]) == 0){
            todoOk = -1;
        }
    }
    if( todoOk == 1){
        validar = 1;
    }
    return validar;
}//Funciona bien
//***********************************************************************************************************
int isApha(char cadena[]){
int todoOk = 1;
    for(int i = 0; i < strlen(cadena); i ++){

        if(isalpha(cadena[i])== 0 && cadena[i] != ' '){
            todoOk = -1;
        }
    }
    return todoOk;
}
//***********************************************************************************************************
int charToInt(char numero[]){
    int numeroInt = 0;
    numeroInt = atoi(numero);
    return numeroInt;
}
//***********************************************************************************************************
float charToFloat(char numero[]){
    float numeroFloat=0;
    numeroFloat = atof(numero);
    return  numeroFloat;
}
//************************************************************************************************************
int validarPatente(char patente[]){
int validar = -1;
int todoOK = 1;
char parteNum[3];
char parteCaracter[3];
int validarNum;
int validarCaracter;

    for(int i = 0; i < 3 ; i ++){
        parteNum[i] = patente[i];
    }
    for(int i = 0; i < 3 ; i++){
        parteCaracter[i] = patente[i+3];
    }
    printf("\nParte num:  %s  y parte caracter:  %s", parteNum,parteCaracter);
        validarNum = isDigit(parteNum);
        validarCaracter = isChar(parteCaracter);
}
//***********************************************
int isChar(char aux[]){
    int validar = 1;
    for(int i = 0; i < strlen(aux); i++){

        if( isalnum(aux[i]) == 0){
            validar = -1;
            break;
        }
    }
    return validar;
}

