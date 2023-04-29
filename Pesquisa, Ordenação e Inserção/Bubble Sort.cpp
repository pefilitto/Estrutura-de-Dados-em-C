#include <stdio.h>

#define TF 5

void BubbleSort(int Vet[TF], int TL)
{
	int aux=0;
	while(TL>1)
	{
		for(int i=0; i < TL-1; i++)
		{
			if(Vet[i]>Vet[i+1])
			{
				aux = Vet[i];
				Vet[i] = Vet[i+1];
				Vet[i+1] = aux;
			}
		
		}
		TL--;
	}
}

void Insere(int Vet[TF], int &TL)
{
	int num;
	printf("Digite um numero\n");
	scanf("%d", &num);
	while(TL<TF && num!=0)
	{
		Vet[TL] = num;
		TL++;
		printf("Digite um numero\n");
		scanf("%d", &num);
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
	BubbleSort(Vet, TL);
	Exibe(Vet, TL);
}
