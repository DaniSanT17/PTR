/*
	main.c: Matrix test program
	author: Andre Cavalcante
	date: may, 2022
	license: CC BY-SA
*/

#include <stdio.h>
#include "dstring.h"


int main(int argc, char **argv) {
	char *st = malloc(5*sizeof(char));
	st[0]='o';
	st[1]='i';
	st[2]=' ';
	st[3]='s';
	st[4]='u';
	DString *s = dstring_create(st, 5);
	print_dstring(s);

	float *p;
	// obtém o tamanho de p em bytes
	int tam = sizeof(p);
	// exibe o resultado
	printf("O tamanho do ponteiro e: %c bytes", st[3]);
	
	printf("\n\n");
	
	return 0;
}
