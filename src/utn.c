/*
 * utn.c
 *
 *  Created on: May 13, 2021
 *      Author: andrea briceño
 */

#ifndef UTN_C_
#define UTN_C_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validacion.h"
#include "utn.h"
#define TAMANOSTRING 25


//INICIALIZACION


int utn_getNumero(int *resultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos) {

	int retorno = -1;
	int auxiliar;
	if (resultado != NULL && mensaje != NULL && mensajeError != NULL && minimo < maximo && reintentos > 0) {
		do{

			printf("%s", mensaje);
			fflush(stdin);
			scanf("%d", &auxiliar);
			if (auxiliar >= minimo && auxiliar <= maximo &&  !isdigit(auxiliar)) {

				*resultado = auxiliar;
				retorno = 0;
				break;
			} else {

				printf("%s", mensajeError);

				retorno = -1;
				reintentos--;
			};
		}while(reintentos>0);

	}
	return retorno;
};

int utn_getFloat(float *resultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos) {

	int retorno = -1;
	float auxiliar; //variable auxiliar;
	if (resultado != NULL && mensaje != NULL && mensajeError != NULL && minimo < maximo && reintentos > 0) {
		do{

			printf("%s", mensaje);
			fflush(stdin);
			scanf("%f", &auxiliar);
			if (auxiliar >= minimo && auxiliar <= maximo &&  !isdigit(auxiliar)) { // si devuelve != 0 cuando si entra

				*resultado = auxiliar;
				retorno = 0;
				break;
			} else {

				printf("%s", mensajeError);

				retorno = -1;
				reintentos--;
			};
		}while(reintentos>0);

	}
	return retorno;
};

int mostrarMenu(int *respuesta) {
	int auxRespuesta;
	printf(" \n ____________________________________MENÚ___________________________________________");
	printf( "\n |                                                                                 |"
			"\n |   1. Cargar los datos de los libros desde el archivo Datos.csv (modo texto).    |"
			"\n |   2. Ordenar libros                                                             |"
			"\n |   3. Listar libros                                                              |"
			"\n |   4. Generar descuento                                                          |"
			"\n |   5. Guardar los datos de los libros en el mapeado.csv (modo texto).            |"
			"\n |   6. Alta de libro                                                              |"
			"\n |   7. Modificar datos de un libro                                                |"
			"\n |   8. Baja de libro                                                              |"
			"\n |   9. Cargar los datos de los libros desde el archivo data.csv (modo binario).   |"
			"\n |  10. Guardar los datos de los libros en el archivo data.csv (modo binario).     |"
			"\n |  11. cantidad libros planeta                                                    |"
			"\n |  12. filtrar los librors de editorial planeta                                   |"
			"\n |  12. SALIR                                                                      |"
			"\n |_________________________________________________________________________________|\n"

			);


	utn_getNumero(&auxRespuesta, "\n  Ingrese una opcion    ","\nError, ingrese una opcion del 1 al 13 \n\n", 1, 13,3);
	*respuesta = auxRespuesta;

	return 0;

};

int utn_getString(char auxiliar[], char *mensaje, char *mensajeError, int reintentos){
	int retorno = -1;
	char bufferString[TAMANOSTRING];
	if(auxiliar != NULL && mensaje != NULL && mensajeError != NULL && reintentos>0)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			gets(bufferString);

			if( strlen(bufferString) < TAMANOSTRING)
			{
				strcpy(auxiliar, bufferString);
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>0);
	}
	return retorno;
};

int utn_getCharAceptar(char *variableChar, char *mensaje, char *mensajeError, int reintentos){
	int retorno = -1;
	char bufferChar;
	if(variableChar != NULL && mensaje != NULL && mensajeError != NULL && reintentos>0)
	{
		do
		{
			printf("%s \n", mensaje);
			fflush(stdin); // SIEMPRE VA AL TOMAR CHARs
			scanf("%c", &bufferChar);

			if(bufferChar == 's' || bufferChar == 'n')
			{
				*variableChar = bufferChar;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
				printf("%d", reintentos);
			}
		}while(reintentos>0);
	}
	return retorno;

}

int utn_getCuil(char auxiliar[], char *mensaje, char *mensajeError, int reintentos){
	int retorno = -1;

	char bufferString[14];
	if(auxiliar != NULL && mensaje != NULL && mensajeError != NULL && reintentos>0)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			gets(bufferString);
			if(strlen(bufferString) < 14){
                if(bufferString[2] == '-' && bufferString[11] == '-' ){

					for(int i = 0 ; bufferString[i]!='\0'; i++){
						if(bufferString[i] == '-' || isdigit(bufferString[i]) == 1){
							continue;
						};
					};
					strcpy(auxiliar, bufferString);
					retorno = 0;
					break;

            }
			else{
				reintentos--;
				printf("%s", mensajeError);
			}

			};

		}while(reintentos>0);
	}
	return retorno;
};

int utn_getSoN(char *variableChar, char *mensaje, char *mensajeError, int reintentos){
	int retorno = -1;
	char bufferChar;
	if(variableChar != NULL && mensaje != NULL && mensajeError != NULL && reintentos>0)
	{
		do
		{
			printf("%s \n", mensaje);
			fflush(stdin);
			scanf("%c", &bufferChar);

			if(bufferChar == 's' || bufferChar == 'n')
			{
				*variableChar = bufferChar;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;

			}
		}while(reintentos>0);
	}
	return retorno;

}

/*
void utn_getChar(char *variableChar, char *mensaje, char *mensajeError,int minimo, int maximo, int reintentos){

	char bufferChar;
	if(variableChar != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos>=0)
	{
		do
		{
			printf("%s \n", mensaje);
			fflush(stdin);
			scanf("%c", &bufferChar);

			if(bufferChar >= minimo && bufferChar <= maximo)
			{
				*variableChar = bufferChar;

				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}

}

*/

/*
int promediarNotas(float *promedio, int nota1, int nota2){

	int retorno = -1;
	float auxiliarpromedio;

	if (promedio != NULL){
		auxiliarpromedio = ((float)nota1 + nota2)/ 2;
		*promedio= auxiliarpromedio;
		retorno = 0;
	};
	return retorno;
}

 */

#endif /* UTN_C_ */
