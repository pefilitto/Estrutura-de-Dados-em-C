#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio2.h>
#include "TADTrabalho.h"

//Comentario Git

void verificaPrioridade(TpReg &reg){
	if(strcmp(reg.processo,"Gravar Dispositivo Interno")==0)
		reg.prioridade = 1;
	else if(strcmp(reg.processo,"Gravar Dispositivo Externo")==0)
		reg.prioridade = 2;
	else if(strcmp(reg.processo,"Deletar")==0)
		reg.prioridade = 3;
	else if(strcmp(reg.processo,"Ler")==0)
		reg.prioridade = 4;
	else if(strcmp(reg.processo,"Imprimir")==0)
		reg.prioridade =5;
}

void exibir(TpDesc Desc1, TpDesc Desc2,TpDesc Desc3,TpDesc Desc4){
	printf("\n------------------------------\n");
	TpPont *aux1=Desc1.inicio,*aux2 = Desc2.inicio,*aux3 = Desc3.inicio,*aux4 = Desc4.inicio;
	printf("Processador 1: \n");
	while(aux1!=NULL && aux1->prox!=NULL){
		printf("%s\t%s\t%d",aux1->reg.nomearq,aux1->reg.processo,aux1->reg.tempo);
		aux1=aux1->prox;
		printf("\n");
	}
	printf("------------------------------\n");
	printf("Processador 2: \n");
	while(aux2!=NULL&&aux2->prox!=NULL){
		printf("%s\t%s\t%d",aux2->reg.nomearq,aux2->reg.processo,aux2->reg.tempo);
		aux2=aux2->prox;
		printf("\n");
	}
	printf("------------------------------\n");
	printf("Processador 3: \n");
	while(aux3!=NULL&&aux3->prox!=NULL){
		printf("%s\t%s\t%d",aux3->reg.nomearq,aux3->reg.processo,aux3->reg.tempo);
		aux3=aux3->prox;
		printf("\n");
	}
	printf("------------------------------\n");
	printf("Processador 4: \n");
	while(aux4!=NULL&&aux4->prox!=NULL){
		printf("%s\t%s\t%d",aux4->reg.nomearq,aux4->reg.processo,aux4->reg.tempo);
		aux4=aux4->prox;
		printf("\n");
	}
	printf("\n------------------------------\n");
}


