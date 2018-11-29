#include "str.h"

string initString(){
    string s = myMalloc(sizeof(struct string));
    s->length = 0;
    s->charList = initList();
    return s;
}

void addCharToString(string s, char c){
    char* data = myMalloc(sizeof(char));
    *data = c;
    s->length++;
    addToList(s->charList, data);
}

char* asCharPtr(string s){
    if (s->length) {
        char *res = myMalloc(sizeof(char) * (s->length+1));
        int i = 0;
        listItemPtr l = s->charList->top;
        do {
            res[i++] = *((char*)l->data);
        } while ((l = l->next) != NULL);
        res[s->length] = '\0';
        return res;
    }else{
        return NULL;
    }
}

int cmpToChar(string s, char* c){
    return !(strcmp(asCharPtr(s), c));
}

void emptyString(string s){
    if(s->length){
        listItemPtr it = s->charList->top;
        listItemPtr next = it->next;
        while((it = next)!= NULL){
            next = it->next;
            myFree(it->data);
            myFree(it);
        };
        myFree(s->charList->top);
        s->charList->top = NULL;
    }
    s->charList->top = NULL;
    s->length = 0;
}

void disposeString(string s){
    emptyString(s);
    myFree(s);
}

