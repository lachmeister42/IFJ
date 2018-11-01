#ifndef parser_h
#define parser_h

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include "errorHandler.h"
#include "scanner.h"
typedef enum {
	NEW_LINE,
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


void parse(EParserState);
void readNextAlphaNumeric(char*);
void instPrint();
void varAss(char *);
void readString(char *);
#endif