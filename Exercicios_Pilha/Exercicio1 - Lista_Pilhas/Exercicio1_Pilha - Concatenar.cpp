#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Ex1TAD.h"

char Menu(){
	printf("[A] Inicializar\n");
	printf("[B] Empilhar\n");
	printf("[C] Desempilhar\n");
	printf("[D] Concatenar\n");
	printf("[E] Exibir pilhas\n");
	printf("[ESC] Sair\n");
	return toupper(getche());
}

int main()
{
	TpPilha p1, p2;
	
	char opc;
	int opcnum, elem;
	
	do{
		opc = Menu();
		switch(opc){
			case 'A':
				system("cls");
				inicializar_pilha(p1);
				inicializar_pilha(p2);
				printf("Pilha 1 e 2 inicializadas com sucesso");
				getch();
			break;
			
			case 'B':
				system("cls");
				printf("Em qual pilha deseja inserir (1/2)?\n");
				scanf("%d", &opcnum);
				if(opcnum == 1){
					if(cheia(p1.topo))
						printf("Pilha 1 cheia\n");
					else{
						printf("Digite um elemento: ");
						scanf("%d", &elem);
						inserir_elemento(p1, elem);
					}
				}
				else{
					if(cheia(p2.topo))
						printf("Pilha 2 cheia\n");
					else{
						printf("Digite um elemento: ");
						scanf("%d", &elem);
						inserir_elemento(p2, elem);
					}
				}
				getch();
			break;
			
			case 'D':
				system("cls");
				concatenar(p1, p2);
				getch();
			break;				
			
			case 'E':
				system("cls");
				printf("Qual pilha deseja exibir (1/2)?\n");
				scanf("%d", &opcnum);
				if(opcnum==1)
					exibir(p1);
				else
					exibir(p2);
				getch();
			break;
		}
		system("cls");
	}while(opc != 27);
}
