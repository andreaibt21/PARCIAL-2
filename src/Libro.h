 /** Libro.h
 *
 *      Author: Andrea Briceño
 */

#ifndef libro_H_INCLUDED
#define libro_H_INCLUDED

typedef struct
{
	int id;
    char titulo[300];
    char autor[300];
    int precio;
    int editorialId;

} Libro;



/** \brief reserva un espacio de memoria de tipo empleado y lo retorna
 *
 * \param this LinkedList* Puntero a la lista
 * \return Retorna un empleado nuevo
 *
 */
Libro* movie_new();


/** \brief Crea un empleado nuevo y lo devuelve por retorno
 *
 * \param char* idStr id del empleado
 * \param char* nombreStr nombre del empleado
 * \param char* horasTrabajadasStr horas de trabajo del empleado
 * \param char* sueldoStr sueldo del empleado
 * \return Retorna un empleado nuevo
 */


Libro* libro_newParametros(char* idStr,char* tituloStr,char* autorStr,char* precioStr, char* editorialIdStr);


/** \brief Asigna un id al empleado pasado por parametro
 * \param Employee* this empleado
 * \param int id id del empleado
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 */
int movie_setId(Libro* this,int id);

/** \brief Asigna un id del empleado pasado por parametro a una variable por puntero
 * \param Employee* this empleado
 * \param int id id del empleado
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 */
int movie_getId(Libro* this,int* id);


/** \brief Asigna un nombre al empleado pasado por parametro
 * \param Employee* this empleado
 * \param char* nombre nombre del empleado
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 */
int movie_setTitulo(Libro* this,char* titulo);

/** \brief Asigna un nombre del empleado pasado por parametro a una variable por puntero
 * \param Employee* this empleado
 * \param char* nombre nombre del empleado
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 */
int movie_getTitulo(Libro* this,char* titulo);


/** \brief Asigna  horas de trabajo al empleado pasado por parametro
 * \param Employee* this empleado
 * \param int horasTrabajadas horas de trabajo del empleado
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 */
int movie_setAutor(Libro* this,char* autor);

/** \brief Asigna horas de trabajo del empleado pasado por parametro a una variable por puntero
 * \param Employee* this empleado
 * \param int horasTrabajadas horas de trabajo del empleado
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 */
int movie_getAutor(Libro* this, char* autor);


/** \brief Asigna un nombre al empleado pasado por parametro
 * \param Employee* this empleado
 * \param int sueldo sueldo del empleado
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 */
int movie_setEditorialId(Libro* this,int editorialId);
/** \brief Asigna un id del empleado pasado por parametro a una variable por puntero
 * \param Employee* this empleado
 * \param int sueldo sueldo del empleado
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 */
int movie_getEditorialId(Libro* this,int* editorialId);

int movie_setPrecio(Libro* this,int precio);
int movie_getPrecio(Libro* this,int* precio);


/** \brief Imprime por consola un empleado
 * \param Employee* this empleado
 * \return void
 */
void movie_printfOne(Libro* this);

/** \brief Evalua cual de los dos parametros es mayor o menor
 * \param void* thisA horas de trabajo de un empleado
 * \param void* thisB horas de trabajo de un empleado
 * \return Retorna 1 si thisA es mayor, -1 si thisB es mayor
 */
int movie_sortTitulo(void* thisA, void* thisB);

/** \brief Evalua cual de los dos parametros es mayor o menor
 * \param void* thisA nombre  de un empleado
 * \param void* thisB nombre de un empleado
 * \return Retorna 1 si thisA es mayor, -1 si thisB es mayor
 */
int movie_sortAutor(void* thisA, void* thisB);

/** \brief Evalua cual de los dos parametros es mayor o menor
 * \param void* thisA id de un empleado
 * \param void* thisB id de un empleado
 * \return Retorna 1 si thisA es mayor, -1 si thisB es mayor
 */
int movie_sortID(void* thisA, void* thisB);

/** \brief Evalua cual de los dos parametros es mayor o menor
 * \param void* thisA sueldo de un empleado
 * \param void* thisB sueldo de un empleado
 * \return Retorna 1 si thisA es mayor, -1 si thisB es mayor
 */
int movie_sortPrecio(void* thisA, void* thisB);

int editorioalAID(int* id, char editorial[]);
int idAEditorial(int numeroDeSector, char nombreDeDia[]);

int obtenerDia(int numeroDeSector, char nombreDeDia[]);
void calcularMonto(void* this);
//int calcularEntradasSala1( void* this);

#endif // libro_H_INCLUDED
