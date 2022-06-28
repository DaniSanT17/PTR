/*
	rational.h: Rational ADT declarations
	author: Andre Cavalcante
	date: june, 2022
	license: CC BY-SA
*/

#ifndef __RATIONAL_H
#define __RATIONAL_H

struct Rational {
	int num;
	int den;
};

struct Rational Rational_init(int num, int den);
struct Rational Rational_sum(const struct Rational r1, const struct Rational r2);
struct Rational Rational_sub(const struct Rational r1, const struct Rational r2);

void Rational_print(const struct Rational r, const char * const msg);

#endif
