/*
	Implementação da ADT Matrix
	Autores: André Cavalcante e Daniel Santiago da Silva
*/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

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

// Número de linhas

unsigned int matrix_nlins(Matrix m) {
	return m.nlins;
}

// Número de colunas

unsigned int matrix_ncols(Matrix m) {
	return m.ncols;
}

// Cópia de matrizes

Matrix matrix_copy(Matrix m) {
	Matrix res;
	res.nlins = m.nlins;
	res.ncols = m.ncols;
	res.values = calloc(m.nlins * m.ncols, sizeof(double));
	if(m.values) {
		for(int i=0; i < res.nlins; i++)
			for(int j=0; j < res.ncols; j++)
				VALUES(res, i, j) = VALUES(m, i, j);
		return res;
	}
	else
		return matrix_nul;
}


Matrix matrix_apply(double (*f)(double val), Matrix m) {
	Matrix res;
	res.nlins = m.nlins;
	res.ncols = m.ncols;
	res.values = calloc(res.nlins * res.ncols, sizeof(double));
	if(m.values) {
		for(int i=0; i < res.nlins; i++)
			for(int j=0; j < res.ncols; j++)
				res.values[i*res.ncols + j] = f(m.values[i*res.ncols + j]);
		return res;
	}
	else
		return matrix_nul;
}

Matrix matrix_create(){
	Matrix res = matrix_nul;
	int nlins, ncols;
	printf("Número de linhas: ");
	if(scanf("%d", &nlins)!=1){
		printf("ERRO: Falha em ler o número de linhas.\n");
		return matrix_nul;
	}
	printf("Número de colunas: ");
	if(scanf("%d", &ncols)!=1){
		printf("ERRO: Falha em ler o número de colunas.\n");
		return matrix_nul;
	}
	if(nlins <= 0 || ncols <=0){
		printf("ERRO: O número de colunas e linhas devem ser maior que 0!\n");
		return matrix_nul;
	}
	res.nlins = nlins;
	res.ncols = ncols;
	res.values = calloc(res.nlins * res.ncols, sizeof(double));
	for(int i = 0; i < nlins; i++){
		for(int j = 0; j < ncols; j++){
			printf("M[%d ; %d] => ", i+1, j+1);
			if(scanf("%lf", &VALUES(res, i, j))!=1){
				printf("ERRO: Falha em ler o valor de entrada.\n");
				return matrix_nul;
			}
		}
	}
	return res;
}

void print_matrix(const char *const name, const Matrix m) {
	if(!m.values){
		printf("Matrix vazia!\n");
		return;
	}
	printf("\n %s(%d:%d)=", name, m.nlins, m.ncols);
	printf("\n\t[\n");
	for(int i = 0; i < matrix_nlins(m); i++) {
		printf("\t[%4.4f", matrix_value(m, i, 0));
		for(int j = 1; j < matrix_ncols(m); j++) {
			printf(", %4.4f", matrix_value(m, i, j));
		}
		printf("]\n");
	}
	printf("]\n");
}

Matrix matrix_sum(Matrix A, Matrix B){
	Matrix res;

	if(A.nlins != B.nlins || A.ncols != B.ncols){	
		printf("ERRO: As matrizes devem ter o mesmo tamanho para a operação de soma!\n");
		return matrix_nul;	
	}
	if (!(A.values) || !(B.values)){
		printf("ERRO: As matrizes não podem estar vazias!\n");
		return matrix_nul;
	}
	res.nlins = A.nlins;
	res.ncols = A.ncols;
	res.values = calloc(res.nlins * res.ncols, sizeof(double));
	for(int i = 0; i < matrix_nlins(A); i++) {
		res.values[i*res.ncols] = A.values[i*A.ncols ] - B.values[i*B.ncols ];
		for(int j = 1; j < matrix_ncols(B); j++) {
			res.values[i*res.ncols + j] = A.values[i*A.ncols + j] + B.values[i*B.ncols + j];
		}
	}
	return res;
}

Matrix matrix_dif(Matrix A, Matrix B){
	Matrix res;

	if(A.nlins != B.nlins || A.ncols != B.ncols){	
		printf("ERRO: As matrizes devem ter o mesmo tamanho para a operação de subtração!\n");
		return matrix_nul;	
	}
	if (!(A.values) || !(B.values)){
		printf("ERRO: As matrizes não podem estar vazias!\n");
		return matrix_nul;
	}
	res.nlins = A.nlins;
	res.ncols = A.ncols;
	res.values = calloc(res.nlins * res.ncols, sizeof(double));
	for(int i = 0; i < matrix_nlins(A); i++) {
		res.values[i*res.ncols] = A.values[i*A.ncols ] - B.values[i*B.ncols ];
		for(int j = 1; j < matrix_ncols(B); j++) {
			res.values[i*res.ncols + j] = A.values[i*A.ncols + j] - B.values[i*B.ncols + j];
		}
	}
	return res;
}


