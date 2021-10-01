//VIDEOAULA #40 - Arquivos com dados numéricos


//LEITURA E ESCRITA DE DADOS DE ARQUIVOS QUE TEM DADOS NUMÉRICOS
//tipo da variavel -> FILE *arq
//abrir o arquivo -> fopen("nome_do_arquivo", ""modo de abertura desejado");
//leitura de dados -> fscanf (nome_do_arquivo, "  ",    )
//para escrever em um novo arquivo -> fprintf (nome_do_arquivo, "  ",    )
//terminou o processamento dos arquivos -> fclose (nome_do_arquivo);

/*
********* MOTIVAÇÃO POR TRAZ DO USO DE ARQUIVOS

1) Persistência de informações
posso gravar as informações de programas em um arquivo

2) Grandes volumes de dados

3)Entrada de dados
vamos poder armazenar entradas de dados


*/


/*
Crie um programa para processar o arquivo "matrizes_float.txt" e:
a) imprimir as duas matrizes 
b) imprimir a soma das duas matrizes
c) armazenar a soma das matrizes no arquivo "somaMatrizes.txt"
*/



#include <stdio.h>


#define MAXTAM 100


//funcao para imprimir cada uma das matrizes
void imprimeMatriz (float M[][MAXTAM], int n, int m)
{
	int i=0;
	int j=0;
	
	for (i=0; i<n; i++)
	{
		for (j=0; j<m; j++)
		{
			printf("%.1f", M[i][j]);
		}
		printf("\n");
	}
	
}



int main ()
{
	//como ler as informações de um arquivo 
	FILE *arq, *arqw;
	//arq é o nome que eu dei
	
	//carregar o arquivo da memória
	arq = fopen("matrizes_float.txt", "r");
	arqw = fopen("somaMatrizes.txt", "w");
	
	//() -> duas strings. A 1: Nome do arquivo, 2: Modo pelo qual vou abrir o arquivo
	//opções de abertura do arquivo: r, w, a
	//r: leitura de dados (read)
	//w: escrita no arquivo (abro (ou crio se ainda não existe) , limpo e escrevo no arquivo) 
	//a: adicionar linhas ao final do arquivo (append)
	
	//fopen -> file open
	//se está na mesma pasta, eu não preciso indicar o caminho junto com o nome do arquivo
	
	
	//agora vou fazer a leitura de dados nesse arquivo escolhido
	//é como se eu tivesse digitado tudo que está no arquivo no prompt para o scanf 
	
	
	int n=0;
	int m=0;
	
	//fazendo sem ler dados de arquivos
	//scanf("%d %d", &n, &m);
	
	//lendo os dados do arquivo
	fscanf(arq, "%d %d", &n, &m);
	
	//EX: leer dados do teclado
	//fscanf(stdin, "%d %d", &n, &m);
	
	//O consumo de dados é feito de maneira sequencial
	
	printf("\n%d %d", n, m);
	
	
	//agora vou ler os dados das matrizes e depois imprimi-las
	int i=0;
	int j=0;
	float M1[MAXTAM][MAXTAM];
	float M2[MAXTAM][MAXTAM];
	
	for (i=0; i<n; i++)
	{
		for (j=0; j<m; j++)
		{
			fscanf(arq, "%f", &M1[i][j]);
		}
	}
	
	printf("\nMatriz 1:\n");
	imprimeMatriz(M1, n, m);
	
	for (i=0; i<n; i++)
	{
		for (j=0; j<m; j++)
		{
			fscanf(arq, "%f", &M2[i][j]);
			//para ja calcular a soma
			M1[i][j] += M2[i][j];
		}
	}
	
	printf("\nMatriz 2:\n");
	imprimeMatriz(M2, n, m);
	
	printf("\nMatriz soma:\n");
	imprimeMatriz(M1, n, m);
	
	//a maneira que estou usando para processar esse arquivo depende fundamentalmente do formato que esse arquivo está armazenado
	
	//c) armazenar a soma das matrizes no arquivo "somaMatrizes.txt"
	
	for (i=0; i<n; i++)
	{
		for (j=0; j<m; j++)
		{
			fprintf(arqw, "%.1f", M1[i][j]);
		}
		
		fprintf(arqw, "\n");
	}
	
	
	//SEMPRE QUE ABRIR UM ARQUIVO, TEMOS QUE FECHA-LO TAMBÉM
	fclose(arq);
	fclose(arqw);
	
	
	return 0;
}