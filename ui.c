#include <stdio.h>
#include <stdlib.h>

#define TAM_TEXTO
#define CSE printf("\xC9");
#define HOR printf("\xCD");
#define CSD printf("\xBB\n");
#define VEE printf("\xC7");
#define VED printf("\xC7\n");
#define CIE printf("\xC8");
#define CID printf("\xBC\n");

void cabecalho(char texto[TAM_TEXTO]) {
	int i;
	CSE
	for (i = 1; i <= (strlen(texto) + 2); i++) {
		HOR
	}
	CSD
	VEE printf(" %s ", texto); VED
	CIE
	for (i = 1; i <= (strlen(texto) + 2); i++) {
		HOR
	}
	CID
} 
