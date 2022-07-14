/*
	Implementação da ADT Matrix
*/

#include <math.h>
#include <stdlib.h>

#include "matrix.h"

Matrix matrix_nul = {.nlins=0, .ncols=0, .values=NULL};

#define VALUES(m, i, j) (m.values[i * m.ncols + j])

double matrix_value(Matrix m, int i, int j) {
	return VALUES(m, i, j);
}

Matrix matrix_value_init(unsigned int nlins, unsigned int ncols, double value) {
	Matrix m = matrix_nul;
	m.values = malloc(nlins * ncols * sizeof(double));
	if(m.values) {
		m.nlins = nlins;
		m.ncols = ncols;
		for(int i=0; i<nlins; i++)
			for(int j=0; j<ncols; j++)
				VALUES(m, i, j) = value;
	}
	return m;
}

Matrix matrix_zeros(unsigned int nlins, unsigned int ncols) {
	return matrix_value_init(nlins, ncols, 0.0);
}

Matrix matrix_ones(unsigned int nlins, unsigned int ncols) {
	return matrix_value_init(nlins, ncols, 1.0);
}

Matrix matrix_identity(unsigned int nlins, unsigned int ncols) {
	Matrix m = matrix_nul;
	m.values = malloc(nlins * ncols * sizeof(double));
	if(m.values) {
		m.nlins = nlins;
		m.ncols = ncols;
		for(int i=0; i<nlins; i++)
			for(int j=0; j<ncols; j++)
				m.values[i*ncols + j] = (i == j) ? 1.0 : 0.0;
	}
	return m;
}

void matrix_free(Matrix *m) {
	if(m) {
		free(m->values);
		*m = matrix_nul;
	}
}

double matrix_getValue(Matrix m, int i, int j) {
	if(i >= m.nlins || j >= m.ncols)
		return NAN;
	return m.values[i*m.ncols + j];
}

unsigned int matrix_nlins(Matrix m) {
	return m.nlins;
}

unsigned int matrix_ncols(Matrix m) {
	return m.ncols;
}

Matrix matrix_copy(Matrix m) {
	Matrix res;
	res.nlins = m.nlins;
	res.ncols = m.ncols;
	m.values = calloc(res.nlins * res.ncols, sizeof(double));
	if(m.values) {
		for(int i=0; i < res.nlins; i++)
			for(int j=0; j < res.ncols; j++)
				VALUES(res, i, j) = VALUES(m, i, j);
		return m;
	}
	else
		return matrix_nul;
}

Matrix matrix_apply(double (*f)(double val), Matrix m) {
	Matrix res;
	res.nlins = m.nlins;
	res.ncols = m.ncols;
	m.values = calloc(res.nlins * res.ncols, sizeof(double));
	if(m.values) {
		for(int i=0; i < res.nlins; i++)
			for(int j=0; j < res.ncols; j++)
				res.values[i*res.ncols + j] = f(m.values[i*res.ncols + j]);
		return res;
	}
	else
		return matrix_nul;
}


Matrix matrix_sum(Matrix A, Matrix B){
	Matrix res;

	if(A.nlins == B.nlins && A.ncols == B.nlins){	
		res.nlins = A.nlins;
		res.ncols = A.ncols;
		res.values = calloc(res.nlins * res.ncols, sizeof(double));
		if (A.values && B.values){	
			for(int i = 0; i < matrix_nlins(A); i++) {
				res.values[i*res.ncols] = A.values[i*A.ncols ] + B.values[i*B.ncols ];
				for(int j = 1; j < matrix_ncols(B); j++) {
					res.values[i*res.ncols + j] = A.values[i*A.ncols + j] + B.values[i*B.ncols + j];
				}
			}}
		return res;
	}else{
		printf("ERROR: Matrix sizes cannot be diferents for sum operation.\n");
		return matrix_nul;

	}

	return res;
}

