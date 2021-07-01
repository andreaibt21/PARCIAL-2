 /** Libro.c
 *
 *      Author: Andrea Briceño
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Libro.h"
#include "LinkedList.h"
#include "parser.h"

Libro* movie_new(){
	Libro* auxiliar = NULL;

	auxiliar = (Libro*)malloc(sizeof(Libro));
	if (auxiliar != NULL){
		strcpy(auxiliar->autor, "");
		strcpy(auxiliar->titulo, "");
		auxiliar->editorialId = 0;
		auxiliar->id = 0;
		auxiliar->precio = 0;
	}
	return auxiliar;
}
                          //	int id; char titulo[300]; char autor[300]; int precio; int editorialId;

Libro* libro_newParametros(char* idStr,char* tituloStr,char* autorStr,char* precioStr, char* editorialIdStr){
	Libro* peliculaAuxiliar = movie_new();
	int auxiliarIdEditorial;

	if( idStr != NULL && tituloStr != NULL &&  precioStr != NULL && editorialIdStr != NULL ){
			if( (movie_setId( peliculaAuxiliar, atoi(idStr) )  ==0) &&
				(movie_setTitulo( peliculaAuxiliar, tituloStr) ==0) &&
				(movie_setAutor( peliculaAuxiliar, autorStr) ==0) &&
				(movie_setPrecio( peliculaAuxiliar, atoi(precioStr) ) ==0) &&
				(editorioalAID(&auxiliarIdEditorial, editorialIdStr) == 0 ) &&
				(movie_setEditorialId( peliculaAuxiliar,auxiliarIdEditorial) == 0)
				){

				}else{
					peliculaAuxiliar=NULL;

				}
	}
	return peliculaAuxiliar;
}

int movie_setId(Libro* this,int id){
	int retorno=-1;
		if(this != NULL && id > 0){
			this -> id = id;
			retorno = 0;
		}

	return retorno;
}

int movie_getId(Libro* this,int* id){
	int retorno=-1;
	if( this != NULL && id != NULL ){
		*id = this -> id;
		retorno = 0;
	}
	return retorno;
}


int movie_setTitulo(Libro* this,char* titulo){
	int retorno=-1;
	if( this != NULL && titulo != NULL){
		strcpy( this -> titulo , titulo );
		retorno = 0;
	}
	return retorno;
}

int movie_getTitulo(Libro* this, char* titulo){
	int retorno=-1;
	if( this != NULL && titulo != NULL){
		strcpy( titulo , this -> titulo );
		retorno = 0;
	}
	return retorno;
}


int movie_setAutor(Libro* this,char* autor){
	int retorno=-1;
		if( this != NULL && autor != NULL){
			strcpy( this -> autor , autor );
			retorno = 0;
		}
		return retorno;
}

int movie_getAutor(Libro* this, char* autor){
	int retorno=-1;
		if( this != NULL && autor != NULL){
			strcpy( autor , this -> autor );
			retorno = 0;
		}
		return retorno;
}


int movie_setPrecio(Libro* this,int precio){
	int retorno=-1;
	if( this != NULL &&  precio > -1){
		 this -> precio = precio ;
		retorno = 0;
	}
	return retorno;
}

int movie_getPrecio(Libro* this,int* precio){
	int retorno=-1;
	if( this != NULL &&  precio != NULL){
		*precio = this -> precio;
		retorno = 0;
	}
	return retorno;
}


int movie_setEditorialId(Libro* this,int editorialId){
	int retorno=-1;
	if( this != NULL &&  editorialId > -1){
		 this -> editorialId = editorialId ;
		retorno = 0;
	}
	return retorno;
}

int movie_getEditorialId(Libro* this,int* editorialId){
	int retorno=-1;
	if( this != NULL &&  editorialId != NULL){
		*editorialId = this -> editorialId;
		retorno = 0;
	}
	return retorno;
}


void movie_printfOne(Libro* this){

	char nombreDia[50];

	//obtenerDia((*(this)).precio, nombreDia);
	printf("\n  ****************  DATOS DE LA PELICULA  ***************** ");
	printf("\n Id venta %d.  Pelicula: %s,      dia: %s,      Horario: %s,         editorialId: $%d       ",
			(*(this)).id,
			(*(this)).titulo,
			nombreDia,
			(*(this)).autor,
			(*(this)).editorialId
			);

}




int movie_sortTitulo(void* thisA, void* thisB)
{
	int retorno=0;
	char auxiliarTituloA[20];
	char auxiliarTituloB[20];

		if(thisA!=NULL && thisB!=NULL)
		{
			if(     movie_getTitulo(thisA, auxiliarTituloA)==0 &&
					movie_getTitulo(thisB, auxiliarTituloB)==0)
			{
				if(strcmp (auxiliarTituloA , auxiliarTituloB) > 0)
				{
					retorno=1;
				}
				if(strcmp (auxiliarTituloA , auxiliarTituloB)  < 0)
				{
					retorno=-1;
				}
			}
		}
		return retorno;
}


int movie_sortAutor(void* thisA, void* thisB){
	int retorno=0;
	char auxiliarAutorA[130];
	char auxiliarAutorB[130];

		if(thisA!=NULL && thisB!=NULL){
			if(     movie_getAutor(thisA, auxiliarAutorA)==0 &&
					movie_getAutor(thisB, auxiliarAutorB)==0){
				if(strcmp (auxiliarAutorA , auxiliarAutorB) > 0 ){
					retorno=1;
				}
				if(strcmp (auxiliarAutorA , auxiliarAutorB) < 0 ){
					retorno=-1;
				}
			}
		}
		return retorno;
}

int movie_sortID(void* thisA, void* thisB){
	int retorno=0;
	int auxiliarIdA;
	int auxiliarIdB;

		if(thisA!=NULL && thisB!=NULL){
			if(     movie_getId(thisA, &auxiliarIdA)==0 &&
					movie_getId(thisB, &auxiliarIdB)==0){
				if(auxiliarIdA > auxiliarIdB){
					retorno=1;
				}
				if(auxiliarIdA < auxiliarIdB){
					retorno=-1;
				}
			}
		}
		return retorno;
}


int movie_sortPrecio(void* thisA, void* thisB){
	int retorno=0;
	int auxiliarPrecioA;
	int auxiliarPrecioB;

		if(thisA!=NULL && thisB!=NULL){
			if(     movie_getPrecio(thisA, &auxiliarPrecioA)==0 &&
					movie_getPrecio(thisB, &auxiliarPrecioB)==0){
				if(auxiliarPrecioA > auxiliarPrecioB){
					retorno=1;
				}
				if(auxiliarPrecioA < auxiliarPrecioB){
					retorno=-1;
				}
			}
		}
		return retorno;
}


int editorioalAID(int* id, char editorial[])
{

	int retorno = 1;
		if( stricmp(editorial,"PLANETA") == 0 )
		{
			*id = 1;
			retorno = 0;
		}
		if( stricmp(editorial,"SIGLO XXI EDITORES") == 0 )
			{
				*id = 2;
				retorno = 0;
			}
		if( stricmp(editorial,"PEARSON") == 0 )
			{
				*id = 3;
				retorno = 0;
			}
		if( stricmp(editorial,"MINOTAURO") == 0 )
			{
				*id = 4;
				retorno = 0;
			}
		if( stricmp(editorial,"SALAMANDRA") == 0 )
			{
				*id = 5;
				retorno = 0;
			}
		if( stricmp(editorial,"PENGUIN BOOKS") == 0 )
			{
				*id = 6;
				retorno = 0;
			}


	return retorno;
};




int idAEditorial(int numeroDeSector, char nombreDeDia[]){

	int retorno = 1;
	if(numeroDeSector > -1	&& numeroDeSector <7){

		switch (numeroDeSector) {
			case 0:
					strcpy(nombreDeDia,"Domingo");
				break;
			case 1:
					strcpy(nombreDeDia,"Lunes");
			break;
			case 2:
					strcpy(nombreDeDia,"Martes");
				break;
			case 3:
					strcpy(nombreDeDia,"Miércoles");
				break;
			case 4:
					strcpy(nombreDeDia,"Jueves");
				break;
			case 5:
					strcpy(nombreDeDia,"Viernes");
				break;
			case 6:
					strcpy(nombreDeDia,"Sábado");
				break;
		}
		retorno = 0;

	}
	return retorno;
};




void calcularMonto(void* this){

	int diaAuxiliar;
	int precioAuxiliar;

	int total;



	/*Desarrollar la función ll_map en la biblioteca linkedList, la cual recibirá la lista y una
función. La función ll_map ejecutará la función recibida como parámetro por cada ítem
de la lista, de este modo se realizarán descuentos a los precios según se detalla:
* Planeta: 20% (si el monto es mayor o igual a $300)
* SIGLO XXI EDITORES: 10% (si el monto es menor o igual a $200
	 * */
	if (this != NULL){
		//printf("entró a calcularMonto");
		movie_getEditorialId(this, &diaAuxiliar);
		movie_getPrecio(this, &precioAuxiliar);


		if( precioAuxiliar >= 300 )
		{// Planeta: 20% (si el monto es mayor o igual a $300)
			total = precioAuxiliar - ((precioAuxiliar * 20 )/100);
			movie_setPrecio( this, total );

		//	printf("precioAuxiliar >= 300");
		}
		if( precioAuxiliar <= 200 ){
  	  	  // SIGLO XXI EDITORES: 10% (si el monto es menor o igual a $200
			total = precioAuxiliar - ((precioAuxiliar * 10 )/100);
			movie_setPrecio( this, total );
			//printf("precioAuxiliar <= 200 ");
		}

		}

}
/*
 * l usuario ingresará el número de sala y se imprimirá por pantalla:
• Cantidad de entradas vendidas para la sala.
• Monto total facturado para la sala.
• Listado de películas que se proyectaron en dicha sala (sin repetir).
 * */

/*
int calcularEntradasSala1( void* this){
	int retorno = 0;
	int cantidadEntradasAuxiliar;
	int sala1;
	if (this != NULL){

		movie_getSala(this, sala1);
		if(sala1 == 1){
			movie_getCantidadEntradas(this, &cantidadEntradasAuxiliar);
		}

	}

	return cantidadEntradasAuxiliar;
}
*/

