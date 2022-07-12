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
	double m1Values[9] = {3, 1, 2, -1, 0, 4};
	double m2Values[9] =  {1, -1, 2, 3, 0, 5};
	Matrix m; Matrix m2 = matrix_identity(2,2);

	m.ncols = 2; m.nlins = 3;
	// m2.ncols = 3; m2.nlins = 1;
	m.values = &m1Values;
	// m2.values = &m2Values;
	
	Matrix m3 = matrix_mul(m, m2);
	print_matrix("Ms", m3);

	matrix_free(&m);
	print_matrix("M", m);
	
	return 0;
}
