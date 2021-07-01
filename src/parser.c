#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"

#include "Libro.h"
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pointerArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pointerFile , LinkedList* pointerArrayListLibro){
	int retorno = -1;
	char buffer[5][300];

	Libro* pointerAuxEmpleado = NULL;
	printf("\n Entró al parser");
	//	int id;    char titulo[300];    char autor[300];    int precio;    int editorialId;
	printf("\n pointerFile %p   pointerArrayListLibro  %p ", pointerFile, pointerArrayListLibro);
	if(pointerFile != NULL && pointerArrayListLibro != NULL){

		fscanf(pointerFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", *(buffer+0), *(buffer+1),*(buffer+2),*(buffer+3),*(buffer+4));
		printf( "\n%s,  %s,  %s,  %s,  %s,    ", *(buffer+0), *(buffer+1),*(buffer+2),*(buffer+3),*(buffer+4));

	while( !feof(pointerFile) ){
		fscanf(pointerFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", *(buffer+0), *(buffer+1),*(buffer+2),*(buffer+3),*(buffer+4));
		printf( "\n%s,  %s,  %s,  %s,  %s,    ", *(buffer+0), *(buffer+1),*(buffer+2),*(buffer+3),*(buffer+4));
		pointerAuxEmpleado = libro_newParametros(*(buffer+0), *(buffer+1),*(buffer+2),*(buffer+3),*(buffer+4));


		if(pointerAuxEmpleado != NULL)
		{
			ll_add(pointerArrayListLibro,pointerAuxEmpleado);
			retorno=0;
		}


	}

	}
  	 return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pointerArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pointerFile , LinkedList* pointerArrayListLibro)
{	int retorno;
	int retornoLeido;
	Libro* pointerAuxEmpleado=NULL;
	Libro auxiliarEmployee;

		if(pointerFile!=NULL && pointerArrayListLibro!=NULL){

			while( !feof(pointerFile) ){

				retornoLeido = fread(&auxiliarEmployee,sizeof(Libro),1,pointerFile);
				pointerAuxEmpleado = movie_new();
				if (pointerAuxEmpleado != NULL ) {

					if(retornoLeido != 0){

						if(  (movie_setId(pointerAuxEmpleado, auxiliarEmployee.id)   == 0) &&
							(movie_setTitulo(pointerAuxEmpleado, auxiliarEmployee.titulo)  == 0) &&
							(movie_setAutor(pointerAuxEmpleado, auxiliarEmployee.autor) == 0) &&
							(movie_setPrecio(pointerAuxEmpleado, auxiliarEmployee.precio) == 0) &&
							(movie_setEditorialId(pointerAuxEmpleado, auxiliarEmployee.editorialId) == 0)
							)
						{

							ll_add(pointerArrayListLibro, pointerAuxEmpleado);
							retorno = 0;
						}
					}

				}
			}
		}

    return retorno;
}
