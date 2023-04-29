#define max 10

struct TpPilha{
	int topo;
	char nome[max];
};

void inicializar(TpPilha &pilha){
	pilha.topo = -1;
	
	printf("Pilha inicializada com sucesso\n");
}

void push(TpPilha &pilha, int elemento){
	pilha.topo++;
	pilha.nome[pilha.topo] = elemento;
}

char pop(TpPilha &pilha){
	return pilha.nome[pilha.topo--];
}

char vazia(int topo){
	if(topo == -1)
		return 1;
	return 0;
}

char cheia(int topo){
	if(topo == max-1)
		return 1;
	return 0;
}

void exibir(TpPilha pilha){ //Como está sendo passado por valor, a pilha não será destruída, sendo assim, a pilha original se mantém
	while(!vazia(pilha.topo))
		printf("%c\n", pop(pilha)); //Vai exibindo a medida que vai tirando da pilha
}

