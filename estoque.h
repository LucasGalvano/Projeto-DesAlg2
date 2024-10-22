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
int *qtd_produtos = 0;

// Array para armazenar os produtos
struct Produto estoque[MAX_PRODUTOS];

void adicionar_estoque();
void estoque_txt(struct Produto produto);
void exibir_estoque();
void buscar_produto();
#endif