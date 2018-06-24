/* Armazenamento(storage) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gerenciamento.h"
#include "storage.h"

/* Objetivo: Verificar a exist�ncia de um arquivo.
Entrada: Nome do arquivo a ser verificada a exist�ncia.
Sa�da: Inteiro com o valor l�gico referente a exist�ncia do arquivo. */

int existeArquivo(char *nomeArquivo, char *tipo) {
	FILE *f;
	if((f = fopen(nomeArquivo, tipo)) == NULL) {
		return 0;
	} else {
		fclose(f);
		return 1;
	}
}

/* Objetivo: Criar um arquivo bin�rio.
Entrada: Nome do arquivo a ser criado.
Sa�da: Nenhuma. */

void criaArquivo(char *nomeArquivo, char *tipo) {
	FILE *f = NULL;
	if((f = fopen(nomeArquivo, tipo)) == NULL) {
		printf("Nao foi possivel criar o arquivo %s.\n", nomeArquivo);
		getch();
		exit(EXIT_FAILURE);
	} else {
		fclose(f);
	}
}

/* Objetivo: Coletar os dados das equipes do arquivo e armazen�-los em uma aloca��o din�mica.
Entrada: Ponteiro da quantidade das equipes, do arquivo onde est�o as esquipes.
Sa�da: Ponteiro da aloca��o din�mica das equipes. */

equipe* coletaDadosEquipe(int *qtdEquipe, FILE *f) {
	equipe aux, *pEquipe = NULL;
	int i = 0;
	
	fseek(f, 0, SEEK_SET);
	while(fread(&aux, sizeof(equipe), 1, f) == 1) {
		*qtdEquipe += 1;
	}
	if (*qtdEquipe != 0) {
		if((pEquipe = (equipe*) calloc(*qtdEquipe, sizeof(equipe))) == NULL) {
			printf("Nao foi possivel alocar para as equipes.\n");
			getch();
			exit(EXIT_FAILURE);
		}
		fseek(f, 0, SEEK_SET);
		while(fread((pEquipe+i), sizeof(equipe), 1, f) == 1) {
			i++;
		}
	}
	return pEquipe;
}

/* Objetivo: Coletar os dados dos pilotos do arquivo e armazen�-los em uma aloca��o din�mica.
Entrada: Ponteiro da quantidade dos pilotos, do arquivo onde est�o os pilotos.
Sa�da: Ponteiro da aloca��o din�mica dos pilotos. */

piloto* coletaDadosPiloto(int *qtdPiloto, FILE *f) {
	piloto aux, *pPiloto = NULL;
	int i = 0;
	
	fseek(f, 0, SEEK_SET);
	while(fread(&aux, sizeof(piloto), 1, f) == 1) {
		*qtdPiloto += 1;
	}
	if (*qtdPiloto != 0) {
		if ((pPiloto = (piloto*) calloc(*qtdPiloto,sizeof(piloto))) == NULL) {
			printf("Nao foi possivel alocar para os pilotos.\n");
			getch();
			exit(EXIT_FAILURE);
		}
		fseek(f, 0, SEEK_SET);
		while(fread((pPiloto+i), sizeof(piloto), 1, f) == 1) {
			i++;
		}
	}
	return pPiloto;
}

/* Objetivo: Coletar os dados dos circuitos do arquivo e armazen�-los em uma aloca��o din�mica.
Entrada: Ponteiro da quantidade dos circuitos, do arquivo onde est�o os circuitos.
Sa�da: Ponteiro da aloca��o din�mica dos circuitos. */

circuito* coletaDadosCircuito(int *qtdCircuito, FILE *f) {
	circuito aux, *pCircuito = NULL;
	int i = 0;
	
	fseek(f, 0, SEEK_SET);
	while(fread(&aux, sizeof(circuito), 1, f) == 1) {
		*qtdCircuito += 1;
	}
	if (*qtdCircuito != 0) {
		if ((pCircuito = (circuito*) calloc(*qtdCircuito, sizeof(circuito))) == NULL) {
			printf("Nao foi possivel alocar para os circuitos.\n");
			getch();
			exit(EXIT_FAILURE);
		}
		fseek(f, 0, SEEK_SET);
		while(fread((pCircuito+i), sizeof(circuito), 1, f) == 1) {
			i++;
		}
	}
	return pCircuito;
}

/* Objetivo: Coletar os dados de voltas do arquivo e armazen�-los em uma aloca��o din�mica.
Entrada: Ponteiro da quantidade das voltas, do arquivo onde est�o as voltas.
Sa�da: Ponteiro da aloca��o din�mica das voltas. */

volta* coletaDadosVolta(int *qtdVolta, FILE *f) {
	volta aux, *pVolta = NULL;
	int i = 0;
	
	fseek(f, 0, SEEK_SET);
	while(fread(&aux, sizeof(volta), 1, f) == 1) {
		*qtdVolta += 1;
	}
	if (*qtdVolta != 0) {
		if ((pVolta = (volta*) calloc(*qtdVolta, sizeof(volta))) == NULL) {
			printf("Nao foi possivel alocar para as voltas.\n");
			getch();
			exit(EXIT_FAILURE);
		}
		fseek(f, 0, SEEK_SET);
		while(fread((pVolta+i), sizeof(volta), 1, f) == 1) {
			i++;
		}
	}
	return pVolta;
}

/* Objetivo: Coletar os dados dos paises do arquivo e armazen�-los em uma aloca��o din�mica.
Entrada: Ponteiro da quantidade dos paises, do arquivo onde est�o os paises.
Sa�da: Ponteiro da aloca��o din�mica dos paises. */

pais* coletaDadosPais(int *qtdPais, FILE *f) {
	pais aux, *pPais = NULL;
	int i = 0;
	
	fseek(f, 0, SEEK_SET);
	while(!feof(f)) {
		fscanf(f, "%s", &aux.sigla);
		fseek(f, (long) sizeof(char), SEEK_CUR);
		fscanf(f, "%[^\n]s\n", &aux.nome);
		*qtdPais += 1;
	}
	if (*qtdPais != 0) {
		if ((pPais = (pais*) calloc(*qtdPais, sizeof(pais))) == NULL) {
			printf("Nao foi possivel alocar para os paises.\n");
			getch();
			exit(EXIT_FAILURE);
		}
		fseek(f, 0, SEEK_SET);
		while(!feof(f)) {
			fscanf(f, "%s", (pPais+i)->sigla);
			fseek(f, (long) sizeof(char), SEEK_CUR);
			fscanf(f, "%[^\n]s\n", (pPais+i)->nome);
			i++;
		}
	}
	return pPais;
}
