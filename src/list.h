//
// Created by tlach on 11/28/2018.
//

#ifndef IFJ_LIST_H
#define IFJ_LIST_H

#include <stdlib.h>
void* myMalloc(size_t);
void myFree(void*);


typedef struct listItem{
    void * data;
    struct listItem* next;
}* listItemPtr;

typedef struct list{
    listItemPtr top;
} * listPtr;

listPtr initList();
listPtr initListNoGarbage();
void pushToList(listPtr, void *);

void pushToListNoGarbage(listPtr l, void *ptr);

void addToList(listPtr, void *);

void removeFromList(listPtr, void *);

void* popFromList(listPtr);

#endif //IFJ_LIST_H
