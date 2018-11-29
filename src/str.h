//
// Created by tlach on 11/28/2018.
//

#ifndef IFJ_STRING_H
#define IFJ_STRING_H
#include "list.h"
#include <string.h>


typedef struct string{
    listPtr charList;
    int length;
}*string;
string initString();
void stringConcat(string,string);
void addCharToString(string, char);
char* asCharPtr(string);
int cmpToChar(string, char*);
void emptyString(string);
void disposeString(string);

#endif //IFJ_STRING_H
