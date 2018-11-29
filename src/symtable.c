#include "symtable.h"

Variable * initializeVariable(char **name){
    Variable * v = myMalloc(sizeof(Variable));
    v->type = UNINIT;
    v->isConstant = 0;
    v->name = *name;
    return v;
}

void disposeVariable(Variable*v){
	myFree(v->name);
    myFree(v);
}

BTItemPtr initializeTree(){
    BTItemPtr item = myMalloc(sizeof(struct BTItem));
    item->v = NULL;
    item->lptr = NULL;
    item->hptr = NULL;
    return item;
}

int getHashedValue(char * v){
	int result = 0;
	for(int i = 0;v[i] != '\0'; i++){
		result = (i+1)*v[i];
	}
	return result;
}

BTItemPtr findOrCreateVariableInFrame(BTItemPtr tree, char * name){
    int hash = getHashedValue(name);
    if (tree->v == NULL){
        tree->v = (Variable*) malloc(sizeof(Variable));
        tree->v->type = UNINIT;
        tree->v->name = name;
        tree->hashedValue = hash;
        return tree;
    }else{
        BTItemPtr item = malloc(sizeof(struct BTItem));
        if (item == NULL) {
            errorHandle(MALLOC_FAILED);
            return NULL;
        }
        BTItemPtr it = tree;
        while(1){
            if (hash < it->hashedValue){
                if (it->lptr == NULL){
                    it->lptr = malloc(sizeof(struct BTItem));
                    it->lptr->v = initializeVariable(&name);
                    it->lptr->lptr = NULL;
                    it->lptr->hptr = NULL;
                    it->lptr->hashedValue = hash;
                    return it->lptr;
                } else {
                    it = it->lptr;
                }
            } else {
                if ((hash == it->hashedValue) && !(strcmp(name, it->v->name))){
                    return it;
                } else if (it->hptr == NULL){
                    it->hptr = malloc(sizeof(struct BTItem));
                    it->hptr->v = initializeVariable(&name);
                    it->hptr->lptr = NULL;
                    it->hptr->hptr = NULL;
                    it->hptr->hashedValue = hash;
                    return it;
                } else {
                    it = it->hptr;
                }
            }
        }
    }
}

int findVariableInFrame(BTItemPtr tree, char * name, BTItemPtr* result){
    int hash = getHashedValue(name);
    *result = NULL;
    if (tree == NULL){
        return 0;
    }else{
        BTItemPtr it = tree;
        while(1){
            if (hash < it->hashedValue){
                if (it->lptr == NULL){
                    return 0;
                } else {
                    it = it->lptr;
                }
            } else {
                if ((hash == it->hashedValue) && !(strcmp(name, it->v->name))){
                    *result = it;
                    return 1;
                } else if (it->hptr == NULL){
                    return 0;
                } else {
                    it = it->hptr;
                }
            }
        }
    }
}

int getVariableFromStack(listPtr stack, char * name, Variable ** result){
    listItemPtr s = stack->top;
    *result = NULL;
    BTItemPtr b;
    do{
        if(findVariableInFrame(s->data, name, &b)){
            *result = b->v;
            return 1;
        }
    }while((s = s->next ) != NULL);
    return 0;
}

char* getVariableValue(Variable * v){
    char* res = myMalloc(sizeof(char)*MAX_STRING_LENGTH);
    switch(v->type){
        case FLOAT:
            strcat(res, "float@");
            sprintf(res, "%s%f",res, v->value.f);
            break;
        case INT:
            strcat(res, "int@");
            sprintf(res, "%s%i",res, v->value.i);
            break;
        case STRING:
            strcat(res, "string@");
            sprintf(res, "%s%s",res, v->value.c);
            break;
        case BOOL:
            strcat(res, "bool@");
            sprintf(res, "%s%s",res, v->value.i ? "TRUE" : "FALSE");
            break;
        case UNINIT:
            fprintf(stderr, "Trying to get value of uninit %s", v->name);
            break;
    }
    return res;
}
