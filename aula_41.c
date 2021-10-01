//VIDEOAULA #41 - Função strtok para separação dos tokens em strings

//COMO PROCESSAR DADOS E INFORMAÇÕES DE ARQUIVOS QUE CONTÉM TEXTO


/*
Exemplo do uso da função strtok para encontrar "tokens" em strings

char *strtok(char *str, const char *delim)

essa função processa uma string, dividindo ela em tokens

EX:
"Pedro Olmo Stancioli\0"
*/

#include <stdio.h>
#include <string.h>     //a função strtok está aqui


int main ()
{
	//vou criar minha string
	char str[] = "Pedro Olmo Stancioli";
	
	//printf("str: %s\n", str);   // ------> Pedro Olmo Stancioli
	
	char *token;
	//criei pois a strtok retorna um ponteiro para char 
	
	token = strtok(str, " ");
	//a strtok precisa de (uma_string, "quais caracteres são responsáveis por dividir essa string em tokens")
	//a strtok vai processar essa string caracter por caracter até encontrar um caracter separador
	//quando encontra o caracter separador, a strtok troca o caracter separador por um \0 e retorna o endereço de memória de onde ele começou o processamento
	
	//printf("str: %s\n", str);   // ------> Pedro
	//printf("token: %s\n", token);   // ------> Pedro
	
	//agora quero pegar o próximo token da string que estou processando
	
	//token = strtok(NULL, " ");
	//o strtok armazena onde ele parou ---> NULL faz ele continuar do próximo de onde ele parou
	
	//printf("str: %s\n", str);   // ------> Pedro
	//printf("token: %s\n", token);   // ------> Olmo
	
	
	//para não ter que ficar fazendo muitos strtok
	//"enquanto o token não chegar no\0 original..."
	while (token != NULL)
	{
		printf("token: %s\n", token);
		token  = strtok(NULL, " ");
	}
	
	
	//POSSO CRIAR uma string separadora e coloca-la no espaço do strtok de caracter responsavel pela divisao em tokens
	//ex: char sep[] = ",#";
	//token  = strtok(str, sep);
	
	return 0;
}