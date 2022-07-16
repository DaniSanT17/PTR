#include "stdio.h"
#define N 4

float identidade[N][N];

void inversa(int n, float Matriz_A[N][N]){
  int linha, coluna, k = 0;
    float pivo = 0, m = 0;
	
for(linha = 0; linha < N; linha++){
    	for(coluna = 0; coluna < N; coluna++){
    		if(linha == coluna){
    		identidade[linha][coluna] = 1;
    	        }else{
    	        identidade[linha][coluna] = 0;     
    	        } 
    	}  
	}

for(coluna = 0; coluna < N; coluna++){
    pivo = Matriz_A[coluna][coluna];
    	for(k = 0; k < N; k++){
		Matriz_A[coluna][k] = (Matriz_A[coluna][k])/(pivo); //L1 -> L1/pivo , L2 -> L2/pivo, L3 -> L3/pivo
		identidade[coluna][k] = (identidade[coluna][k])/(pivo); //Ex: 1 0 0 / pivo  , 0 1 0 / pivo,   0 0 1/ pivo
        }
    
	for(linha = 0; linha < N; linha++){
		if(linha != coluna){
			m = Matriz_A[linha][coluna];
           			for(k = 0; k < N; k++){
			Matriz_A[linha][k] = (Matriz_A[linha][k]) - (m*Matriz_A[coluna][k]); //Ex: L2 -> L2 - ( 1"m" - L1) 
			identidade[linha][k] = (identidade[linha][k]) - (m*identidade[coluna][k]);  
    			}
    		}
    	}  
}

for(linha = 0; linha < N; linha++){
	for(coluna = 0; coluna < N; coluna++){
	  printf("%lf ", identidade[linha][coluna]);    
  }
      
    printf("\n");
}
}

int main(){

    float Mat[N][N] = {{2,3,-1,2},{0,4,-3,5},{1,2,1,3},{0,4,1,0}};
inversa(N,Mat);
return 0;    
}