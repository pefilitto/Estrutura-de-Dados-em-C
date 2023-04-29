#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "Ex4TAD.h"



int main()
{
	TpPilha pilha;
	inicializar(pilha);
	
	int n, pilha_sorteada, operacao_sorteada, num;
	
	srand(time(NULL));
	printf("Digite a quantidade de pilhas desejada: ");
	scanf("%d", &n);
	TpPilha estrutura[n];
	
	pilha_sorteada = rand() % n+1;
	operacao_sorteada = rand() % 2+1;
	
	if(operacao_sorteada == 1){
		printf("Push escolhido\n\n");
		if(cheia(estrutura[pilha_sorteada].topo))
			printf("Pilha cheia. Nao foi possivel realizar o push\n");
		else{
			printf("Digite o numero para inserir: ");
			scanf("%d", &num);
			push(estrutura[pilha_sorteada], num);
			printf("\n");
			exibir(estrutura[pilha_sorteada]);
		}

	}
	if(operacao_sorteada == 2){
		printf("Pop escolhido\n\n");
		if(vazia(estrutura[pilha_sorteada].topo))
			printf("Pilha vazia. Não foi possivel realizar o pop\n");
		else{
			pop(estrutura[pilha_sorteada]);
			printf("\n");
			exibir(estrutura[pilha_sorteada]);
		}

	}
}
