#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gerenciamento.h"
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
	if((f = fopen(nomeArquivo, "wb")) == NULL) {
		printf("Nao foi possivel criar o arquivo %s.\n", nomeArquivo);
		getch();
		exit(EXIT_FAILURE);
	} else {
		fclose(f);
	}
}

void coletaDadosEquipe(struct Equipe *pEquipe, int *qtdEquipCad, FILE *f) {
	struct Equipe aux;
	int i = 0;
	
	fseek(f, 0, SEEK_SET);
	while(fread(&aux, sizeof(struct Equipe), 1, f) == 1) {
		*qtdEquipCad += 1;
	}
	if (*qtdEquipCad != 0) {
		if((pEquipe = (struct Equipe*) malloc(*qtdEquipCad * sizeof(struct Equipe))) == NULL) {
			printf("Nao foi possivel alocar.\n");
		}
		fseek(f, 0, SEEK_SET);
		while(fread((pEquipe+i), sizeof(struct Equipe), 1, f) == 1) {
			i++;
		}
		for (i = 0; i < *qtdEquipCad; i++) {
			printf("EQUIPE: %s\n", (*(pEquipe+i)).nome);
		}
		getch();
	}
	
}
