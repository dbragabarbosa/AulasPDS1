/*Você recebeu um arquivo cartelas.txt contendo 1 milhão de apostas feitas na mega-sena. Neste exercício, você deve verificar duas coisas. 
Primeiro, conte e imprima o número de cartelas que foram vencedoras. Os números sorteados foram: 6, 9, 22, 23, 48, 52. 
Depois, à título de curiosidade, você deve contar quantas pessoas apostaram nos números do seriado Lost, que são: 4, 8, 15, 16, 23, 42. */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define INFINITO 2000000000



void troca (int v[], int i, int j)
{
	int aux;
	aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

void ordenar_por_selecao (int x[], int n)
{
	int menor, pos;
	int i, k = 0;
	
	while (k < n)
	{
		menor = INFINITO;
		for (i=k; i<n; i++)
		{
			if (x[i]< menor)
			{
				menor = x[i];
				pos = i;
			}
			troca(x, k, pos);
			k++;
		}
	}
}






int main ()
{
	int i;
	int num_cartela = 1;
	
	int cartela_atual[6];
	int cartela_venc[6] = {6, 9, 22, 23, 48, 52};
	int cartela_lost[6] = {4, 8, 15, 16, 23, 42};
	
	FILE *arq, *arq_aux;
	arq = fopen("cartelas.txt", "r");
	arq_aux = fopen("auxiliar.txt", "w");
	
	while (feof(arq) == 0)
	{
		int cont;
		
		fprintf(arq_aux, "Ordenada: ");
		
		for (i=0; i<6; i++)
		{
			fscanf(arq, "%d ", &cartela_atual[i]);
		}
		
		ordenar_por_selecao(cartela_atual, 6);
		
		for (i=0; i<6; i++)
		{
			fpritnf(arq_aux, "%d ", cartela_atual[i]);
		}
		
		fpritnf(arq_aux, "\n");
		
		
		for (cont=0; cont<6; cont++)
		{
			if (cartela_atual[cont] != cartela_venc[cont])
			{
				break;
			}
		}
		
		if (cont == 6)
		{
			printf("\nA cartela %d eh vencedora.", num_cartela);
		}
		
		
		for (cont=0; cont<6; cont++)
		{
			if (cartela_atual[cont] != cartela_lost[cont])
			{
				break;
			}
		}
		
		if (cont == 6)
		{
			printf("\nA cartela %d eh igual aos ep de lost.", num_cartela);
		}
		
		
		num_cartela++;
	}


	
	
	
	
	fclose(arq);
	fclose(arq_aux);
	return 0;
}