#ifndef parser_h
#define parser_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "str.h"
#include "errorHandler.h"
#include "scanner.h"
#include "symtable.h"

listPtr variableHeap;
string lastWord;

typedef enum {
	IN_IF,
	IN_WHILE,
	IN_FUNCTION,
    VARIABLE_ASSIGNEMENT,
	PRINT
} EParserState;


typedef struct tParserStateStack{
	struct tParserStateItem * top;
} * PSStackPtr;

typedef struct tParserStateItem{
	struct tParserStateItem * next;
	EParserState state;
} * PSStackItemPtr;

void initParser(FILE *file);
void deinitParser();


void parse();

#endif