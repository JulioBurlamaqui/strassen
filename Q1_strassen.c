#include <stdio.h>
#include <stdlib.h>

int **soma(int **A, int **B, int grau)
{
	int i, j, k;
	
	int **C;
	C = malloc(sizeof(int)*grau);
	
	for(i = 0; i < grau; i++)
		{
			for(j = 0; j < grau; j++)
			{
				C[i][j] = 0;
				for(k = 0; k < grau; k++)
					C[i][j] += A[i][k] + B[k][j];
			}
		}
	return C;	
}

int **subtrai(int **A, int **B, int grau)
{
	int i, j, k;

	int **C;
	C = malloc(sizeof(int)*grau);	
	
	for(i = 0; i < grau; i++)
		{
			for(j = 0; j < grau; j++)
			{
				C[i][j] = 0;
				for(k = 0; k < grau; k++)
					C[i][j] += A[i][k] - B[k][j];
			}
		}
	return C;	
}

void strassen(int **A, int **B, int **C, int grau)
{
    int i, j, k;
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
		    M1[i] = malloc(sizeof(int)*grau/2);
		    M2[i] = malloc(sizeof(int)*grau/2);
		    M3[i] = malloc(sizeof(int)*grau/2);
		    M4[i] = malloc(sizeof(int)*grau/2);
		    M5[i] = malloc(sizeof(int)*grau/2);
		    M6[i] = malloc(sizeof(int)*grau/2);
		    M7[i] = malloc(sizeof(int)*grau/2);	
		}	
	}
    
    if(grau <= 2)
	{
   		for(i = 0; i < grau; i++)
		{
			for(j = 0; j < grau; j++)
			{
				C[i][j] = 0;
				for(k = 0; k < grau; k++)
					C[i][j] += A[i][k] * B[k][j];
			}
		}
	
		{//Libera espaços	
 	    	for(i = 0; i < grau/2; i++)
			{
				free[i](A11);
			    free[i](A12);
			    free[i](A21);
			    free[i](A22);
			    free[i](B11);
			    free[i](B12);
			    free[i](B21);
			    free[i](B22);
			    free[i](M1);
			    free[i](M2);
			    free[i](M3);
			    free[i](M4);
			    free[i](M5);
			    free[i](M6);
			    free[i](M7);
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

	for(i = 0; i < grau/2; i++)
    {
        for(j = 0; j < grau/2; j++)
        {
            A11[i][j] = A[i]         [j];
            A12[i][j] = A[i+(grau/2)][j];
            A21[i][j] = A[i]         [j+(grau/2)];
            A22[i][j] = A[i+(grau/2)][j+(grau/2)];
        }            
    }    

    strassen(soma(A11, A22, grau/2), soma(B11, B22, grau/2), M1, grau/2);
    strassen(soma(A21, A22, grau/2), B11, M2, grau/2);
    strassen(A11, subtrai(A11, A22, grau/2), M3, grau/2);
    strassen(A22, subtrai(A21, A11, grau/2), M4, grau/2);
    strassen(soma(A11, A12, grau/2), B22, M5, grau/2);
    strassen(subtrai(A21, A11, grau/2), soma(B11, B12, grau/2), M6, grau/2);
    strassen(subtrai(A12, A22, grau/2), soma(B21, B22, grau/2), M7, grau/2);	

	{//Libera espaços
		for(i = 0; i < grau/2; i++)
			{
				free[i](A11);
			    free[i](A12);
			    free[i](A21);
			    free[i](A22);
			    free[i](B11);
			    free[i](B12);
			    free[i](B21);
			    free[i](B22);
			    free[i](M1);
			    free[i](M2);
			    free[i](M3);
			    free[i](M4);
			    free[i](M5);
			    free[i](M6);
			    free[i](M7);
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
	int n = 0;
	int i, j;
	int **A, **B, **C;
	
	printf("Entre com o grau das matrizes.\n");
	scanf("%d", &n);
	
	printf("Teste0\n");
	
	A = malloc(sizeof(int)*n);
	B = malloc(sizeof(int)*n);
	C = malloc(sizeof(int)*n);
	
	for(i = 0; i < n; i++)
	{
		A[i] = malloc(sizeof(int)*n);
		B[i] = malloc(sizeof(int)*n);
		C[i] = malloc(sizeof(int)*n);		
	}	
	
	printf("Teste1\n");
	
	srand(time(NULL));
	
	printf("Teste2\n");
			
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			A[i][j] = 0;
			B[i][j] = 0;
		}			
	}	
	
	printf("Teste3\n");
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			A[i][j] = rand()%5;
			B[i][j] = rand()%5;
		}			
	}	

	printf("Teste4\n");
	
	strassen(A,B, C, n);
	
	printf("Teste5\n");
	
	free(A);
	free(B);
	free(C);
	
	printf("Teste6\n");
	
	return 0;
}