Matrix matrix_dif(Matrix A, Matrix B){
	Matrix res;

	if(A.nlins == B.nlins && A.ncols == B.nlins){	
		res.nlins = A.nlins;
		res.ncols = A.ncols;
		res.values = calloc(res.nlins * res.ncols, sizeof(double));
		if (A.values && B.values){
			for(int i = 0; i < matrix_nlins(A); i++) {
				res.values[i*res.ncols] = A.values[i*A.ncols ] - B.values[i*B.ncols ];
				for(int j = 1; j < matrix_ncols(B); j++) {
					res.values[i*res.ncols + j] = A.values[i*A.ncols + j] - B.values[i*B.ncols + j];
				}
		}}
		return res;
	}else{
		printf("ERROR: Matrix sizes cannot be diferents for sum operation.\n");
		return matrix_nul;
	}

	return res;
}

Matrix matrix_scalar_mul(double n, Matrix m){
	Matrix res;
	res.nlins = m.nlins;
	res.ncols = m.ncols;
	res.values = calloc(res.nlins * res.ncols, sizeof(double));
	if(m.values) {
		for(int i=0; i < res.nlins; i++)
			for(int j=0; j < res.ncols; j++)
				res.values[i*res.ncols + j] = n * m.values[i*res.ncols + j];
		return res;
	}
	else
		return matrix_nul;
}


Matrix matrix_mul(Matrix A, Matrix B){
	if(A.ncols == B.nlins){
		Matrix res = matrix_zeros(A.nlins, B.ncols);	

		if (A.values && B.values){
			for(int i=0; i < res.nlins; i++){
				for (int k=0; k < A.ncols; k++){
						res.values[i*res.ncols ] = res.values[i*res.ncols ] + A.values[i*A.ncols+k]*B.values[k*B.ncols];
					}
				for(int j=1; j < res.ncols; j++){
					for (int k=0; k < A.ncols; k++){
						res.values[i*res.ncols + j] = res.values[i*res.ncols + j] + A.values[i*A.ncols+k]*B.values[k*B.ncols + j];
					}
				}	
			}
			return res;
		}

	}else{
		printf("ERROR: Matrix A column number and Matrix B lines number cannot be diferents for multiplication operation.\n");
	}
	return matrix_nul;
	
};


int matrix_compare(Matrix A, Matrix B){
	if(A.ncols == B.ncols && A.nlins == B.nlins){
		for(int i = 0; i < matrix_nlins(A); i++) {
			if(matrix_value(A, i, 0) != matrix_value(B, i, 0)){
				return 0;
			}
		for(int j = 1; j < matrix_ncols(A); j++) {
			if(matrix_value(A, i, j) != matrix_value(B, i, j)){
				return 0;
			}
		}
	}
	}else{
		return 0;
	}

	return 1;
}

double matrix_det(Matrix m){

	if(m.values && m.nlins==m.ncols){
		Matrix aux = matrix_copy(m);
		double factor = 0;	
    	double temp = 0;	
    	int count = 0;	

		// faz a transformação em um triangulo...
		for(int i = 0; i < matrix_nlins(m); i++)
		{
			if(matrix_value(aux, i, 0) == 0)
			{
				for(int k = i; k < aux.nlins; k++)
				{
					if(matrix_value(aux, k, i) != 0)
					{
						for(int j = 0; j < aux.nlins; j++)
						{
							temp = matrix_value(aux, i, j);
							aux.values[i*aux.nlins + j] = matrix_value(aux, k, j);
							aux.values[k*aux.nlins + j] = temp;
						}
						k = aux.nlins;
					}
				}
				count++;
			}

			if(matrix_value(aux, i, i) != 0)
			{
				for(int k = i + 1; k < aux.nlins; k++)
				{
					factor = -1.0 * matrix_value(aux, k, i) /  matrix_value(aux, i, i);
					for(int j = i; j < aux.nlins; j++)
					{
						aux.values[k*aux.nlins + j] = aux.values[k*aux.nlins + j] + (factor * aux.values[i*aux.nlins + j]);
					}
				}
			}
		}

		temp = 1.0;
		// Calcula o determinante
		printf("\nTemp = 0 ");
		for(int i = 0; i < aux.nlins; i++)
		{
			temp *= matrix_value(aux, i, i);
		}

		if(count % 2 == 0)
			return temp;
		else
			return -1.0 * temp;

	}else{
		printf("ERROR: The input is not a Square Matrix or his value is NULL!!!");
	}
  
	
    
}