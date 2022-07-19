/*
	Implementação da ADT Matrix
*/

#include <math.h>
#include <stdlib.h>

#include "dstring.h"

DString *dstring_create(char *string){
	DString *dstr = malloc(sizeof(DString));
	dstr->strBuff = malloc(sizeof(string));
	dstr->strBuff = string;
	dstr->size = sizeof(string)/sizeof(char);

	return dstr;
};

