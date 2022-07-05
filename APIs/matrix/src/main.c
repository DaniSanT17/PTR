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
	Matrix m = matrix_identity(3,3);
	Matrix m2 = matrix_ones(3,3);
	Matrix m3 = matrix_sum(m, m2);
	print_matrix("M", m3);
	
	matrix_free(&m);
	print_matrix("M", m);
	
	return 0;
}
