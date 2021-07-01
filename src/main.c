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
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
    int respuesta = 0;
   // char* archivo ;

    //archivo = (char*)calloc(50,sizeof(char));



   LinkedList* listaPeliculas = ll_newLinkedList();
    do{
    	mostrarMenu(&respuesta);

        switch(respuesta) {
            case 1:
            /*	if( utn_getString(archivo,  "\n Ingrese el nombre del archivo a leer   (datos.csv) ",	"Error, intente de nuevo", 3) == 0 &&
            		controller_loadFromText(archivo,listaPeliculas)  != 0){

            		printf("Error, intente nuevamente");
            	}
            	printf("archivoooooo %s",archivo);
*/
            	controller_loadFromText("Datos.csv",listaPeliculas);
                break;
        	case 2:

        		controller_sortMovie(listaPeliculas);

				break;
        	case 3:

				controller_ListMovie(listaPeliculas);

				break;

        	case 4:

        		 if(ll_map(listaPeliculas,calcularMonto) == NULL && controller_saveAsText("mapeado.csv",listaPeliculas) == -1 ){

					printf( "\n Hubo un error, intente nuevamente");

        		 }

				break;

			case 5:
				ll_deleteLinkedList(listaPeliculas);
				printf("\n  ****************  USTED HA SALIDO  ***************** ");
				break;

		/*	case 2:

				if(	controller_loadFromBinary("MOCK_DATA.bin",listaPeliculas) != 0){
            		printf("Error, intente nuevamente");
            	}

				break;
			case 3:
				controller_addMovie(listaPeliculas);

				break;
			case 4:
				controller_editMovie(listaPeliculas);
				break;
			case 5:

				controller_removeMovie(listaPeliculas);
				break;
			case 6:

				controller_ListMovie(listaPeliculas);

				break;
			case 7:
				controller_sortMovie(listaPeliculas);
				break;
			case 8:
				controller_saveAsText(archivo,listaPeliculas);


				break;
			case 9:
				controller_saveAsBinary("MOCK_DATA.bin",listaPeliculas);

				break;
		*/

        }
    }while(respuesta != 10);
    return EXIT_SUCCESS;
}
