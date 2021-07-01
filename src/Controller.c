 /** controller.c
 *
 *      Author: Andrea Briceño
 */
#include <stdio.h>
#include <stdlib.h>
#include "Libro.h"
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"


int controller_addLibro(LinkedList* pointerArrayListMovies){

	int retorno = -1;
    Libro *peliculaAuxiliar = NULL;
    int  auxiliarId = 0;
	int idMaximo;
	char auxiliarTitulo[150];
	char auxiliarAutor[150];
	int auxiliarPrecio;
	int cantidadLibros;
	int auxiliarEditorialId;

    		if (pointerArrayListMovies != NULL){


    				printf("\n    ---------------- Alta de un libro nuevo ------------- \n");
    				if (  (utn_getString(auxiliarTitulo,"\n Ingrese el titulo  ", "\n Error intente nuevamente  ", 3) == 0) &&
					      (utn_getString(auxiliarAutor,"\n Ingrese el autor ", "\n Error, intente nuevamente",3) == 0) &&
					      (utn_getNumero(&auxiliarPrecio,"\n Ingrese el precio (Entre 1 y 90000) ", "\n Error, intente nuevamente", 1, 90000,3) == 0) &&
					      (utn_getNumero(&auxiliarEditorialId,"\n Ingrese el id de la editorial: \n1 - PLANETA \n2 - SIGLO XXI EDITORES \n3 - PEARSON\n4 - MINOTAURO\n5 - SALAMANDRA \n6 - PENGUIN BOOKS                ", "\n Error, intente nuevamente", 1, 6,3) == 0)
				       ){
    					if( ll_isEmpty(pointerArrayListMovies) == 0){

    						cantidadLibros = ll_len(pointerArrayListMovies);

							for(int i=0; i<cantidadLibros ; i++){

								peliculaAuxiliar =ll_get(pointerArrayListMovies, i);
								libro_getId(peliculaAuxiliar, &idMaximo);

								if(  auxiliarId>idMaximo ){
									idMaximo = auxiliarId;
								};
							};
    					};
    					printf("auxiliarId %d idMaximo  %d", auxiliarId, idMaximo);
    					idMaximo++;
    				    printf("auxiliarId %d idMaximo  %d", auxiliarId, idMaximo);
    					peliculaAuxiliar = libro_new();

    					if(   (libro_setId(peliculaAuxiliar, idMaximo) == 0) &&
  							  (libro_setTitulo(peliculaAuxiliar, auxiliarTitulo) == 0) &&
							  (libro_setAutor(peliculaAuxiliar, auxiliarAutor) == 0) &&
							  (libro_setPrecio(peliculaAuxiliar, auxiliarPrecio) == 0) &&
							  (libro_setEditorialId(peliculaAuxiliar, auxiliarEditorialId) == 0)

    					){
    						ll_add(pointerArrayListMovies, peliculaAuxiliar);
							printf("\nEl libro cargado es: \n");
							libro_printfOne(peliculaAuxiliar);
							retorno=0;
    					}else{
    						printf("\nHubo un error al cargar el libro \n");

    					};
    				};
    		};
	return retorno;
}


