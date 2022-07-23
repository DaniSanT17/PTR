/*
	Implementação da ADT Integral
	Autor: Daniel Santiago da Silva
*/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "integrate.h"

Integral *build_integrate(double lowerl, double upperl, FPoly f){
    Integral *int_func = malloc(sizeof(Integral));
    int_func->lowerl = lowerl;
    int_func->upperl = upperl;
    int_func->func = f;

    return int_func;
}

void integrate_set_upl(Integral *int_func, double upperl){
    int_func->upperl = upperl;
}

void integrate_set_lowl(Integral *int_func, double lowerl){
    int_func->lowerl = lowerl;
}
void integrate_set_fun(Integral *int_func, FPoly f){
    int_func->func = f;
}

double do_integration(Integral int_func, double step){
    if(int_func.func){
        double sum = int_func.func(int_func.lowerl);
        for(double i=int_func.lowerl+step;i<int_func.upperl-step;i+=step){
            sum = sum + 2*(int_func.func(i));
        }
        sum = sum + int_func.func(int_func.upperl);

        return (step/2)*sum;
    }
    return 0;
}




