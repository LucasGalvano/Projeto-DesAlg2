#ifndef estoque_h
#define estoque_h

#define MAX_PRODUTOS 100
#define MAX_DIGITOS 50

// Estrutura para armazenar as informações do produto
struct Produto {
    char tipo[MAX_DIGITOS];
    char tamanho[MAX_DIGITOS];
    float valor;
    int codigo;
};

void adicionar_estoque(struct Produto *estoque, int *qtd_produtos);
void estoque_txt(struct Produto produto);
void exibir_estoque(struct Produto *estoque, int *qtd_produtos);
void buscar_produto(struct Produto *estoque, int *qtd_produtos);
#endif