int controller_editLibro(LinkedList* pointerArrayListMovies)
{

	int retorno = -1;
	Libro *peliculaAuxiliar = NULL;
	char auxiliarTitulo[150];
	char auxiliarAutor[150];
	int auxiliarPrecio;
	int datoACambiar;
	int idLibroACambiar;
	int cantidadLibros;
	int  auxiliarId = 0;
	int idMaximo;
	if(ll_isEmpty(pointerArrayListMovies) == 0 && pointerArrayListMovies != NULL){

			printf("\n    ---------------- Modificación de un libro ------------- \n");


				cantidadLibros = ll_len(pointerArrayListMovies);
				for(int i=0; i<cantidadLibros ; i++){
					peliculaAuxiliar = ll_get(pointerArrayListMovies, i);
					libro_getId(peliculaAuxiliar, &idMaximo);
					if(  auxiliarId>idMaximo ){
						idMaximo = auxiliarId;


					};
				};


				if(	utn_getNumero(&idLibroACambiar, "\nIngrese el id del libro a cambiar    ", "\nError, intente nuevamente",  -1, idMaximo, 3) == 0){

					for (int i = 0; i < cantidadLibros; i++) {
						peliculaAuxiliar = ll_get(pointerArrayListMovies, i);
						libro_getId(peliculaAuxiliar, &auxiliarId);

						if (idLibroACambiar == auxiliarId) {
							printf("\nlibro encontrado");
							libro_printfOne(peliculaAuxiliar);
							break;
						}
					}
					do{
						utn_getNumero(&datoACambiar, "\n Ingrese una opcion del 1 al 3 \n1- modificar nombre \n2- modificar horas trabajadas \n3- modificar salario, \n4-  Volver al menú principal        ", "\n Error, ingrese nuevamente", 1, 4, 3);

						switch (datoACambiar) {
							case 1:
								if (  (utn_getString(auxiliarTitulo,"\n Ingrese el nombre  ", "\n Error intente nuevamente  ", 3) == 0) &&
									  (libro_setTitulo(peliculaAuxiliar, auxiliarTitulo) == 0) ){
											printf("\n DATOS NUEVOS-------------------------------- \n");
											libro_printfOne(peliculaAuxiliar);
											retorno=0;
								}
								break;
							case 2:
								if (  (utn_getString(auxiliarAutor,"\n Ingrese las horas trabajadas  ", "\n Error, intente nuevamente",3) == 0) &&
									  (libro_setAutor(peliculaAuxiliar, auxiliarAutor) == 0) ){
											printf("\n DATOS NUEVOS-------------------------------- \n");
											libro_printfOne(peliculaAuxiliar);
											retorno=0;
								}
								break;
							case 3:
								if (  (utn_getNumero(&auxiliarPrecio,"\n Ingrese el sueldo  ", "\n Error, intente nuevamente", 1, 90000,3) == 0) &&
									  (libro_setPrecio(peliculaAuxiliar, auxiliarPrecio) == 0) ){
											printf("\n DATOS NUEVOS-------------------------------- \n");
											libro_printfOne(peliculaAuxiliar);
											retorno=0;
								}
							break;
							case 4:
							break;
						}
					 }while(  datoACambiar != 4);


				}else{
					printf("\n\nLo sentimos, ID no encontrado");
				}

	}else{
		printf("No hay libros cargados");

	}

	return retorno;
}


int controller_removeLibro(LinkedList* pointerArrayListMovies)
{

	int retorno = -1;
	Libro *peliculaAuxiliar = NULL;
	int  auxiliarId = 0;
	char validacion;
	int idLibroACambiar;
	int cantidadLibros;
	int idMaximo;

	int indexLibro;
	if(ll_isEmpty(pointerArrayListMovies) == 0 && pointerArrayListMovies != NULL){

			printf("\n    ---------------- Baja de un libro ------------- \n");


				cantidadLibros = ll_len(pointerArrayListMovies);
				for(int i=0; i<cantidadLibros ; i++){
					peliculaAuxiliar = ll_get(pointerArrayListMovies, i);
					libro_getId(peliculaAuxiliar, &idMaximo);
					if(  auxiliarId>idMaximo ){
						idMaximo = auxiliarId;
					};
				};


				if(	utn_getNumero(&idLibroACambiar, "\nIngrese el id del libro a dar de baja  ", "\nError, intente nuevamente",  -1, idMaximo, 3) == 0){

					for (int i = 0; i < cantidadLibros; i++) {
						peliculaAuxiliar = ll_get(pointerArrayListMovies, i);
						libro_getId(peliculaAuxiliar, &auxiliarId);

						if (idLibroACambiar == auxiliarId) {
							printf("\nlibro encontrado");
							libro_printfOne(peliculaAuxiliar);
							indexLibro =  ll_indexOf(pointerArrayListMovies, peliculaAuxiliar);
							break;
						}

					}
							utn_getCharAceptar(&validacion, "\n¿Está seguro que desea borrar este libro?  ('s' o 'n')        ", "\n Error, ingrese nuevamente", 3);
							switch (validacion) {

								case 's':
									ll_remove(pointerArrayListMovies, indexLibro);
									printf("\n libro eliminado");
								break;
								case 'n':
									printf("\n Operación cancelada");
								break;
							}
				}else{
					printf("\n\nLo sentimos, ID no encontrado");
				}

	}else{
		printf("No hay libros cargados");

	}

	return retorno;
}

