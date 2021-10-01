//ESTRUTURAS


/*
Leia as informações de peso, altura e sexo de uma pessoa e informe se ela pode
engordar ou emagrecer a partir do seu peso ideal, que é calculado da seguinte forma:
Homem: (Altura-100)X0.90
Mulher: (Altura-100)X0.85
*/

//ex de motivação para usar estruturas
/*tenho 3 variaveis (peso, altura e sexo) que estão associadas
a mesma entidade (uma pessoa) e não há nada no código mostrando
que essas variáveis dizem respeito à mesma entidade
*/

//CRIANDO UMA ESTRUTURAS
typedef struct Pessoa
{
	float altura;
	float peso;
	char sexo;
} Pessoa;
//Pessoa --> nome do meu tipo de dado
//{} --> campos que esse tipo de dados composto terá
//criei um tipo de dado composto
//AGORA EXISTE O TIPO DE DADO 'STRUCT PESSOA' (igual int, float...)
//agora, uso p.altura, p.sexo e p.peso para acessar cada um desses campos


/*OUTRA MANEIRA DE UTILIZAR OS TIPOS DE DADOS COMPOSTOS
TYPEDEF --> DEFINIR UM NOVO TIPO DE DADOS

typedef int inteiro --> vou poder chamar agora o tipo de dados int como 'inteiro'
ele nao sobrepõe, cria um novo

ENTAO, vou colocar typedef antes de struct e 'Pessoa' depois do } do struct
--> exatamente igual fazer typedef int inteiro

não vai ser mais necessario escrever o struct na declaração de Pessoa nem na chamada da funçao
*/



#include <stdio.h>
#include <stdlib.h>

//#define 


//funcao para avaliar imprimir o peso ideal e falar se deve emagrecer ou engordar 
void avaliaPesoPessoa (/*struct*/ Pessoa P)
{
	float pesoIdeal = 0;
	
	if (toupper(p.sexo) == 'F')
	{
		pesoIdeal = (p.altura-100)*0.85;
	}
	else 
	{
		pesoIdeal = (p.altura-100)*0.9;
	}
	
	printf("\nPeso ideal: %.2f\n", pesoIdeal);
	
	if (p.peso > pesoIdeal)
	{
		printf("\nPode emagrecer. \n");
	}
	else 
	{
		printf("\nPode engordar. \n");
	}
}

int main ()
{
	/*struct*/ Pessoa p;
	
	scanf("%f %f %c", &p.altura, %p.peso, &p.sexo);
	//associei esssas variaveis a um unico tipo de dado (pessoa)
	
	avaliaPesoPessoa(p);
	
	return 0;
}