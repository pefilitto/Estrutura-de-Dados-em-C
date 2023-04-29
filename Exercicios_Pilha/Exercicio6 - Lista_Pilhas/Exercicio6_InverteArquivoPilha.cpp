#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Ex6TAD.h"

void InverteArq(TpPilha pilha, char nomearq[50]){
	FILE *ptr = fopen(nomearq, "r");
	FILE *ptr2 = fopen("Invertido.txt", "w");
	char c, s;
	
	c = fgetc(ptr);
	while(!feof(ptr)){
		inserir_elemento(pilha, c);
		
		c = fgetc(ptr);
	}
	
	while(!vazia(pilha.topo))
		fputc(pop(pilha), ptr2);
		
	printf("Invertido com sucesso\n");
}

int main()
{
	TpPilha pilha;
	inicializar_pilha(pilha);
	InverteArq(pilha, "TextoParaInverter.txt");
}

