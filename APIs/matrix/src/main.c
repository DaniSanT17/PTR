/*
	main.c: Matrix test program
	author: Andre Cavalcante
	date: may, 2022
	license: CC BY-SA
*/

#include <stdio.h>
#include "matrix.h"

float power_2(float a){
	return a*a;
}
float power_3(float a){
	return a*a*a;
}
int main(int argc, char **argv) {
	// double m1Values[9] = {2, -2, -1, 3, -4, 1, 1, 1, 5};
	// double m2Values[16] =  {1, 0, 2, 0, 2, 1, 1, 1, 2, 3, 0, 1, -1, 1, 2, 2};
	// double m3Values[25] =  {1, 2, 3, -3, 1, 0, 4, 0, 0, 0, 0, 1, 0, 1, 1, 0, -6, 6, 1, 3, 0, 2, 0, -1, 1};
	// Teste  matrix_zeros(unsigned int nlins, unsigned int ncols);
	Matrix m = matrix_zeros(5, 5);
	print_matrix("Zeros", m);
	
	// Matrix matrix_ones(unsigned int nlins, unsigned int ncols);
	Matrix m2 = matrix_ones(5, 5);
	print_matrix("1s", m2);

	// Matrix matrix_identity(unsigned int nlins, unsigned int ncols);
	Matrix m3 = matrix_identity(5, 5);
	print_matrix("Id", m3);
	
	// Matrix matrix_copy(Matrix m);
	// void matrix_free(Matrix *m);
	matrix_free(&m);
	m = matrix_copy(m3);
	print_matrix("New Id", m);
	
	// Matrix matrix_apply(double (*f)(double val), Matrix m);
	Matrix m4 = matrix_create();
	matrix_apply(*power_2,m4);
	print_matrix("Power2 ", m4);
	Matrix m5 = matrix_create();
	matrix_apply(*power_2,m5);
	print_matrix("Power3 ", m5);

	// double       matrix_value(Matrix m, int i, int j);
	printf("Primeiros de cada 1 %lf %lf %lf %lf %lf\n",matrix_value(m, 0,0), matrix_value(m2, 0,0),matrix_value(m3, 0,0),matrix_value(m4, 0,0),matrix_value(m5, 0,0));

	// unsigned int matrix_nlins(Matrix m);
	// unsigned int matrix_ncols(Matrix m);

	// Matrix matrix_create(); // Done
	// Matrix matrix_scalar_mul(double n, Matrix m); // Done
	// Matrix matrix_scalar_sum(double n, Matrix m); // Done
	// Matrix matrix_scalar_dif(double n, Matrix m); // Done
	// Matrix matrix_mul(Matrix A, Matrix B); // Done
	// Matrix matrix_sum(Matrix A, Matrix B); // Done
	// Matrix matrix_dif(Matrix A, Matrix B); // Done
	// int matrix_compare(Matrix A, Matrix B); // Done
	// double matrix_det(Matrix m); // Done
	// Matrix matrix_transpose(Matrix m); // Done
	// Matrix matrix_inverse(Matrix m); // Done
	// void print_matrix(const char *const name, const Matrix m); // Done
	
	
	

	matrix_free(&m2);

	return 0;
}


