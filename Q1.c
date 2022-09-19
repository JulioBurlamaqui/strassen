#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv[])
{
	if(argc == 1) 
	{//Não há -n
		srand(time(NULL));
		
		int grau = 0;
		int i, j, k;
		
		printf("Entre com o grau das matrizes.\n");
		scanf("%d", &grau);
		
		int A[grau][grau], B[grau][grau], C[grau][grau];
				
		for(i = 0; i < grau; i++)
		{
			for(j = 0; j < grau; j++)
			{
				A[i][j] = 0;
				B[i][j] = 0;
			}			
		}	
		
		printf("Entre com os valores de A:\n");
		for(i = 0; i < grau; i++)
		{
			for(j = 0; j < grau; j++)
				scanf("%d", &A[i][j]);
		}
		
		printf("Entre com os valores de B:\n");
		for(i = 0; i < grau; i++)
		{
			for(j = 0; j < grau; j++)
				scanf("%d", &B[i][j]);
		}		
		
		for(i = 0; i < grau; i++)
		{
			for(j = 0; j < grau; j++)
			{
				C[i][j] = 0;
				for(k = 0; k < grau; k++)
				{
					C[i][j] += A[i][k] * B[k][j];
				}
			}
		}
		
		printf("A:\n");
		for(i = 0; i < grau; i++)
		{
			for(j = 0; j < grau; j++)
				printf("%d   ", A[i][j]);
			printf("\n");
		}
		
		printf("\n\nB:\n");
		for(i = 0; i < grau; i++)
		{
			for(j = 0; j < grau; j++)
				printf("%d   ", B[i][j]);
			printf("\n");
		}
		
		printf("\n\nC:\n");
		for(i = 0; i < grau; i++)
		{
			for(j = 0; j < grau; j++)
				printf("%d   ", C[i][j]);
			printf("\n");
		}
		
		return 0;
	}
	else
	{//Foi passado o argumento -n				
		srand(time(NULL));
	
		int grau = atoi(argv[2]);
		int i, j, k;
		
		int A[grau][grau], B[grau][grau], C[grau][grau];

				
		for(i = 0; i < grau; i++)
		{
			for(j = 0; j < grau; j++)
			{
				A[i][j] = 0;
				B[i][j] = 0;
			}			
		}	
		
		for(i = 0; i < grau; i++)
		{
			for(j = 0; j < grau; j++)
			{
				A[i][j] = rand()%5;
				B[i][j] = rand()%5;
			}			
		}	
		
		for(i = 0; i < grau; i++)
		{
			for(j = 0; j < grau; j++)
			{
				C[i][j] = 0;
				for(k = 0; k < grau; k++)
				{
					C[i][j] += A[i][k] * B[k][j];
				}
			}
		}
		
		printf("A:\n");
		for(i = 0; i < grau; i++)
		{
			for(j = 0; j < grau; j++)
				printf("%d   ", A[i][j]);
			printf("\n");
		}
		
		printf("\n\nB:\n");
		for(i = 0; i < grau; i++)
		{
			for(j = 0; j < grau; j++)
				printf("%d   ", B[i][j]);
			printf("\n");
		}
		
		printf("\n\nC:\n");
		for(i = 0; i < grau; i++)
		{
			for(j = 0; j < grau; j++)
				printf("%d   ", A[i][j]);
			printf("\n");
		}
		
		return 0;
	}
}

