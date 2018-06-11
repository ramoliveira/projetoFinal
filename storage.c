#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gerenciamento.h"
#include "storage.h"

/*
Objetivo: Verificar a existência de um arquivo.
Entrada: Nome do arquivo a ser verificada a existência.
Saída: Inteiro com o valor lógico referente a existência do arquivo.
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
Objetivo: Criar um arquivo binário.
Entrada: Nome do arquivo a ser criado.
Saída: Nenhuma.
*/

void criaArquivo(char nomeArquivo[TAM_NOME]) {
	FILE *f;
	if((f = fopen(nomeArquivo, "wb+")) == NULL) {
		printf("Nao foi possivel criar o arquivo %s.\n", nomeArquivo);
		getch();
		exit(EXIT_FAILURE);
	} else {
		fclose(f);
	}
}

equipe* coletaDadosEquipe(int *qtdEquipCad, FILE *f) {
	equipe aux, *pEquipe = NULL;
	int i = 0;
	
	fseek(f, 0, SEEK_SET);
	while(fread(&aux, sizeof(equipe), 1, f) == 1) {
		*qtdEquipCad += 1;
	}
	if (*qtdEquipCad != 0) {
		if((pEquipe = (equipe*) malloc(*qtdEquipCad * sizeof(equipe))) == NULL) {
			printf("Nao foi possivel alocar.\n");
		}
		fseek(f, 0, SEEK_SET);
		while(fread((pEquipe+i), sizeof(equipe), 1, f) == 1) {
			i++;
		}
		for (i = 0; i < *qtdEquipCad; i++) {
			printf("Equipe: %s\n", (pEquipe+i)->nome);
		}
		getch();
	}
	return pEquipe;
}
