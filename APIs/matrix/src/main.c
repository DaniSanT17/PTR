/*
	main.c: Matrix test program
	author: Andre Cavalcante
	date: may, 2022
	license: CC BY-SA
*/

#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

double power_2(double a){
	return a*a;
}
double power_3(double a){
	return a*a*a;
}
int main(int argc, char **argv) {
	double m1Values[9] = {0, -2, -1, 3, -4, 1, 1, 1, 0};
	double m2Values[16] =  {1, 0, 2, 0, 2, 1, 1, 1, 2, 3, 0, 1, -1, 1, 2, 2};
	double m3Values[25] =  {1, 2, 3, -3, 1, 0, 4, 0, 0, 0, 0, 1, 0, 1, 1, 0, -6, 6, 1, 3, 0, 2, 0, -1, 1};
	printf("Teste  matrix_zeros\n");
	Matrix m = matrix_zeros(5, 5);
	print_matrix("Zeros", m);
	
	printf("Teste matrix_ones\n");
	Matrix m2 = matrix_ones(6, 6);
	print_matrix("1s", m2);

	printf("Teste matrix_identity\n");
	Matrix m3 = matrix_identity(5, 5);
	print_matrix("Id", m3);
	
	// Matrix matrix_copy(Matrix m);
	// void matrix_free(Matrix *m);
	matrix_free(&m);
	m = matrix_copy(m3);
	print_matrix("New Id", m);
	

	// Matrix matrix_create(); // Done
	// Matrix matrix_apply(double (*f)(double val), Matrix m);
	Matrix m4 = matrix_create();
	m4 = matrix_apply(*power_2,m4);
	print_matrix("Power2 ", m4);
	Matrix m5 = matrix_create();
	m5 = matrix_apply(*power_3,m5);
	print_matrix("Power3 ", m5);

	// double       matrix_value(Matrix m, int i, int j);
	printf("Primeiros de cada 1 %lf %lf %lf %lf %lf\n",matrix_value(m, 0,0), matrix_value(m2, 0,0),matrix_value(m3, 0,0),matrix_value(m4, 0,0),matrix_value(m5, 0,0));

	// unsigned int matrix_nlins(Matrix m);
	// unsigned int matrix_ncols(Matrix m);
	printf("Tamanho das matrizes 4: %d e %d\n", matrix_nlins(m4), matrix_ncols(m4));

	// Matrix matrix_scalar_mul(double n, Matrix m); // Done
	Matrix m6 = matrix_scalar_mul(2, m4);
	print_matrix("Escalar x 2 ", m6);
	// Matrix matrix_scalar_sum(double n, Matrix m); // Done
	m6 = matrix_scalar_sum(10, m6);
	print_matrix("Escalar + 10 ", m6);
	// Matrix matrix_scalar_dif(double n, Matrix m); // Done
	m6 = matrix_scalar_dif(20, m6);
	print_matrix("Escalar - 2 ", m6);
	// Matrix matrix_mul(Matrix A, Matrix B); // Done
	Matrix m7 = matrix_mul(m6, m5);
	print_matrix("m6 x m5 ", m7);
	// Matrix matrix_sum(Matrix A, Matrix B); // Done
	Matrix m8 = matrix_sum(m4, m5);
	print_matrix("m4 + m5 ", m8);
	// Matrix matrix_dif(Matrix A, Matrix B); // Done
	Matrix m9 = matrix_dif(m4, m5);
	print_matrix("m4 - m5 ", m9);
	// int matrix_compare(Matrix A, Matrix B); // Done
	printf("M1 = M3? %d\nM4 = M6? %d\n",matrix_compare(m,m3),matrix_compare(m4,m6));
	// double matrix_det(Matrix m); // Done
	Matrix m10; m10.ncols = 3; m10.nlins = 3; m10.values = malloc(sizeof(double)*9);
	Matrix m11; m11.ncols = 4; m11.nlins = 4; m11.values = malloc(sizeof(double)*16);
	Matrix m12; m12.ncols = 5; m12.nlins = 5; m12.values = malloc(sizeof(double)*25);
	for(int i=0;i<9;i++){
		m10.values[i]=m1Values[i];
	}
	for(int i=0;i<16;i++){
		m11.values[i]=m2Values[i];
	}
	for(int i=0;i<25;i++){
		m12.values[i]=m3Values[i];
	}
	print_matrix("m10 ", m10);print_matrix("m11 ", m11);print_matrix("m12 ", m12);
	printf("Determinantes das maztrizes acima em ordem são: %lf %lf %lf\n", matrix_det(m10), matrix_det(m11), matrix_det(m12));
	// Matrix matrix_transpose(Matrix m); // Done
	print_matrix("m10T ", matrix_transpose(m10));
	print_matrix("m11T ", matrix_transpose(m11));
	print_matrix("m12T ", matrix_transpose(m12));
	// Matrix matrix_inverse(Matrix m); // Done
	Matrix m10i = matrix_inverse(m10); 
	print_matrix("m10i ", m10i);
	print_matrix("m10 x m10i = id", matrix_mul(m10,m10i));
	Matrix m11i = matrix_inverse(m11); 
	print_matrix("m11i ", m11i);
	print_matrix("m10 x m10i = id", matrix_mul(m11,m11i));
	Matrix m12i = matrix_inverse(m12); 
	print_matrix("m11i ", m12i);
	print_matrix("m10 x m10i = id", matrix_mul(m12,m12i));
	// void print_matrix(const char *const name, const Matrix m); // Done
	
	
	

	matrix_free(&m);
	matrix_free(&m2);
	matrix_free(&m3);
	matrix_free(&m4);
	matrix_free(&m5);
	matrix_free(&m6);
	matrix_free(&m7);
	matrix_free(&m8);
	matrix_free(&m9);
	matrix_free(&m10);
	matrix_free(&m11);
	matrix_free(&m12);
	matrix_free(&m10i);
	matrix_free(&m11i);
	matrix_free(&m12i);

	return 0;
}


