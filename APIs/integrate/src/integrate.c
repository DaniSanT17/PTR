#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "integrate.h"

Integrate build_integrate(double lowerl, double upperl, double *f){
    Integrate int_func;
    int_func.lowerl = lowerl;
    int_func.upperl = upperl;
    int_func.fPoly = f;

    return int_func;
}

double do_integration(Integrate int_func, double step){
    double sum = int_func.fPoly(int_func.lowerl);
    for(double i=int_func.lowerl+step;i<int_func.upperl-step;i+=step){
        sum = sum + 2*(int_func.fPoly(i));
    }
    sum = sum + int_func.fPoly(int_func.upperl);

    return (step/2)*sum;
}




