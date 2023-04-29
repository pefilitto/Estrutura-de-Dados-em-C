#include<stdio.h>
#include<conio2.h>
#include <string.h>
 
struct filme{
    char nome[60], classif[6];
    int ano, duracao;
    float gasto,renda,espec;
};

struct prod_ano{
	int ano, cont;
};

struct ano_prod{
	int ano;
	char nome[60];
};

struct espec{
	int txespec;
	char nome[60];
};

struct valormediano{
	int ano;
	char nome[60];
};

struct classificacao{
	char classi[15];
};
 
void MaiorLucro(){
	filme reg;
    FILE *arq = fopen("Filmes2.txt","r");
    int maior=0;
    char nome[50];
    
     
    fscanf(arq,"%[^;];%d;%[^;];%f;%f;%d;%f\n",&reg.nome, &reg.ano, &reg.classif, &reg.gasto, &reg.renda, &reg.duracao, &reg.espec);
    while(!feof(arq))
    {
    	if((reg.renda - reg.gasto) > maior){
    		maior = reg.renda - reg.gasto;
    		strcpy(nome, reg.nome);
    	}
     
        fscanf(arq,"%[^;];%d;%[^;];%f;%f;%d;%f\n",&reg.nome, &reg.ano, &reg.classif, &reg.gasto, &reg.renda, &reg.duracao, &reg.espec);
    }
    printf("O filme %s possui o maior lucro com %d\n", nome, maior);
    //printf("%s %d %s %.2f %.2f %d %.2f \n",reg.nome, reg.ano, reg.classif, reg.gasto, reg.renda, reg.duracao, reg.espec);
    
    fclose(arq);
    getch();
}

void MaiorEspec(){
	filme reg;
    FILE *arq = fopen("Filmes2.txt","r");
    int maior=0;
    char nome[50];
    
     
    fscanf(arq,"%[^;];%d;%[^;];%f;%f;%d;%f\n",&reg.nome, &reg.ano, &reg.classif, &reg.gasto, &reg.renda, &reg.duracao, &reg.espec);
    while(!feof(arq))
    {
    	if(reg.espec > maior){
    		maior = reg.espec;
    		strcpy(nome, reg.nome);
    	}
     
        fscanf(arq,"%[^;];%d;%[^;];%f;%f;%d;%f\n",&reg.nome, &reg.ano, &reg.classif, &reg.gasto, &reg.renda, &reg.duracao, &reg.espec);
    }
    printf("O filme %s possui o maior espectador com %d\n", nome, maior);
}

void TxtparaBin(){
	filme reg;
	FILE *ptr = fopen("Filmes2.txt", "r");
	FILE *ptr2 = fopen("Binario.dat", "wb");
	
	rewind(ptr2);
	fscanf(ptr,"%[^;];%d;%[^;];%f;%f;%d;%f\n", &reg.nome, &reg.ano, &reg.classif, &reg.gasto, &reg.renda, &reg.duracao, &reg.espec);
	while(!feof(ptr)){
		fwrite(&reg, sizeof(filme), 1, ptr2);
		
		fscanf(ptr,"%[^;];%d;%[^;];%f;%f;%d;%f\n",&reg.nome, &reg.ano, &reg.classif, &reg.gasto, &reg.renda, &reg.duracao, &reg.espec);
	}
	
	printf("Criado com sucesso\n");
	
	fclose(ptr);
	fclose(ptr2);
	getch();
}

void MediaHoras(){
	filme reg;
	FILE *ptr = fopen("Binario.dat", "rb+");
	int cont=0;
	float media;
	
	
	fread(&reg, sizeof(filme), 1, ptr);
	while(!feof(ptr)){
		cont++;
		media = media + reg.duracao;
		fread(&reg, sizeof(filme), 1, ptr);
	}
	
	media = media/(cont*60);
	
	printf("A media de horas dos filmes é de %.1f\n", media);
	
	fclose(ptr);
		
}

void prod_filmes_ano(){
	filme reg;
	prod_ano estrutura[30];
	int maior=0, TL=0, cont=0, maiorano=0, i;
	
	FILE *ptr = fopen("Binario.dat", "rb");
	rewind(ptr);
	fread(&reg, sizeof(filme), 1, ptr);
	while(!feof(ptr)){
		for(i=0, cont=0; i<TL && cont == 0; i++)
			if(reg.ano == estrutura[i].ano)
				cont=1;
		if(cont==1)
			estrutura[i-1].cont += 1;
		else{
			estrutura[TL].ano = reg.ano;
			estrutura[TL].cont = 1;
			TL++;
		}
		fread(&reg, sizeof(filme), 1, ptr);
	}
	
	for(int i=0; i<TL; i++){
		printf("%d %d\n", maior, maiorano);
		if(estrutura[i].cont > maior){
			
			maior = estrutura[i].cont;
			maiorano = estrutura[i].ano;
		}
		printf("ANO MAIOR = %d\n", maiorano);
	}
	
	printf("O ano com maior producao eh %d\n", maiorano);
	fclose(ptr);
}

