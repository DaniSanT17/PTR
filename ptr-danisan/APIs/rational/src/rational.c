/*
	rational.c: Rational ADT implementation
	author: Andre Cavalcante
	date: june, 2022
	license: CC BY-SA
*/

#include <stdio.h>
#include <stdlib.h>

#include "rational.h"

struct Rational Rational_init(int num, int den) {
	struct Rational r;
	r.num = num;
	r.den = den;
	return r;
}

struct Rational Rational_sum(const struct Rational r1, const struct Rational r2){
	struct Rational r;
	r.num = r1.num*r2.den + r2.num*r1.den;
	r.den = r1.den * r2.den;
	return r;
}


struct Rational Rational_sub(const struct Rational r1, const struct Rational r2){
	struct Rational r;
	r.num = r1.num*r2.den - r2.num*r1.den;
	r.den = r1.den * r2.den;
	return r;
}


void Rational_print(const struct Rational r, const char * const msg) {
	printf("%s=%d/%d\n", msg, r.num, r.den);
}
