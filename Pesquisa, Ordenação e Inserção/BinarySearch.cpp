#include <stdio.h>
#define TF 7

void InsereOrdenado(int vet[TF], int &TL){ //Precisa inserir ordenado pois a Busca Binária já considera a estrutura ordenada
	int num, pos;
	printf("Numero: ");
	scanf("%d", &num);
	while(TL<TF && num != 0){
		pos=0;
		while(pos<TL && num>vet[pos])
			pos++;
		
		for(int i=TL; i>pos; i--)
			vet[i] = vet[i-1];
		
		vet[pos] = num;
		TL++;
		printf("Numero: ");
		scanf("%d", &num);
	}
}

int BinarySearch(int vet[TF], int &TL,int num){
	int fim=TL-1, meio=fim/2, inicio = 0;

	while(inicio<fim && vet[meio]!=num){
		if (num<vet[meio])
			fim=meio-1;
		else
			inicio=meio+1;
		meio=(inicio+fim)/2;	
	}
	if(inicio<fim)
		if (vet[meio]==num)
			return meio;
	else
		return -1;
}

int main (){
	int i, num, vet[TF], TL=0;
	InsereOrdenado(vet, TL);	
	printf("\nNumero para buscar: ");
	scanf("%d",&num);
	printf("%d",BinarySearch(vet,TL,num));
}
