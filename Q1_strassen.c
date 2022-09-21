#include <stdio.h>
#include <stdlib.h>

int **soma(int **A, int **B, int grau)
{//Soma as matrizes passadas e retorna a matriz resultado
	int i, j;
	
	int **C;
	C = malloc(sizeof(int)*grau);
	for(i = 0; i < grau; i++)
		C[i] = malloc(sizeof(int)*grau);		
	
	for(i = 0; i < grau; i++)
	{
		for(j = 0; j < grau; j++)
			C[i][j] += A[i][j] + B[i][j];
	}
	
	return C;	
}

int **subtrai(int **A, int **B, int grau)
{//Subtrai as matrizes passadas e retorna a matriz resultado
	int i, j;

	int **C;
	C = malloc(sizeof(int)*grau);
	for(i = 0; i < grau; i++)
		C[i] = malloc(sizeof(int)*grau);	
	
	for(i = 0; i < grau; i++)
	{
		for(j = 0; j < grau; j++)
			C[i][j] += A[i][j] - B[i][j];
	}
	return C;	
}

void strassen(int **A, int **B, int **C, int grau)
{
    int i, j, k;
    
	if(grau <= 2) 
	{//Se for menor ou igual a dois faça normalmente
   		for(i = 0; i < grau; i++)
		{
			for(j = 0; j < grau; j++)
			{
				C[i][j] = 0;
				for(k = 0; k < grau; k++)
					C[i][j] += A[i][k] * B[k][j];
			}
		}
		
        return;
    }
    
    int **A11, **A12, **A21, **A22;
    int **B11, **B12, **B21, **B22;
    int **C11, **C12, **C21, **C22;
    int **M1, **M2, **M3, **M4, **M5, **M6, **M7;
    
    {//Aloca dinamicamente
		A11 = malloc(sizeof(int)*grau/2);
	    A12 = malloc(sizeof(int)*grau/2);
	    A21 = malloc(sizeof(int)*grau/2);
	    A22 = malloc(sizeof(int)*grau/2);
	    B11 = malloc(sizeof(int)*grau/2);
	    B21 = malloc(sizeof(int)*grau/2);
	    B12 = malloc(sizeof(int)*grau/2);
	    B22 = malloc(sizeof(int)*grau/2);
	    C11 = malloc(sizeof(int)*grau/2);
        C12 = malloc(sizeof(int)*grau/2);
	    C21 = malloc(sizeof(int)*grau/2);
		C22 = malloc(sizeof(int)*grau/2);
	    M1 = malloc(sizeof(int)*grau/2);
	    M2 = malloc(sizeof(int)*grau/2);
	    M3 = malloc(sizeof(int)*grau/2);
	    M4 = malloc(sizeof(int)*grau/2);
	    M5 = malloc(sizeof(int)*grau/2);
	    M6 = malloc(sizeof(int)*grau/2);
	    M7 = malloc(sizeof(int)*grau/2);
	
	    for(i = 0; i < grau/2; i++)
		{
			A11[i] = malloc(sizeof(int)*grau/2);
		    A12[i] = malloc(sizeof(int)*grau/2);
		    A21[i] = malloc(sizeof(int)*grau/2);
		    A22[i] = malloc(sizeof(int)*grau/2);
		    B11[i] = malloc(sizeof(int)*grau/2);
		    B21[i] = malloc(sizeof(int)*grau/2);
		    B12[i] = malloc(sizeof(int)*grau/2);
		    B22[i] = malloc(sizeof(int)*grau/2);
		    C11[i] = malloc(sizeof(int)*grau/2);
	        C12[i] = malloc(sizeof(int)*grau/2);
		    C21[i] = malloc(sizeof(int)*grau/2);
			C22[i] = malloc(sizeof(int)*grau/2);
		    M1[i] = malloc(sizeof(int)*grau/2);
		    M2[i] = malloc(sizeof(int)*grau/2);
		    M3[i] = malloc(sizeof(int)*grau/2);
		    M4[i] = malloc(sizeof(int)*grau/2);
		    M5[i] = malloc(sizeof(int)*grau/2);
		    M6[i] = malloc(sizeof(int)*grau/2);
		    M7[i] = malloc(sizeof(int)*grau/2);	
		}
		
		for(i = 0; i < grau/2; i++)
  		{
	        for(j = 0; j < grau/2; j++)
	        {
	            A11[i][j] = 0;
	            A12[i][j] = 0;
	            A21[i][j] = 0;
	            A22[i][j] = 0;
	            B11[i][j] = 0;
	            B12[i][j] = 0;
	            B21[i][j] = 0;
	            B22[i][j] = 0;
	            C11[i][j] = 0;
	            C12[i][j] = 0;
	            C21[i][j] = 0;
	            C22[i][j] = 0;
	            M1[i][j] = 0;
	            M2[i][j] = 0;
	            M3[i][j] = 0;
	            M4[i][j] = 0;
				M5[i][j] = 0;
	            M6[i][j] = 0;
	            M7[i][j] = 0;
	        }         
    	}
	}
	
	for(i = 0; i < grau/2; i++)
    {//Divide as matrizes A e B em 4 submatrizes cada
        for(j = 0; j < grau/2; j++)
        {
            A11[i][j] = A[i]         [j];
            A12[i][j] = A[i]		 [j+(grau/2)];
            A21[i][j] = A[i+(grau/2)][j];
            A22[i][j] = A[i+(grau/2)][j+(grau/2)];
            B11[i][j] = B[i]         [j];
            B12[i][j] = B[i]		 [j+(grau/2)];
            B21[i][j] = B[i+(grau/2)][j];
            B22[i][j] = B[i+(grau/2)][j+(grau/2)];
        }         
    }  
    
    strassen(soma(A11, A22, grau/2), soma(B11, B22, grau/2), M1, grau/2);
    strassen(soma(A21, A22, grau/2), B11, M2, grau/2);
    strassen(A11, subtrai(A11, A22, grau/2), M3, grau/2);
    strassen(A22, subtrai(A21, A11, grau/2), M4, grau/2);
    strassen(soma(A11, A12, grau/2), B22, M5, grau/2);
    strassen(subtrai(A21, A11, grau/2), soma(B11, B12, grau/2), M6, grau/2);
    strassen(subtrai(A12, A22, grau/2), soma(B21, B22, grau/2), M7, grau/2);	
    
    C11 = subtrai(soma(M1, M4, grau/2), soma(M5, M7, grau/2), grau/2);
    C12 = soma(M3, M5, grau/2);
    C21 = soma(M2, M4, grau/2);
    C22 = soma(subtrai(M1, M2, grau/2), soma(M3, M6, grau/2), grau/2);  
    
	for(i = 0; i < grau/2; i++)
	{
  		for(j = 0; j < grau/2; j++)
  	    {
            C[i]         [j]   		  = C11[i][j];
            C[i]         [j+(grau/2)] = C12[i][j];
            C[i+(grau/2)][j] 		  = C21[i][j];
            C[i+(grau/2)][j+(grau/2)] = C22[i][j];
        }     
	}

	{//Libera espaços
		for(i = 0; i < grau/2; i++)
			{
				free(A11[i]);
			    free(A12[i]);
			    free(A21[i]);
			    free(A22[i]);
			    free(B11[i]);
			    free(B12[i]);
			    free(B21[i]);
			    free(B22[i]);
			    free(M1[i]);
			    free(M2[i]);
			    free(M3[i]);
			    free(M4[i]);
			    free(M5[i]);
			    free(M6[i]);
			    free(M7[i]);
			}	
			
		    free(A11);
		    free(A12);
		    free(A21);
		    free(A22);
		    free(B11);
		    free(B12);
		    free(B21);
		    free(B22);
		    free(M1);
		    free(M2);
		    free(M3);
		    free(M4);
		    free(M5);
		    free(M6);
		    free(M7);
	}
    
    return;
}

