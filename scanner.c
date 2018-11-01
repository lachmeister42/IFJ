#ifndef scanner_c
#define scanner_c

#include "scanner.h"

/** Implementation of scanner
**/

void initScanner(){
	lastChar = malloc(sizeof(struct tCharStruct));
	readNextChar();
}

void deinitScanner(){
	free(lastChar);
}

bool isAlphaNumeric(tCharStructPtr c){
	return c->type == LETTER || c->type == NUMBER;
}

tCharStructPtr readNextChar(){
	lastChar->c = (char)getc(stdin);
	if((lastChar->c >= 'A' && lastChar->c <= 'Z') || (lastChar->c >= 'a' && lastChar->c <= 'z')) {
		lastChar->type = LETTER;
	}else if(lastChar->c >= '0' && lastChar->c <= '9'){
		lastChar->type = NUMBER;
	}else if(lastChar->c >= '('){
		lastChar->type = LEFT_PARENTHESIS;
	}else if(lastChar->c >= ')'){
		lastChar->type = RIGHT_PARENTHESIS;	
	}else if(lastChar->c == '"'){
		lastChar->type = QUOTE;
	}else if(lastChar->c == '.'){
		lastChar->type = DOT;
	}else if(lastChar->c == '\\'){
		lastChar->type = BACKSLASH;
	}else if(lastChar->c == ' ' || lastChar->c == '\t' ){
		lastChar->type = EMPTY;
	}else if(lastChar->c == '\n'){
		lastChar->type = END_OF_LINE;
	}else{
		lastChar->type = UNKNOWN;
	}
	return getLastChar();
}
tCharStructPtr getLastChar(){
	return lastChar;
}

#endif