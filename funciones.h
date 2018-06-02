#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[100];
}EMovie;



/**
 *  imprime opciones para luego retornar la opcion
 *  @return retorna la opcion
 */
int menuModifica();

/**
 *  envia los datos que estan en memoria al archivo datos.bin
 *  @param FILE puntero a archivo
 *  @return retorna 0 si envio, -1 sino
 */
int altaPelicula(FILE*);

/**
 *  lee estructura a estructura desde el archivo en buffer, y compara, luego edita ese dato en el archivo
 *  @param FILE puntero a archivo
 *  @return retorna 0 si envio, -1 sino
 */
int modificaPelicula(FILE*);
/**
 *  manda los datos del .bin al .html en forma de texto
 *  @param FILE puntero a archivo
 *  @return retorna 0 si envio, -1 sino
 */
int generarHtml(FILE*);

/*
se hace un ftell de el archivo DATOS.BIN, y el resultado
de los bits ocupados del mismo, se dividen por el sizeof
de la estructura EMOVIE, lo cual me da los indices ocupados

con los indices, reservo memoria con malloc, y genero un array auxiliar
con la memoria justa para los datos actuales de DATOS.BIN

creo un ciclo repetitivo buscando la coincidencia, la cual es
el nombre de la pelicula a dar de baja(parametro que se pide al usuario), y cuando la encuentro,
no la incluyo en el archivo  temporal

luego, remuevo el archivo BIN principal(remove), y renombro el archivo temporal(rename)
como BIN, est este ultimo, no tedran los valores logicos negados, por ende
el dato sera borrado.
*/

/**
 *  genera un archivo temporal, sin el dato a dar de baja, luego, borra el principal, y renombra el temporal al principal
 *  @param FILE puntero a archivo
 *  @return retorna 0 si envio, -1 sino
 */
int bajaPelicula(FILE*);


#endif // FUNCIONES_H_INCLUDED
