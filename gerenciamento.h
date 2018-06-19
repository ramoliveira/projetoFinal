#ifndef _GERENCIAMENTO_h
#define _GERENCIAMENTO_h

#define TAM_NOME 30
#define TAM_SIGLA 4
#define TAM_DATA 11
#define QTD_NUM 3
#define ERRO_DB_PILOTO printf("Arquivo ""pilotos.dat"" indisponivel.\n");
#define ERRO_DB_PAIS printf("Arquivo ""paises.txt"" indisponivel.\n");
#define ERRO_DB_EQUIP printf("Arquivo ""equipes.dat"" indisponivel.\n");
#define ERRO_DB_CIRCUITO printf("Arquivo ""circuitos.dat"" indisponivel.\n");
#define ERRO_DB_PAIS_VAZIO printf("O Banco de Dados de Paises esta vazio.\nPortanto, preencha manualmente.\n");
#define ERRO_DB_EQUIPE_VAZIO printf("O Banco de Dados de Equipes esta vazio.\nPortanto, preencha manualmente.\n");
#define ERRO_CAD_PILOT printf("Piloto invalido! Este piloto ja esta cadastrado!\nAperte ENTER para cadastrar outro\n");
#define ERRO_CAD_EQUIP printf("Equipe Invalida! Esta equipe ja esta cadastrada!\nAperte ENTER para cadastrar outra\n");

typedef struct Tempo{
	int minutos;
	int segundos;
	float milisegundos;
} tempo;

typedef struct Pais{
	char sigla[TAM_SIGLA];
	char nome[TAM_NOME];
} pais;

typedef struct Equipe{
	char nome[TAM_NOME];
	char sigla[TAM_SIGLA];
	pais paisEquipe;
} equipe;

typedef struct Piloto{
	int id;
	char nome[TAM_NOME];
	equipe equipePiloto;
	char dataNascimento[TAM_DATA];
	char sexo;
	pais paisPiloto;
} piloto;

typedef struct Circuito{
	int id;
	char nome[TAM_NOME];
	pais paisCircuito;
	float quilometros;
	tempo menorTempo;
	char pilotoMenorTempo[TAM_NOME];
} circuito;

typedef struct Volta{
	int piloto;
	int circuito;
	equipe equipePiloto;
	char dataVolta[TAM_DATA];
	tempo melhorVolta;
} volta;

void geraNumerosPiloto(int *numeros, piloto *pPiloto, int *qtdPiloto);
void inclusaoPilotos();
void alterarPilotos(piloto *dadosPilotos, int *qtdPilotos);
void excluirPilotos(piloto *dadosPilotos, int *qtdPilotos);
void inclusaoEquipes();
void excluirEquipes(equipe *dadosEquipes, int *qtdEquipes);
void inclusaoCircuitos();
void alterarCircuitos(circuito *dadosCircuito, int *qtdCircuitos);
void inclusaoVoltas();
void alterarVoltas(volta *dadosVoltas, int *qtdVoltas);
void exclusaoVoltas(volta *dadosVoltas, int *qtdVoltas);
#endif
