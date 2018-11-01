#ifndef scanner_h
#define scanner_h

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef enum {
	NUMBER,
	LETTER,
	LEFT_PARENTHESIS,
	RIGHT_PARENTHESIS,
	QUOTE,
	DOT,
	BACKSLASH,
	EMPTY,
	END_OF_LINE,
	END_OF_FILE,
	UNKNOWN
} ECharType;

typedef struct tCharStruct{
	ECharType type;
	char c;
} * tCharStructPtr;

tCharStructPtr lastChar;

tCharStructPtr readNextChar();
tCharStructPtr getLastChar();
void initScanner();
void deinitScanner();
#endif