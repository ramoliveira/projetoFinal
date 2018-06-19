/*Gerenciamento e controle dos dados cadastrais - Tópico 2.1*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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
	
	FILE *f, *p, *q;
	char opcao = '\0';
	int qtdEquipCad, qtdPilotCad, qtdPaisCad, flag, numeros[QTD_NUM], opcaoId, opcaoEquipe, opcaoPais, i;
	equipe *pEquip;
	pais *pPais;
	piloto *pPiloto, pilotoCadastro;
	
	if (!existeArquivo("pilotos.dat", "rb")) {
		criaArquivo("pilotos.dat", "wb+");
	}
	if ((f = fopen("pilotos.dat", "rb+")) == NULL) {
		ERRO_DB_PILOTO
		exit(EXIT_FAILURE);
	}
	if (!existeArquivo("paises.txt", "rt")) {
		criaArquivo("paises.txt", "wt+");
	}
	if ((p = fopen("paises.txt", "rt+")) == NULL) {
		ERRO_DB_PAIS
		exit(EXIT_FAILURE);
	}
	if (!existeArquivo("equipes.dat", "rb")) {
		criaArquivo("equipes.dat", "wb+");
	}
	if ((q = fopen("equipes.dat", "rb+")) == NULL) {
		ERRO_DB_EQUIP
		exit(EXIT_FAILURE);
	}
	do {
		flag = 1;
		qtdEquipCad = 0;
		qtdPilotCad = 0;
		qtdPaisCad = 0;
		pEquip = coletaDadosEquipe(&qtdEquipCad, q);
		pPiloto = coletaDadosPiloto(&qtdPilotCad, f);
		pPais = coletaDadosPais(&qtdPaisCad, p);
		system("cls");
		strcpy(pilotoCadastro.nome, "");
		strcpy(pilotoCadastro.dataNascimento, "");
		strcpy(pilotoCadastro.equipePiloto.nome, "");
		strcpy(pilotoCadastro.equipePiloto.sigla, "");
		strcpy(pilotoCadastro.equipePiloto.paisEquipe.nome, "");
		strcpy(pilotoCadastro.equipePiloto.paisEquipe.sigla, "");
		strcpy(pilotoCadastro.paisPiloto.nome, "");
		strcpy(pilotoCadastro.paisPiloto.sigla, "");
		pilotoCadastro.sexo = '\0';
		pilotoCadastro.id = -1;
		cabecalho("Cadastro de Piloto");
		
		do {
			leValidaNome("Digite o nome do piloto: ", pilotoCadastro.nome);
			if (qtdPilotCad != 0) {
				for (i = 0; i < qtdPilotCad; i++) {
					if (stricmp(pilotoCadastro.nome, pPiloto[i].nome) == 0) {
						ERRO_CAD_PILOT
						getch();
						flag = 0;
						break;
					} else {
						flag = 1;
					}
				}
			}
		} while(!flag);

		leValidaData(pilotoCadastro.dataNascimento, "Digite a data de nascimento do piloto: ");
		leValidaChar(&pilotoCadastro.sexo, 'm', 'f', "Digite o sexo do piloto [m/f]: ");
		
		LINHA
		
		geraNumerosPiloto(numeros, pPiloto, &qtdPilotCad);
		printf("Escolha um ID para o piloto dos numeros abaixo:\n");
		for (i = 0; i < QTD_NUM; i++) {
			printf("(%2d) - %3d\n", i+1, numeros[i]);
		}
		leValidaInt(&opcaoId, 1, i+1, "Digite de acordo com o indice: ");
		pilotoCadastro.id = numeros[opcaoId-1];
		
		LINHA
		
		if (qtdPaisCad != 0) {
			printf("Escolha o pais do piloto:\n");
			for (i = 0; i < qtdPaisCad; i++) {
				printf("(%2d) - Pais: %-15s Sigla: %3s\n", i+1, pPais[i].nome, pPais[i].sigla);
			}
			leValidaInt(&opcaoPais, 1, i+1, "Digite de acordo com o indice: ");
			pilotoCadastro.paisPiloto = pPais[opcaoPais-1];
		} else {
			ERRO_DB_PAIS_VAZIO
		}
		
		LINHA
		
		if (qtdEquipCad != 0) {
			printf("Escolha a equipe do piloto:\n");
			for (i = 0; i < qtdEquipCad; i++) {
				printf("(%2d) - Sigla: %3s Nome: %-15s\n", i+1, pEquip[i].sigla, pEquip[i].nome);
			}
			leValidaInt(&opcaoEquipe, 1, i+1, "Digite de acordo com o indice: ");
			pilotoCadastro.equipePiloto = pEquip[opcaoEquipe-1];
		} else {
			ERRO_DB_EQUIPE_VAZIO
		}
		
		fwrite(&pilotoCadastro, sizeof(piloto), 1, f);
		
		apresentaEscolheMenuRepete(&opcao);
		if (qtdPaisCad != 0) {
			free(pPais);
		}
		if (qtdEquipCad != 0) {
			free(pEquip);
		}
		if (qtdPilotCad != 0) {
			free(pPiloto);
		}
	} while(opcao == 's');
	fclose(f);
	fclose(p);
	fclose(q);
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
	
	FILE *f, *p;
	int qtdEquipCad, qtdPaisCad, i = 0, flag;
	char opcao = '\0';
	int opcaoPais = -1;
	equipe equipeCadastro, *pEquipe;
	pais *pPais;
	
	if (!existeArquivo("equipes.dat", "rb")) {
		criaArquivo("equipes.dat", "wb+");
	}
	if((f = fopen("equipes.dat", "rb+")) == NULL) {
		printf("Arquivo ""equipes.dat"" indisponivel.\n");
		exit(EXIT_FAILURE);
	}
	if (!existeArquivo("paises.txt", "rt")) {
		criaArquivo("paises.txt", "wt+");
	}
	if ((p = fopen("paises.txt", "rt+")) == NULL) {
		printf("Arquivo ""paises.txt"" indisponivel.\n");
		exit(EXIT_FAILURE);
	}
	
	do {
		qtdEquipCad = 0;
		qtdPaisCad = 0;
		pEquipe = coletaDadosEquipe(&qtdEquipCad, f);
		pPais = coletaDadosPais(&qtdPaisCad, p);
		do {
			system("cls");
			strcpy(equipeCadastro.nome, "");
			strcpy(equipeCadastro.paisEquipe.nome, "");
			strcpy(equipeCadastro.paisEquipe.sigla, "");
			strcpy(equipeCadastro.sigla, "");
			flag = 1;
			
			cabecalho("Cadastro de Equipe");
			leValidaNome("Digite o nome da equipe: ", equipeCadastro.nome);
			leValidaSigla("Digite a sigla da equipe [SSS]: ", equipeCadastro.sigla);
			
			if (qtdPaisCad != 0) {
				printf("Escolha um pais para a equipe:\n");
				for (i = 0; i < qtdPaisCad; i++) {
					printf("(%d) - [%s] %s\n", i+1, pPais[i].sigla, pPais[i].nome);
				}
				leValidaInt(&opcaoPais, 1, i+1, "Digite o pais escolhido:\n");
				equipeCadastro.paisEquipe = pPais[opcaoPais-1];
			} else {
				ERRO_DB_PAIS_VAZIO
				leValidaSigla("Digite a sigla do pais da equipe [SSS]: ", equipeCadastro.paisEquipe.sigla);
				leValidaNome("Digite o nome do pais da equipe: ", equipeCadastro.paisEquipe.nome);
			}
			
			if (qtdEquipCad != 0) {
				for (i = 0; i < qtdEquipCad; i++) {
					if (stricmp(pEquipe[i].sigla, equipeCadastro.sigla) == 0) {
						ERRO_CAD_EQUIP
						getch();
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
		if (qtdPaisCad != 0) {
			free(pPais);
		}
	} while(opcao == 's');
	fclose(p);
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

void inclusaoCircuitos(){
	
	/*Fazer a chamada da função de cadastramento de circuitos*/
	/*Utilizar pesquisa binária para identificar repetição de código de circuito*/
	FILE *a, *b, *c;
	char opcao = '\0';
	int flag, qtdPilotoCad, qtdPaisCad, qtdCircuitCad, opcaoPais, i;
	piloto *pPiloto;
	pais *pPais;
	circuito *pCircuito, circuitoCadastro;
	
	if (!existeArquivo("pilotos.dat", "rb")) {
		criaArquivo("pilotos.dat", "wb+");
	}
	if ((a = fopen("pilotos.dat", "rb+")) == NULL) {
		ERRO_DB_PILOTO
		exit(EXIT_FAILURE);
	}
	if (!existeArquivo("paises.txt", "rt")) {
		criaArquivo("paises.txt", "wt+");
	}
	if ((b = fopen("paises.txt", "rt+")) == NULL) {
		ERRO_DB_PAIS
		exit(EXIT_FAILURE);
	}
	if (!existeArquivo("circuitos.dat", "rb")) {
		criaArquivo("circuitos.dat", "wb+");
	}
	if ((c = fopen("circuitos.dat", "rb+")) == NULL) {
		ERRO_DB_CIRCUITO
		exit(EXIT_FAILURE);
	}
	
	do {
		flag = 1;
		pPiloto = coletaDadosPiloto(&qtdPilotoCad, a);
		pPais = coletaDadosPais(&qtdPaisCad, b);
		pCircuito = coletaDadosCircuito(&qtdCircuitCad, c);
		
		system("cls");
		strcpy(circuitoCadastro.nome, "");
		strcpy(circuitoCadastro.pilotoMenorTempo, "");
		circuitoCadastro.id = -1;
		circuitoCadastro.quilometros = -1;
		strcpy(circuitoCadastro.paisCircuito.nome, "");
		strcpy(circuitoCadastro.paisCircuito.sigla, "");
		circuitoCadastro.menorTempo.minutos = -1;
		circuitoCadastro.menorTempo.segundos = -1;
		circuitoCadastro.menorTempo.milisegundos = -1;
		
		cabecalho("Cadastro de Circuitos");
		circuitoCadastro.id = qtdCircuitCad + 1;
		leValidaNome("Digite o nome do circuito: ", circuitoCadastro.nome);
		
		LINHA
		
		printf("Escolha o pais do circuito:\n");
		for (i = 0; i < qtdPaisCad; i++) {
			printf("(%2d) - Pais: %-15s Sigla: %3s\n", i+1, pPais[i].nome, pPais[i].sigla);
		}
		leValidaInt(&opcaoPais, 1, i+1, "Digite de acordo com o indice: ");
		circuitoCadastro.paisCircuito = pPais[opcaoPais-1];
		
		LINHA
		
		leValidaFloat(&circuitoCadastro.quilometros, 3000, 29000, "Digite o tamanho do circuito: ");
		
		LINHA
		
		leValidaTempo(&circuitoCadastro.menorTempo.minutos, &circuitoCadastro.menorTempo.segundos, &circuitoCadastro.menorTempo.milisegundos, "Digite o menor tempo do circuito [min:seg:mili]: ");
		
		LINHA
		
		leValidaNome("Digite o nome do piloto com menor tempo no circuito: ", circuitoCadastro.pilotoMenorTempo);
		printf("Escolha o piloto com o menor tempo no circuito:\n");
		for (i = 0; i < qtdPilotoCad; i++) {
			printf("(%2d) - Piloto: %-15s Equipe %s");
		}
		
		fwrite(&circuitoCadastro, sizeof(circuito), 1, c);
		
		apresentaEscolheMenuRepete(&opcao);
		if (qtdPaisCad != 0) {
			free(pPais);
		}
		if (qtdPilotoCad != 0) {
			free(pPiloto);
		}
		if (qtdCircuitCad != 0) {
			free(pCircuito);
		}
	} while(opcao == 's');
	fclose(a);
	fclose(b);
	fclose(c);
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

