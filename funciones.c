#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"
#include "Inputs.h"




int altaPelicula(FILE* datos)
{
    EMovie peliculaAuxiliar;
    int aux;

    aux=getString(peliculaAuxiliar.titulo,"Nombre de pelicula :","Demasiado largo\n",1,19);
    if (aux==-1)
        return -1;

    aux=getString(peliculaAuxiliar.genero,"Genero :","Demasiado largo\n",1,19);
    if (aux==-1)
        return -1;

    aux=getInt(&peliculaAuxiliar.duracion,"Duracion :","Demasiado largo\n",1,300);
    if (aux==-1)
        return -1;

    aux=getString(peliculaAuxiliar.descripcion,"Descripcion :","Demasiado largo\n",1,49);
    if (aux==-1)
        return -1;

    aux=getInt(&peliculaAuxiliar.puntaje,"Puntaje :","Demasiado largo\n",1,10);
    if (aux==-1)
        return -1;

    aux=getString(peliculaAuxiliar.linkImagen,"Link IMG :","Demasiado largo\n",1,99);
    if (aux==-1)
        return -1;


    fflush(stdin);
    fseek(datos, 0L, SEEK_END);
    fwrite(&peliculaAuxiliar,sizeof(EMovie),1,datos);

    return 0;
}

int modificaPelicula(FILE* datos)
{
    char parametro[20];
    int aux,cant;
    EMovie peliculaAuxiliar;


    aux=getString(parametro,"Ingresar nombre de pelicula a modificar","Demasiado largo\n",1,19);
    if (aux==-1)
        return -1;

    rewind(datos);


    while(!feof(datos))
    {

        cant = fread(&peliculaAuxiliar,sizeof(EMovie),1,datos);

        if(cant!=1)
        {
            if(feof(datos))
            {
                printf("No se encontraron los datos ingresados\n");
                return -1;
            }
            else
            {
                printf("Error al leer datos\n");
                return -1;
            }
        }

        if (strcmp(peliculaAuxiliar.titulo,parametro) == 0)
        {



            switch(menuModifica())
            {

            case 1:
                aux=getString(peliculaAuxiliar.titulo,"Nuevo Nombre pelicula :","Demasiado largo\n",1,19);
                if (aux==-1)
                    return -1;

                break;
            case 2:
                aux=getString(peliculaAuxiliar.genero,"Genero :","Demasiado largo\n",1,19);
                if (aux==-1)
                    return -1;
                break;
            case 3:
                aux=getInt(&peliculaAuxiliar.duracion,"Duracion :","Demasiado largo\n",1,300);
                if (aux==-1)
                    return -1;
                break;
            case 4:
                aux=getInt(&peliculaAuxiliar.puntaje,"Puntaje :","Demasiado largo\n",1,10);
                if (aux==-1)
                    return -1;
                break;
            case 5:
                aux=getString(peliculaAuxiliar.descripcion,"Descripcion :","Demasiado largo\n",1,49);
                if (aux==-1)
                    return -1;
                break;
            case 6:

                aux=getString(peliculaAuxiliar.linkImagen,"Link IMG :","Demasiado largo\n",1,99);
                if (aux==-1)
                    return -1;
                break;



            default:
                printf("Opcion invalida\n\n");
                return -1;
            }


            fseek(datos,(long)(-1)*sizeof(EMovie),SEEK_CUR);
            fflush(stdin);
            fwrite(&peliculaAuxiliar,sizeof(EMovie),1,datos);


            break;
        }
    }

    return 0;
}



int generarHtml(FILE* datos)
{
    FILE* html;

    EMovie peliAux;
    char buffer[1080]= {}; //="<html><body><MARQUEE><h1>Hola a todos</h1></MARQUEE></body></html>";
    int cant;
    char auxchar[10];

    rewind(datos);

    while (!feof(datos))
    {


        cant = fread(&peliAux,sizeof(EMovie),1,datos);


        if(cant!=1)
        {
            if(feof(datos))
            {
                printf("Carga completa\n\n");
                break;
            }
            printf("Error al leer archivo de datos\n\n");
            fclose(html);
            return -1;
        }



        strcat(buffer,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='");

        strcat(buffer,peliAux.linkImagen);

        strcat(buffer,"'alt=''></a><h3><a href='#'>");

        strcat(buffer,peliAux.titulo);

        strcat(buffer,"</a><h3><ul><li>Género:");

        strcat(buffer,peliAux.genero);

        strcat(buffer,"</li><li>Puntaje:");

        sprintf(auxchar,"%d",peliAux.puntaje);

        strcat(buffer,auxchar);

        strcat(buffer,"</li><li>Duración:");

        sprintf(auxchar,"%d",peliAux.duracion);

        strcat(buffer,auxchar);

        strcat(buffer,"</li></ul><p>");

        strcat(buffer,peliAux.descripcion);

        strcat(buffer,"</p></article>");

        html = fopen("web.html","w");
        fprintf(html,buffer);
    }


    fclose(html);
    return 0;
}

int menuModifica()
{
    int opcion;
    printf("\t--MODIFICACION--\n\n");
    printf("1-NOMBRE\n");
    printf("2-GENERO\n");
    printf("3-DURACION\n");
    printf("4-PUNTAJE\n");
    printf("5-DESCRIPCION\n");
    printf("6-LINK IMAGEN\n");
    scanf("%d",&opcion);

    return opcion;
}

int bajaPelicula(FILE* datos)
{
    EMovie* peliculasBuffer;
    int tam,i,aux,flag=0;
    char parametro[21];
    FILE* temp;

    fseek(datos,0l,SEEK_END);
    tam = ftell(datos)/sizeof(EMovie);

    peliculasBuffer=(EMovie*)malloc(tam * sizeof(EMovie)); // memoria de datos actuales

    rewind(datos);
    fread(peliculasBuffer,sizeof(EMovie),tam,datos);       //cargo el array dinamico con todos los datos (includo el que se quiere dar de baja)

    aux=getString(parametro,"Ingresar pelicula a dar de baja","Datos invalidos",1,19);
    if(aux==-1)
    {
        free(peliculasBuffer);
        return -1;
    }



    temp = fopen("temporal.bin","wb+"); //creo archivo temporal

    for (i=0; i<tam; i++)
    {
        if ( strcmp(parametro,(peliculasBuffer+i)->titulo)==0)
        {
            flag = 1;

        }
        else
        {

            fseek(temp,0l,SEEK_END);
            fflush(stdin);
            fwrite(peliculasBuffer+i,sizeof(EMovie),1,temp);
        }
    }//for

    fclose(temp);
    fclose(datos);

    remove("datos.bin");
    rename("temporal.bin","datos.bin");

    datos = fopen("datos.bin","rb+");

    free(peliculasBuffer);

    if (flag == 0)
        return -1;


    return 0;
}
