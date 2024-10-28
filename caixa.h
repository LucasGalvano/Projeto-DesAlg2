#ifndef caixa_h
#define caixa_h

#include "estoque.h"
#include "publico.h"


struct Produto;      
struct Funcionarios; 

struct Caixa {
    float saldo;
  
};

void registrar_venda(struct Produto *estoque, int *qtd_produtos, struct Funcionarios *funcionarios, int qtd_funcionarios, struct Caixa *caixa);

#endif
