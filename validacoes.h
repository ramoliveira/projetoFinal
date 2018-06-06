/*Arquivo de Cabeçalho - Funções*/
#ifndef _VALIDACOES_h
#define _VALIDACOES_h

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include <time.h>

#define TAM_DATA 11

/*VALIDAÇÕES*/
void leValidaFloat(float *pValor, float valorMin, float valorMax, char texto[30]);
void leValidaNome(char texto[], char *nome);
void leValidaChar(char *pChar, char X, char Y, char titulo[30]);
void leValidaInt(int *pValor,int valorMin, int valorMax, char texto[]);
void leValidaData(char *data);

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

/*Objetivo: lê e realizar as validações de datas
Parâmetros: ponteiro da data
Retorno: nenhum*/

void leValidaData(char *data){
	
	struct tm *local;
	time_t t;
	t = time(NULL);
	local=localtime(&t);
	
	int anoAtual = local->tm_year+1900;
	int mesAtual = local->tm_mon+1;
	int diaAtual = local->tm_mday;
	
	
	char data_aux[TAM_DATA], diaS[TAM_DATA], mesS[TAM_DATA], anoS[TAM_DATA];
	strcpy(data_aux, "");
	strcpy(diaS, "");
	strcpy(mesS, "");
	strcpy(anoS, "");
	int i = 0, flag = 1, dia = 0, mes = 0, ano = 0;
	
	do {
		printf("Digite sua data de nascimento: [dd/mm/aaaa]\n");
		fflush(stdin);
		flag = scanf("%d/%d/%d", &dia, &mes, &ano);
		if (!flag) {
			printf("Data invalida! Apenas numeros sao aceitos.\n");
		}else if (ano < 1900 || ano > anoAtual) {
			printf("Ano invalido! Digite um ano no intervalo de 1900 a %d.\n", anoAtual);
			flag = 0;
		}else if (mes < 1 || mes > 12) {
			printf("Mes invalido! Digite um mes no intervalo de 1 a 12.\n");
			flag = 0;
		}else if (ano == anoAtual){
			if(mes > mesAtual){
				printf("Data Invalida! Digite novamente\n");
				flag=0;
			}
		}else if ((dia < 1 || dia > 31) && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)) {
			printf("Dia invalido! Nos meses de Janeiro, Marco, Maio, Julho, Agosto, Outubro e Dezembro, os dias vao de 1 a 31.\n");
			flag = 0;
	    }else if ((dia < 1 || dia > 30) && (mes == 4 || mes == 6 || mes == 9 || mes == 11)) {
	    	printf("Dia invalido! Nos meses de Abril, Junho, Setembro e Novembro, os dias vao de 1 a 30.\n");
	    	flag = 0;
		}else if (dia == 29 && mes == 2 && (ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0))) {
			flag = 1;
		}else if ((dia < 1 || dia > 28) && mes == 2) {
			printf("Dia invalido! No mes de Fevereiro, os dias vao de 1 a 28.\n");
			flag = 0;
		}else{
			flag = 1;
		}
		
		if((ano == anoAtual) && (mes == mesAtual)){
			if(dia > diaAtual){
				printf("Data Invalida! Digite novamente\n");
				flag=0;
			}
		}
	} while(!flag);
	
	snprintf(diaS, TAM_DATA, "%d", dia);
	snprintf(mesS, TAM_DATA, "%d", mes);
	snprintf(anoS, TAM_DATA, "%d", ano);
	
	strcat(data_aux, diaS);
	strcat(data_aux, "/");
	strcat(data_aux, mesS);
	strcat(data_aux, "/");
	strcat(data_aux, anoS);
	
	strcpy(data,data_aux);
}

#endif