void simulacao(FILE *ptr, TpDesc desc1, TpDesc desc2, TpDesc desc3, TpDesc desc4){
	TpReg reg, regaux;
	TpPont *caixa, *atual;
	char click;
	char nomeprocesso[50];
	int tempo=0, cont1=0, cont2=0, cont3=0, cont4=0, conttotal=0, menor = 10;
	
	while(!kbhit()&& !feof(ptr)){
		system("cls");
		if(tempo % 2 == 0){
			fscanf(ptr, "%d,%[^,],%[^,],%d\n", &reg.processador, &reg.nomearq, &reg.processo, &reg.tempo);
			verificaPrioridade(reg);
			caixa = novaCaixa(reg);
			
			if(reg.processador == 1){
				if(desc1.inicio == NULL){
					desc1.inicio = desc1.fim = caixa;
				}
				else{
					desc1.fim -> prox = caixa;
					caixa -> ant = desc1.fim;
					desc1.fim = caixa;
				
					atual = desc1.fim;
					TpReg regaux;
					while(atual -> ant != NULL && atual -> reg.prioridade < atual -> ant -> reg.prioridade){
						regaux = atual->reg;
						atual->reg = atual -> ant -> reg;
						atual -> ant -> reg = regaux;
						
						atual = atual -> ant;
					}
				}
			}
			else if(reg.processador == 2){
				if(desc2.inicio == NULL){
					desc2.inicio = desc2.fim = caixa;
				}
				else{
					desc2.fim -> prox = caixa;
					caixa -> ant = desc2.fim;
					desc2.fim = caixa;
				
					atual = desc2.fim;
					TpReg regaux;
					while(atual -> ant != NULL && atual -> reg.prioridade < atual -> ant -> reg.prioridade){
						regaux = atual->reg;
						atual->reg = atual -> ant -> reg;
						atual -> ant -> reg = regaux;
						
						atual = atual -> ant;
					}
				}
			}
			else if(reg.processador == 3){
				if(desc3.inicio == NULL){
					desc3.inicio = desc3.fim = caixa;
				}
				else{
					desc3.fim -> prox = caixa;
					caixa -> ant = desc3.fim;
					desc3.fim = caixa;
				
					atual = desc3.fim;
					TpReg regaux;
					while(atual -> ant != NULL && atual -> reg.prioridade < atual -> ant -> reg.prioridade){
						regaux = atual->reg;
						atual->reg = atual -> ant -> reg;
						atual -> ant -> reg = regaux;
						
						atual = atual -> ant;
					}
				}
			}
			else{
				if(desc4.inicio == NULL){
					desc4.inicio = desc4.fim = caixa;
				}
				else{
					desc4.fim -> prox = caixa;
					caixa -> ant = desc4.fim;
					desc4.fim = caixa;
				
					atual = desc4.fim;
					TpReg regaux;
					while(atual -> ant != NULL && atual -> reg.prioridade < atual -> ant -> reg.prioridade){
						regaux = atual->reg;
						atual->reg = atual -> ant -> reg;
						atual -> ant -> reg = regaux;
						
						atual = atual -> ant;
					}
				}
			}
		}
		decrementa(desc1,cont1,conttotal);
		decrementa(desc2,cont2,conttotal);
		decrementa(desc3,cont3,conttotal);
		decrementa(desc4,cont4,conttotal);
		exibir(desc1,desc2,desc3,desc4);
		tempo++;
		printf("Tempo decorrido: %d \nAtividades Processador 1: %d \nAtividades Processador 2: %d\nAtividades Processador 3: %d\nAtividades Processador 4: %d\nAtividades total: %d\n",tempo,cont1,cont2,cont3,cont4,conttotal);
	}
	
	if(kbhit() && getche() == 27){
			if(desc1.inicio -> reg.tempo < menor)
				strcpy(nomeprocesso, desc1.inicio -> reg.processo);	
			else if(desc2.inicio -> reg.tempo < menor)
				strcpy(nomeprocesso, desc2.inicio -> reg.processo);
			else if(desc3.inicio -> reg.tempo < menor)
				strcpy(nomeprocesso, desc3.inicio -> reg.processo);
			else
				strcpy(nomeprocesso, desc4.inicio -> reg.processo);
				
		
			FILE *ptr3 = fopen("aux.txt","a+");
			fclose(ptr);		
			FILE *ptr2 = fopen("backup.txt", "w");
			TpReg aux2;
			fscanf(ptr, "%d,%[^,],%[^,],%d\n", &aux2.processador, &aux2.nomearq, &aux2.processo, &aux2.tempo);
			while(!feof(ptr) && strcmp(aux2.processo, nomeprocesso) != 0)
				fscanf(ptr, "%d,%[^,],%[^,],%d\n", &aux2.processador, &aux2.nomearq, &aux2.processo, &aux2.tempo);
			
			char c = fgetc(ptr);	
			while(!feof(ptr)){
				fputc(c, ptr3);
				c = fgetc(ptr);
			}
			fseek(ptr3,0,SEEK_SET);
			c = fgetc(ptr3);
			while(!feof(ptr3)){
				fputc(c,ptr2);
				c=fgetc(ptr3);
			}
			
		fclose(ptr2);
		
	}
	fclose(ptr);
}



int main()
{
	TpDesc desc1, desc2, desc3, desc4;
	char resp;
	FILE *ptr = NULL;
	Inicializar(desc1);
	Inicializar(desc2);
	Inicializar(desc3);
	Inicializar(desc4);
	FILE *teste = fopen("backup.txt","r");
	if (teste == NULL || (teste != NULL && fseek(teste, 0, SEEK_END) == 0 && ftell(teste) == 0)){
		ptr = fopen("comandos.txt", "r");
	}
	else {
		printf("Existe um Backup. Quer utiliza-lo? (S/N)\n");
		fflush(stdin);
		scanf("%c", &resp);
		if(resp == 'S' || resp == 's'){
			ptr = fopen("backup.txt","r");
		}
		else ptr = fopen("comandos.txt", "r");
	}
	simulacao(ptr,desc1, desc2, desc3, desc4);	
}
