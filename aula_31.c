//ORDENAÇÃO POR CONTAGEM

/*
Uma empresa armazena em uma variável indexada os números dos 
cheques emitidos em um dia pelo setor financiero.

Considere que os números dos cheques são valores inteiros e de
1 a 100 e que os chequessão emitidos em uma ordem aleatória.

Ao final do dia, para facilitar o controle, a empresa precisa 
ordenar estes dados em ordem crescente
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXCHEQUES 10     

//FUNCAO DE ORDENAÇÃO POR CONTAGEM
void ordcont (int vet[], vet_ord[], int n)
{
	int cont[MAXCHEQUES];
	int j =0;
	
	for (j=0; j<n; j++)
	{
		cont[j] = 0;
		for(i=0; i<n; i ++)
		{
			if(vet[i] < vet[j])
			{
				cont[j]++;
			}
		}
		vet_ord[cont[j]] = vet[j];
	}
}

//FUNCAO PARA GERAR UM ALEATORIO ENTRE 0 E n-1
int random (int n)
{
	return rand()%n;
}

//FUNCAO PARA GERAR ALEATORIOS ENTRE MIN E MAX (INCLUSIVE)
int randInt (int min, int max)    //min=5, max=10
{
	return min + random(max - min + 1);
}

//FUNCAO PARA GERAR ALEATORIOS PONTO FLUTUANTE ENTRE 0 E 1
float randf ()
{
	return (float)rand()/ 32767;
}

//FUNCAO PARA GERAR ALEATORIOS PONTO FLUTUANTE ENTRE MIN E MAX
float randFloat (float min, float max)
{
	return min + randf()*(max-min);
}

//FUNCAO PARA IMPRIMIR O VETOR
void imprimeVet (int v[], int n)
{
	int i=0;
	for(i=0; i<n; i++)
	{
		printf("\n%d \n", v[i]);
	}
}

//FUNCAO PARA VER SE JÁ EXISTE O CHEQUE
int existe (int k, int v[], int n)
{
	int i=0;
	
	for (i=0; i<n; i++)
	{
		if(k == v[i])
		{
			return 1;
		}
	}
	return 0;
}

int main ()
{
	int vet[MAXCHEQUES];
	
	//numero de cheques gerados em um dia
	int n= randInt(1,MAXCHEQUES);
	printf("\nn: %d \n", n);
	
	//iniciando processo de geração desses números
	int i=0;
	int cheque=0;
	
	while (i<n);
	{
		cheque = randInt(1,MAXCHEQUES);
		if (!existe(cheque, vet, i))
		{
			vet[i] = cheque;
			i++;
		}
	}
	
	//printf("\ncheques: ");
	//imprimindo o vetor
	//imprimeVet (vet, n);
	
	//ordenando o vetor
	//int vet[MAXCHEQUES];
	int cont[MAXCHEQUES];
	int vet_ord[MAXCHEQUES];
	/*
	int j =0;
	
	for (j=0; j<n; j++)
	{
		cont[j] = 0;
		for(i=0; i<n; i ++)
		{
			if(vet[i] < vet[j])
			{
				cont[j]++;
			}
		}
		vet_ord[cont[j]] = vet[j];
	}
	*/
	
	
	ordcont (vet, vet_ord, n);
	
	printf("\ncheques ordenados: ");
	//imprimindo o vetor
	imprimeVet (vet_ord, n);
	
	return 0;
}