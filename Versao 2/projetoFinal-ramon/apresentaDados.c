#include <stdio.h>
#include <stdlib.h>
#include "apresentaDados.h"
#include "storage.h"
#include "gerenciamento.h"

/*Objetivo: apresentar dados de todos os pilotos
Parâmetros:
Retorno: nenhum
*/

void apresentaDadosPilotos(){
	
	struct Piloto *dadosPilotos;
	int qtdPilotos;
	int i=0;
	
	coletaDadosPiloto(dadosPilotos,&qtdPilotos,/*Arquivo*/);
	cabecalho("PILOTOS\n\n");
	printf("NOME  EQUIPE NASC  ID  SEXO  PAÍS\n");
	
	for(i=0;i<qtdPilotos;i++){
		printf("%-30s %-3s %-10s ", dadosPilotos[i].nome,dadosPilotos[i].equipe,dadosPilotos[i].dataNascimento);
		printf("%-3d %c %s\n", dadosPilotos[i].id,dadosPilotos[i].sexo,dadosPilotos[i].pais);
	}
}

/*Objetivo: apresentar dados de todos os equipes
Parâmetros:
Retorno: nenhum
*/

void apresentaDadosEquipes(){
	
	struct Equipe *dadosEquipe;
	int qtdEquipes;
	int i=0;
	
	coletaDadosEquipe(dadosEquipe,&qtdEquipes,/*Arquivo*/);
	cabecalho("EQUIPES\n\n");
	printf("EQUIPE  SIGLA  PAÍS\n");
	
	for(i=0;i<qtdEquipes;i++){
		printf("%-10s %-3s %-10s\n");
	}
}

/*Objetivo: apresentar dados de todos os circuitos
Parâmetros:
Retorno: nenhum
*/

void apresentaDadosCircuitos(){
	
	struct Circuito *dadosCircuito;
	int qtdCircuitos;
	int i=0;
	
	coletaDadosCircuito(dadosCircuito,&qtdCircuitos,/*Arquivo*/);
	cabecalho("CIRCUITOS\n\n");
	printf("ID  NOME  	  PAÍS  TAM(KM)  PILOTO MENOR TEMPO\n\n");
	
	for(i=0;i<qtdCircuitos;i++){
		printf("%-3d %-20s %-10s ", dadosCircuito[i].id,dadosCircuito[i].nome,dadosCircuito[i].pais);
		printf("%-3.2f %-10s\n", dadosCircuito[i].quilometros,dadosCircuito[i].pilotoMenorTempo);
	}
}

/*Objetivo: apresentar dados de todos os circuitos
Parâmetros:
Retorno: nenhum
*/

void apresentaDadosVolta(){
	
	struct Volta *dadosVolta;
	int qtdVoltas;
	int i=0;
	
	coletaDadosVolta(dadosVolta,&qtdVoltas,/*Arquivo*/);
	cabecalho("MELHORES VOLTAS\n\n");
	printf("ID Piloto  ID Circuito  Equipe  DATA  TEMPO\n\n");
	
	for(i=0;i<qtdVoltas;i++){
		printf("%-3d %-3d %-3s ", dadosVolta[i].piloto,dadosVolta[i].circuito,dadosVolta[i].equipePiloto);
		printf("%-10s %d:%d:%d\n", dadosVolta[i].dataVolta,dadosVolta[i].melhorVolta.minutos,dadosVolta[i].melhorVolta.segundos,dadosVolta[i].melhorVolta.milisegundos);
	}
}




