#include <stdio.h>
#include <stdlib.h>
#include "gerenciamento.h"
#include "storage.h"

/*
Objetivo: Verificar a existência de um arquivo.
Entrada: Nome do arquivo a ser verificada a existência.
Saída: Inteiro com o valor lógico referente a existência do arquivo.
*/

int existeArquivo(char nomeArquivo[TAM_NOME]){
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
	if((f = fopen(nomeArquivo, "wb")) == NULL) {
		printf("Nao foi possivel criar o arquivo %s.\n", nomeArquivo);
		getch();
		exit(EXIT_FAILURE);
	} else {
		fclose(f);
	}
}

/*Objetivo: coleta a quantidade de cadastros do arquivo equipe e aloca um espaço de memória
Entrada: ponteiro da estrutura de equipe, ponteiro da quantidade de equipe, ponteiro do arquivo
Saída: nenhum
*/

void coletaDadosEquipe(struct Equipe *pEquipe, int *qtdEquipCad, FILE *f) {
	
	struct Equipe aux;
	int i=0;	
		
	fseek(f, 0, SEEK_SET);
	while(!feof(f)) {
		if(fread(&aux, sizeof(struct Equipe), 1, f) == 1) {
		*qtdEquipCad+=1;
		} else {
			break;
		}
	}
	
	if (*qtdEquipCad != 0) {
		pEquipe = malloc((*qtdEquipCad) * sizeof(struct Equipe));
		fseek(f, 0, SEEK_SET);
		while(!feof(f)) {
			if(fread((pEquipe+i), sizeof(struct Equipe), 1, f) == 1) {
				i++;
			} else {
				break;
			}
		}
	}
}

/*Objetivo: coleta a quantidade de cadastros do arquivo piloto e aloca um espaço de memória
Entrada: ponteiro da estrutura de piloto, ponteiro da quantidade de piloto, ponteiro do arquivo
Saída: nenhum
*/

void coletaDadosPiloto(struct Piloto *pPiloto, int *qtdPilotosCad, FILE *f) {
	
	struct Piloto aux;
	int i=0;
	
	fseek(f, 0, SEEK_SET);
	while(!feof(f)) {
		if(fread(&aux, sizeof(struct Piloto), 1, f) == 1) {
			*qtdPilotosCad += 1;
		} else {
			break;
		}
	}
	
	if (*qtdPilotosCad != 0) {
		pPiloto = malloc((*qtdPilotosCad) * sizeof(struct Piloto));
		fseek(f, 0, SEEK_SET);
		while(!feof(f)) {
			if(fread((pPiloto+i), sizeof(struct Piloto), 1, f) == 1) {
				i++;
			} else {
				break;
			}
		}
	}
}

/*Objetivo: coleta a quantidade de cadastros do arquivo circuito e aloca um espaço de memória
Entrada: ponteiro da estrutura de circuito, ponteiro da quantidade de circuito, ponteiro do arquivo
Saída: nenhum
*/

void coletaDadosCircuito(struct Circuito *pCircuito, int *qtdCircuitosCad, FILE *f) {
	
	struct Circuito aux;
	int i=0;
	
	fseek(f, 0, SEEK_SET);
	while(!feof(f)) {
		if(fread(&aux, sizeof(struct Circuito), 1, f) == 1) {
			*qtdCircuitosCad+=1;
		} else {
			break;
		}
	}
	if (*qtdCircuitosCad != 0) {
		pCircuito = malloc((*qtdCircuitosCad) * sizeof(struct Circuito));
		fseek(f, 0, SEEK_SET);
		while(!feof(f)) {
			if(fread((pCircuito+i), sizeof(struct Circuito), 1, f) == 1) {
				i++;
			} else {
				break;
			}
		}
	}
}

/*Objetivo: coleta a quantidade de cadastros do arquivo voltas e aloca um espaço de memória
Entrada: ponteiro da estrutura de volta, ponteiro da quantidade de volta, ponteiro do arquivo
Saída: nenhum
*/

void coletaDadosVolta(struct Volta *pVolta, int *qtdVoltasCad, FILE *f) {
	
	struct Volta aux;
	int i=0;
	
	fseek(f, 0, SEEK_SET);
	while(!feof(f)) {
		if(fread(&aux, sizeof(struct Volta), 1, f) == 1) {
			*qtdVoltasCad+=1;
		} else {
			break;
		}
	}
	
	if (*qtdVoltasCad != 0) {
		pVolta = malloc((*qtdVoltasCad) * sizeof(struct Volta));
		fseek(f, 0, SEEK_SET);
		while(!feof(f)) {
			if(fread((pVolta+i), sizeof(struct Volta), 1, f) == 1) {
				i++;
			} else {
				break;
			}
		}
	}
}





