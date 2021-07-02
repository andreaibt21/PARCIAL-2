 /** main.c
 *		TP3 - 1°E
 *      Author: Andrea Briceño
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Libro.h"
#include "parser.h"
#include "utn.h"


int main()
{
	setbuf(stdout, NULL);
    int respuesta = 0;

   LinkedList* listaLibros = ll_newLinkedList();
    do{
    	mostrarMenu(&respuesta);

        switch(respuesta) {
            case 1:
            	if( controller_loadFromText("Datos.csv",listaLibros)  != 0){
            		printf("Error, intente nuevamente");
            	}
                break;
        	case 2:
        		controller_sortLibro(listaLibros);
				break;
        	case 3:
				controller_ListLibro(listaLibros);
				break;

        	case 4:
        		 if(ll_map(listaLibros,generarDescuentos) == NULL && controller_saveAsText("mapeado.csv",listaLibros) == -1 ){
					printf( "\n Hubo un error, intente nuevamente");
        		 }else{
        			 printf( "\n ********* DESCUENTOS GENERADOS  *********");
        		 }

				break;

			case 5:
				controller_saveAsText("mapeado.csv",listaLibros);
				break;

			case 6:
				controller_addLibro(listaLibros);

				break;
			case 7:
				controller_editLibro(listaLibros);
				break;
			case 8:

				controller_removeLibro(listaLibros);
				break;

			case 9:
				if(	controller_loadFromBinary("Datos.bin",listaLibros) != 0){
					printf("Error, intente nuevamente");
				}
				break;
			case 10:

				controller_saveAsBinary("Datos.bin",listaLibros);

				break;

			case 11:
				controller_Contador(listaLibros);

						break;
			case 12:
				controller_filtro(listaLibros);

						break;
			case 13:
				ll_deleteLinkedList(listaLibros);
				printf("		************ USTED HA SALIDO ************");

				break;


        }
    }while(respuesta != 13);
    return EXIT_SUCCESS;
}

/**
	char archivo[20];

  case 2:
				if( utn_getString(archivo,  "\n Ingrese el nombre del archivo a leer   (datos.csv) ",	"Error, intente de nuevo", 3) == 0 &&
					controller_loadFromText(archivo,listaLibros)  != 0){

					printf("Error, intente nuevamente");
				}
				printf("archivoooooo %s",archivo);

				if(	controller_loadFromBinary("MOCK_DATA.bin",listaLibros) != 0){
					printf("Error, intente nuevamente");
				}

				break;	*/
