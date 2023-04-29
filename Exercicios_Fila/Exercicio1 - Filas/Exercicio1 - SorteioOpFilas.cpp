#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "Fila.h"

void Sorteia(TpFila fila){
	srand(time(NULL));
	char c;
	int operacao_sorteada = 1+(rand() % 3);
	
	do{
		if(operacao_sorteada == 1){
			printf("Inserir na fila foi a operacao escolhida\n");
			printf("Digite o elemento que deseja inserir: ");
			fflush(stdin);
			scanf("%c", &c);
			push(fila, c);
			printf("\n");
			exibir(fila);
		}
		if(operacao_sorteada == 2){
			printf("Remover da pilha foi a operacao escolhida\n");
			if(!vazia(fila.fim)){				
				printf("\nRemovendo...\n");
				Sleep(2000);
				retirar(fila);
				printf("\nRemovido com sucesso!\n");
				exibir(fila);
			}
			else
				printf("Fila vazia\n");
		}
	}while(getche() != 27);

}

int main()
{
	TpFila fila;
	inicializar(fila);
	Sorteia(fila);
}