int main(int argc, char** argv)
{
	int grau = 0;
	int i, j;
	int **A, **B, **C;
	
	printf("Entre com o grau das matrizes.\n");
	scanf("%d", &grau);
	
	A = malloc(sizeof(int)*grau);
	B = malloc(sizeof(int)*grau);
	C = malloc(sizeof(int)*grau);
	
	for(i = 0; i < grau; i++)
	{
		A[i] = malloc(sizeof(int)*grau);
		B[i] = malloc(sizeof(int)*grau);
		C[i] = malloc(sizeof(int)*grau);		
	}
	
	srand(time(NULL));
			
	for(i = 0; i < grau; i++)
	{
		for(j = 0; j < grau; j++)
		{
			A[i][j] = 0;
			B[i][j] = 0;
			C[i][j] = 0;
		}			
	}	
	
	for(i = 0; i < grau; i++)
	{
		for(j = 0; j < grau; j++)
		{
			A[i][j] = rand()%2;
			B[i][j] = rand()%2;
		}			
	}
	
	for(i = 0; i < grau; i++)
	{
		for(j = 0; j < grau; j++)
			printf("%d   ", A[i][j]);
		printf("\n");
	}
	printf("\n\n\n");
	
	for(i = 0; i < grau; i++)
	{
		for(j = 0; j < grau; j++)
			printf("%d   ",B[i][j]);
		printf("\n");
	}
	printf("\n\n\n");
	
	strassen(A, B, C, grau);
	
	for(i = 0; i < grau; i++)
	{
		free(A[i]);
		free(B[i]);
		free(C[i]);
	}	
	
	for(i = 0; i < grau; i++)
	{
		for(j = 0; j < grau; j++)
			printf("%d   ", C[i][j]);
		printf("\n");
	}
	
	free(A);
	free(B);
	free(C);
	
	return 0;
}