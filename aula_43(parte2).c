//COMO ALOCAR UMA MATRIZ DINAMICAMENTE USANDO MALLOC


#include <stdio.h>
#include <stdlib.h>

/* quero criar essa matriz dinamicamente
0 0
0 0
0 0
(n=3, m=2)
*/



//função mais dificl
void alocaMatriz (int ***M, int n, int m)
{
	//???????
}

//FUNÇÃO PRONTA
int **alocaMatriz (int n, int m)
{
	int i=0, j=0;
	
	int **M = (int**)malloc(n * sizeof(int*));
	
	for (i=0; i<n; i++)
	{
		M[i] = (int*)malloc(m * sizeof(int));
	}
	
	//para preencher a matriz com zeros
	for (i=0; i<n; i++)
	{
		for (j=0; j<m; j++)
		{
			M[i][j] = 0;
		}
	}
	
	return M;
}

void liberaMatriz (int **M, int n, int m)
{
	int i=0;
	
	for (i=0; i<n; i++)
	{
		free(M[i]);
	}
	free(M);
}

void imprimeMatriz (int **M, int n, int m)
{
	int i=0, j=0;
	
	for (i=0; i<n; i++)
	{
		for (j=0; j<m; j++)
		{
			printf("%3d ", M[i][j]);
		}
		printf("\n");
	}
	
}


int main ()
{
	//matriz criada de forma estática
	//int M[100][100];
	
	//como aramazenar uma matriz de forma dinâmica?
	
	//uma matriz é um ponteiro para ponteiro
	//M é um ponteiro do tipo int que aponta para outro inteiro do tipo int
	int **M = NULL;
	
	int n=0, m=0, i=0;
	scanf("%d %d", &n, &m);
	
	M = alocaMatriz(n, m);
	imprimeMatriz(M, n, m);
	liberaMatriz(M, n, m);
	
	
	/* INUTILIZADO PELAS FUNÇÕES
	
	//a matriz é um conjunto de n vetores de m valores
	
	//primeiro vou reservar o espaço para n ponteiros para inteiros
	M = (int**)malloc(n * sizeof(int*));
	
	//agora vou alocar os espaços para m inteiros
	
	/		*M = (int*)malloc(m * sizeof(int));
			*(M+1) OU  M[1] = (int*)malloc(m * sizeof(int));
	/
	
	for (i=0; i<n; i++)
	{
		M[i] = (int*)malloc(m * sizeof(int));
	}
	
	
	//agora para desalocar a memoria de toda a matriz 
	for (i=0; i<n; i++)
	{
		free(M[i]);
	}
	free(M);
	
	*/
	
	
	return 0;
}