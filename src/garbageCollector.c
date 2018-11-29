//
// Created by tlach on 11/28/2018.
//

#include "garbageCollector.h"

void initGC(){
    garbage = initListNoGarbage();
}

void* myMalloc(size_t size){
    void* ptr = malloc(size);
    pushToListNoGarbage(garbage, ptr);
    return ptr;
}

void myFree(void* ptr){
    free(ptr);
    removeFromList(garbage, ptr);
}

void deInitGC(){
    while(garbage->top->next != NULL){
        free(popFromList(garbage));
    }
    free(garbage->top->data);
    free(garbage->top);
    free(garbage);
    garbage = NULL;
}
