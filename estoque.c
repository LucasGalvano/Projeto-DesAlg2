#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "estoque.h"
#include "funcoes.h"
#include "caixa.h"

//funcao para add estoque
void adicionar_estoque(struct Produto *estoque, int *qtd_produtos, struct Caixa *caixa) {
    if (*qtd_produtos >= MAX_PRODUTOS) {
        printf("O estoque está cheio. Não é possível adicionar mais produtos.\n");
        return;
    }

    struct Produto novo_produto;

    // info para o codigo gerado
    srand(time(NULL));
    int *codigos = NULL;
    int tamanho = 0;
  
    // Solicita e valida as informações do produto

    // Tipo do produto
    do {
        printf("Digite o tipo do produto: ");
        if (fgets(novo_produto.tipo, MAX_DIGITOS, stdin) == NULL) {
            printf("Erro ao ler tipo do produto, tente novamente!\n");
            continue;
        }
        novo_produto.tipo[strcspn(novo_produto.tipo, "\n")] = '\0';
    } while (strlen(novo_produto.tipo) == 0);

    // Tamanho do produto
    do {
        printf("Digite o tamanho do produto: ");
        if (fgets(novo_produto.tamanho, MAX_DIGITOS, stdin) == NULL) {
            fprintf(stderr, "Erro ao ler tamanho do produto, tente novamente\n");
            continue;
        }
        novo_produto.tamanho[strcspn(novo_produto.tamanho, "\n")] = '\0';
    } while (strlen(novo_produto.tamanho) == 0);

    // Valor do produto
    do {
        printf("Digite o valor do produto: R$ ");
        if (scanf("%f", &novo_produto.valor) != 1) {
            fprintf(stderr, "Erro ao ler valor do produto, tente novamente\n");
            clearBuffer();
            continue;
        };
        getchar();
    } while (novo_produto.valor <= 0);

    // Gera e verifica o Codigo do produto
    do {
        novo_produto.codigo = gera_codigo();
        printf("Codigo do produto: %d\n", novo_produto.codigo);
    } while (checa_codigo(&codigos, &tamanho, novo_produto.codigo) != 0);

    // Verifica se o saldo é suficiente para adicionar o produto
    if (caixa->saldo < novo_produto.valor) {
        printf("Saldo insuficiente no caixa para adicionar o produto.\n");
        return;
    }

    // Adiciona o produto ao estoque e ajusta o saldo
    estoque[*qtd_produtos] = novo_produto;
    (*qtd_produtos)++;
    caixa->saldo -= novo_produto.valor;
    printf("Produto adicionado com sucesso! Total de produtos: %d\n", *qtd_produtos);

    // Salva no txt
    estoque_txt(novo_produto);
    printf("O produto foi adicionado ao estoque com sucesso!\n");
}

// Funcao para salvar as informacões de um produto em um arquivo txt
void estoque_txt(struct Produto produto) {
    FILE *arquivo = fopen("estoque.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    // Salva as informacões do produto no arquivo
    fprintf(arquivo, "Tipo: %s\n", produto.tipo);
    fprintf(arquivo, "Tamanho: %s\n", produto.tamanho);
    fprintf(arquivo, "Valor: %.2f\n", produto.valor);
    fprintf(arquivo, "Codigo: %d\n", produto.codigo);

    fclose(arquivo);
}

// Funcao para exibir todo o estoque
void exibir_estoque(struct Produto *estoque, int *qtd_produtos) {
    if (*qtd_produtos == 0) {
        printf("O estoque esta vazio.\n");
        return;
    }

    printf("\n--- Estoque Atual ---\n");
    int i;
    for (i = 0; i < *qtd_produtos; i++) {
        printf("Produto %d:\n", i + 1);
        printf("Tipo: %s\n", estoque[i].tipo);
        printf("Tamanho: %s\n", estoque[i].tamanho);
        printf("Valor: %.2f\n", estoque[i].valor);
        printf("Codigo: %d\n", estoque[i].codigo);
        printf("-------------\n");
    }
}

// Funcao para buscar um produto pelo codigo
void buscar_produto(struct Produto *estoque, int *qtd_produtos) {
    if (*qtd_produtos == 0) {
        printf("O estoque esta vazio. Adicione algo para consulta-lo.\n");
        return;
    }

    int codigo_busca;
    printf("Digite o codigo do produto: ");
    if(scanf("%d", &codigo_busca) != 1){
        fprintf(stderr, "Erro ao ler codigo, tente novamente\n");
        clearBuffer();
    };
    getchar();

    // Procura pelo produto no estoque
    int encontrado = 0;
    int i;
    for (i = 0; i < *qtd_produtos; i++) {
        if (estoque[i].codigo == codigo_busca) {
            printf("\nProduto encontrado:\n");
            printf("Tipo: %s\n", estoque[i].tipo);
            printf("Tamanho: %s\n", estoque[i].tamanho);
            printf("Valor: %.2f\n", estoque[i].valor);
            printf("Codigo: %d\n", estoque[i].codigo);
            printf("--------------------------\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Produto com codigo %d nao foi encontrado no estoque.\n", codigo_busca);
    }
}