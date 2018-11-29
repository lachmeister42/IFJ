#ifndef errorhandler_h
	#define errorhandler_h
	#include<stdio.h>
	#include<stdlib.h>

//	#include "parser.h"
	typedef enum {
		MALLOC_FAILED,
		CHAR_NOT_EXPECTED,
		VARIABLE_NOT_ASSIGNED
	}EError;

	void errorHandle(EError);
#endif
