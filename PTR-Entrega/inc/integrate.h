/* ADT INTEGRAL */

#ifndef _INTEGRATE_H
#define _INTEGRATE_H

typedef double (*FPoly)(double);

typedef struct integral {
	double upperl;
	double lowerl;
    FPoly func;
} Integral;


Integral *build_integrate(double lowerl, double upperl, FPoly f);
void integrate_set_upl(Integral *int_func, double upperl);
void integrate_set_lowl(Integral *int_func, double lowerl);
void integrate_set_fun(Integral *int_func, FPoly f);
double do_integration(Integral int_func, double step);
#endif
