#define maxpilha 10

struct TpPilha{
	int topo;
	char nome[maxpilha];
};

void inicializar_pilha(TpPilha &pilha){
	pilha.topo = -1;
}

void inserir_elemento(TpPilha &pilha, int elemento){
	pilha.topo++;
	pilha.nome[pilha.topo] = elemento;
}

char pop(TpPilha &pilha){ //Desempilhando
	return pilha.nome[pilha.topo--];
}

int vazia(int topo){
	if(topo == -1)
		return 1; //Retorna verdadeiro se o topo for -1
	return 0;
}

void concatenar(TpPilha pilha, TpPilha pilha2){
	int cont=0, i=maxpilha, elemento;
	while(!vazia(pilha2.topo))
		inserir_elemento(pilha, pop(pilha2));
	
	printf("Concatenado com sucesso\n");
	
	while(!vazia(pilha.topo))
		printf("%d\n", pop(pilha));
}

char cheia(int topo){
	if(topo == maxpilha-1)
		return 1;
	return 0;
}

void exibir(TpPilha pilha){ //Como está sendo passado por valor, a pilha não será destruída, sendo assim, a pilha original se mantém
	while(!vazia(pilha.topo))
		printf("%d\n", pop(pilha)); //Vai exibindo a medida que vai tirando da pilha
}
