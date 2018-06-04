/*Arquivo de Cabe�alho - Fun��es*/
#ifndef _VALIDACOES_h
#define _VALIDACOES_h

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

/*MACROS*/
#define TAM_NOME 50

/*VALIDA��ES*/
void leValidaFloat(float *pValor, float valorMin, float valorMax, char texto[30]);
void leValidaNome(char *nome, int tamString, char texto[]);
void leValidaChar(char *pChar, char X, char Y, char titulo[30]);
void leValidaInt(int *pValor,int valorMin, int valorMax, char texto[]);
void formataNome(char *nome);

//Objetivo: l� e validar valores reais
//Par�metros:  ponteiro de valores m�nimos e m�ximos
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

///Objetivo: l� e validar nomes
//Par�metros:  ponteiro de nome e texto
//Retorno: nenhum

void leValidaNome(char *nome, int tamString, char texto[]){
	
	int flag=0,i=0;
	int qtdEspacos=0;
	
	do{	
		do{
			do{
				fflush(stdin);
				printf(texto);
				scanf("%[^\n]s", nome);
				
				if(nome[0] == ' '){
					printf("Nome Invalido\nDigite Novamente\n");
					getch();
					system("cls");
					flag=1;
				}else{
					flag=0;
				}
			}while(flag==1);
			
			if(strlen(nome)>tamString || strlen(nome)<2){
				printf("Nome Invalido\nDigite Novamente\n");
				getch();
				system("cls");
				flag=1;
			}else{
				flag=0;
			}
		}while(flag==1);
		
		for(i=0;i<strlen(nome);i++){
			if(!isalpha(*(nome+i))){
				if((*(nome+i)) == ' '){
					i++;
				}else{
					printf("Nome Invalido\nDigite Novamente\n");
					getch();
					system("cls");
					flag=1;
					break;
				}	
			}else{
				flag=0;
			}
		}
	}while(flag==1);
	
	formataNome(nome);
}


//Objetivo: l� e validar caracteres
//Par�metros: ponteiro de char, dois caracteres v�lidos e t�tulo
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
			printf("Op�ao Invalida! Digite Novamente!\n");getch();system("cls");
		}else{
			flag=1;
		}		
	}while(flag==0);
				
}

//Objetivo: l� e validar inteiros
//Par�metros: ponteiro de inteiro,valor m�nimo, valor m�ximo e texto
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
//Par�metros: ponteiro de nome
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
