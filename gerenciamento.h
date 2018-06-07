#ifndef _GERENCIAMENTO_h
#define _GERENCIAMENTO_h

#define TAM_NOME 30
#define TAM_SIGLA 4
#define TAM_DATA 11

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
	struct Tempo melhorVolta;
};

void inclusaoPilotos();
void alterarPilotos(struct Piloto *dadosPilotos, int *qtdPilotos);
void excluirPilotos(struct Piloto *dadosPilotos, int *qtdPilotos);
void inclusaoEquipes();
void excluirEquipes(struct Equipe *dadosEquipes, int *qtdEquipes);
void inclusaoCircuitos(struct Circuito *dadosCircuito, int *qtdCircuitos);
void alterarCircuitos(struct Circuito *dadosCircuito, int *qtdCircuitos);
void inclusaoVoltas(struct Volta *dadosVoltas, int *qtdVoltas);
void alterarVoltas(struct Volta *dadosVoltas, int *qtdVoltas);
void exclusaoVoltas(struct Volta *dadosVoltas, int *qtdVoltas);
#endif
