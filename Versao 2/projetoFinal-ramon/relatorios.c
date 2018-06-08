#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "storage.h"

int main() {
	
	return 0;
}

/*RELAT�RIOS*/

/*R1*/

/*Objetivo: filtrar os dados de acordo com a solicita��o do usu�rio
Par�metros: 
Retorno: nenhum */

void pesquisaDados(){
	
	char opcao,opcao2;
	
	/*FAZER CHAMA DOS MENUS*/
	/*ABRIR ARQUIVOS RELACIONADOS AOS MENUS*/
	
	apresentaEscolheMenuRelatorios1(&opcao);
	leValidaChar("T para categoria completa ou F para filtrar - (T/F): ");
	
	switch(opcao){
		case '1':
			
		
		
	}
}



/*R2*/
/*Objetivo: filtrar os dados de acordo com o nome solicitado
Par�metros: 
Retorno: nenhum */

void pesquisaPilotos(){
	
	char nome[TAM_NOME];	
	int i=0,aux=0,qtdPilotos=0; 
	struct Piloto *pilotos;
	
	printf("\tPESQUISA PILOTOS\n\n");
	leValidaNome("Digite o nome do piloto: ",nome);	system("cls");
	
	for(i=0;i<strlen(nome);i++){
		nome[i] = toupper(nome[i]);
	}
	
	coletaDadosPiloto(pilotos,&qtdPilotos,/*Arquivo*/);
	cabecalho("PILOTOS\n\n");
	printf("NOME  EQUIPE NASC  ID  SEXO  PA�S\n"); /*REVISAR STRSTR*/
	
	for(i=0;i<qtdPilotos;i++){
		if(strstr(nome,pilotos[i].nome)!=NULL){
			printf("%-30s %-3s %-10s ", pilotos[i].nome,pilotos[i].equipe,pilotos[i].dataNascimento);
			printf("%-3d %c %s\n", pilotos[i].id,pilotos[i].sexo,pilotos[i].pais);
			aux=1;	
		}
	}
	
	if(aux!= 1){
		printf("Nenhum piloto encontrado\n\n");getch();system("cls");
	}
}


/*R3*/
/*Objetivo: apresentar os dados de um determinado circuito  
Par�metros: 
Retorno: nenhum */

void pesquisaCircuitos(){
	
	int idCircuito=0, qtdCircuitos=0;
	char data[TAM_DATA];
	char aux;
	struct Circuito *circuitos;
	
	printf("\tPESQUISA CIRCUITOS\n\n");
	/*Fun��o Aprensenta Circuitos*/
	
	coletaDadosCircuito(circuitos,&qtdCircuitos,/*Arquivo*/);
	
	leValidaInt(&idCircuito,1,100,"Digite o ID do Circuito: ");
	leValidaChar(&aux,'S','N',"Deseja adicionar uma data - (S|N): ");
	
	if(aux == 'S'){
		leValidaData(data,"Digite uma data - [dd/mm/aaaa]: ");		
	}else{
		for(i=0;i<qtdCircuitos;i++){
			
			
			
		}	
	}
	

	/*FALTA CONCLUIR*/		
	
	
}

/*R4*/
/*Objetivo: apresentar circuitos por meio do nome ou c�digo 
Par�metros: 
Retorno: nenhum */

void apresentaCircuitosCadastrados(){
	
	char opcao;
	char nome[TAM_NOME];
	struct Circuito *circuitos;
	int qtdCircuitos;
	
	cabecalho("CIRCUITOS\n\n");
	printf("(1) - Consultar por nome\n");
	printf("(2) - Consultar por c�digo\n");
	scanf(" %c", &opcao);opcao=toupper(opcao);
	
	coletaDadosCircuito(circuitos,&qtdCircuitos,/*Arquivo*/);
	
	switch(opcao){
		case '1':
			leValidaNome("Digite o nome do circuito: ", nome);
			for(i=0;i<qtdCircuitos;i++){
				if(strstr(nome,circuitos[i].nome)!=NULL){
					
					
				}
			}
			
			
	}
	
	
	
	
}


/*R5*/
/*Objetivo: apresentar os pilotos de acordo com uma data fornecida 
Par�metros: 
Retorno: nenhum*/

void apresentaPilotosData(){
	
	char dataInicial[TAM_DATA];
	char dataFinal[TAM_DATA];
	
	printf("\tPILOTOS - DATA\n\n");
	leValidaData(dataInicial,"Data Inicial - [dd/mm/aaaa]: ");
	leValidaData(dataInicial,"Data Final - [dd/mm/aaaa]: ");
	
	/*Terminar intervalo de tempo*/
	
	
	
	
}

/*R6*/
/*Objetivo: pesquisar pilotos, equipes e circuitos que realizaram tempo de volta menor ou igual a fornecida 
Par�metros:  
Retorno: nenhum */

void apresentaDadosTempo(){
	
	struct Tempo tempo;
	
	printf("\tPESQUISA TEMPO\n\n");
	printf("Tempo desejado\n");
	leValidaInt(&tempo.minutos,0,60);
	
	
	
	
	
	
	
}

/*R7*/
/*Objetivo:  
Par�metros: 
Retorno: nenhum */

void apresentaDadosSem_melhorVolta(){

	


	
}



