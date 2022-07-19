/*
	main.c: Matrix test program
	author: Andre Cavalcante
	date: may, 2022
	license: CC BY-SA
*/

#include <stdio.h>
#include "dstring.h"


int main(int argc, char **argv) {
	char *st = calloc(1,sizeof(char));
	st[0]='o';
	st[1]='i';
	st[2]=' ';
	st[3]='s';
	st[4]='u';
	DString *s = dstring_create(st);
	printf("Tamanho da DString %d\n", s->size);
	return 0;
}
