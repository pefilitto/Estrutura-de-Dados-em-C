#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Ex2TAD.h"

void ExcluirElemento(TpPilha pilha, TpPilha pilha2, int elemento){
	//int elemento;
	
	//printf("Digite um numero a ser excluido da pilha: ");
	//scanf("%d", &elemento);
	
	while(!vazia(pilha.topo)){
		if(verificaTopo(pilha) == elemento)
			pop(pilha);
		else
			inserir(pilha2, pop(pilha));
	}
	printf("Excluido com sucesso\n");
	exibir(pilha2);
}


int main()
{
	TpPilha p1, p2;
	
	int numero, numero2;
	
	inicializar(p1);
	inicializar(p2);
	
	while(!cheia(p1.topo)){
		printf("Numero para inserir na pilha: ");
		scanf("%d", &numero2);
		inserir(p1, numero2);
	}
	
	printf("\n\n\n");
	exibir(p1);
	printf("\n\n\n");
	
	printf("Digite um numero para ser excluido da pilha: ");
	scanf("%d", &numero);
	
	ExcluirElemento(p1, p2, numero);
}
