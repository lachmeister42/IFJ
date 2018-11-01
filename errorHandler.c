#ifndef errorhandler_c
#define errorhandler_c
#include "errorHandler.h"

void errorHandle(EError e){
	char msg[100];
	switch (e){
		case MALLOC_FAILED:
			sprintf(msg,"[Error]: Couldn't allocate enough memory\n!");
			break;
		case CHAR_NOT_EXPECTED:
			sprintf(msg,"[Error]: Char was not expected at this time %c\n", lastChar->c);
			break;
		
		default:
			sprintf(msg,"[Error]: Undocumented error!\n");
			break;		
	}
	fprintf(stderr, msg);
	fflush(stderr);
	exit(3);
}
#endif