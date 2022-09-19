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

