/* ADT Matrix */

#ifndef _INTEGRATE_H
#define _INTEGRATE_H


typedef struct integrate {
	double upperl;
	double lowerl;
    double (*fPoly)(double)
} Integrate;


Integrate build_integrate(double lowerl, double upperl, double *f);
double do_integration(Integrate int_func, double step);
#endif
