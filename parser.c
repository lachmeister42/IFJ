#ifndef parser_c
#define parser_c
#include "parser.h"
/** Implementation of scanner
**/

/**
*	Function which returns initialized stack of BTItemPtr
*   @return initialized empty stack

PSStackPtr initializeStateStack(){
	PSStackPtr stack = malloc(sizeof(struct tParserStateStack));
	stack->top = NULL;
	return stack;
}
/**
*	Prints stack values, without popping

void printStack(PSStackPtr t){
	printf("Stacktrace print\n");
	PSStackItemPtr p = t->top;
	while(p != NULL){
		printf("%s\n", stateToString(PSStackItemPtr->state));
		fflush(stdout);
		p = p->next;
	}
}

char * stateToString(EParserState state){
	switch(state){
		case NEW_LINE:
			return "\tOn new line";
		default:
			return "\tNOT Implementated";
	}
}
/**
*	Pushes BTItemPtr item to tBTStack stack
*	@param stack stack to push to 
*	@param item item to push 
*   @return initialized empty stack

void pushBTStack(PSStackPtr * stack, EParserState state){
	if (stack->top == NULL){
		stack->top = malloc(sizeof(struct tParserStateItem));
		stack->top->state = state;
		stack->top->next = NULL;
	}else{
		tStackItemPtr parrent = stack->top;
		while(parrent->next != NULL){
			parrent = parrent->next;
		}
		parrent->next = malloc(sizeof(struct tParserStateItem));
		parrent->next->state = state;
		parrent->next->next = NULL;
	}
}
**/
void getToNextLine(){
	while(readNextChar()->type != END_OF_LINE || readNextChar()->type != END_OF_FILE);
	readNextChar();
}

void parse(EParserState state){
	char * word = malloc(sizeof(char)*100);
	readNextAlphaNumeric(word);
	if (!strcmp(word, "print")) {
		instPrint();
	}else{
		varAss(word);
	}
	getToNextLine();
	if(getLastChar()->type == END_OF_FILE){
		exit(0);
	}
}

void varAss(char * varName){
	printf("NOT IMPLEMENTED");
}

void instPrint(){
	char * toPrint = malloc(sizeof(char)*100);
	readString(toPrint);
	printf("PRINT %s\n", toPrint);
	fflush(stdout);
	free(toPrint);
}

void readString(char * word){
	tCharStructPtr cStruct;
	while(getLastChar()->type == EMPTY){
		readNextChar();
	}
	if (getLastChar()->type != QUOTE){
		errorHandle(CHAR_NOT_EXPECTED);
	}
	readNextChar();
	while((cStruct = getLastChar())->type != QUOTE){
		switch(cStruct->type){
			case END_OF_LINE:
				errorHandle(CHAR_NOT_EXPECTED);
				break;
			case BACKSLASH:
				if (readNextChar()->type != END_OF_LINE) {
					errorHandle(CHAR_NOT_EXPECTED);
				}
				break;
			default:
				strcat(word, &(cStruct->c));
				readNextChar();
				break;
		}
	}
}

void readNextAlphaNumeric(char * word){
	while(getLastChar()->type != EMPTY){
		switch(getLastChar()->type){
			case LETTER:
			case NUMBER:
				strcat(word, &(getLastChar()->c));
				readNextChar();
				break;
			default:
				errorHandle(CHAR_NOT_EXPECTED);
				break;
		}
	}
}


#endif