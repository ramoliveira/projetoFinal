#include <stdio.h>
#include <stdlib.h>
#include "storage.h"

/*
Objetivo: Verificar a exist�ncia de um arquivo.
Entrada: Nome do arquivo a ser verificada a exist�ncia.
Sa�da: Inteiro com o valor l�gico referente a exist�ncia do arquivo.
*/

int existeArquivo(char nomeArquivo[TAM_NOME]) {
	FILE *f;
	if((f = fopen(nomeArquivo, "rb")) == NULL) {
		return 0;
	} else {
		fclose(f);
		return 1;
	}
}

/*
Objetivo: Criar um arquivo bin�rio.
Entrada: Nome do arquivo a ser criado.
Sa�da: Nenhuma.
*/

void criaArquivo(char nomeArquivo[TAM_NOME]) {
	FILE *f;
	if((f = fopen(nomeArquivo, "w+b")) == NULL) {
		printf("Nao foi possivel criar o arquivo %s.\n", nomeArquivo);
		getch();
		exit(EXIT_FAILURE);
	} else {
		fclose(f);
	}
}
