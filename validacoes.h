/*Arquivo de Cabeçalho - Funções*/
#ifndef _VALIDACOES_h
#define _VALIDACOES_h

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

/*VALIDAÇÕES*/
void leValidaFloat(float *pValor, float valorMin, float valorMax, char texto[30]);
void leValidaNome(char texto[], char *nome);
void leValidaChar(char *pChar, char X, char Y, char titulo[30]);
void leValidaInt(int *pValor,int valorMin, int valorMax, char texto[]);
void formataNome(char *nome);

//Objetivo: lê e validar valores reais
//Parâmetros:  ponteiro de valores mínimos e máximos
//Retorno: nenhum

void leValidaFloat(float *pValor, float valorMin, float valorMax, char texto[30]){
	
	int flag=0,i=0;
	char num[10];
	
	do{	
		do{	
			fflush(stdin);
			printf(texto);
			scanf("%s", &num);
			for(i=0;i<strlen(num);i++){
				if(!isdigit(num[i]) && num[i]!='.'){
					printf("Digite apenas numeros e ponto\n\n");getch();system("cls");
					flag=1;
					break;
				}else{
					flag=0;
				}
			}
		}while(flag==1);
	
		*pValor = atof(num);
					
		if(*pValor<valorMin || *pValor>valorMax){
			printf("Valor Invalido - valor min %.2f e valor max %.2f\nDigite Novamente\n", valorMin,valorMax);
			getch();system("cls");
			flag=1;
		}else{
			flag=0;
		}
	}while(flag==1);
}

///Objetivo: lê e validar nomes
//Parâmetros:  ponteiro de nome e texto
//Retorno: nenhum

void leValidaNome(char texto[], char *nome) {
	int flag = 1, qtdEspacos = 0, i;
	
	do {
		qtdEspacos = 0;
		printf(texto);
		fflush(stdin);
		scanf("%[^\n]s", nome);
		for (i = 0; i < strlen(nome); i++) {
			if (nome[i] == ' ' || nome[i] == '\0' || nome[i] == '\n') {
				qtdEspacos++;
			} 
		}
		if (qtdEspacos == strlen(nome)) {
			printf("Nome invalido! O nome esta vazio.\n");
			flag = 0;
		} else if (strlen(nome) < 2) {
			printf("Nome invalido! O nome e muito curto.\n");
			flag = 0;
		} else {
			for (i = 0; i < strlen(nome); i++) {
				if (isdigit(nome[i]) != 0) {
					printf("Nome invalido! Digite apenas letras.\n");
					flag = 0;
					break;
				} else {
					flag = 1;
				}
			}
		}
	} while(!flag);
	
	formataNome(nome);
}


//Objetivo: lê e validar caracteres
//Parâmetros: ponteiro de char, dois caracteres válidos e título
//Retorno: nenhum

void leValidaChar(char *pChar, char X, char Y, char titulo[30]){
	
	int flag=0;
	
	X = toupper(X);
	Y = toupper(Y);
	
	do{
		printf(titulo);
		scanf(" %c", pChar);
		*pChar = toupper(*pChar);
		
		if(*pChar != X && *pChar != Y){
			system("cls");
			printf("Opçao Invalida! Digite Novamente!\n");getch();system("cls");
		}else{
			flag=1;
		}		
	}while(flag==0);
				
}

//Objetivo: lê e validar inteiros
//Parâmetros: ponteiro de inteiro,valor mínimo, valor máximo e texto
//Retorno: nenhum

void leValidaInt(int *pValor,int valorMin, int valorMax, char texto[]){
	
	char num[8];
	int flag,i=0;
	
	do{
		do{
			fflush(stdin);
			printf(texto);
			scanf("%s", &num);
			for(i=0;i<strlen(num);i++){
				if(!isdigit(num[i])){
					printf("Digite apenas numeros\nDigite Novamente\n");
					getch();
					system("cls");
					flag=1;
					break;
				}else{
					flag=0;
				}
			}		
		}while(flag==1);
		
		*pValor = atoi(num);
		
		if(*pValor<valorMin || *pValor>valorMax){
			printf("Quantidade Invalida\nValor Min %d e Valor Max %d\n", valorMin, valorMax);
			getch();
			system("cls");
			flag=1;
		}else{
			flag=0;
		}
	}while(flag==1);			
}

//Objetivo: formatar nome 
//Parâmetros: ponteiro de nome
//Retorno: nenhum

void formataNome(char *nome){
	
	int i=0;
	
	nome[0] = toupper(nome[0]);
	
	for(i=1;i<strlen(nome);i++){
		if(nome[i]==' '){
			i++;
			nome[i] = toupper(nome[i]);	
		}else{
			nome[i] = tolower(nome[i]);
		}
	}
}
#endif
