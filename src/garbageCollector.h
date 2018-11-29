//
// Created by tlach on 11/28/2018.
//

#ifndef IFJ_GARBAGECOLLECTOR_H
#define IFJ_GARBAGECOLLECTOR_H

#include <stdlib.h>
#include "list.h"

listPtr garbage;

void initGC();
void* myMalloc(size_t);
void myFree(void* ptr);
void deInitGC();


#endif //IFJ_GARBAGECOLLECTOR_H
