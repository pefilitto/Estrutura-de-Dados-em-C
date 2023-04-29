#include <stdio.h>

#define TF 10

void InsereOrdenado(int Vet[TF], int &TL)
{
	int pos, num;
	printf("Digite um numero: \n");
	scanf("%d", &num);
	while(TL<TF && num != 0)
	{
		pos=0;
		while(pos<TL && num > Vet[pos])
			pos++;
			
		for(int i=TL; i>pos; i--)
			Vet[i] = Vet[i-1];
			
		Vet[pos] = num;
		TL++;
		printf("Digite um numero: \n");
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
	
	InsereOrdenado(Vet, TL);
	Exibe(Vet, TL);
}

