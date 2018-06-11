/*Gerenciamento e controle dos dados cadastrais - Tópico 2.1*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "validacoes.h"
#include "ui.h"
#include "gerenciamento.h"
#include "storage.h"

/******PILOTOS*******/
/*Objetivo: incluir um piloto 
Parâmetros:
Retorno: nenhum */

void inclusaoPilotos(){
	/*Fazer a chamada da função de cadastramento de pilotos*/
	/*Utilizar pesquisa binária para identificar repetição de código de piloto*/
	FILE *f;
	int opcao;
	
	if (!existeArquivo("equipes.bin")) {
		system("cls");
		cabecalho("Inclusao de Pilotos");
		printf("Por favor cadastre uma equipe primeiro!\n");
		printf("Aperte ENTER para voltar ao menu.\n");
		getch();
		return;
	} else {
		if((f = fopen("equipe.bin", "r+b")) == NULL) {
			printf("Arquivo indisponivel!\n");
			exit(EXIT_FAILURE);
		} else {
			do {
				
			} while(opcao == 1);
		}
	}
}

/*Objetivo: alterar um piloto que usuário desejar
Parâmetros: ponteiro da estrutura piloto e ponteiro da quantidade de pilotos
Retorno: nenhum */

void alterarPilotos(piloto *dadosPilotos, int *qtdPilotos){
	
	/*Fazer a chamada da função de apresenta pilotos para a escolha por meio do código*/	
	
}

/*Objetivo: excluir um piloto que usuário desejar
Parâmetros: ponteiro da estrutura piloto e ponteiro da quantidade de pilotos
Retorno: nenhum */


void excluirPilotos(piloto *dadosPilotos, int *qtdPilotos){
		
	/*Fazer a chamada da função de apresenta pilotos para a escolha por meio do código*/
	
}

/******EQUIPES******/
/*Objetivo: incluir uma equipe 
Parâmetros: 
Retorno: nenhum */

void inclusaoEquipes(){
	
	/*Fazer a chamada da função de cadastramento de equipes*/
	/*Utilizar pesquisa binária para identificar repetição de código de equipe*/
	
	FILE *f;
	int qtdEquipCad, i = 0, flag;
	char opcao = '\0';
	equipe equipeCadastro, *pEquipe;
	
	if (!existeArquivo("equipes.dat")) {
		criaArquivo("equipes.dat");
	}
	 
	if((f = fopen("equipes.dat", "rb+")) == NULL) {
		printf("Arquivo ""equipes.dat"" indisponivel.\n");
		exit(EXIT_FAILURE);
	}
	do {
		qtdEquipCad = 0;
		pEquipe = coletaDadosEquipe(&qtdEquipCad, f);
		do {
			system("cls");
			strcpy(equipeCadastro.nome, "");
			strcpy(equipeCadastro.pais, "");
			strcpy(equipeCadastro.sigla, "");
			flag = 1;
			cabecalho("Cadastro de Equipe");
			leValidaNome("Digite o nome da equipe: ", equipeCadastro.nome);
			leValidaSigla("Digite a sigla [SSS]: ", equipeCadastro.sigla);
			leValidaNome("Digite o nome do pais da equipe: ", equipeCadastro.pais);
			if (qtdEquipCad != 0) {
				for (i = 0; i < qtdEquipCad; i++) {
					if (stricmp(pEquipe[i].sigla, equipeCadastro.sigla) == 0) {
						printf("Equipe Invalida! Esta equipe ja esta cadastrada!\n");
						flag = 0;
						break;
					} else {
						flag = 1;
					}
				}
			}
			if (flag) {
				fseek(f, 0, SEEK_END);
				fwrite(&equipeCadastro, sizeof(equipe), 1, f);
			}
		} while(!flag);
		apresentaEscolheMenuRepete(&opcao);
		if (qtdEquipCad != 0) {
			free(pEquipe);
		}
	} while(opcao == 's');
	fclose(f);
}

/*Objetivo: excluir uma equipe que usuário desejar
Parâmetros: ponteiro da estrutura equipe e ponteiro da quantidade de equipes
Retorno: nenhum */

void excluirEquipes(equipe *dadosEquipes, int *qtdEquipes){
		
	/*Fazer a chamada da função de apresenta equipes para a escolha por meio da sigla*/
	
}

/******CIRCUITOS*******/
/*Objetivo: inclusão de um circuito 
Parâmetros: ponteiro da estrutura circuito e ponteiro da quantidade de circuitos
Retorno: nenhum */

void inclusaoCircuitos(circuito *dadosCircuito, int *qtdCircuitos){
	
	/*Fazer a chamada da função de cadastramento de circuitos*/
	/*Utilizar pesquisa binária para identificar repetição de código de circuito*/
		
}

/*Objetivo: alterar um circuito que usuário desejar
Parâmetros: ponteiro da estrutura circuito e ponteiro da quantidade de circuitos
Retorno: nenhum*/

void alterarCircuitos(circuito *dadosCircuito, int *qtdCircuitos){
	
	/*Fazer a chamada da função de apresenta circuitos para a escolha por meio do código*/	
	
}

/*****VOLTAS*****/
/*Objetivo: inclusão de uma volta 
Parâmetros: ponteiro da estrutura voltas e ponteiro da quantidade de voltas
Retorno: nenhum */

void inclusaoVoltas(volta *dadosVoltas, int *qtdVoltas){
	
	/*Fazer a chamada da função de cadastramento de voltas*/
}

/*Objetivo: alterar dados de uma volta que usuário desejar
Parâmetros: ponteiro da estrutura voltas e ponteiro da quantidade de voltas
Retorno: nenhum */

void alterarVoltas(volta *dadosVoltas, int *qtdVoltas){
	
	/*Fazer a chamada da função de apresenta voltas para a escolha*/
	
}

/*Objetivo: excluir uma volta que usuário desejar
Parâmetros: ponteiro da estrutura voltas e ponteiro da quantidade de voltas
Retorno: nenhum */

void exclusaoVoltas(volta *dadosVoltas, int *qtdVoltas){
	
	/*Fazer a chamada da função de apresenta voltas para a escolha*/
	
}

