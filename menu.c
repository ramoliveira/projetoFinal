#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include </menu/ui/ui.c>

void apresentaEscolheMenuPrincipal(char *opcao) {
	int flag = 1;
	do {
		cabecalho("Menu Principal");
		printf("(1) - Piloto;\n");
		printf("(2) - Equipe;\n");
		printf("(3) - Circuito;\n");
		printf("(4) - Volta;\n");
		printf("(5) - Relatorios;\n");
		printf("(S) - Sair do programa\n");
		scanf(" %c", opcao);
		*opcao = tolower(*opcao);
		if ((*opcao < 49 || *opcao > 53) && (*opcao != 's')) {
			printf("Opcao invalida! Escolha de acordo com o menu.\n");
			flag = 0;
		} else {
			flag = 1;
		}		
	} while(!flag);
}