Matrix matrix_mul(Matrix A, Matrix B){
	if(A.ncols != B.nlins){
		printf("ERRO: O número de colunas da matriz A deve ser igual ao número de linhas da matriz B\n");
		return matrix_nul;
	}
	if (!(A.values) || !(B.values)){
		printf("ERRO: As matrizes não podem estar vazias!\n");
		return matrix_nul;
	}
	Matrix res = matrix_zeros(A.nlins, B.ncols);	
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
	
};

Matrix matrix_scalar_sum(double n, Matrix m){
	if(!(m.values)) {
		printf("ERRO: As matrizes não podem estar vazias!\n");
		return matrix_nul;
	}
	Matrix res;
	res.nlins = m.nlins;
	res.ncols = m.ncols;
	res.values = calloc(res.nlins * res.ncols, sizeof(double));
	for(int i=0; i < res.nlins; i++)
		for(int j=0; j < res.ncols; j++)
			res.values[i*res.ncols + j] = n + m.values[i*res.ncols + j];
	return res;
}

Matrix matrix_scalar_dif(double n, Matrix m){
	if(!(m.values)) {
		printf("ERRO: As matrizes não podem estar vazias!\n");
		return matrix_nul;
	}
	Matrix res;
	res.nlins = m.nlins;
	res.ncols = m.ncols;
	res.values = calloc(res.nlins * res.ncols, sizeof(double));
	for(int i=0; i < res.nlins; i++)
		for(int j=0; j < res.ncols; j++)
			res.values[i*res.ncols + j] = m.values[i*res.ncols + j] - n;
	return res;
}

Matrix matrix_scalar_mul(double n, Matrix m){
	if(!(m.values)) {
		printf("ERRO: As matrizes não podem estar vazias!\n");
		return matrix_nul;
	}
	Matrix res;
	res.nlins = m.nlins;
	res.ncols = m.ncols;
	res.values = calloc(res.nlins * res.ncols, sizeof(double));
	for(int i=0; i < res.nlins; i++)
		for(int j=0; j < res.ncols; j++)
			res.values[i*res.ncols + j] = m.values[i*res.ncols + j] * n;
	return res;
}

int matrix_compare(Matrix A, Matrix B){
	if(A.ncols != B.ncols || A.nlins != B.nlins){
		return 0;
	}
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
	return 1;
}

double matrix_det(Matrix m){
	if(!(m.values) || m.nlins!=m.ncols){
		printf("ERRO: A matriz de entrada deve ser quadrada e não pode estar vazia!!!\n");
		return 0;
	}
	Matrix aux = matrix_copy(m);
	int nl = matrix_nlins(aux);
	double factor = 0;	
	double temp = 0;	
	int count = 0;	
	for(int i = 0; i < nl-1; i++){
		if(VALUES(aux, i, i) == 0){
			for(int k = i; k < nl; k++){
				if(VALUES(aux, k, i) != 0){
					for(int j = 0; j < nl; j++){
						temp = VALUES(aux, i, j);
						VALUES(aux, i, j) = VALUES(aux, k, j);
						VALUES(aux, k, j) = temp;
					}
					k = nl;
				}
			}
			count++;
		}
		else{
			for(int k = i + 1; k < nl; k++){
				factor = -1.0 * VALUES(aux, k, i) / VALUES(aux, i, i);
				for(int j = i; j < nl; j++){
					VALUES(aux, k, j) = VALUES(aux, k, j) + (factor * VALUES(aux, i, j));
				}
			}
		}
	}
	temp = 1.0;
	for(int i = 0; i < nl; i++){
		temp *= VALUES(aux, i, i);
	}
	if(count % 2 == 0)
		return temp;
	else
		return -1.0 * temp;
	
}

Matrix matrix_transpose(Matrix m){
	if(!(m.values)){
		printf("ERRO: As matrizes não podem estar vazias!\n");
		return matrix_nul;
	}
	Matrix res;
	res.ncols = m.nlins;
	res.nlins = m.ncols;
	res.values = calloc(res.nlins * res.ncols, sizeof(double));

	for(int i=0; i<res.nlins; i++){
		for(int j=0; j<res.ncols; j++){
			VALUES(res, i, j) = VALUES(m, j, i);
		}
	}
	return res;
}

Matrix matrix_inverse(Matrix m){
	if(m.ncols != m.nlins || !(m.values)){
		printf("ERROR: A matriz de entrada deve ser quadrada e não pode ser vazia!!!\n");
		return matrix_nul;
	}
	Matrix aux = matrix_copy(m);
	Matrix id = matrix_identity(m.nlins, m.ncols);
	int k = 0, N= m.ncols;
	float pivot = 0, n = 0;
	for(int j = 0; j < N; j++){
		pivot = VALUES(aux,j,j);
		for(k = 0; k < N; k++){
			VALUES(aux, j, k) = VALUES(aux, j,k)/(pivot); 
			VALUES(id,j,k) = VALUES(id,j,k)/(pivot); 
		}
		for(int i = 0; i < N; i++){
			if(i != j){
				n = VALUES(aux,i,j);
				for(int k = 0; k < N; k++){
					VALUES(aux,i,k) = VALUES(aux,i,k) - n*VALUES(aux,j,k); 
					VALUES(id,i,k) = VALUES(id,i,k) - n*VALUES(id,j,k);  
				}
			}
		}  
	}
	return id;
}