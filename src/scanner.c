#ifndef scanner_c
#define scanner_c

#include "scanner.h"

/** Implementation of scanner
**/

void initScanner(FILE *file) {
    input = file;
    lastChar = myMalloc(sizeof(struct tCharStruct));
}

tCharStructPtr readNextChar() {
    lastChar->c = (char) getc(input);
    if (lastChar->c >= 'a' && lastChar->c <= 'z') {
        lastChar->type = LOW_LETTER;
    } else if (lastChar->c >= 'A' && lastChar->c <= 'Z') {
        lastChar->type = HIGH_LETTER;
    } else if (lastChar->c >= '0' && lastChar->c <= '9') {
        lastChar->type = NUMBER;
    } else if (lastChar->c >= '(') {
        lastChar->type = LEFT_PARENTHESIS;
    } else if (lastChar->c >= ')') {
        lastChar->type = RIGHT_PARENTHESIS;
    } else if (lastChar->c == '"') {
        lastChar->type = QUOTE;
    } else if (lastChar->c == '.') {
        lastChar->type = DOT;
    } else if (lastChar->c == '\\') {
        lastChar->type = BACKSLASH;
    } else if (lastChar->c == ' ' || lastChar->c == '\t') {
        lastChar->type = EMPTY;
    } else if (lastChar->c == '\n') {
        lastChar->type = END_OF_LINE;
    } else if (lastChar->c == EOF) {
        lastChar->type = END_OF_LINE;
    } else if (lastChar->c == '_') {
        lastChar->type = UNDERSCORE;
    } else {
        lastChar->type = UNKNOWN;
    }
    return getLastChar();
}

tCharStructPtr getLastChar() {
    return lastChar;
}

#endif