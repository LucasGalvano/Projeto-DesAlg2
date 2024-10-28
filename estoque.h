#ifndef estoque_h
#define estoque_h

#include "caixa.h"


#define MAX_PRODUTOS 100
#define MAX_DIGITOS 50


struct Produto {
    char tipo[MAX_DIGITOS];
    char tamanho[MAX_DIGITOS];
    float valor;
    int codigo;
};


void adicionar_estoque(struct Produto *estoque, int *qtd_produtos,struct Caixa *caixa);
void estoque_txt(struct Produto produto);
void exibir_estoque(struct Produto *estoque, int *qtd_produtos);
void buscar_produto(struct Produto *estoque, int *qtd_produtos);
#endif