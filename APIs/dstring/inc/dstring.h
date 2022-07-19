/* ADT Matrix */

#ifndef _DSTRING_H
#define _DSTRING_H

typedef struct Matrix {
	unsigned int nlins;
	unsigned int ncols;
	double      *values;
} Matrix;

extern Matrix matrix_nul;

Matrix matrix_zeros(unsigned int nlins, unsigned int ncols);
Matrix matrix_ones(unsigned int nlins, unsigned int ncols);
Matrix matrix_identity(unsigned int nlins, unsigned int ncols);
Matrix matrix_copy(Matrix m);
Matrix matrix_apply(double (*f)(double val), Matrix m);

void matrix_free(Matrix *m);

double       matrix_value(Matrix m, int i, int j);
unsigned int matrix_nlins(Matrix m);
unsigned int matrix_ncols(Matrix m);



Matrix matrix_mul(Matrix A, Matrix B);

#endif
