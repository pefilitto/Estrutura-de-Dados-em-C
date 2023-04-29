#define maxfila 10

struct TpFila{
	int fim;
	char nome[maxfila];
};

void inicializar(TpFila &fila){
	fila.fim = -1;
	
	printf("Fila inicializada com sucesso\n");
}

char vazia(int fim){
	if(fim == -1)
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

char push(TpFila &fila,	char elemento){
	fila.fim++;
	return fila.nome[fila.fim] = elemento;
}

char elementoInicio(TpFila fila){
	return fila.nome[0];
}

char elementoFim(TpFila fila){
	return fila.nome[fila.fim];
}

char retirar(TpFila &fila){
	char elemento = fila.nome[0];
	
	for(int i=0; i<fila.fim; i++)
		fila.nome[i] = fila.nome[i+1];
	fila.fim--;
	
	return elemento;
}

void exibir(TpFila fila){
	while(!vazia(fila.fim))
		printf("%c\t", retirar(fila));
}