int controller_ListLibro(LinkedList* pointerArrayListMovies){
	int retorno = -1;
	int  auxiliarId;
	char auxiliarTitulo[150];
	char auxiliarAutor[150];
	char auxiliarEditorialTexto[300];
	int auxiliarPrecio;
	int auxiliarIdEditorial;



	int lenghtLibros = ll_len(pointerArrayListMovies);
	if (pointerArrayListMovies != NULL && lenghtLibros > 0){
		printf("\n           ********************************************  LIBROS ********************************************* ");


		for(int i = 0; i < lenghtLibros; i++ ){
			Libro*  peliculaAuxiliar= ll_get(pointerArrayListMovies, i);

			libro_getId( peliculaAuxiliar, &auxiliarId);
			libro_getTitulo(peliculaAuxiliar, auxiliarTitulo);
			libro_getAutor(peliculaAuxiliar, auxiliarAutor);
			libro_getPrecio(peliculaAuxiliar, &auxiliarPrecio);
			libro_getEditorialId(peliculaAuxiliar, &auxiliarIdEditorial);
			idAEditorial(auxiliarIdEditorial, auxiliarEditorialTexto);

			printf("\n Id %2d.  Titulo: %-50s |   Autor: %-15s |   Precio: %8d |   Editorial: %s  ",
																	   auxiliarId,
																	   auxiliarTitulo,
																	   auxiliarAutor,
																	   auxiliarPrecio,
																	   auxiliarEditorialTexto
																	   );
		};
		retorno = 0;
	}else{
		printf("No hay libros cargados");

	}


    return retorno;
}


int controller_sortLibro(LinkedList* pointerArrayListMovies)
{
		int retorno = -1;
		int(*funcionTipoOrden)(void*,void*);
		int tipodeSort;


		int lenghtLibros = ll_len(pointerArrayListMovies);
		if (pointerArrayListMovies != NULL && lenghtLibros > 0){



			utn_getNumero(&tipodeSort, "\n Ingrese una opcion del 1 al 8 "
					"\n 1- Ordenar ID de forma ascendente "
					"\n 2- Ordenar ID de forma descendente "
					"\n 3- Ordenar Autor de A - Z "
					"\n 4- Ordenar Autor de Z - A "
					"\n 5- Ordenar Titulo de A - Z "
					"\n 6- Ordenar Titulo de Z - A "
					"\n 7- Ordenar Precio de forma ascendente "
					"\n 8- Ordenar Precio de forma descendente "
					"\n 9- Ordenar Editorial de A - Z "
					"\n10- Ordenar Editorial de Z - A "
					"\n11-  Volver al menú principal        ", "\n Error, ingrese nuevamente ", 1, 11, 3);

					switch (tipodeSort) {
						case 1:
						case 2:
							funcionTipoOrden = libro_sortID;
							break;
						case 3:
						case 4:
							funcionTipoOrden = libro_sortAutor;
							break;
						case 5:
						case 6:
							funcionTipoOrden = libro_sortTitulo;
							break;
						case 7:
						case 8:
							funcionTipoOrden = libro_sortPrecio;
							break;
						case 9:
						case 10:
							funcionTipoOrden = libro_sortEditorial;
							break;
						case 11:
							break;
					}//Fin switch

			if(tipodeSort % 2 != 0){
				ll_sort(pointerArrayListMovies, funcionTipoOrden, 1);
			}else{
				ll_sort(pointerArrayListMovies, funcionTipoOrden, 0);
			}
			printf("\n               ** Lista ordenada ** ");
			retorno = 0;
		}else{
			printf("No hay libros cargados");

		}

    return retorno;
}


