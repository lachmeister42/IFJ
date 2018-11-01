#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "errorHandler.h"


#define MAX_VARIABLE_LENGTH 100
typedef enum {
	INT,
	FLOAT,
	STRING,
	BOOL,
	NONE
}EVariableType;

typedef struct BTItem {
	struct BTItem * lptr;
	struct BTItem * hptr;
	int hashedValue;
	EVariableType type;
	char * value;
} * BTItemPtr;

typedef struct {
	BTItemPtr top;
} tBinTree;

typedef struct tStackItem{
	BTItemPtr value;
	struct tStackItem *next;
} * tStackItemPtr;

typedef struct {
	tStackItemPtr top;
} tBTStack;

tBinTree * initializeTree();
void addItem(tBinTree* ,char*);
void printTree(tBinTree *);
void disposeTree(tBinTree *);

tBTStack * initializeStack();
void printStack(tBTStack * t);
void pushBTStack(tBTStack * stack, BTItemPtr item);
BTItemPtr popBTStack(tBTStack * stack);