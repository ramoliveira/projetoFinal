#ifndef _GERENCIAMENTO_h
#define _GERENCIAMENTO_h

#define TAM_NOME 30
#define TAM_SIGLA 4
#define TAM_DATA 11

typedef struct Tempo{
	int minutos;
	int segundos;
	float milisegundos;
} tempo;

typedef struct Piloto{
	int id;
	char nome[TAM_NOME];
	char equipe[TAM_SIGLA];
	char dataNascimento[TAM_DATA];
	char sexo;
	char pais[TAM_NOME];
} piloto;

typedef struct Equipe{
	char nome[TAM_NOME];
	char sigla[TAM_SIGLA];
	char pais[TAM_NOME];
} equipe;

typedef struct Circuito{
	int id;
	char nome[TAM_NOME];
	char pais[TAM_NOME];
	float quilometros;
	tempo menorTempo;
	char pilotoMenorTempo[TAM_NOME];
} circuito;

typedef struct Volta{
	int piloto;
	int circuito;
	char equipePiloto[TAM_SIGLA];
	char dataVolta[TAM_DATA];
	tempo melhorVolta;
} volta;

void inclusaoPilotos();
void alterarPilotos(piloto *dadosPilotos, int *qtdPilotos);
void excluirPilotos(piloto *dadosPilotos, int *qtdPilotos);
void inclusaoEquipes();
void excluirEquipes(equipe *dadosEquipes, int *qtdEquipes);
void inclusaoCircuitos(circuito *dadosCircuito, int *qtdCircuitos);
void alterarCircuitos(circuito *dadosCircuito, int *qtdCircuitos);
void inclusaoVoltas(volta *dadosVoltas, int *qtdVoltas);
void alterarVoltas(volta *dadosVoltas, int *qtdVoltas);
void exclusaoVoltas(volta *dadosVoltas, int *qtdVoltas);
#endif
