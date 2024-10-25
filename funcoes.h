#ifndef funcoes_h
#define funcoes_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para o relatório
typedef struct {
    char data[11];
    char conteudo[255];
} Relatorio;

// Estrutura para a loja
struct Loja {
    char nome_loja[50];
    char senha[7];
};

// Funções
void clearBuffer();
void cadastrar_loja(struct Loja *loja);
int login(struct Loja *loja);
void salvarRelatorio(Relatorio novo_relatorio);
void gerarRelatorio();
int gera_codigo();
int checa_codigo(int **codigos, int *tamanho, int codigo);

#endif
