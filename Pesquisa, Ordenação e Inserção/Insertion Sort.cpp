#include <stdio.h>
#include <conio2.h>


#define TF 5


void InsertionSort(int Vet[TF], int TL)
{
	int aux, i = TL-1;
	
	while(i>0 && Vet[i]<Vet[i-1])
	{
		aux = Vet[i];
		Vet[i] = Vet[i-1];
		Vet[i-1] = aux;
		i--;
	}
}


void Insere(int Vet[TF], int &TL)
{
	int num;
	printf("Digite um numero:\n");
	scanf("%d", &num);
	while(TL<TF && num!=0)
	{
		Vet[TL++] = num;
		InsertionSort(Vet, TL);
		printf("Digite um numero:\n");
		scanf("%d", &num);
	}
}

void Exibe(int Vet[TF], int &TL)
{
	for(int i=0; i<TL; i++)
		printf("Vetor [%d]: %d\n", i, Vet[i]);
}

int main()
{
	int Vet[TF], TL=0;
	
	Insere(Vet, TL);
	InsertionSort(Vet, TL);
	Exibe(Vet, TL);
}









	
