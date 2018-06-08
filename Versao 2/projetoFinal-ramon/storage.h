#ifndef _STORAGE_h
#define _STORAGE_h

#define TAM_NOME 30
#define EXIT_FAILURE 1

int existeArquivo(char nomeArquivo[TAM_NOME]);
void criaArquivo(char nomeArquivo[TAM_NOME]);
void coletaDadosEquipe(struct Equipe *pEquipe, int *qtdEquipCad, FILE *f);
void coletaDadosPiloto(struct Piloto *pPiloto, int *qtdPilotosCad, FILE *f);
void coletaDadosCircuito(struct Circuito *pCircuito, int *qtdCircuitosCad, FILE *f);
void coletaDadosVolta(struct Volta *pVolta, int *qtdVoltasCad, FILE *f);
 
#endif