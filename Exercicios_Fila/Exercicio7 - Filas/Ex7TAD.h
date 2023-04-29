#define maxfila 100

struct TpCarro{
	char idVeiculo[50];
	char cor[50];
	char fabricante[50];
	char prioridade;
};

struct TpFila{
	int fim;
	TpCarro nome[maxfila];
};

void inicializar(TpFila &fila){
	fila.fim = -1;
	
	printf("Fila inicializada com sucesso\n");
}

char vazia(TpFila fila){
	if(fila.fim == -1)
		return 1;
	else
		return 0;
}

char cheia(int fim){
	if(fim == maxfila-1)
		return 1;
	else
		return 0;
}

void insere(TpFila &fila, TpCarro carro){
	int i=0;
	TpCarro aux;
	fila.fim++;
	fila.nome[fila.fim] = carro;	
	
	i=fila.fim;
	while(i>0 && fila.nome[i].prioridade < fila.nome[i-1].prioridade){
		aux = fila.nome[i];
		fila.nome[i] = fila.nome[i-1];
		fila.nome[i-1] = aux;
		i--;
	}
}

TpCarro elementoFim(TpFila fila){
	return fila.nome[fila.fim];
}

TpCarro retirar(TpFila &fila){
	TpCarro elemento = fila.nome[0];
	
	for(int i=0; i<fila.fim; i++)
		fila.nome[i] = fila.nome[i+1];
	fila.fim--;
	
	return elemento;
}

void exibir(TpFila fila){
	for(int i=0; i<=fila.fim; i++)
		printf("\t. %s \t %s \t %s \t %c\n", fila.nome[i].idVeiculo, fila.nome[i].cor, fila.nome[i].fabricante , fila.nome[i].prioridade);
}
