//#VIDEOAULA #43 - PARTE 1
//INTRODUÇÃO À ALOCAÇÃO DINÂMICA DE MEMÓRIA EM C

#include <stdio.h>
#include <stdlib.h>


int main ()
{
	float x = 0;
	float *p = NULL;
	
	x = 3.14;
	
	//funcao que vai reservar um espaço na memoria correspondente à quantidade de bytes que eu passo como parametro
	//malloc vai encontrar uma sequencia de endereços disponiveis e reservar para que eu possa fazer acesso no meu programa
	//malloc retorna o primeiro endereço dessa sequencia 
	//vou atribuir esse endereço de retorno para o meu ponteiro p
	//vou fazer um typecast para converter o endereço retornado no tipo de dado do meu ponteiro
	p = (float*)malloc( sizeof(float) );
	
	
	*p = 2.72;  //vai para a regiao armazenada pela funcao malloc
	
	printf ("%f", *p);  // = 2.72
	
	//para desalocar o espaço guardado por malloc, usando o ponteiro p
	free(p);
	
	
	return 0;
}


/* MOTIVAÇÕES PARA O USO DA FUNÇÃO MALLOC
- consigo alocar um vetor de tamanho definido definido em tempo de execução 

*/

//FUNÇÃO QUE CRIA UM VETOR V DE FLOATS COM UM TAMANHO DEFINIDO EM TEMPO DE EXECUÇÃO E ZERA SEUS VALORES

//pois float* é o tipo da variavel v que mandei pra função
void aloca (float **x, int n)
{
	*x = (float *)malloc(n*sizeof(float));
	
	int i=0;
	for(i=0; i<n; i++)
	{
		(*x)[i] = 0;
	}
}


int main ()
{
	int i, n = 0;
	
	scanf("%d", &n);
	
	if (n > 0)
	{
		
		//essa atribuição não é suportada pelo gcc
		//float v[n];
		
		//LOGO vamos precisar da alocação dinamica de memoria
		float *v = NULL;
		
		aloca(&v, n);					/*
										v  = (float*)malloc(n* sizeof(float) );
										//v virou um vetor v de floats normal
										
										
										int i=0;
										for (i+0; i<n; i++)
										{
											v[i] = 0;
										}
										*/
		
		free(v);
		
	}
	
	
	return 0;
}