int controller_saveAsText(char* path , LinkedList* pointerArrayListMovies)
{
	int retorno = -1;
	int  auxiliarId;
	char auxiliarTitulo[150];
	char auxiliarAutor[150];
	int auxiliarPrecio;
	int auxiliarEditorialId ;


	if(ll_isEmpty(pointerArrayListMovies) == 0){
	FILE *pointerFile = fopen(path,"w");
		if (path != NULL && pointerArrayListMovies != NULL && pointerFile != NULL){
			fprintf( pointerFile,"Id,    Tiulo,    Autor,  Precio,   Editorial \n");
			for(int i = 0; i < ll_len(pointerArrayListMovies); i++){

				Libro  *peliculaAuxiliar = ll_get(pointerArrayListMovies, i);
				if(		libro_getId( peliculaAuxiliar, &auxiliarId) == 0 &&
						libro_getTitulo(peliculaAuxiliar, auxiliarTitulo) == 0 &&
						libro_getAutor(peliculaAuxiliar, auxiliarAutor) == 0 &&
						libro_getPrecio(peliculaAuxiliar, &auxiliarPrecio) == 0 &&
						libro_getEditorialId(peliculaAuxiliar, &auxiliarEditorialId) == 0
					)
				{
				fprintf( pointerFile,"%d, %s, %s, %d,  %d\n",
														 auxiliarId,
														 auxiliarTitulo,
														 auxiliarAutor,
														 auxiliarPrecio,
														 auxiliarEditorialId
														 );
				}
			}

			fclose(pointerFile);
			printf("\nDatos guardados en %s", path);
			retorno = 0;
		};
	}else{
		printf("Error, No hay datos para guardar");

	}

	return retorno;


}


int controller_saveAsBinary(char* path , LinkedList* pointerArrayListMovies)
{
	int retorno = -1;
	int cantidadEscrita;

	if(ll_isEmpty(pointerArrayListMovies) == 0){
		if (path != NULL && pointerArrayListMovies != NULL){
			FILE *pointerFile=fopen(path,"wb");

			int lenghtLibros = ll_len(pointerArrayListMovies);

			for(int i = 0; i < lenghtLibros; i++ ){

				Libro*  peliculaAuxiliar= ll_get(pointerArrayListMovies, i);
				if(pointerFile != NULL){
					cantidadEscrita = fwrite(peliculaAuxiliar, sizeof(Libro),1, pointerFile);
				};
			}
			if (cantidadEscrita < 1){
				printf("\nError al escribir el archivo");
			}else{
				printf("\nDatos guardados en %s", path);
				retorno = 0;
			}
			fclose(pointerFile);
		};
	}else{
		printf("Error, No hay datos para guardar");

	}
	return retorno;
}


