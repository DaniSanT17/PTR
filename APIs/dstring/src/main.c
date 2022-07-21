
#include <stdlib.h>
#include <stdio.h>
#include "dstring.h"


int main(int argc, char **argv) {
	printf("###### Teste ADT DString #######\n");

	printf("\n####### Teste dstring_create ##########\n"); 
	printf("Criando dstrings com *char\n");
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
	printf("Dstring S1 = ") ;print_buffer(s);
	printf("Dstring S2 = "); print_buffer(s2);
	printf("Dstring S3 = "); print_buffer(s3);

	printf("\n####### Teste dstring_from_char ##########\n"); 
	DString *s4 = dstring_from_char('a');
	print_buffer(s4);
	DString *s5 = dstring_from_char('b');
	print_buffer(s5);
	DString *s6 = dstring_from_char('c');
	print_buffer(s6);
	printf("\nTamanhos da 4, 5 e 6 DStrings: %d, %d, %d\n",dstring_size(s4), dstring_size(s5), dstring_size(s6));

	printf("\n####### Teste dstring_from_int ##########\n"); 
	DString *s7 = dstring_from_int(2);
	printf("Alocando memória para dstring de tamanho: %d\n", s7->size);
	DString *s8 = dstring_from_int(3);
	printf("Alocando memória para dstring de tamanho: %d\n", s8->size);

	printf("\n####### Teste dstring_from_double ##########\n"); 
	double d = 4.232145125;
	DString *s9 = dstring_from_double(d);
	printf("Alocando memória para dstring de tamanho: %d\n", s9->size);

	printf("\n####### Teste dstring_from_float ##########\n"); 
	float e = 5.232145125;
	DString *s10 = dstring_from_float(e);
	printf("Alocando memória para dstring de tamanho: %d\n", s10->size);

	printf("\n####### Teste dstring_from_long ##########\n"); 
	long f = 12124124;
	DString *s11 = dstring_from_long(f);
	printf("Alocando memória para dstring de tamanho: %d\n", s11->size);

	printf("\n####### Teste dstring_from_dstring ##########\n"); 
	DString *s12 = dstring_from_dstring(s);
	printf("S1 = "); print_buffer(s);
	printf("DString criada S12 = "); print_buffer(s12);

	printf("\n####### Teste dstring_concat ##########\n");
	printf("Concatenando DStrings S1, S2 e S3:\n"); 
	DString *s13 = dstring_concat(s,s2);
	printf("S1 + S2 = "); print_buffer(s13);
	DString *s14 = dstring_concat(s13,s3);
	printf("S1 + S2 + S3 = ");print_buffer(s14);

	printf("\n####### Teste dstring_size ##########\n"); 
	printf("\nTamanhos das 3 primeiras DStrings: %d, %d, %d\n",dstring_size(s), dstring_size(s2), dstring_size(s3));

	printf("\n####### Teste dstring_add_buffer ##########\n"); 
	printf("Adicionando buffer nas strings com memórias alocadas anteriormente:\n");
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

	printf("\n######## Teste Define BUFFER ########\n");
	char *buff = BUFFER(s);
	printf("Imprimindo buffer coletado da string S1: \n");
	for(int i =0;i<s->size;i++){
		printf("%c", buff[i]);
	}


	printf("\n\n####### Teste free_dstring ##########\n"); 


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
	


	return 0;
}
