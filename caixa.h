#ifndef caixa_h
#define caixa_h

struct Caixa {
    float saldo;
};

void registrar_venda(struct Produto *estoque, int *qtd_produtos, struct Funcionarios *funcionarios, int qtd_funcionarios, struct Caixa *caixa);
#endif