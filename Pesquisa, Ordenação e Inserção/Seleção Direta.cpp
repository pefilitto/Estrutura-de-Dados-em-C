#include <stdio.h>

#define TF 5

//


void SelecaoDireta(int Vet[TF], int TL)
{
	int maior, aux, posmaior;
	while(TL>1)
	{
		maior = Vet[0];
		posmaior = 0;
		for(int i=0; i<TL; i++)
		{
			if(Vet[i]>maior)
			{
				maior = Vet[i];
				posmaior = i; // o i é a posição que se encontra o maior elemento
			}
		}
		aux = Vet[TL-1];
		Vet[TL-1] = Vet[posmaior];
		Vet[posmaior] = aux;
		TL--;
	}
}

void Insere(int Vet[TF], int &TL)
{
	int num;
	printf("Digite um numero: \n");
	scanf("%d", &num);
	while(TL<TF && num != 0)
	{
		Vet[TL++] = num;
		if(TL<TF)
		{
			printf("Digite um numero: \n");
			scanf("%d", &num);
		}
	}
}

void Exibe(int Vet[TF], int &TL)
{
	for(int i=0; i<TL; i++)
		printf("Vetor [%d] %d\n", i, Vet[i]);
}

int main()
{
	int Vet[TF], TL=0;
	
	Insere(Vet, TL);
	SelecaoDireta(Vet, TL);
	Exibe(Vet, TL);
}
