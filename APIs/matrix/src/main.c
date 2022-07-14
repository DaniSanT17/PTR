/*
	main.c: Matrix test program
	author: Andre Cavalcante
	date: may, 2022
	license: CC BY-SA
*/

#include <stdio.h>
#include "matrix.h"

static void print_matrix(const char *const name, const Matrix m) {
	printf("%s(%u,%u) = [\n", name, m.nlins, m.ncols);
	for(int i = 0; i < matrix_nlins(m); i++) {
		printf("\t[%4.4f", matrix_value(m, i, 0));
		for(int j = 1; j < matrix_ncols(m); j++) {
			printf(", %4.4f", matrix_value(m, i, j));
		}
		puts("]");
	}
	puts("]");
}

int main(int argc, char **argv) {
	double m1Values[9] = {2, -2, -1, 3, -4, 1, 1, 1, 5};
	double m2Values[16] =  {4, 5, -3, 0, 2, -1, 3, 1, 1, -3, 2, 1, 0, 2, -2, 5};
	double m3Values[25] =  {1, 2, 3, -3, 1, 0, 4, 0, 0, 0, 0, 1, 0, 1, 1, 0, -6, 6, 1, 3, 0, 2, 0, -1, 1};
	Matrix m; Matrix m2; Matrix m3;

	m.ncols = 3; m.nlins = 3;
	m2.ncols = 4; m2.nlins = 4;
	m3.ncols = 5; m3.nlins = 5;
	m.values = &m1Values;
	m2.values = &m2Values;
	m3.values = &m3Values;
	double det = matrix_det(m);
	printf("\nDeterminante da matriz M = %f", det);
	det = matrix_det(m2);

	printf("\nDeterminante da matriz M = %f", det);
	det = matrix_det(m3);

	printf("\nDeterminante da matriz M = %f", det);

	
	print_matrix("M", m);
	
	
	matrix_free(&m);

	return 0;
}
