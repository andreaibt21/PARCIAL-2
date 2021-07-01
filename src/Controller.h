 /** controller.h
 *
 *      Author: Andrea Briceño
 */

/** \brief Alta de empleados
 *
 * \param pointerArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addMovie(LinkedList* pointerArrayListMovies);

/** \brief Modificar datos de empleado
 *
 * \param pointerArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editMovie(LinkedList* pointerArrayListMovies);
/** \brief Baja de empleado
 *
 * \param pointerArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_removeMovie(LinkedList* pointerArrayListMovies);

/** \brief Listar empleados
 *
 * \param pointerArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListMovie(LinkedList* pointerArrayListMovies);
/** \brief Ordenar empleados
 *
 * \param pointerArrayListEmployee LinkedList*
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 *
 */
int controller_sortMovie(LinkedList* pointerArrayListMovies);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* el archivo
 * \param pointerArrayListEmployee LinkedList*
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 */
int controller_saveAsText(char* path , LinkedList* pointerArrayListMovies);
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char* el archivo
 * \param pointerArrayListEmployee LinkedList*
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pointerArrayListMovies);

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* el archivo
 * \param pointerArrayListEmployee LinkedList*
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 *
 */
int controller_loadFromText(char* path , LinkedList* pointerArrayListMovies);

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* el archivo
 * \param pointerArrayListEmployee LinkedList*
 * \return Retorna 0 si fue un exito, -1 si hubo un error
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pointerArrayListMovies);





