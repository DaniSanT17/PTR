
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "dstring.h"
#include "integrate.h"

double polynomial(double a){
	
	return 2*(a*a*a)-(a*a)+3*a+4;
}

double power_2(double a){
	return a*a;
}
double power_3(double a){
	return a*a*a;
}
int main(int argc, char **argv) {
	printf("\n###################################################################################\n");
	printf("########## Teste ADT DString #######\n");

	printf("\n####### Teste dstring_create ##########\n"); 
	printf("Criando dstrings com *char\n");
	char *st = malloc(10*sizeof(char));
	for(int i=0;i<10;i++){
		st[i]= 65+i;
	}
	char *st2 = malloc(10*sizeof(char));
	for(int i=0;i<10;i++){
		st2[i]= 75+i;
	}
	char *st3 = malloc(6*sizeof(char));
	for(int i=0;i<6;i++){
		st3[i]= 85+i;
	}
	DString *s = dstring_create(st, 10);
	DString *s2 = dstring_create(st2, 10);
	DString *s3 = dstring_create(st3, 6);
	printf("Dstring S1 = ") ;print_buffer(s);
	printf("Dstring S2 = "); print_buffer(s2);
	printf("Dstring S3 = "); print_buffer(s3);

	printf("\n####### Teste dstring_from_char ##########\n"); 
	DString *s4 = dstring_from_char('a');
	print_buffer(s4);
	DString *s5 = dstring_from_char('b');
	print_buffer(s5);
	DString *s6 = dstring_from_char('c');
	print_buffer(s6);
	printf("\nTamanhos da 4, 5 e 6 DStrings: %d, %d, %d\n",dstring_size(s4), dstring_size(s5), dstring_size(s6));

	printf("\n####### Teste dstring_from_int ##########\n"); 
	DString *s7 = dstring_from_int(2);
	printf("Alocando memória para dstring de tamanho: %d\n", s7->size);
	DString *s8 = dstring_from_int(3);
	printf("Alocando memória para dstring de tamanho: %d\n", s8->size);

	printf("\n####### Teste dstring_from_double ##########\n"); 
	double d = 4.232145125;
	DString *s9 = dstring_from_double(d);
	printf("Alocando memória para dstring de tamanho: %d\n", s9->size);

	printf("\n####### Teste dstring_from_float ##########\n"); 
	float e = 5.232145125;
	DString *s10 = dstring_from_float(e);
	printf("Alocando memória para dstring de tamanho: %d\n", s10->size);

	printf("\n####### Teste dstring_from_long ##########\n"); 
	long f = 12124124;
	DString *s11 = dstring_from_long(f);
	printf("Alocando memória para dstring de tamanho: %d\n", s11->size);

	printf("\n####### Teste dstring_from_dstring ##########\n"); 
	DString *s12 = dstring_from_dstring(s);
	printf("S1 = "); print_buffer(s);
	printf("DString criada S12 = "); print_buffer(s12);

	printf("\n####### Teste dstring_concat ##########\n");
	printf("Concatenando DStrings S1, S2 e S3:\n"); 
	DString *s13 = dstring_concat(s,s2);
	printf("S1 + S2 = "); print_buffer(s13);
	DString *s14 = dstring_concat(s13,s3);
	printf("S1 + S2 + S3 = ");print_buffer(s14);

	printf("\n####### Teste dstring_size ##########\n"); 
	printf("\nTamanhos das 3 primeiras DStrings: %d, %d, %d\n",dstring_size(s), dstring_size(s2), dstring_size(s3));

	printf("\n####### Teste dstring_add_buffer ##########\n"); 
	printf("Adicionando buffer nas strings com memórias alocadas anteriormente:\n");
	char *p = calloc(20, sizeof(char));
	for(int i=0;i<20;i++){
		p[i] = 97+i;
	}
	dstring_add_buffer(s7, p);
	printf("\nInt 3: "); print_buffer(s7);
	dstring_add_buffer(s8, p);
	printf("Int 3: "); print_buffer(s8);
	dstring_add_buffer(s9, p);
	printf("Double 4.232145125: "); print_buffer(s9);
	dstring_add_buffer(s10, p);
	printf("Float 5.232145125: "); print_buffer(s10);
	dstring_add_buffer(s11, p);
	printf("Long 12124124: "); print_buffer(s11);

	printf("\n######## Teste Define BUFFER ########\n");
	char *buff = BUFFER(s);
	printf("Imprimindo buffer coletado da string S1: \n");
	for(int i =0;i<s->size;i++){
		printf("%c", buff[i]);
	}


	printf("\n\n####### Teste free_dstring ##########\n"); 


	free_dstring(s);
	free_dstring(s2);
	free_dstring(s3);
	free_dstring(s4);
	free_dstring(s5);
	free_dstring(s6);
	free_dstring(s7);
	free_dstring(s8);
	free_dstring(s9);
	free_dstring(s10);
	free_dstring(s12);
	free_dstring(s13);
	free_dstring(s14);
	print_buffer(s);

	printf("\n###################################################################################\n");
	printf("###### Teste ADT Integral #######\n");

	printf("Polinomio F(x) = 2x^3 - x^2 + 3x + 4\n");
	Integral int_func = build_integrate(-5.0, 7.0, *polynomial);
	printf("Limite inferior: %lf, Limite superior: %lf, F(2) = %lf\n", int_func.lowerl, int_func.upperl, (*(int_func.func))(2));
	double res = do_integration(int_func, 0.0001);
	
	printf("Integral de 2x^3 - x^2 + 3x + 4 de -5 a 7 é igual a %lf\n\n", res);


	printf("Polinomio F(X) = x^3\n");
	Integral int_func2 = build_integrate(0.0, 15.0, *power_3);
	printf("Limite inferior: %lf, Limite superior: %lf, F(2) = %lf\n", int_func2.lowerl, int_func2.upperl, (*(int_func2.func))(2));
	res = do_integration(int_func2, 0.0001);
	
	printf("Integral de x^3 de 0 a 15 é igual a %lf\n", res);

	printf("\n###################################################################################\n");
	printf("###### Teste ADT Matrix #######\n");

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


