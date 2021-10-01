/*PASSAGEM DE PARAMETROS 

--> POR VALOR 
o normal

--> OU POR REFERENCIA(ENDEREÇO)
a gente ****envia os endereços de memoria das variáveis*****
ou seja, a função modifica os valores das variáveis passadas
mesmo não estando em seu escopo

como fazer: utilize ponteiros como parametros
				ex: void alterar (int *x)
			e mande o endereço da variavel desejada
				ex: alterar(&a);