void classification(){
	filme reg;
	classificacao cl[30];
	FILE *ptr = fopen("Binario.dat", "rb");
	FILE *ptr2 = fopen("ClassificacaoAgrupada.txt", "w");
	FILE *ptr3 = fopen("Binario.dat", "rb");
	int ok=0, TL=0;
	
	while(!feof(ptr)){
		rewind(ptr3);
		for(int i=0; i<TL && ok==0; i++)
			if(strcmp(reg.classif, cl[i].classi) == 0)
				ok=1;
				
		if(ok == 0){
			strcpy(cl[TL].classi, reg.classif);
			TL++;
			fread(&reg, sizeof(filme), 1, ptr3);
			while(!feof(ptr3)){
				if(strcmp(reg.classif, cl[TL-1].classi) == 0){
					fputs(reg.classif, ptr2);
					fputc('\t', ptr2);
					fputs(reg.nome, ptr2);
					fputc('\n', ptr2);
				}
				fread(&reg, sizeof(filme), 1, ptr3);
			}
		}
		
		fread(&reg, sizeof(filme), 1, ptr);
	}
	
	printf("Agrupado por classificacao com sucesso");
	
	fclose(ptr);
	fclose(ptr2);
	fclose(ptr3);
}

void anoproducao(){
	ano_prod estrutura[40];
	filme reg;
	FILE *ptr = fopen("Binario.dat", "rb");
	FILE *ptr2 = fopen("OrdenadoProducao.txt", "w");
	int TL=0, i, j, aux;
	
	fread(&reg, sizeof(filme), 1, ptr);
	while(!feof(ptr) && TL<40){
		strcpy(estrutura[TL].nome, reg.nome);
		estrutura[TL].ano = reg.ano;
		
		TL++;
		fread(&reg, sizeof(filme), 1, ptr);
	}
	
	for(int i=TL-1; i>0; i--){
		for(int j=0; j<i; j++){
			if(estrutura[j].ano > estrutura[j+1].ano){
				aux = estrutura[j].ano;
				estrutura[j].ano = estrutura[j+1].ano;
				estrutura[j+1].ano = aux; 
			}		
		}
	}
	
	for(int i=0; i<TL; i++){
		fprintf(ptr2, "%d", estrutura[i].ano);
		fputc('\t', ptr2);
		fputs(estrutura[i].nome, ptr2);
		fputc('\n', ptr2);
	}

	printf("Ordenado pelo ano de producao\n");
	fclose(ptr);
	fclose(ptr2);
	getch();
}

void ordenatxespec(){
	filme reg;
	espec estrutura[40];
	FILE *ptr = fopen("Binario.dat", "rb");
	FILE *ptr2 = fopen("OrdenadoTaxaEspec.txt", "w");
	int TL=0, i, j, aux;
	
	//Passando os registros da struct para o vetor 'estrutura'
	fread(&reg, sizeof(filme), 1, ptr);
	while(!feof(ptr) && TL<40){
		strcpy(estrutura[TL].nome, reg.nome);
		estrutura[TL].txespec = reg.espec;
		
		TL++;
		fread(&reg, sizeof(filme), 1, ptr);
	}
	
	//Ordenando o vetor 'estrutura'
	for(int i=TL-1; i>0; i--){
		for(int j=0; j<i; j++){
			if(estrutura[j].txespec > estrutura[j+1].txespec){
				aux = estrutura[j].txespec;
				estrutura[j].txespec = estrutura[j+1].txespec;
				estrutura[j+1].txespec = aux;
			}
		}
	}
	
	//Exibindo o vetor 'estrutura'
	for(int i=0; i<TL; i++){
		fprintf(ptr2, "%d", estrutura[i].txespec);
		fputc('\t', ptr2);
		fputs(estrutura[i].nome, ptr2);
		fputc('\n', ptr2);
	}
	
	printf("Ordenado do menor para o maior pela taxa de espectador\n");
	fclose(ptr);
	fclose(ptr2);
	getch();
	
}

void valor_mediano(){
	filme reg;
	valormediano estrutura[40];
	FILE *ptr = fopen("Binario.dat", "rb");
	int TL=0, aux, meio, media;
	
	//Passando os registros da struct para o vetor 'estrutura'
	fread(&reg, sizeof(filme), 1, ptr);
	while(!feof(ptr)){
		estrutura[TL].ano = reg.ano;
		strcpy(estrutura[TL].nome, reg.nome);
		
		TL++;
		fread(&reg, sizeof(filme), 1, ptr);
	}
	
	//Ordenando o vetor 'estrutura'
	for(int i=TL-1; i>0; i--){
		for(int j=0; j<i; j++){
			if(estrutura[j].ano > estrutura[i].ano){
				aux = estrutura[j].ano;
				estrutura[j].ano = estrutura[j+1].ano;
				estrutura[j+1].ano = aux;			
			}
		}
	}
	
	//Verificando elemento central do vetor
	meio = TL/2;
	if(meio%2 != 0)
		printf("O valor mediano de ano eh: %d \t %s\n", estrutura[meio].ano, estrutura[meio].nome);
	else{
		media = (estrutura[meio].ano+estrutura[meio].ano)/2;
		printf("O valor mediano de ano eh %d (media entre os dois elementos mais centrais): \n", media);
	}
	
	fclose(ptr);
	getch();
}



 
 
 
 
int main()
{
	//MaiorLucro();
	//MaiorEspec();
	//TxtparaBin();
	//MediaHoras();
	//prod_filmes_ano();
	//classification();
	//anoproducao();
	//ordenatxespec();
	valor_mediano();
}
