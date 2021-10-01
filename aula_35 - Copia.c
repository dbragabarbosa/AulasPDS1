/*
Crie k predios de forma cilíndrica em uma superfície de 100m x 100m 
e calcule o volume total ocupado pelos predios. Tanto k, quanto o 
raio e a altura dos cilindros devem ser gerados aleatoriamente:
- k deve variar entre 1 e 30;
- o raio deve variar entre 1 e 5 metros;
- a altura deve variar entre 1 e 100 metros.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXPREDIOS 30
#define MAXRAIO 5
#define MAXALTURA 100
#define SIZE 100

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
				

//vou utilizar o centro de cada cilindro para localiza-los nessa superficie
//ou seja, ao invés de criar uma variavel x e y para cada cilindro, vou fazer:
typedef struct Ponto
{
	float x, y;
} Ponto;

//
typedef struct Circulo
{
	Ponto centro;
	float raio;
} Circulo;

//
typedef struct Cilindro 
{
	Ponto centro;
	float altura;
} Cilindro;

//funcao que retorna a area do circulo
float areaCirculo (Circulo c)
{
	return 3.141592*c.raio*c.raio;
}

//funcao para calcular a diferença entre pontos
//retorna a diferenca euclidiana no espaço entre p1 e p2
float distancia (Ponto p1, Ponto p2)
{
	return sqrt(pow(p1.x-p2.x, 2) + pow(p1.y-p2.y, 2));
}

//funcao para ver se os circulos estão se sobrepondo ou não
int colisaoCirculos (Circulo c1, Circulo c2)
{
	if (distancia(c1.centro, c2.centro) < c1.raio + c2.raio)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//funcao para criar os cilindros
void criaCilindro (Cilindro *c)
{
	float altura = randFloat(1, MAXALTURA);
	(*c).altura = altura;
	float raio = randFloat (1, MAXRAIO);
	//(*c).base.raio = raio;
	// OU
	c->base.raio = raio;
	c->base.centro.x = randFloat(0+raio, SIZE-raio);
	c->base.centro.y = randFloat(0+raio, SIZE-raio);
}

//funcao para verificar se o cilindro criado não colida com outro já existente
int colisaoPredios(Cilindro c, Cilindro predios[], int n)
{
	int i=0;
	for (int i=0; i < n; i++)
	{
		if (colisaoCirculos(predio.base, predio[i].base))
		{
			return 1;
		}
		else 
		{
			return 0;		
		}
	}
}

//funcao para calcular o volume dos cilindros
float volumeCilindro (Cilindro c)
{
	return areaCirculo(c.base) * c.altura;
}

int main ()
{
	//vou criar um vetor de cilindros 
	Cilindro predios[MAXPREDIOS];
	//sortear a qntd de predios
	int k = randInt(1, MAXPREDIOS);
	int i=0;
	
	//preciso criar os cilindros e colocalos na superficie
	for (int i=0; i < k; i++)
	{
		criaCilindro(&predios[i]);
		
		//para criar até ser um cilindro que não colida com outro já existente
		if (colisaoPredios(predios[i], predios, i))
		{
			i--;
		}
	}
	//CRIEI TODOS OS CILINDROS
	//AGORA FALTA CALCULAR O VOLUME
	
	float volumeTotal = 0;
	for (i=0; i<k; i++)
	{
		volumeTotal += volumeCilindro(predios[i]);
	}
	
	printf("\nVOlume total: %f", volumeTotal);
	
	/*
	Ponto p1, p2;
	scanf("%f %f", &p1.x, &p1.y);
	scanf("%f %f", &p2.x, &p2.y);
	
	printf("\ndist: %f\n", distancia(p1, p2));
	
	Circulo c1, c2;
	scanf("%f %f", &c1.raio, &c2.raio);
	c1.centro = p1;
	c2.centro = p2;
	
	printf("\narea circulo 1: %f\n", areaCirculo(c1));
	printf("\ncolisao? %d\n", colisaoCirculos(c1, c2));
	*/
	
	
	return 0;
}