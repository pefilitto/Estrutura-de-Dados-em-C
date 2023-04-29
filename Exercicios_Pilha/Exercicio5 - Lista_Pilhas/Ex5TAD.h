#define maxpilha 5

struct TpPilha{
	int topo;
	char nome[maxpilha];
};

void inicializar_pilha(TpPilha &pilha){
	pilha.topo = -1;
}

char inserir_elemento(TpPilha &pilha, int elemento){
	pilha.topo++;
	return pilha.nome[pilha.topo] = elemento;
}

char pop(TpPilha &pilha){ //Desempilhando
	return pilha.nome[pilha.topo--];
}

int vazia(int topo){
	if(topo == -1)
		return 1; //Retorna verdadeiro se o topo for -1
	return 0;
}

char cheia(int topo){
	if(topo == maxpilha-1)
		return 1;
	return 0;
}

void exibir(TpPilha pilha){ //Como est� sendo passado por valor, a pilha n�o ser� destru�da, sendo assim, a pilha original se mant�m
	while(!vazia(pilha.topo))
		printf("%d\n", pop(pilha)); //Vai exibindo a medida que vai tirando da pilha
}

