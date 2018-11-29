//
// Created by tlach on 11/28/2018.
//

#include "list.h"

listPtr initList(){
    listPtr l = (listPtr) myMalloc(sizeof(struct list));
    l->top = NULL;
    return l;
}

listPtr initListNoGarbage(){
    listPtr l = (listPtr) malloc(sizeof(struct list));
    l->top = NULL;
    return l;
}

void pushToList(listPtr l, void *ptr) {
    listItemPtr tmp = myMalloc(sizeof(struct listItem));
    tmp->next = l->top;
    tmp->data = ptr;
    l->top = tmp;
}

void pushToListNoGarbage(listPtr l, void *ptr) {
    listItemPtr tmp = malloc(sizeof(struct listItem));
    tmp->next = l->top;
    tmp->data = ptr;
    l->top = tmp;
}

listItemPtr getLast(listPtr l){
    listItemPtr it = l->top;
    if (l->top == NULL){
        return NULL;
    }
    while(it->next != NULL){
        it = it->next;
    }
    return it;
}

void addToList(listPtr l, void *ptr){
    listItemPtr tmp = myMalloc(sizeof(struct listItem));
    tmp->data = ptr;
    tmp->next = NULL;
    if (l->top == NULL){
        l->top = tmp;
    }else {
        listItemPtr it = getLast(l);
        it->next = tmp;
    }
}

void removeFromList(listPtr l, void * ptr){
    listItemPtr parent = l->top;
    if (parent->data == ptr){
        popFromList(l);
    }else {
        while (1){
            if (parent->next == NULL){
                break;
            }else if (parent->next->data == ptr) {
                listItemPtr tmp = parent->next;
                parent->next = parent->next->next;
                myFree(tmp);
            }
            parent = parent->next;
        }
    }
}

void* popFromList(listPtr l){
    listItemPtr top = l->top;
    l->top = l->top->next;
    void * res = top->data;
    myFree(top);
    return res;
}



