#ifndef parser_c
#define parser_c

#include "parser.h"

/** Implementation of parser
**/

void initParser(FILE *file) {
    variableHeap = initList();
    pushToList(variableHeap, initializeTree());
    lastWord = initString();
    initScanner(file);
}

EKeyWord isKeyWord(string s) {
    char *w = asCharPtr(s);
    if (!strcmp(w, "def")) {
        return DEF;
    } else if (!strcmp(w, "do")) {
        return DO;
    } else if (!strcmp(w, "else")) {
        return ELSE;
    } else if (!strcmp(w, "end")) {
        return END;
    } else if (!strcmp(w, "if")) {
        return IF;
    } else if (!strcmp(w, "not")) {
        return NOT;
    } else if (!strcmp(w, "nil")) {
        return NIL;
    } else if (!strcmp(w, "then")) {
        return THEN;
    } else if (!strcmp(w, "while")) {
        return WHILE;
    } else {
        return NO_KEY;
    }
}

void parse() {
    int shouldBeenLast = 0;
    int setShouldBeenLast= 0;
    int run = 1;
    while (run) {
        printf("%c\n", readNextChar()->c);

        switch (getLastChar()->type) {
            case Q_MARK:
            case EX_POINT:
                setShouldBeenLast = 1;
            case NUMBER:
            case HIGH_LETTER:
            case UNDERSCORE:
                if (lastWord->length == 0) {
                    errorHandle(0);
                }
            case LOW_LETTER:
                if(shouldBeenLast){
                    errorHandle(0);
                }
                addCharToString(lastWord, getLastChar()->c);
                break;
            case EMPTY:
                if(lastWord->length != 0) {
                    switch (isKeyWord(lastWord)) {
                        case DEF:
                            fprintf(stdout, "def");
                            fflush(stdout);
                            run = 0;
                            break;
                        case DO:
                            break;
                        case ELSE:
                            break;
                        case END:
                            break;
                        case IF:
                            break;
                        case NOT:
                            break;
                        case NIL:
                            break;
                        case THEN:
                            break;
                        case WHILE:
                            break;
                        case NO_KEY:
                            break;
                    }
                    setShouldBeenLast = 0;
                    shouldBeenLast = 0;
                    emptyString(lastWord);
                }
            default:
                break;
        }
        shouldBeenLast = setShouldBeenLast;
    }
}
#endif