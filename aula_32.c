/*
Escreva um programa para simular a rolagem de dois dados.
Neste programa, vc deve rolar os dois dados 36.000 vezes e:
a) imprimir quantas vezes cada arranjo ocorreu;
b) imprimir a soma dos dados mais frequente;
c) imprimir o arranjo mais frequente;

ex
a)          --> USAR INDICE <--> MATRIZ 
(1,1): 34
(1,2): 6      
...
(6,6): 35

b)
2: 34
3: 63
...
12: 35
-> 7

c)
->(1,3)
*/

//VETORES ->1 DIMENSÃO 
//MATRITEZ ->POSSO ADICIONAR 1 DIMENSÃO A MAIS

#include <stdio.h>
#include <stdlib.h>

#define NFACES 6
#define NSOMAS NFACES+NFACES-1
#define NROLLS 36000

//funcao para zerar a matriz inteira
void zeraMatriz (int M[NFACES][NFACES], int n, int m)
{
	int i=0;
	int j=0;
	
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			M[i][j] = 0;
		}
	}
}
//para passar matrizes como parametro, diferente dos vetores,
//é preciso especificar o numero de posicoes da segunda dimensao 

//funcao para rolar os dados
int rolaDado ()
{
	return rand()%NFACES;
	//gera um numero aleatorio entre 0 e 5
	//(fica mais fácil para acessar na matriz 
}

//funcao para imprimir a matriz
void imprimeMatriz (int M[NFACES][NFACES], int n, int m)
{
	int i=0;
	int j=0;
	
	for (int i=0; i < n; i++)
	{
		for (int j=0; j < m; j++)
		{
			printf("%5d", M[i][j]);
		}
		printf("\n");
	}
}

//funcao para zerar o vetor
void zeraVetor (int v[], int n)
{
	int i=0;
	for (int i=0; i < n; i++)
	{
		v[i] = 0;
	}
}

//funcao para imprimir o vetor
void imprimeVetor (int v[], int n)
{
	int i=0; 
	for (int i=0; i<n; i++)
	{
		printf("%d ", v[i]);
	}
	printf("\n");
}


int main ()
{
	//criando uma matriz com 6 lnhas e 6 colunas
	int M[NFACES][NFACES];
	
	//para zerar a primeira posicao da matriz
	//M[0][0] = 0;
	
	//funcao para zerar a matriz inteira
	zeraMatriz (M, NFACES, NFACES);
	
	int i=0;
	int d1=0;
	int d2=0;
	
			//vetor para armazenar as contagens das somas
			int somas[NSOMAS];
			
			//funcao para zerar o vetor
			zeraVetor (somas, NSOMAS);
	
	//funcao para contabilizar as 36 mil rolagens dos dados
	for (int i=0; i < NROLLS; i++)
	{
		d1 = rolaDado();
		d2 = rolaDado();
		M[d1][d2]++;
		somas[d1+d2] = somas[d1+d2] + 1;
	}
	
	//funcao para imprimir a matriz
	imprimeMatriz (M, NFACES, NFACES);
	
	//LETRA A PRONTA
	
	//agora quero calcular a soma de todas as rolagens feitas
	
			//vetor para armazenar as contagens das somas
			//int somas[11];
			
			//funcao para zerar o vetor
			//zeraVetor (somas, NSOMAS);
	
	// vou colocar somas [d1+d2]++; no 'for' da rolagem dos dados
	//e passar a declaracao do somas[11] para cima desse for
	
	printf("\n Vetor das somas: ");
	
	//funcao para imprimir o vetor
	imprimeVetor(somas, NSOMAS);
	
	//agora quero contar qual é a posição mais frequente 
	
	/*algoritmo para um i navegar entre o tamanho das somas 
	e atualizar a variavel maior_i sempre que chegar em um
	número maior que ele */
	int maior_i=0;
	
	for (int i=0; i < NSOMAS; i++)
	{
		if (somas[i] > somas[maior_i])
		{
			maior_i = i;
		}
	}
	
	printf("\n Soma mais frequente: %d", maior_i+2);
	/*+2 pq a gente estava tratando o 1 do dado como 0
	e o 6 como 5, pois assim é mais fácil de acessar 
	e contabilizar nas matrizes */
	
	//LETRA B PRONTA
	
	//agora quero imprimir qual o arranjo mais frenquente
	//ou seja, a celula da matriz com o maior valor
	
	int maior_j=0;
	maior_i=0;
	int j=0;
	
	//mesma logica de algoritmo de navegaçao pela matriz
	for (int i=0; i < NFACES; i++)
	{
		for (j=0; j < NFACES; j++)
		{
			if (M[i][j] > M[maior_i][maior_j])
			{
				maior_i = i;
				maior_j = j;
			}
		}
	}
	
	printf("\nArranjo mais frequente: %d, %d (%d)\n", (maior_i+1), (maior_j+1), M[maior_i][maior_j]);
	
	return 0;
}