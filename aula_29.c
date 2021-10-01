/*
- Os preços dos produtos vendidos nessa loja variam de R$5,00 
a R$100,00
- Cada cliente compra apenas um produto.
- O número e o preço de cada produto, o número de clientes e os 
produtos comprados devem ser gerados aleatoriamente.
- No máximo 200 produtos.
- No máximo 50 clientes.
*/

#include <stdio.h>
#include <stdlib.h>


#define MIN_PRECO 5
#define MAX_PRECO 100
#define MAX_PRODUTOS 200
#define MAX_CLIENTES 50 

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
	return (float)rand()/ RAND_MAX;
}

//FUNCAO PARA GERAR ALEATORIOS PONTO FLUTUANTE ENTRE MIN E MAX
float randFloat (float min, float max)
{
	return min + randf()*(max-min);
}

int main ()
{
	int i=0;
	
	//gerando uma "tabela" pra ser colocado os precos dos produtos
	float precos[MAX_PRODUTOS];
	//ex:precos[1] = 84;
	
	//gerando aleatoriamente o numero de produtos
	int n_prod = randInt(1, MAX_PRODUTOS);
	
	//atribuindo os precos dos produtos de forma aleatoria
	for (i=0; i<n_prod; i++)
	{
		precos[i] = randInt(MIN_PRECO, MAX_PRECO);
	}
	 
	//gerando as compras dos clientes de forma aleatoria
	int n_clientes = randInt(1, MAX_CLIENTES);
	
	//criando uma estrutura para armazenar as compras dos clientes
	int compras[MAX_CLIENTES];
	
	//preenchendo aletoriamente as compras feitas pelos clientes
	for (i=0; i<n_clientes; i++)
	{
		compras[i] = random(n_prod);
	}
	
	//calculando o faturamento
	float faturamento=0;
	
	//varrendo a tabela de compras
	int prod=0;
	float preco=0;
	
	for(i=0; i<n_clientes; i++)
	{
		//int prod = compras[i];
		//float preco = precos[prod];
		faturamento += precos[compras[i]];
	}
	
	printf("\nFaturamento: %f \n", faturamento);
	
	return 0;
}