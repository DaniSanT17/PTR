/*
	main.c: Factorial
	author: Andre Cavalcante
	date: june, 2022
	license: CC BY-SA
*/

#include <stdlib.h>
#include <stdio.h>
#include <gmp.h>

void factorial(mpz_t fac, unsigned int n) {
	mpz_set_ui(fac, 1);
	while(n > 1) {
		mpz_mul_ui(fac, fac, n);
		n--;
	}
}

int main(int argc, char **argv) {
	mpz_t fac;
	unsigned int n=20;
	
	if(argc==2)
		n = atoi(argv[1]);
	
	mpz_init(fac);
	factorial(fac, n);
	gmp_printf("Factorial (%d) = %Zd\n", n, fac);
	mpz_clear(fac);
	
	return 0;
}
