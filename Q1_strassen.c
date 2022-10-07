#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
			C[i][j] = A[i][j] + B[i][j];
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
			C[i][j] = A[i][j] - B[i][j];
	}

	return C;	
}

void multiplica(int **A, int **B, int **C, int grau)
{//Multiplica pelo método tradicional duas matrizes e modifica a resultado. Não retorna nada.
	int i, j, k;
	
	for(i = 0; i < grau; i++)
	{
		for(j = 0; j < grau; j++)
		{
			for(k = 0; k < grau; k++)
				C[i][j] += A[i][k] * B[k][j];
		}
	}

	return;
}


void strassen(int **A, int **B, int **C, int grau)
{
    int i, j;
    
	if(grau <= 2) 
	{//Strassen híbrido
		multiplica(A, B, C, grau);

        return;
    }
    
    int **A11, **A12, **A21, **A22;
    int **B11, **B12, **B21, **B22;
    int **C11, **C12, **C21, **C22;
    int **M1, **M2, **M3, **M4, **M5, **M6, **M7;
    
    {//Aloca dinamicamente
	    A11 = malloc(sizeof(int*)*grau/2);
	    A12 = malloc(sizeof(int*)*grau/2);
	    A21 = malloc(sizeof(int*)*grau/2);
	    A22 = malloc(sizeof(int*)*grau/2);
	    B11 = malloc(sizeof(int*)*grau/2);
	    B21 = malloc(sizeof(int*)*grau/2);
	    B12 = malloc(sizeof(int*)*grau/2);
	    B22 = malloc(sizeof(int*)*grau/2);
	    C11 = malloc(sizeof(int*)*grau/2);
		C12 = malloc(sizeof(int*)*grau/2);
	    C21 = malloc(sizeof(int*)*grau/2);
	    C22 = malloc(sizeof(int*)*grau/2);
	    M1 = malloc(sizeof(int*)*grau/2);
	    M2 = malloc(sizeof(int*)*grau/2);
	    M3 = malloc(sizeof(int*)*grau/2);
	    M4 = malloc(sizeof(int*)*grau/2);
	    M5 = malloc(sizeof(int*)*grau/2);
	    M6 = malloc(sizeof(int*)*grau/2);
	    M7 = malloc(sizeof(int*)*grau/2);
	
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
    strassen(A11, subtrai(B12, B22, grau/2), M3, grau/2);
    strassen(A22, subtrai(B21, B11, grau/2), M4, grau/2);
    strassen(soma(A11, A12, grau/2), B22, M5, grau/2);
    strassen(subtrai(A21, A11, grau/2), soma(B11, B12, grau/2), M6, grau/2);
    strassen(subtrai(A12, A22, grau/2), soma(B21, B22, grau/2), M7, grau/2);	
    
    C11 = soma(subtrai(soma(M1, M4, grau/2), M5, grau/2), M7, grau/2);
    C12 = soma(M3, M5, grau/2);
    C21 = soma(M2, M4, grau/2);
    C22 = soma(soma(subtrai(M1, M2, grau/2), M3, grau/2), M6, grau/2);  

	for(i = 0; i < grau/2; i++)
	{//Reagrupa as submatrizes resultado na matriz resultado
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
	if(argc == 1) 
	{//Não há argumento -n
		int **A, **B, **C;  //Cria apontadores para matrizes
		int grau;  //Grau das matrizes quadradas
		int i, j;  // Variáveis auxiliares

		printf("Entre com o grau das matrizes.\n");
		scanf("%d", &grau);

		A = malloc(sizeof(int*)*grau);
		B = malloc(sizeof(int*)*grau);
		C = malloc(sizeof(int*)*grau);

		for(i = 0; i < grau; i++)
		{
			A[i] = malloc(sizeof(int)*grau);
			B[i] = malloc(sizeof(int)*grau);
			C[i] = malloc(sizeof(int)*grau);		
		}
		
		printf("Entre com os valores de A:\n");
		for(i = 0; i < grau; i++)
		{//Recebe valores da matriz A do teclado
			for(j = 0; j < grau; j++)
				scanf("%d", &A[i][j]);
		}
		
		printf("Entre com os valores de B:\n");
		for(i = 0; i < grau; i++)
		{//Recebe valores da matriz B do teclado
			for(j = 0; j < grau; j++)
				scanf("%d", &B[i][j]);
		}		

		for(i = 0; i < grau; i++)
		{//Inicializando C
			for(j = 0; j < grau; j++)
				C[i][j] = 0;
		}	
		
		multiplica(A, B, C, grau);

		printf("Tradicional:\n");
		for(i = 0; i < grau; i++)
		{//Imprime a matriz resultado
			for(j = 0; j < grau; j++)
				printf("%d ", C[i][j]);
			printf("\n");
		}

		for(i = 0; i < grau; i++)
		{//Resetando o valor de C para zero
			for(j = 0; j < grau; j++)
				C[i][j] = 0;
		}	

		strassen(A, B, C, grau);
		
		printf("Strassen:\n");
		for(i = 0; i < grau; i++)
		{//Imprime a matriz resultado
			for(j = 0; j < grau; j++)
				printf("%d ", C[i][j]);
			printf("\n");	
		}

		for(i = 0; i < grau; i++)
		{
			free(A[i]);
			free(B[i]);
			free(C[i]);
		}	

		free(A);
		free(B);
		free(C);
		
		return 0;
	}
	else
	{//Foi passado o argumento -n				
		int **A, **B, **C;  //Cria apontadores para matrizes
		int grau = atoi(argv[2]);  //Grau já passado no terminal
		double tempoTradicional = 0.0;  //Variável que armazena o tempo de execução do algoritmo tradicional
		double tempoStrassen = 0.0;  //Variável que armazena o tempo de execução do algoritmo de Strassen
		int i, j;  // Variáveis auxiliares

		A = malloc(sizeof(int*)*grau);
		B = malloc(sizeof(int*)*grau);
		C = malloc(sizeof(int*)*grau);

		for(i = 0; i < grau; i++)
		{
			A[i] = malloc(sizeof(int)*grau);
			B[i] = malloc(sizeof(int)*grau);
			C[i] = malloc(sizeof(int)*grau);		
		}

		srand(time(NULL));  //Inicializando o seed
		
		for(i = 0; i < grau; i++)
		{//Gerando valores aleatórios entre {0, 4} e os alocando nas matrizes A e B
			for(j = 0; j < grau; j++)
			{
				A[i][j] = rand()%5;
				B[i][j] = rand()%5;
			}			
		}	
		
		clock_t begin = clock();
		multiplica(A, B, C, grau);
		clock_t end = clock();

		tempoTradicional += (double)(end - begin) / CLOCKS_PER_SEC;

		printf("O tempo do cálculo pelo método tradicional foi de %f segundos\n\n", tempoTradicional);

		for(i = 0; i < grau; i++)
		{//Resetando o valor de C para zero
			for(j = 0; j < grau; j++)
				C[i][j] = 0;
		}	

		begin = clock();
		strassen(A, B, C, grau);
		end = clock();

		tempoStrassen += (double)(end - begin) / CLOCKS_PER_SEC;

		printf("O tempo do cálculo pelo método de Strassen foi de %f segundos", tempoStrassen);
		
		for(i = 0; i < grau; i++)
		{
			free(A[i]);
			free(B[i]);
			free(C[i]);
		}	

		free(A);
		free(B);
		free(C);

		return 0;
	}
}
