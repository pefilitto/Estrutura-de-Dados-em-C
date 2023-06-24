#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <windows.h>
#include "TAD.h"

int main()
{
	char opc;
	TpDesc desc;
	TpReg reg;
	do{
		opc = Menu();
		switch(opc){
			case 'A': Inicializar(desc);
			break;
			
			case 'B': reg = ElementoInicio(desc);
					  printf("\nElemento: %c | Prioridade: %d\n", reg.elemento, reg.prioridade);
					  getch();
			break;
			
			case 'C': reg = ElementoFinal(desc);
					  printf("\nElemento: %c | Prioridade: %d\n", reg.elemento, reg.prioridade);
					  getch();
			break;
			
			case 'D': Insere(desc);
			break;
			
			case 'E': Excluir(desc);
			break;
			
			case 'F': Exibir(desc);
			break;
			
			case 'G': ExibirRecursivamente(desc.inicio, 1);
			break;
		}
		system("cls");
	}while(opc != 27);
}


