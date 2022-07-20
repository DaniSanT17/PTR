/*
	main.c: Matrix test program
	author: Andre Cavalcante
	date: may, 2022
	license: CC BY-SA
*/
#include <stdlib.h>
#include <stdio.h>
#include "dstring.h"


int main(int argc, char **argv) {
	// Teste dstring_create(char *string, int size); // Done +-
	char *st = malloc(10*sizeof(char));
	for(int i=0;i<10;i++){
		st[i]= 65+i;
	}
	char *st2 = malloc(10*sizeof(char));
	for(int i=0;i<10;i++){
		st2[i]= 75+i;
	}
	char *st3 = malloc(6*sizeof(char));
	for(int i=0;i<6;i++){
		st3[i]= 85+i;
	}
	DString *s = dstring_create(st, 10);
	DString *s2 = dstring_create(st2, 10);
	DString *s3 = dstring_create(st3, 6);

	// Teste dstring_from_char(char string); // Done +-
	DString *s4 = dstring_from_char('a');
	print_buffer(s4);
	DString *s5 = dstring_from_char('b');
	print_buffer(s5);
	DString *s6 = dstring_from_char('c');
	print_buffer(s6);
	printf("\nTamanhos da 4, 5 e 6 DStrings: %d, %d, %d\n",dstring_size(s4), dstring_size(s5), dstring_size(s6));
	// Teste dstring_from_int(int size); // Done +-
	DString *s7 = dstring_from_int(2);
	DString *s8 = dstring_from_int(3);
	// Teste dstring_from_double(double size); // Done +-
	double d = 4.232145125;
	DString *s9 = dstring_from_double(d);
	// Teste dstring_from_float(float size); // Done +-
	float e = 5.232145125;
	DString *s10 = dstring_from_float(e);
	// Teste dstring_from_long(int long size); // Done +-
	long f = 12124124;
	DString *s11 = dstring_from_long(f);
	print_buffer(s11);
	printf("\nTamanhos da demais DStrings: %d, %d, %d, %d, %d\n\n",dstring_size(s7), dstring_size(s8), dstring_size(s9), dstring_size(s10), dstring_size(s11));
	// Teste dstring_from_dstring(DString *string); // Done +-
	DString *s12 = dstring_from_dstring(s);
	// Teste dstring_concat(DString *string1, DString *string2); // Done +-
	DString *s13 = dstring_concat(s,s2);
	print_buffer(s13);
	DString *s14 = dstring_concat(s13,s3);
	print_buffer(s14);
	// Teste dstring_size(DString *string); // Done +-
	printf("\nTamanhos das 3 primeiras DStrings: %d, %d, %d\n",dstring_size(s), dstring_size(s2), dstring_size(s3));
	// Teste dstring_add_buffer(DString *str, char *string);
	char *p = calloc(20, sizeof(char));
	for(int i=0;i<20;i++){
		p[i] = 97+i;
	}
	dstring_add_buffer(s7, p);
	printf("\nInt 3: "); print_buffer(s7);
	dstring_add_buffer(s8, p);
	printf("Int 3: "); print_buffer(s8);
	dstring_add_buffer(s9, p);
	printf("Double 4.232145125: "); print_buffer(s9);
	dstring_add_buffer(s10, p);
	printf("Float 5.232145125: "); print_buffer(s10);
	dstring_add_buffer(s11, p);
	printf("Long 12124124: "); print_buffer(s11);
	// Teste free_dstring(DString *str); //Done +-

	
	
	

	free_dstring(s);
	free_dstring(s2);
	free_dstring(s3);
	free_dstring(s4);
	free_dstring(s5);
	free_dstring(s6);
	free_dstring(s7);
	free_dstring(s8);
	free_dstring(s9);
	free_dstring(s10);
	free_dstring(s12);
	free_dstring(s13);
	free_dstring(s14);
	print_buffer(s);
	
	printf("\n\n");
	// char *p = malloc(sizeof(char));
	// if(p){
	// 	printf("Sim!");
	// }else{
	// 	printf("Não!");

	// }
	return 0;
}
