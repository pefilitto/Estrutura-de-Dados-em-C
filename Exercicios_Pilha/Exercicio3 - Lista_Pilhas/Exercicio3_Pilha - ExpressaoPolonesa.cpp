#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Ex3TAD.h"


void ExpressaoPolonesa(char string[50], TpPilha pilha)
{
	int op1, op2;
	for(int i=0; i<strlen(string) && string[i] != '\0'; i++)
	{
		if(isdigit(string[i])) //Ou string[i]-48;
			push(pilha, string[i]);
		else {
			op2 = pop(pilha)-'0';
			op1 = pop(pilha)-'0';
			if(string[i] == '+')
				push(pilha, ((op1+op2)+'0'));
			else if(string[i] == '-'){
				//op1 = pop(pilha)-;
				//op2 = pop(pilha);
				push(pilha, ((op1-op2)+'0'));
			}
			else if(string[i] == '*'){
				//op1 = pop(pilha);
				//op2 = pop(pilha);
				push(pilha, ((op1*op2)+'0'));
			}
			else if(string[i] == '/'){
				//op1 = pop(pilha);
				//op2 = pop(pilha);
				push(pilha, ((op1/op2)+'0'));
			}
		}
	}
	
	printf("%d\n", pop(pilha)-'0'); //Colocando o -'0' para converter para inteiro
}


int main()
{
	TpPilha pilha;
	inicializar(pilha);
	char string[50];
	printf("Digite a string: ");
	fflush(stdin);
	gets(string);
	ExpressaoPolonesa(string, pilha);
}
