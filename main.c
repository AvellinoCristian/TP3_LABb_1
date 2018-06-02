#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"




int main()
{
    char seguir='s';
    int opcion=0,flag=0;
    FILE *datos;

    datos=fopen("datos.bin","rb+");
    if (datos == NULL)
    {
        printf("No existen datos, generando nuevo archivo...\n\n");
        datos=fopen("datos.bin","wb+");

        if(datos==NULL)
        {
            printf("Imposible generar archivo nuevo\n\n");
            exit(1);
        }
       printf("Archivo nuevo generado con exito!\n\n");
       flag=1;
    }

    if(flag==0)
    printf("Datos cargados con exito!\n");
    system("pause");
    system("cls");


    while(seguir=='s')
    {
        system("cls");

        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("\n\n5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
               if (altaPelicula(datos) == 0)
               {
                   printf("Datos agregados correctamente\n\n");
                   system("pause");
               }
               else
               {
                   printf("Alta cancelada!\n\n");
                   system("pause");
               }

                break;
            case 2:

                if (bajaPelicula(datos) == 0)
                    {
                   printf("Datos borrados correctamente\n\n");
                   system("pause");
               }
               else
               {
                   printf("Datos incorrectos\n\n");
                   system("pause");
               }

                break;
            case 3:
                system("cls");
                if (modificaPelicula(datos) == 0)
               {
                   printf("Datos modificados correctamente\n\n");
                   system("pause");
               }
               else
               {
                   printf("Modificacion cancelada!!\n\n");
                   system("pause");
               }

               break;
            case 4:


                   if (generarHtml(datos) == 0)
               {
                   printf("HTML creada correctamente\n\n");
                   system("pause");
               }
               else
               {
                   printf("Error al generar HTML!!\n\n");
                   system("pause");
               }

                break;

             case 5:
                seguir = 'n';
                break;
        }
    }


    fclose(datos);
    return 0;
}
