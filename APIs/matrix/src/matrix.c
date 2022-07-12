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
				printf("\nC(%d,%d) = 0", i+1, 1);
				for (int k=0; k < A.ncols; k++){
						printf("+ %f*%f ", A.values[i*A.ncols+k], B.values[k*B.ncols]);
						res.values[i*res.ncols ] = res.values[i*res.ncols ] + A.values[i*A.ncols+k]*B.values[k*B.ncols];
					}
				for(int j=1; j < res.ncols; j++){
					printf("\nC(%d,%d) = 0", i+1, j+1);
					for (int k=0; k < A.ncols; k++){
						printf("+ %f*%f ", A.values[i*A.ncols+k], B.values[k*B.ncols+j]);
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
