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


// Definição da estrutura da loja
struct Loja {
    char nome_loja[50];
    char senha[7];
};

void clearBuffer();
void cadastrar_loja(struct Loja *loja);
int login(struct Loja *loja);
void salvarRelatorio(Relatorio novo_relatorio);
void gerarRelatorio();
#endif