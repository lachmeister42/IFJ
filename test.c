#include "binaryTree.h"
#include <stdio.h>
#include <stdlib.h>
#include "scanner.h"
#include "parser.h"


int main(int argC,char ** argV){
	initScanner();
	while(1){
		parse(NEW_LINE);
	}
	deinitScanner();
}