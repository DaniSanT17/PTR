/*
	main.c: Rational ADT test program
	author: Andre Cavalcante
	date: june, 2022
	license: CC BY-SA
*/

#include <stdio.h>

#include "rational.h"

int main(int argc, char **argv) {
	puts("Rational test");

	struct Rational r1 = Rational_init(2, 3);
	struct Rational r2 = Rational_init(5, 2);
	struct Rational r3 = Rational_sum(r1, r2);

	Rational_print(r1, "r1");
	puts("+");
	Rational_print(r2, "r2");
	puts("=");
	Rational_print(r3, "r3");

	Rational_print(Rational_sum(r3, Rational_sub(r2,r1)), "conta");

	puts("Bye");
	return 0;
}
