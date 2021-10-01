//VIDEOAULA #45 - PARTE 2
//aprendendo outras funções recursivas

//SEMPRE PENSE EM DOIS ASPECTOS AO UTILIZAR FUNÇÕES RECURSIVAS
//1)caso trivial (condiçao de parada)  --> quando a função retorna algo, em que ela não prossegue com a chamada recursivas
//2)passo recursivo 


/*EXEMPLOS DE FUNÇÕES RECURSIVAS                          ----> tente fazer no papel as recursivas primeiro e depois passar para c

1)fatorial  ---> fat(n) --- 1,           se n<=1
                        --- n*fat(n-1),  caso contrário
						
*/

int fat (int n)
{
	if (n <= 1)
		return 1;
	return n * fat(n-1);
}

/*EXEMPLOS DE FUNÇÕES RECURSIVAS                          ----> tente fazer no papel as recursivas primeiro e depois passar para c

2)fibonacci   ---> fib(n) ===         1,          se n<=2
						  === fib(n-1)+fib(n-2),  caso contrário
*/

//implementação recursiva
int fib (int n)
{
	if (n <= 2)
		return 1;
	return fib(n-1) + fib(n-2);
}                                         // ------> FUNÇÃO POUCO EFICIENTE === usa muita memória, são necessárias muitas operações


//implementação iterativa
int fib2 (int n)
{
	int a = 0;
	int b = 1;
	int i = 1;
	int c = a+b;
	
	while (i < n)
	{
		//printf("\nexecutando fib(%d)...", c);
		c = a + b;
		a = b;
		b = c;
		i++;
	}
	
	return c;
}                                   // -----> FUNÇÃO MAIS EFICIENTE 




//A RECURSIVIDADE MUITAS VEZES TORNA O ALGORITMO MAIS SIMPLES, ENTRETANTO, NEM SEMPRE UM ALGORITMO RECURSIVO É O MELHOR CAMINHO PARA SE RESOLVER UM PROBLEMA




#include <stdio.h>

int main ()
{
	int n=0;
	scanf("%d", &n);
	printf("\nfat: %d", fat(n));
	printf("\nfib %d", fib(n));
}