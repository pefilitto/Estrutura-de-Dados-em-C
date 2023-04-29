#define max 10

struct TpPilha{
	int topo;
	char nome[max];
};

void inicializar(TpPilha &pilha){
	pilha.topo = -1;
	
	printf("Pilha inicializada com sucesso\n");
}

char push(TpPilha &pilha, char elemento){
	pilha.topo++;
	return pilha.nome[pilha.topo] = elemento;
}

char pop(TpPilha &pilha){
	return pilha.nome[pilha.topo--];
}

int cheia(int topo){
	if(topo == max-1)
		return 1;
	return 0;
}

int vazia(int topo){
	if(topo == -1)
		return 1;
	return 0;
}

void exibir(TpPilha pilha){
	while(!vazia(pilha.topo))
		printf("%s\n", pop(pilha));
}




