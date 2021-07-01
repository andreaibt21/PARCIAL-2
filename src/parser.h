/*
 * parser.h
 *
 *  Created on: Jun 7, 2021
 *      Author: andrea
 */

#ifndef PARSER_H_
#define PARSER_H_
int parser_LibroFromText(FILE* pointerFile , LinkedList* pointerArrayListLibro);
int parser_LibroFromBinary(FILE* pointerFile , LinkedList* pointerArrayListLibro);


#endif /* PARSER_H_ */
