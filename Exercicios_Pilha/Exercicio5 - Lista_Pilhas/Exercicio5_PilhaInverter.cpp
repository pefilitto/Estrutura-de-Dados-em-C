#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Ex5TAD.h"

void InvertePilha(TpPilha pilha){
	int num;
	for(int i=0; i<maxpilha; i++){
		printf("%do numero da pilha: ", i+1);
		scanf("%d", &num);
		inserir_elemento(pilha, num);
	}
	
	exibir(pilha);
}

int main()
{
	TpPilha pilha;
	inicializar_pilha(pilha);
	InvertePilha(pilha);
}
