//REVISÃO PARA A PROVA 3 - EXERCÍCIOS DE RECURSIVIDADE 

/*1. Escreva uma função RECURSIVA que receba por parâmetro um ponteiro para uma string e a imprime invertda. 
Se a função receber um ponteiro para a string "bola", a sua função deve imprimir "alob".
Sua função não pode usar loops (for, while, etc).
Dica: lembre-se de uma propriedade de strings que vetores de caracteres não necessariamente possuem.
A sua função deve ter o seguinte protótipo: void strInv (char *str); */

#include <stdio.h>

//bola\0 -> alob
void strInv (char *str)
{
	//condicao de parada:
	//pense -> "Qual é o caso trivial?" aquele que não vou precisar fazer nada
	
	if (*str == '\0')
	{
		return;
	}
	
	//passo recursivo:
	strInv(str+1);
	printf("%c", *str);
}


/*2. Escreva uma função RECURSIVA que recebe como parâmetros um vetor de inteiros v e o seu tamanho n e retorna a soma dos elementos desse vetor v.
Sua função não pode usar loops (for, while, etc). 
Ex: se o vetor for {5, 1, -4, 9} a sua função deve retornar 11.
O seu procedimento deve ter o seguinte protótipo: int somaVet (int v[], int n); */


//v = {5, 1, -4, 9}
int somaVet (int v[], int n)
{
	//condicao de parada:
	//"Qual é o caso em que eu não tenho que prosseguir com a minha recursão? Que eu já sei resolver?"
	
	if (n == 1)
	{
		return v[0];
	}
	
	//passo recursivo:
	//v[n-1] -> ultimo elemento desse vetor
	
	return v[n-1] + somaVet(v, n-1);
	
	
}

/*3.Escreva uma função RECURSIVA para desalocar toda a memória ocupada por uma matriz quadrada n x n.
A sua função recebe como parâmetros o ponteiro para matriz, que obviamente foi alocada dinamicamente, e o seu tamanho n (a matriz tem n colunas e n linhas).
Sua função não pode usar loops (for, while, etc) e deve ter o seguinte protótipo: void freeMatrix (int **M, int n) */


/* Exemplo de matriz aalocada dinamicamente 2x2
M = {F1, F8}
F1 = M[0] = {0, 1}
F8 = M[1] = {2, 3}

*/

void freeMatrix (int **M, int n)
{
	//condicao de parada:
	
	if (n == 0)
	{
		free(M);
		return;
	}
	
	//passo recursivo:
	free(M[n-1]);
	freeMatrix (M, n-1);
}



int main ()
{
	char str[] = "bola";
	strInv(str);
	
	int v[] = {4, 3, 7, -4, 9};
	printf("\n%d", somaVet(v, 5));
	
	return 0;
}






/* 4.Escreva um programa para imprimir todas as hashtags contidas num arquivo tweets.txt contenco tweets.
Um tweet é uma mensagem postada por alguem da plataforma Twiter e uma hashtag é uma palavra que se inicia como o caractere #.
Pra simplificar, considere que todas as ocorrências do caractere # estão associasdas a hashtags. 

Exemplo de arquivo: 

A vida é bela! #gratidao #namaste !!!
Algumas #hashtags aleatorias #para testar o #algoritmo 

O seu programa deve imprimir

#gratidao #namaste
#hashtags #para #algoritmo 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main ()
{
	FILE *arq = fopen("tweets.txt", "r");     // ---> tenho um arquivo tweets.txt aberto com um texto com hashtags
	FILE *arqw = fopen ("hashtags.txt", "w");     //--> criando um arquivo para armazenar 
	
	//vou colocar a primeira linha do arquivo em um vetor, e achar as palavras que tem hashtags para imprimi-las
	
	char linha[1000];
	char *palavra;
	
	while (!feof(arq))
	{
		fgets(linha, 1000, arq);        //--> no vetor linha, agora tenho a primeira linha do arquivo
		
		palavra = strtok (linha, "\n")
		while (palavra != NULL)
		{
			if (palavra[0] == '#')
			{
				fprintf(arqw, "%s ", palavra);
			}
			
			palavra = strtok (NULL, " \n");
		}
		
		fprintf(arqw, "\n")
	}
	
	fclose(arq);
	fclose(arqw);
	
	return 0;
}


/*5. Complete o código abaixo, que descreve uma função de nome matrizEsparsa.
Essa função recebe uma matriz de adjacencias n x n e o valor de n como parâmetros, desaloca essa matriz da memória, e retorna a matris esparsa corerespondente.
Uma matriz de adjacencias n x n é usada para registrar laços de amizades entre n pessoas.
Em uma matriz de adjacencias M, M[i][j] = 1 se a pessoa de código i é amiag da pessoa de código j e M[i][j] = 0, caso contrário.
Uma matriz esparsa ME é uma estrutura mais compacta, em que ME[i][0] registra o número de amigos da pessoa i, ME[i][1] registra o código do seu primeiro amigo,
ME[i][2] o código do segundo amigo, e assim por diante. */


int ** matrizEsparsa (int **M, int n)
{
	int i, j, n_cols, count;
	
	int **ME = ((int**)malloc(n*sizeof(int*));
	
	for (i=0; i<n; i++)
	{
		n_cols = somaVet(M[i], n);
		
		ME[i] = (int*)malloc( (n_cols+1) * sizeof(int) );
		
		ME[i][0] = n_cols;
		
		count = 1;
		
		for (j=0; j<n; j++)
		{
			if (M[i][j])
			{
				ME[i][count] = j;
				count++;
			}
		}
	}
	
	freeMatrix (M, n);
	
	return ME;2
	
}