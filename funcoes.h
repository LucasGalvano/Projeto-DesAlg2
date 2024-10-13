#ifndef funcoes_h
#define funcoes_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char data[11];
    char conteudo[255];
} Relatorio;

void clearBuffer();

void salvarRelatorio(Relatorio novo_relatorio);
void gerarRelatorio();
void consultarRelatorio();
int gera_senha();
#endif