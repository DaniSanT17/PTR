/* ADT Matrix */

#ifndef _INTEGRATE_H
#define _INTEGRATE_H

typedef double (*FPoly)(double);

typedef struct integral {
	double upperl;
	double lowerl;
    FPoly func;
} Integral;


Integral build_integrate(double lowerl, double upperl, FPoly f);
double do_integration(Integral int_func, double step);
#endif
