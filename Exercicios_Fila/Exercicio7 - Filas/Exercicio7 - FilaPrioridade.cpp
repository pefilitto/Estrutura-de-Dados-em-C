#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include "Ex7TAD.h"


void Learquivo(){
	TpFila fila;
	TpCarro carro, aux;
	FILE *arq = fopen("Dados.txt","r");
    int operacao_sorteada;
    char nome[50];
    
    srand(time(NULL));
    rewind(arq);
    while(!feof(arq)){
    	
    	operacao_sorteada = rand() % 4;
    	
    	if(operacao_sorteada > 1.5){
    		if(cheia(fila.fim)){
    			printf("A operacao escolhida foi inserir, porem a fila esta cheia\n");
    			Sleep(2000);
    		}
    		else{
    			printf("\nInsercao na fila foi a operacao escolhida\n\n");
    			printf("Inserindo: ");
    			fscanf(arq,"%[^,],%[^,],%[^,],%c\n", &carro.idVeiculo, &carro.cor, &carro.fabricante, &carro.prioridade);
    			printf("%s \t %s \t %s \t %c\n\n", carro.idVeiculo, carro.cor, carro.fabricante, carro.prioridade);
    			insere(fila, carro);
    			exibir(fila);
    			Sleep(2000);
    		}
    	} 
    	else {
    		if(vazia(fila)){
    			printf("\nA operacao escolhida foi remover, porem a fila esta vazia\n");
				Sleep(2000);
    		}
    		else{
    			printf("\nRemocao da fila foi a operacao escolhida\n\n");
    			printf("Removendo... ");
    			carro = retirar(fila);
    			printf("%s \t %s \t %s \t %c\n\n", carro.idVeiculo, carro.cor, carro.fabricante, carro.prioridade);
    			if(vazia(fila))
    				printf("\nFila agora esta vazia\n");
    			else
    				exibir(fila);
    			Sleep(2000);
    		}
    	}
    }
}

int main()
{	
	TpFila fila;
	TpCarro carro;
	inicializar(fila);
	Learquivo();
}
