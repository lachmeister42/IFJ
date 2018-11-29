#include "errorHandler.h"

void errorHandle(EError e){
	char msg[100];
	switch (e){
		case VARIABLE_NOT_ASSIGNED:
			sprintf(msg,"[Error]: Variable was not assigned\n!");
			break;
		case MALLOC_FAILED:
			sprintf(msg,"[Error]: Couldn't allocate enough memory\n!");
			break;
		case CHAR_NOT_EXPECTED:
			sprintf(msg,"[Error]: Char was not expected at this time \n");
			break;
		
		default:
			sprintf(msg,"[Error]: Undocumented error!\n");
			break;		
	}
	fprintf(stderr, msg);
	fflush(stderr);
	exit(3);
}