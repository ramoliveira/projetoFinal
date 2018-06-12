#ifndef _STORAGE_h
#define _STORAGE_h

#define TAM_NOME 30
#define EXIT_FAILURE 1

int existeArquivo(char nomeArquivo[TAM_NOME]);
void criaArquivo(char nomeArquivo[TAM_NOME]);
equipe* coletaDadosEquipe(int *qtdEquipCad, FILE *f);
piloto* coletaDadosPiloto(int *qtdPilotosCad, FILE *f);
circuito* coletaDadosCircuito(int *qtdCircuitosCad, FILE *f);
volta* coletaDadosVolta(int *qtdVoltasCad, FILE *f);
 
#endif
