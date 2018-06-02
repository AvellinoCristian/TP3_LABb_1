#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Inputs.h"
#include "funciones.h"

/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int aux;

    printf("%s\n",message);
    fflush(stdin);
    scanf("%d",&aux);

    if (aux >= lowLimit && aux <= hiLimit)
    {
        *input=aux;
        return 0;
    }

    printf("%s\n",eMessage);
    return -1;
}


/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit)
{
    float aux;

    printf("%s\n",message);
    fflush(stdin);
    scanf("%f",&aux);

    if (aux >= lowLimit && aux <= hiLimit)
    {
        *input=aux;
        return 0;
    }

    printf("%s\n",eMessage);
    return -1;
}

/**
* \brief Solicita una cadena de caracteres al usuario y la valida
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{

    char aux[200];

    printf("%s\n",message);
    fflush(stdin);
    scanf("%[^\n]",aux);

    if (strlen(aux) >= lowLimit && strlen(aux) <= hiLimit )

    {
        strcpy(input,aux);
        return 0;
    }

    printf("%s\n",eMessage);
    return -1;




}


//validacion

int esSoloLetras(char cadena[])
{
    int i=0;
    while (cadena[i] != '\0')
    {
        if( (cadena[i]!= ' ')&&(cadena[i]< 'a' || cadena[i] > 'z')&&(cadena[i] < 'A' || cadena[i] > 'Z'))
            return -1;
        i++;

    }
    return 0;
}

int esSoloNumeros(char cadena[])
{
    int i=0;
    while (cadena[i] != '\0')
    {
        if( cadena[i]< '0' || cadena[i] > '9')
            return -1;
        i++;

    }
    return 0;
}
