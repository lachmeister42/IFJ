#ifndef binarytree_h
#define binarytree_h

#include "binaryTree.h"
/** Implementation of binaryTree
**/

tBinTree * initializeTree(){
	tBinTree * tree = malloc(sizeof(tBinTree));
	if (tree == NULL) {
		errorHandle(MALLOC_FAILED);
	}
	tree->top = NULL;
	return tree;
}

void disposeTree(tBinTree * tree){
	if (tree->top != NULL) {
		tBTStack * toDelete = initializeStack();
		BTItemPtr item;
		pushBTStack(toDelete, tree->top);
		while((item = popBTStack(toDelete)) != NULL){
			if (item->lptr != NULL){
				pushBTStack(toDelete, item->lptr);
			}
			if (item->hptr != NULL){
				pushBTStack(toDelete, item->hptr);
			}
			free(item->value);
			free(item);
		}
		free(toDelete);
	}
	free(tree);
}

int getHashedValue(char * val){
	int result = 0;
	for(int i = 0; val[i] != '\0'; i++){
		result = (i+1)*val[i];
	}
	return result;
}
/**
*	Adds item to tree
*   @param tree
*   @param value 
**/
void addItem(tBinTree * tree, char * value){
	BTItemPtr newItem = malloc(sizeof(struct BTItem));
	if (newItem == NULL) {
		errorHandle(MALLOC_FAILED);
	}
	newItem->hashedValue = getHashedValue(value);
	newItem->value = malloc(sizeof(char)* 50);
	if (newItem->value == NULL) {
		errorHandle(MALLOC_FAILED);
	}
	strcpy(newItem->value, value);
	newItem->lptr = NULL;
	newItem->hptr = NULL;
	newItem->type = NONE;
	if (tree->top == NULL) {
		tree->top = newItem;
	} else {
		BTItemPtr item = tree->top;
		while(1){
			if (newItem->hashedValue < item->hashedValue){
				if (item->lptr == NULL){
					item->lptr = newItem;
					break;
				} else {
					item = item->lptr;
				}				 
			} else {
				if (item->hptr == NULL){
					item->hptr = newItem;
					break;
				} else {
					item = item->hptr;
				}			
			}
		}
	}
}

BTItemPtr getItemNode(tBinTree * tree, char * value){
	int hashedValue = getHashedValue(value);
	BTItemPtr item = tree->top;
	do{
		if (item == NULL) {
			errorHandle(MALLOC_FAILED);
		}else{
			if (item->hashedValue == hashedValue){
				if (strcmp(item->value, value)) {
					break;
				}else{
					item = item->hptr;
				}
			}else if (item->hashedValue < hashedValue){
				item = item->hptr;
			}else if (item->hashedValue > hashedValue){
				item = item->lptr;
			}
		}
	}while(1);
	return item;
}
/**
*	Prints content of given node
*   @param node BTItemPtr of node to print
*   @param row row number of the node in the tree
**/
void printNode(BTItemPtr node, int row){
 	printf("row %i\t\t%s\n",row, node->value);
	printf("->L%s\t\t\t\t->H%s\n",node->lptr ==NULL ? "----": node->lptr->value, node->hptr ==NULL ? "----": node->hptr->value);
	fflush(stdout);
}
/**
*	Prints content of given tree
*   @param tbt tBinTree ptr to tree to be printed 
**/
void printTree(tBinTree * tbt){
	tBTStack * stack;
	tBTStack * nextStack = initializeStack();
	
	int nextRowPop = 1;
	int row = 0;
	BTItemPtr stackItem;
	pushBTStack(nextStack, tbt->top);
	while(nextRowPop){
		stack = nextStack;
		nextStack = initializeStack();
		nextRowPop = 0;
		while((stackItem = popBTStack(stack)) != NULL){
			if (stackItem->lptr != NULL){
				pushBTStack(nextStack, stackItem->lptr);
				nextRowPop = 1;
			}
			if (stackItem->hptr != NULL){
				pushBTStack(nextStack, stackItem->hptr);
				nextRowPop = 1;
			}
			printNode(stackItem, row);
		}
		row++;
		free(stack);
	}
	free(nextStack);
}
/**
*	Function which returns initialized stack of BTItemPtr
*   @return initialized empty stack
**/
tBTStack * initializeStack(){
	tBTStack * stack = malloc(sizeof(tBTStack));
	stack->top = NULL;
	return stack;
}
/**
*	Prints stack values, without popping
**/
void printStack(tBTStack * t){
	printf("Stack print\n");
	tStackItemPtr p = t->top;
	while(p != NULL){
		printf("%s\n",p->value->value);
		fflush(stdout);
		p = p->next;
	}
}
/**
*	Pushes BTItemPtr item to tBTStack stack
*	@param stack stack to push to 
*	@param item item to push 
*   @return initialized empty stack
**/
void pushBTStack(tBTStack * stack, BTItemPtr item){
	if (stack->top == NULL){
		stack->top = malloc(sizeof(struct tStackItem));
		stack->top->value = item;
		stack->top->next = NULL;
	}else{
		tStackItemPtr parrent = stack->top;
		while(parrent->next != NULL){
			parrent = parrent->next;
		}
		parrent->next = malloc(sizeof(struct tStackItem));
		parrent->next->value = item;
		parrent->next->next = NULL;
	}
}
/**
*	Pops BTItemPtr from tBTStack stack
*	@param stack stack to pop from
*   @return BTItemPtr of popped item
**/
BTItemPtr popBTStack(tBTStack * stack){
	if (stack->top == NULL) {
		return NULL;
	}
	tStackItemPtr oldTop = stack->top;
	stack->top = stack->top->next;
	BTItemPtr res = oldTop->value;
	free(oldTop);
	return res;
}


#endif