#ifndef  objectsStructs_h
#define objectsStructs_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "errorHandler.h"
#include "list.h"


#define MAX_VARIABLE_LENGTH 100
#define MAX_STRING_LENGTH 200
typedef enum {
	INT,
	FLOAT,
	STRING,
	BOOL,
	UNINIT
}EVariableType;



typedef enum {
    PLUS,
    MINUS,
    MULTIPL,
    DIVIDE
}EOperatorType;

typedef union {
	int i;
	char* c;
	double f;
}VarValue;

typedef struct {
	char* name;
	EVariableType type;
	VarValue value;
	int isConstant;
} Variable;

Variable * initializeVariable(char **);
void disposeVariable(Variable*v);
char* getVariableValue(Variable * v);

typedef struct BTItem {
	struct BTItem * lptr;
	struct BTItem * hptr;
	int hashedValue;
	Variable *v;
} * BTItemPtr;

BTItemPtr initializeTree();
void disposeTree(BTItemPtr);

BTItemPtr findOrCreateVariableInFrame(BTItemPtr, char *);
int findVariableInFrame(BTItemPtr, char *, BTItemPtr*);
int getVariableFromStack(listPtr, char *, Variable **);

#endif