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
	double m1Values[9] = {2, -2, -1, 3, -4, 1, 1, 1, 1};
	double m2Values[16] =  {1, 0, 2, 0, 2, 1, 1, 1, 2, 3, 0, 1, -1, 1, 2, 2};
	double m3Values[25] =  {1, 2, 3, -3, 1, 0, 4, 0, 0, 0, 0, 1, 2, 1, 1, 0, -6, 6, 1, 3, 0, 2, 0, -1, 1};
	printf("\n########### Teste  matrix_zeros ##########\n");
	Matrix m = matrix_zeros(5, 5);
	print_matrix("Zeros", m);
	
	printf("\n######### Teste matrix_ones ########\n");
	Matrix m2 = matrix_ones(6, 6);
	print_matrix("1s", m2);

	printf("\n########### Teste matrix_identity ###########\n");
	Matrix m3 = matrix_identity(5, 5);
	print_matrix("Id", m3);
	
	printf("\n###########Teste matrix_copy e matrix_free #############\n");
	matrix_free(&m);
	m = matrix_copy(m3);
	print_matrix("New Id", m);
	

	printf("\n########## Teste matrix_apply com função x^2 #########");
	Matrix m4; m4.ncols = 5; m4.nlins = 5;
	m4.values = malloc(sizeof(double)*25);
	for(int i=0;i<25;i++){
		m4.values[i] = i;
	}
	print_matrix("M4 ", m4);
	m4 = matrix_apply(*power_2,m4);
	print_matrix("Potência 2 de M4 ", m4);

	printf("\n########## Teste matrix_apply com função x^3 #########");

	Matrix m5; m5.ncols = 5; m5.nlins = 5;
	m5.values = malloc(sizeof(double)*25);
	for(int i=0;i<25;i++){
		m5.values[i] = i;
	}
	print_matrix("M5 ", m5);
	m5 = matrix_apply(*power_3,m5);
	print_matrix("Potência 3 de M5 ", m5);

	printf("\n##########Teste matrix_value ############\n");
	printf("\nPrimeiros das matrizes M1, M2, M3, M4 e M5: %lf %lf %lf %lf %lf\n",matrix_value(m, 0,0), matrix_value(m2, 0,0),matrix_value(m3, 0,0),matrix_value(m4, 0,0),matrix_value(m5, 0,0));

	printf("\n########## Teste matrix_nlins e matrix_ncols############\n");
	printf("\nTamanho da matriz 4: %d x %d\n", matrix_nlins(m4), matrix_ncols(m4));

	printf("\n########## Teste matrix_scalar_mul, matrix_scalar_sum e matrix_scalar_dif ############\n");
	print_matrix("M6 ", m4);
	Matrix m6 = matrix_scalar_mul(2, m4);
	print_matrix("M6 * 2 ", m6);

	m6 = matrix_scalar_sum(10, m6);
	print_matrix("M6 + 10 ", m6);

	m6 = matrix_scalar_dif(20, m6);
	print_matrix("M6 - 20 ", m6);

	printf("\n########## Teste matrix_mul, matrix_sum e matrix_dif ############\n");
	print_matrix("M4 ", m4);
	print_matrix("M5 ", m5);
	print_matrix("M6 ", m6);
	Matrix m7 = matrix_mul(m6, m5);
	print_matrix("M6 * M5 ", m7);
	Matrix m8 = matrix_sum(m4, m5);
	print_matrix("M4 + M5 ", m8);
	Matrix m9 = matrix_dif(m4, m5);
	print_matrix("M4 - M5 ", m9);

	printf("\n########## Teste matrix_compare ############\n");
	print_matrix("M1 ", m);
	print_matrix("M3 ", m3);
	print_matrix("M4 ", m4);
	print_matrix("M6 ", m6);
	printf("Comparando M1 e M3? R=%d | Verdadeiro = 1\nComparando M4 e M6? R=%d | Falso = 0\n",matrix_compare(m,m3),matrix_compare(m4,m6));

	printf("\n########## Teste matrix_det, matrix_transpose e matrix_inverse ############\n"); 
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


	print_matrix("M10 ", m10);
	printf("Determinante de M10: %lf\n", matrix_det(m10));
	print_matrix("M10^T ", matrix_transpose(m10));
	Matrix m10i = matrix_inverse(m10); 
	print_matrix("M10^-1 ", m10i);
	print_matrix("M10 x M10^-1 = id", matrix_mul(m10,m10i));

	print_matrix("M11 ", m11);
	printf("Determinante de M11: %lf\n", matrix_det(m11));
	print_matrix("M11^T ", matrix_transpose(m11));
	Matrix m11i = matrix_inverse(m11); 
	print_matrix("M11^-1 ", m11i);
	print_matrix("M11 x M11^-1 = id", matrix_mul(m11,m11i));


	print_matrix("M12 ", m12);
	printf("Determinante de M12: %lf\n", matrix_det(m12));
	print_matrix("M12^T ", matrix_transpose(m12));
	Matrix m12i = matrix_inverse(m12); 
	print_matrix("M12^-1 ", m12i);
	print_matrix("M12 x M12^-1 = id", matrix_mul(m12,m12i));

	printf("\n########## Teste matrix_create ############\n"); 

	printf("Digite as dimensões de sua matriz:\n");
	Matrix m13 = matrix_create();
	print_matrix("M13 ", m13);

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


