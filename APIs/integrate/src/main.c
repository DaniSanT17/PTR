/*
	main.c - Hello World Template
	author: Daniel  Santiago
	date: june, 14
	
*/

// Regra do trapézio composta T(s) = step ((f(a)+f(b))/2 + sum (f(i)))

#include <stdio.h>
#include <math.h>
#include "integrate.h"

double f_squared(double a){
	
	return 2*(a*a*a)-(a*a)+3*a+4;
}
 
int main() {

	Integral int_func = build_integrate(-5.0, 7.0, *f_squared);
	printf("limite inferior: %lf, limite superior: %lf, f(2) = %lf", int_func.lowerl, int_func.upperl, (*(int_func.func))(2));
	double res = do_integration(int_func, 0.0001);
	
	printf("Integral de x^2 de 0 a 2 é igual a %lf\n", res);

    return 0;
}