/*
	main.c: Matrix test program
	author: Andre Cavalcante
	date: may, 2022
	license: CC BY-SA
*/

#include <stdio.h>
#include "matrix.h"

int main(int argc, char **argv) {
	double m1Values[9] = {2, -2, -1, 3, -4, 1, 1, 1, 5};
	double m2Values[16] =  {1, 0, 2, 0, 2, 1, 1, 1, 2, 3, 0, 1, -1, 1, 2, 2};
	double m3Values[25] =  {1, 2, 3, -3, 1, 0, 4, 0, 0, 0, 0, 1, 0, 1, 1, 0, -6, 6, 1, 3, 0, 2, 0, -1, 1};
	Matrix m; Matrix m2; Matrix m3;
	// m2 = matrix_create(4,4);

	// print_matrix("M", m2);
	m.ncols = 3; m.nlins = 3;
	m2.ncols = 4; m2.nlins = 4;
	m3.ncols = 5; m3.nlins = 5;
	m.values = &m1Values;
	// m2 = matrix_copy(m);
	m2.values = &m2Values;
	m3.values = &m3Values;

	
	print_matrix("M", m2);
	print_matrix("N", matrix_transpose(m2));
	
	
	matrix_free(&m);
	matrix_free(&m2);

	return 0;
}


