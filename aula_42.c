//VIDEOAULA #42 - Arquivos com dados textuais


/*
Processar arquivo PDS1.dat e:
a) imprimir a média de todas as notas
b) gerar um arquivo com os alunos que vão para especial (soma das notas < 12)
c) imprimir o nome e a nota do melhor alunos
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXTAM 100

int main ()
{
	FILE *arq = fopen("PDS1.dat", "r");
	char linha[MAXTAM];
	
	FILE *arq_esp = fopen("Especial.dat", "w");
	
	int mat=0;    //mat --> matricula
	char *nome = NULL;
	float nota1=0;
	float nota2=0;
	
	float soma=0;
	int count_notas=0;
	
	float maior_nota = -1;
	char nome_melhor[MAXTAM];
	
	//funcao que retorna se o arquivo acabou ou não -> 0=Não acabou
	//enquanto esse arquivo não acabou...
	while (!feof(arq))
	{
		fgets(linha, MAXTAM, arq);
		//printf("%s\n", linha);
		
		//3,Francisco Ferdinando,8.5,4.8
		
		mat = atoi(strtok(linha, ","));  //atoi --> converte uma string para inteiro
		nome = strtok(NULL, ",");
		nota1 = atof(strtok(NULL, ","));   //atof --> converte uma string para float 
		nota2 = atof(strtok(NULL, ","));
		
		printf("%d %s %.1f %.1f\n", mat, nome, nota1, nota2);
		
		if (nota1 + nota2 < 12)
		{
			fprintf(arq_esp, "%s, %.2f\n", nome, nota1+nota2);
		}
		
		if (nota1+nota2 > maior_nota)
		{
			maior_nota = nota1+nota2;
			//funcao para passar texto entre strings
			strcpy(nome_melhor, nome);
		}
		
		soma += nota1 + nota2;
		count_notas += 2;
		
	}
	
	printf("\nMedia: %.2f", soma/count_notas):
	
	printf("\nMelhor aluno: %s (%.1f)", nome_melhor, maior_nota);

	fclose(arq);
	fclose(arq_esp);
	
	return 0;
}