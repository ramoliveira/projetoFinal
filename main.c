/*S�ntese - Projeto Final - Lucas Henrique - UC17201125 - Ram�n Dias - UC14201004
Objetivo: Gest�o dos testes do Campeonato de Moto GP, auxiliando o usu�rio com diversas op��es de menu
Entrada: piloto, equipe, circuito, melhor volta
Sa�da: de acordo com o menu de op��es.
*/

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int main() {
	//Declara��es
	char opcao = '\0';
	
	//Instru��es
	
	telaEntrada();
	do {
		apresentaEscolheMenuPrincipal(&opcao);
		chamaFuncoesMenuPrincipal(&opcao);
	} while(opcao != 's');
	
	return EXIT_SUCCESS;
}


