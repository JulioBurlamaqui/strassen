#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv[])
{
	if(argc == 1)
	{
		int n = 0;
		int i, j, k;
		
		printf("Entre com o grau das matrizes.\n");
		scanf("%d", &n);
		
		int A[n][n], B[n][n], C[n][n];
		
		srand(time(NULL));
				
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < n; j++)
			{
				A[i][j] = 0;
				B[i][j] = 0;
			}			
		}	
		
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < n; j++)
			{
				A[i][j] = rand()%5;
				B[i][j] = rand()%5;
			}			
		}	
		
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < n; j++)
			{
				C[i][j] = 0;
				for(k = 0; k < n; k++)
				{
					C[i][j] += A[i][k] * B[k][j];
				}
			}
		}
		
		printf("%d  %d\n%d  %d\n\n", A[0][0], A[0][1], A[1][0], A[1][1]);
		printf("%d  %d\n%d  %d\n\n", B[0][0], B[0][1], B[1][0], B[1][1]);	
		printf("%d  %d\n%d  %d\n\n", C[0][0], C[0][1], C[1][0], C[1][1]);
		
		return 0;
	}
	else{		
		int n = atoi(argv[2]);
		int i, j, k;
		
		int A[n][n], B[n][n], C[n][n];
		
		srand(time(NULL));
				
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < n; j++)
			{
				A[i][j] = 0;
				B[i][j] = 0;
			}			
		}	
		
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < n; j++)
			{
				A[i][j] = rand()%5;
				B[i][j] = rand()%5;
			}			
		}	
		
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < n; j++)
			{
				C[i][j] = 0;
				for(k = 0; k < n; k++)
				{
					C[i][j] += A[i][k] * B[k][j];
				}
			}
		}
		
		printf("%d  %d\n%d  %d\n\n", A[0][0], A[0][1], A[1][0], A[1][1]);
		printf("%d  %d\n%d  %d\n\n", B[0][0], B[0][1], B[1][0], B[1][1]);	
		printf("%d  %d\n%d  %d\n\n", C[0][0], C[0][1], C[1][0], C[1][1]);
		
		return 0;
	}
}

void separaMatriz(int* A)
{
	int grau = sizeof(A[0])/4 // Pegando o grau da matriz com sizeof de uma linha ou coluna depois dividindo por 4 por ser inteiro
	
	if(grau > 2)
	{
		int A11[grau/2][grau/2], A12[grau/2][grau/2], A21[grau/2][grau/2], A22[grau/2][grau/2];
		
		for(i = 0; i < grau/2; i++)
		{
			for(j = 0; j < grau/2; j++)
			{
				A11[i][j] = 0;
				A12[i][j] = 0;
				A21[i][j] = 0;
				A22[i][j] = 0;
			}			
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
		separaMatriz(A11);
		separaMatriz(A12);
		separaMatriz(A21);
		separaMatriz(A22);
	}
	else
	{
			  		
	}
}