//Definindo as tarefas existentes no arquivo
struct TpReg{
	int processador;
	char nomearq[50];
	char processo[50];
	int tempo;
	int prioridade;
};

struct TpPont{
	TpPont *ant, *prox;
	TpReg reg;
};

struct TpDesc{
	TpPont *inicio, *fim;
	int qtd;
};

/*char Menu(){
	printf("A - Inicializar\n");
	printf("B - Ver Elemento Inicio\n");
	printf("C - Ver elemento Final\n");
	printf("D - Inserir\n");
	printf("E - Excluir\n");
	printf("F - Exibir\n");
	printf("G - Exibir Recursivamente\n");
	printf("ESC - Sair\n");
	return toupper(getche());
}*/

void Inicializar(TpDesc &desc){
	desc.inicio = desc.fim = NULL;
	desc.qtd = 0;
}

TpReg ElementoInicio(TpDesc desc){
	return desc.inicio -> reg;
	getch();
}

TpReg ElementoFinal(TpDesc desc){
	return desc.fim -> reg;
	getch();
}

TpPont *novaCaixa(TpReg reg){
	TpPont *nc = new TpPont;
	
	nc -> ant = nc -> prox = NULL;
	nc -> reg = reg;
	return nc;
}

/*void Insere(TpDesc &desc){
	TpPont *caixa, *atual;
	char elemento;
	int prioridade;
	TpReg reg, regaux;
	printf("\nDigite um elemento e sua prioridade: ");
	fflush(stdin);
	scanf("%c", &elemento);
	scanf("%d", &prioridade);
	while(prioridade != 0){
		reg.elemento = elemento;
		reg.prioridade = prioridade;
		caixa = novaCaixa(reg);
		desc.qtd++;
		
		if(desc.inicio == NULL) 
			desc.inicio = desc.fim = caixa;
			
		else{
			desc.fim -> prox = caixa;
			caixa -> ant = desc.fim;
			desc.fim = caixa;
			
			
			atual = desc.fim;
			while(atual -> ant != NULL && atual -> reg.prioridade < atual -> ant -> reg.prioridade){
				//Faz a troca
				regaux = atual -> reg;
				atual -> reg = atual -> ant -> reg;
				atual -> ant -> reg = regaux;
				
				atual = atual -> ant;
			}
		}
		printf("\nDigite um elemento e sua prioridade: ");
		fflush(stdin);
		scanf("%c", &elemento);
		scanf("%d", &prioridade);
	}
}*/


//Consertar a funcao excluir
/*void Excluir(TpDesc &desc){
	TpPont *aux;
	if(desc.inicio == NULL)
		printf("Fila vazia");
	else{
		//O aux passa a ser a primeira caixinha da lista
		aux = desc.inicio;
		//O desc.inicio aponta para o proximo elemento da lista, indicado por 'aux -> prox'
		desc.inicio = aux -> prox;
		//A posicao ant do proximo elemento, indicado agora por 'desc.inicio -> ant' aponta para null
		desc.inicio -> ant = NULL;
		//Deleta-se o aux (primeira caixinha da lista)
		delete(aux);
	}
	printf("\nExcluido com sucesso\n");
	getch();	
}*/

bool FilaVazia(TpDesc desc){
	return desc.inicio == NULL;	
}

/*void Exibir(TpDesc desc){
	TpPont *atual;
	atual = desc.inicio;
	int i=0;
	printf("\n\n");
	while(atual -> prox != NULL){
		printf("\nElemento %d: %c | Prioridade: %d\n", i+1, atual -> reg.elemento, atual -> reg.prioridade);
		
		atual = atual -> prox;
		i++;
	}
	printf("\nElemento %d: %c | Prioridade: %d\n", i+1, atual -> reg.elemento, atual -> reg.prioridade);
	getch();
}*/


//Passar o desc.inicio como primeiro parametro e o 1 como segundo; 
/*void ExibirRecursivamente(TpPont *atual, int i){
	if(atual -> prox == NULL){
		printf("\nElemento %d: %c | Prioridade: %d\n", i, atual -> reg.elemento, atual -> reg.prioridade);
		printf("\nVisualize os elementos acima\n");
	}
	else{
		printf("\nElemento %d: %c | Prioridade: %d\n", i, atual -> reg.elemento, atual -> reg.prioridade);
		ExibirRecursivamente(atual -> prox, ++i);
	}
	getch();
}*/

void decrementa(TpDesc &desc, int &cont, int &contt) {
    TpPont *aux;
    if (desc.inicio != NULL) {
        if (desc.inicio != NULL && desc.inicio->reg.tempo > 0) {
            desc.inicio->reg.tempo -= 1;
        }
         if (desc.inicio->reg.tempo == 0) {
            aux = desc.inicio;
            desc.inicio = desc.inicio->prox;
            if (desc.inicio != NULL) {
                desc.inicio->ant = NULL;
            }
            delete aux;
            cont++;
            contt++;
        }
    }
}




























