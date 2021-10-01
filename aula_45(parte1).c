//VIDEOAULA #45 - PARTE 1

//recursividade, (funções que chamam elas mesmas), normalmente são funções pequenas

//toda função recursiva tem que ter uma condição de parada (ou caso trivial)
//caso contrário, a função vai empilhar operações na pilha de execuções até a memória disponível acabar

//EXEMPLO DE UMA FUNÇÃO RECURSIVA(FAZ UMA CHAMADA PRA ELA MESMA) --> void foo
#include <stdio.h>

void foo(int a)
{
	if (a<0)
		return;
	//foo(a-1);  ---->> inverte a ordem impressa
	printf("\n%d", a);
	foo(a-1);
}


//n + n-1 + n-2 + ... + 1
int soma (int n)
{
	if (n<=0)
		return 0;
	return n + soma(n-1);
}

int main ()
{
	int a=3;
	foo(a);
	printf("\nsoma: %d", soma(a));
	return 0;
}
