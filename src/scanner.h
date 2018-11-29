#ifndef scanner_h
#define scanner_h

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include "garbageCollector.h"

FILE *input;


typedef enum {
    DEF,
    DO,
    ELSE,
    END,
    IF,
    NOT,
    NIL,
    THEN,
    WHILE,
    NO_KEY
} EKeyWord;

typedef enum {
    NUMBER, // '.[0-9]'
    LOW_LETTER, // '.[a-z]'
    HIGH_LETTER, // '.[A-Z]'
    LEFT_PARENTHESIS, // '('
    RIGHT_PARENTHESIS, // ')'
    QUOTE, //'"'
    DOT, //'.'
    BACKSLASH, // '\\'
    EMPTY, // ' ' || '\t' || '\n'
    END_OF_LINE, // '\n'
    END_OF_FILE, // 'EOF'
    UNDERSCORE, // '_'
    Q_MARK, //'?'
    EX_POINT, // '!'
    UNKNOWN
} ECharType;

typedef struct tCharStruct {
    ECharType type;
    char c;
} *tCharStructPtr;

tCharStructPtr lastChar;

int canBeTerm(tCharStructPtr c);

tCharStructPtr readNextChar();

tCharStructPtr getLastChar();

void initScanner(FILE *file);

void deinitScanner();

#endif