void inclusaoVoltas(){
	
	/*Fazer a chamada da função de cadastramento de voltas*/
	FILE *a, *b, *c;
	char opcao = '\0';
	int flag, qtdPilotoCad, qtdCircuitoCad, qtdVoltaCad, i, opcaoPiloto, opcaoCircuito;
	piloto *pPiloto; circuito *pCircuito; volta *pVolta, voltaCadastro;
	
	if (!existeArquivo("pilotos.dat", "rb")) {
		criaArquivo("pilotos.dat", "wb+");
	}
	if ((a = fopen("pilotos.dat", "rb+")) == NULL) {
		
	}
	if (!existeArquivo("circuitos.dat", "rb")) {
		criaArquivo("circuitos.dat", "wb+");
	}
	if ((b = fopen("circuitos.dat", "rb+")) == NULL) {
		
	}
	if (!existeArquivo("voltas.dat", "rb")) {
		criaArquivo("voltas.dat", "wb+");
	}
	if ((c = fopen("voltas.dat", "rb+")) == NULL) {
		
	}
	
	do {
		flag = 1;
		pPiloto = coletaDadosPiloto(&qtdPilotoCad, a);
		pCircuito = coletaDadosCircuito(&qtdCircuitoCad, b);
		pVolta = coletaDadosVolta(&qtdVoltaCad, c);
		printf("%d", qtdPilotoCad);
		getch();
		
		system("cls");
		voltaCadastro.piloto = -1;
		voltaCadastro.circuito = -1;
		strcpy(voltaCadastro.equipePiloto.nome, "");
		strcpy(voltaCadastro.equipePiloto.sigla, "");
		strcpy(voltaCadastro.equipePiloto.paisEquipe.nome, "");
		strcpy(voltaCadastro.equipePiloto.paisEquipe.sigla, "");
		strcpy(voltaCadastro.dataVolta, "");
		voltaCadastro.melhorVolta.minutos = -1;
		voltaCadastro.melhorVolta.segundos = -1;
		voltaCadastro.melhorVolta.milisegundos = -1;
		
		cabecalho("Cadastro de Voltas");
		printf("Escolha o piloto da volta abaixo:\n");
		for (i = 0; i < qtdPilotoCad; i++) {
			printf("(%2d) - ID: %3d Nome: %-15s\n", i+1, pPiloto[i].id, pPiloto[i].nome);
			getch();
		}
		leValidaInt(&opcaoPiloto, 1, i+1, "Digite sua escolha abaixo:\n");
		voltaCadastro.piloto = pPiloto[opcaoPiloto-1].id;
		voltaCadastro.equipePiloto = pPiloto[opcaoPiloto-1].equipePiloto;
		
		LINHA
		
		printf("Escolha o circuito da volta abaixo:\n");
		for (i = 0; i < qtdCircuitoCad; i++) {
			printf("(%2d) - ID: %3d Nome: %-15s\n", i+1, pCircuito[i].id, pCircuito[i].nome);
		}
		leValidaInt(&opcaoCircuito, 1, i+1, "Digite sua escolha abaixo:\n");
		voltaCadastro.circuito = pCircuito[opcaoCircuito-1].id;
		
		LINHA
		
		leValidaData(voltaCadastro.dataVolta, "Digite a data da volta [dd/mm/aaaa]: ");
		
		LINHA
		
		leValidaTempo(&voltaCadastro.melhorVolta.minutos, &voltaCadastro.melhorVolta.segundos, &voltaCadastro.melhorVolta.milisegundos, "Digite o tempo da volta [min:seg:mili]: ");
		
		fwrite(&voltaCadastro, sizeof(volta), 1, c);
		apresentaEscolheMenuRepete(&opcao);
		if (qtdPilotoCad != 0) {
			free(pPiloto);
		}
		if (qtdCircuitoCad != 0) {
			free(pCircuito);
		}
		if (qtdVoltaCad != 0) {
			free(pVolta);
		}
	} while(opcao == 's');
	fclose(a);
	fclose(b);
	fclose(c);
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

void geraNumerosPiloto(int *numeros, piloto *pPiloto, int *qtdPiloto) {
	int i, j, flag = 1;
	
	srand(time(NULL));
	do {
		for (i = 0; i < QTD_NUM; i++) {
			*(numeros+i) = rand() % 100; 
		}
		if (*qtdPiloto != 0) {
			for (i = 0; i < *qtdPiloto; i++) {
				for (j = 0; j < QTD_NUM; j++) {
					if (*(numeros+j) = (pPiloto+i)->id) {
						flag = 0;
						break;
					} else {
						flag = 1;
					}
				}
				if (!flag) {
					break;
				}
			}			
		}
	} while(!flag);
}

