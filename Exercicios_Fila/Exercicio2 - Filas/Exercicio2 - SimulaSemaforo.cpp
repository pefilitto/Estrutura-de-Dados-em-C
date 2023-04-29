#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "Fila.h"

void PreencheFila(TpFila fila){
	printf("Preenchendo fila\n\n");
	char elemento;

	for(int i=0; i<maxfila; i++){
		scanf("%c", &elemento);
		push(fila, elemento);
	}
}


void SimulaSemaforo(TpFila fila){
	int cont1=0, cont2=0, ok=0;
	
	do{
		if(!vazia(fila.fim)){
			printf("Semaforo fechado. Pressione espaco para abrir!\n");
			if(getch() == 32){
				do{
					printf("Semaforo aberto. Pressione backspace a qualquer momento para fechar\n");
					retirar(fila);
					cont1++;
				}while(getch() != 8);
			}
			else{
				Sleep(2000);
				cont2+=2;
			}
		}
		else{
			ok=1;
			printf("Fila ja vazia!\n");
		}
	}while(getch() != 27 && ok==0);
	
	printf("%d elementos foram tirados e duraram %d segundos na fila\n", cont1, cont2);
}

int main()
{
	TpFila fila;
	inicializar(fila);
	PreencheFila(fila);
	SimulaSemaforo(fila);
}