int controller_loadFromText(char* path , LinkedList* pointerArrayListMovies){

	int retorno = -1;
	char validacion = 's';
	FILE *pointerFile = NULL;
	if (path != NULL && pointerArrayListMovies != NULL){

		if(ll_isEmpty (pointerArrayListMovies ) == 1){

			pointerFile = fopen(path,"r");

			if( parser_LibroFromText(pointerFile, pointerArrayListMovies) == 0 )
			{
				printf("\nArchivo leido y cerrado con éxito");
				retorno = 0;

			}else{
				printf("\nNo se pudo leer el archivo");
			}
			fclose(pointerFile);

		}else{

			utn_getCharAceptar(&validacion, "\nYa hay datos cargados en el sistema, desea guardarlos? ('s' o 'n')    ", "\n Error, ingrese nuevamente", 3);
			switch (validacion)
			{
				case 'n':
					printf("\nSe han borrado los datos cargados anteriormente.  ");
					ll_clear(pointerArrayListMovies);
					FILE *pointerFile=fopen(path,"r");

					if(pointerFile != NULL && parser_LibroFromText(pointerFile, pointerArrayListMovies) == 0 )
					{
						printf("\nArchivo nuevo leido y cerrado con éxito");
						fclose(pointerFile);
						retorno = 0;
					}
				break;
				case 's':
					if(controller_saveAsText( "respaldo.csv", pointerArrayListMovies) == 0){

						ll_clear(pointerArrayListMovies);

						FILE *pointerFile=fopen(path,"r");

						if(pointerFile != NULL && parser_LibroFromText(pointerFile, pointerArrayListMovies) == 0 )
						{
							printf("\nArchivo nuevo leido y cerrado con éxito");
							fclose(pointerFile);
							retorno = 0;
						}


					}
				break;
				}
			}
	}
    return retorno;
}


int controller_loadFromBinary(char* path , LinkedList* pointerArrayListMovies){

	    int retorno = -1;
	    	char validacion = 's';
	    	if (path != NULL && pointerArrayListMovies != NULL){


	    		if(ll_isEmpty (pointerArrayListMovies ) == 1){

	    			FILE *pointerFile=fopen(path,"rb");

	    			if(pointerFile != NULL &&
	    				parser_LibroFromBinary(pointerFile, pointerArrayListMovies) == 0 ){
	    				printf("\nArchivo leido y cerrado con éxito");
	    				retorno = 0;

	    			}else{
	    				printf("\nNo se pudo leer el archivo");
	    			}
	    			fclose(pointerFile);

	    		}else{

	    			utn_getCharAceptar(&validacion, "\nYa hay datos cargados en el sistema, desea guardarlos? ('s' o 'n')    ", "\n Error, ingrese nuevamente", 3);
	    			switch (validacion)
	    			{
	    				case 'n':
	    					printf("\nSe han borrado los datos cargados anteriormente.  ");
	    					ll_clear(pointerArrayListMovies);
	    					FILE *pointerFile=fopen(path,"rb");

	    					if(  pointerFile != NULL &&
	    					     parser_LibroFromBinary(pointerFile, pointerArrayListMovies)  == 0  )
	    					{
	    						printf("\nArchivo nuevo leido y cerrado con éxito");
	    						fclose(pointerFile);
	    						retorno = 0;
	    					}
	    				break;
	    				case 's':
	    					if ( controller_saveAsBinary("respaldo.bin",pointerArrayListMovies) == 0 )
	    					{
								ll_clear(pointerArrayListMovies);
								FILE *pointerFile=fopen(path,"rb");

								if(  pointerFile != NULL &&
									 parser_LibroFromBinary(pointerFile, pointerArrayListMovies)  == 0  )
								{
									printf("\nArchivo nuevo leido y cerrado con éxito");
									fclose(pointerFile);
									retorno = 0;
								}
	    					}
	    				break;
	    				}
	    			}
	    	}
	        return retorno;


}



int controller_Contador(LinkedList* pointerArrayListMovies)
{
		int retorno = -1;
		int (*funcion)(void* element);
		int opcion;
		int cantidad;

		int lenghtLibros = ll_len(pointerArrayListMovies);
		if (pointerArrayListMovies != NULL && lenghtLibros > 0){



			utn_getNumero(&opcion, "\n Ingrese una opcion del 1 al 8 "
					"\n 1- calcular Cantidad Editorial Planeta "
					"\n 2-"
					"\n 3- "
					"\n 4- "
					"\n 5-"
					"\n 6- "
					"\n 7-  Volver al menú principal        ", "\n Error, ingrese nuevamente ", 1, 7, 3);

					switch (opcion) {
						case 1:
							funcion = calcularCantidadEditorialPlaneta;
							break;
						case 2:
						case 3:
						case 4:

							break;
						case 5:
						case 6:


						break;
						case 7:

								break;
					}//Fin switch


					cantidad = ll_count(pointerArrayListMovies, funcion);
					printf("\n  cantidad de libro con editorial  el planeta %d",cantidad );


			retorno = 0;
		}else{
			printf("No hay libros cargados");

		}

    return retorno;
}



