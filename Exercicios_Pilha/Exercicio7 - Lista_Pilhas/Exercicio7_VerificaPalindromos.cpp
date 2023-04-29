#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Ex7TAD.h"

void Palindromos(TpPilha pilha, char string[50]){
	int cont=0;
	for(int i=0; i<strlen(string); i++)
		push(pilha, string[i]);
	
	for(int i=0; i<strlen(string) && !vazia(pilha.topo); i++)
		if(pop(pilha) == string[i])
			cont++;
		
	if(cont == strlen(string))
		printf("Sao palindromos\n");
	else
		printf("Nao sao palindromos\n");
}

int main(){
	TpPilha pilha;
	inicializar(pilha);
	char string[50];
	printf("Digite a palavra para verificar se eh palindromo: ");
	fflush(stdin);
	gets(string);
	Palindromos(pilha, string);
}
