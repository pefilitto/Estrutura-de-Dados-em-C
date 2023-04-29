#define maxpilha 5

struct TpPilha{
	int topo;
	char nome[maxpilha];
};

void inicializar(TpPilha &pilha){
	pilha.topo = -1; //Pilha.topo � o �ndice da pilha, diferente de pilha.nome[pilha.topo], que � o conte�do que est� na posi��o topo
	
	printf("Pilha inicializada com sucesso\n");
}

char pop(TpPilha &pilha){ //Desempilhando
	return pilha.nome[pilha.topo--];
}

char verificaTopo(TpPilha &pilha){
	return pilha.nome[pilha.topo]; //Verificando o topo da pilha
}

int inserir(TpPilha &pilha, int elemento){
	pilha.topo++;
	return pilha.nome[pilha.topo] = elemento;
}

int vazia(int topo){
	if(topo == -1)
		return 1;
	return 0;
}

void exibir(TpPilha pilha){ //Como est� sendo passado por valor, a pilha n�o ser� destru�da, sendo assim, a pilha original se mant�m
	while(!vazia(pilha.topo))
		printf("%d\n", pop(pilha)); //Vai exibindo a medida que vai tirando da pilha
}

int cheia(int topo){
	if(topo == maxpilha-1)
		return 1;
	return 0;
}