int controller_filtro(LinkedList* pointerArrayListMovies)
{
		int retorno = -1;
		int (*funcion)(void* element);
		int opcion;

		LinkedList* LinkedListNueva = NULL;

		int lenghtLibros = ll_len(pointerArrayListMovies);
		if (pointerArrayListMovies != NULL && lenghtLibros > 0){



			utn_getNumero(&opcion, "\n Ingrese una opcion del 1 al 8 "
					"\n 1- filtrar Editorial Planeta "
					"\n 2-"
					"\n 3- "
					"\n 4- "
					"\n 5-"
					"\n 6- "
					"\n 7-  Volver al menú principal        ", "\n Error, ingrese nuevamente ", 1, 7, 3);

					switch (opcion) {
						case 1:
							funcion = filterPlaneta;
							break;
						case 2:
						case 3:
						case 4:
						case 5:
						case 6:
						case 7:
						break;
					}//Fin switch


					LinkedListNueva = ll_filter(pointerArrayListMovies, funcion);
					if(LinkedListNueva != NULL){
						controller_ListLibro(LinkedListNueva);
					};


			retorno = 0;
		}else{
			printf("No hay libros cargados");

		}

    return retorno;
}




/*
int controller_Informes(LinkedList* pointerArrayListMovies){
	Pelicula *peliculaAuxiliar = NULL;
	int retorno = -1;
	int tipodeInforme;
	int  auxiliarPrecio = 0;
	int salaMaxima;

	utn_getNumero(&tipodeInforme,
			"\n _________Ingrese una opcion del 1 al 8 "
			"\n | 1- Cantidad de entradas vendidas para la sala."
			"\n | 2- Monto total facturado para la sala.  "
			"\n | 3- Listado de películas que se proyectaron en dicha sala  "
			"\n | 4-  Volver al menú principal    \n |    ", "\n Error, ingrese nuevamente", 1, 5, 3);

	if (pointerArrayListMovies != NULL && ll_isEmpty(pointerArrayListMovies == 0)){


			if(ll_isEmpty(pointerArrayListMovies) == 0 && pointerArrayListMovies != NULL){

					printf("\n    ---------------- Modificación de un libro ------------- \n");



						for(int i=0; i< ll_len(pointerArrayListMovies); i++){
							peliculaAuxiliar = ll_get(pointerArrayListMovies, i);
							movie_getSala(peliculaAuxiliar, &salaMaxima);
							if(  auxiliarPrecio>salaMaxima )
							{
								salaMaxima = auxiliarPrecio;
							};
						};


						if(	utn_getNumero(&idLibroACambiar, "\nIngrese el id del libro a cambiar    ", "\nError, intente nuevamente",  -1, idMaximo, 3) == 0){


						}}


		//usuario ingresará el número de sala y se imprimirá por pantalla:
		//"\n | 1- Cantidad de entradas vendidas para la sala."

		switch (tipodeInforme) {
			case 1:

				utn_getNumero(&tipodeInforme,
							"\n Ingrese el numero de sala", "\n Error, ingrese nuevamente", 1, 5, 3);
				for(int i = 0; i < ll_len(pointerArrayListMovies); i++){

								Pelicula  *peliculaAuxiliar = ll_get(pointerArrayListMovies, i);
								//movie_getSala(peliculaAuxiliar, &auxiliarPrecio)
				}



				break;
			default:
				break;
		}



		 retorno = 0;
	}

	return retorno;

}*/
