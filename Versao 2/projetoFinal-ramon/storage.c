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
Entrada: ponteiro da quantidade de equipe, ponteiro do arquivo
Saída: ponteiro de equipe
*/

equipe* coletaDadosEquipe(int *qtdEquipCad, FILE *f) {
	
	equipe aux, *pEquipe;
	int i=0;	
		
	fseek(f, 0, SEEK_SET);
	while(!feof(f)) {
		if(fread(&aux, sizeof(equipe), 1, f) == 1) {
		*qtdEquipCad+=1;
		} else {
			break;
		}
	}
	
	if (*qtdEquipCad != 0) {
		pEquipe = malloc((*qtdEquipCad) * sizeof(equipe));
		fseek(f, 0, SEEK_SET);
		while(!feof(f)) {
			if(fread((pEquipe+i), sizeof(equipe), 1, f) == 1) {
				i++;
			} else {
				break;
			}
		}
	}
	
	return pEquipe;
}

/*Objetivo: coleta a quantidade de cadastros do arquivo piloto e aloca um espaço de memória
Entrada: ponteiro da quantidade de piloto, ponteiro do arquivo
Saída: ponteiro de piloto
*/

piloto* coletaDadosPiloto(int *qtdPilotosCad, FILE *f) {
	
	piloto aux, *pPiloto;
	int i=0;
	
	fseek(f, 0, SEEK_SET);
	while(!feof(f)) {
		if(fread(&aux, sizeof(piloto), 1, f) == 1) {
			*qtdPilotosCad += 1;
		} else {
			break;
		}
	}
	
	if (*qtdPilotosCad != 0) {
		pPiloto = malloc((*qtdPilotosCad) * sizeof(piloto));
		fseek(f, 0, SEEK_SET);
		while(!feof(f)) {
			if(fread((pPiloto+i), sizeof(piloto), 1, f) == 1) {
				i++;
			} else {
				break;
			}
		}
	}
	
	return pPiloto;
}

/*Objetivo: coleta a quantidade de cadastros do arquivo circuito e aloca um espaço de memória
Entrada: ponteiro da quantidade de circuito, ponteiro do arquivo
Saída: ponteiro de circuito
*/

circuito* coletaDadosCircuito(int *qtdCircuitosCad, FILE *f) {
	
	struct Circuito aux;
	int i=0;
	
	fseek(f, 0, SEEK_SET);
	while(!feof(f)) {
		if(fread(&aux, sizeof(circuito), 1, f) == 1) {
			*qtdCircuitosCad+=1;
		} else {
			break;
		}
	}
	if (*qtdCircuitosCad != 0) {
		pCircuito = malloc((*qtdCircuitosCad) * sizeof(circuito));
		fseek(f, 0, SEEK_SET);
		while(!feof(f)) {
			if(fread((pCircuito+i), sizeof(circuito), 1, f) == 1) {
				i++;
			} else {
				break;
			}
		}
	}
	
	return pCircuito;
}

/*Objetivo: coleta a quantidade de cadastros do arquivo voltas e aloca um espaço de memória
Entrada: ponteiro da quantidade de volta, ponteiro do arquivo
Saída: ponteiro de volta
*/

volta* coletaDadosVolta(int *qtdVoltasCad, FILE *f) {
	
	volta aux, *pVolta;
	int i=0;
	
	fseek(f, 0, SEEK_SET);
	while(!feof(f)) {
		if(fread(&aux, sizeof(volta), 1, f) == 1) {
			*qtdVoltasCad+=1;
		} else {
			break;
		}
	}
	
	if (*qtdVoltasCad != 0) {
		pVolta = malloc((*qtdVoltasCad) * sizeof(volta));
		fseek(f, 0, SEEK_SET);
		while(!feof(f)) {
			if(fread((pVolta+i), sizeof(volta), 1, f) == 1) {
				i++;
			} else {
				break;
			}
		}
	}
	
	return pVolta;
}







