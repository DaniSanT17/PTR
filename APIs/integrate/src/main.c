

// Regra do trapézio composta T(s) = step ((f(a)+f(b))/2 + sum (f(i)))

#include <stdio.h>
#include <math.h>
#include "integrate.h"

double polynomial(double a){
	
	return 2*(a*a*a)-(a*a)+3*a+4;
}

double xpower3(double a){

	return a*a*a;
}
 
int main() {

	printf("###### Teste ADT Integral #######\n");

	printf("Polinomio F(x) = 2x^3 - x^2 + 3x + 4\n");
	Integral int_func = build_integrate(-5.0, 7.0, *polynomial);
	printf("Limite inferior: %lf, Limite superior: %lf, F(2) = %lf\n", int_func.lowerl, int_func.upperl, (*(int_func.func))(2));
	double res = do_integration(int_func, 0.0001);
	
	printf("Integral de 2x^3 - x^2 + 3x + 4 de -5 a 7 é igual a %lf\n\n", res);


	printf("Polinomio F(X) = x^3\n");
	Integral int_func2 = build_integrate(0.0, 15.0, *xpower3);
	printf("Limite inferior: %lf, Limite superior: %lf, F(2) = %lf\n", int_func2.lowerl, int_func2.upperl, (*(int_func2.func))(2));
	res = do_integration(int_func2, 0.0001);
	
	printf("Integral de x^3 de 0 a 15 é igual a %lf\n", res);

    return 0;
}