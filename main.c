/*Síntese - Projeto Final - Lucas Henrique - UC17201125 - Ramón Dias - UC
Objetivo: gestão dos testes do Campeonato de Moto GP, auxiliando o usuário com diversas opções de menu
Entrada: piloto, equipe, circuito, melhor volta
Saída: de acordo com o menu de opções
*/

#include <stdio.h>
#include <stdlib.h>
#include </menu/menu.c>

struct Tempo{
	int minutos;
	int segundos;
	float milisegundos;
};

struct Piloto{
	int id;
	char nome[TAM_NOME];
	char equipe[TAM_SIGLA];
	char dataNascimento[TAM_DATA];
	char sexo;
	char pais[TAM_NOME];
};

struct Equipe{
	char nome[TAM_NOME];
	char sigla[TAM_SIGLA];
	char pais[TAM_NOME];
};

struct Circuito{
	int id;
	char nome[TAM_NOME];
	char pais[TAM_NOME];
	float quilometros;
	struct Tempo menorTempo;
	char pilotoMenorTempo[TAM_NOME];
};

struct Volta{
	int piloto;
	int circuito;
	char equipePiloto[TAM_SIGLA];
	char dataVolta[TAM_DATA];
	struct Tempo melhorVolta
};

int main() {
	/*Declarações*/
	char opcao = '\0';
	
	/*Instruções*/
	do {
		apresentaEscolheMenuPrincipal(&opcao);
	} while(opcao != 's');
	
	return 0;
}
