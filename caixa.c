#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "estoque.h"
#include "funcoes.h"
#include "publico.h"
#include "caixa.h"

// Funcao para registrar venda
void registrar_venda(struct Produto *estoque, int *qtd_produtos, struct Funcionarios *funcionarios, int qtd_funcionarios) {
    printf("--- Registrar venda ---\n");
    
    // Exibe o estoque disponivel
    printf("--- Estoque disponivel ---\n");
    int i;
    for (i = 0; i < *qtd_produtos; i++) {
        printf("Produto %d:\n", i + 1);
        printf("Tipo: %s\n", estoque[i].tipo);
        printf("Tamanho: %s\n", estoque[i].tamanho);
        printf("Valor: %.2f\n", estoque[i].valor);
        printf("Codigo: %d\n", estoque[i].codigo);
        printf("-------------\n");
    }

    if (*qtd_produtos == 0) {
        printf("O estoque esta vazio. Adicione algo para consulta-lo.\n");
        return;
    }

    int id_funcionario;
    int codigo_busca;
    int funcionario_encontrado = 0;
    int produto_encontrado = 0;
    float valor_venda = 0.0;
    struct Produto produto_vendido;
    struct Funcionarios *vendedor = NULL;

    // Solicitar e validar o ID do funcionario
    while (!funcionario_encontrado) {
        printf("Digite o ID do funcionario que realizou a venda: ");
        scanf("%d", &id_funcionario);
        getchar();

        // Verifica se o ID corresponde a um funcionario valido
        for (i = 0; i < qtd_funcionarios; i++) {
            if (funcionarios[i].id == id_funcionario) {
                vendedor = &funcionarios[i];
                funcionario_encontrado = 1;
                break;
            }
        }

        if (!funcionario_encontrado) {
            printf("ID do funcionario invalido. Tente novamente.\n");
        }
    }

    // Solicitar e validar o codigo do produto
    while (!produto_encontrado) {
        printf("Digite o codigo do produto que sera vendido: ");
        scanf("%d", &codigo_busca);
        getchar(); 

        // Verifica se o produto esta no estoque
        for (i = 0; i < *qtd_produtos; i++) {
            if (estoque[i].codigo == codigo_busca) {
                produto_encontrado = 1;
                valor_venda = estoque[i].valor;
                produto_vendido = estoque[i];

                // Remove o produto do estoque
                int j;
                for (j = i; j < *qtd_produtos - 1; j++) {
                    estoque[j] = estoque[j + 1];
                }
                (*qtd_produtos)--;

                break;
            }
        }

        if (!produto_encontrado) {
            printf("Codigo do produto invalido. Tente novamente.\n");
        }
    }

    // Exibe o produto vendido e o funcionario que realizou a venda
    printf("\n--- Venda registrada ---\n");
    printf("Produto vendido:\n");
    printf("Tipo: %s\n", produto_vendido.tipo);
    printf("Tamanho: %s\n", produto_vendido.tamanho);
    printf("Valor: R$ %.2f\n", produto_vendido.valor);
    printf("Codigo: %d\n", produto_vendido.codigo);
    printf("Vendido por: %s\n", vendedor->nome);

    vendedor->total_vendas += valor_venda;  // Incrementa o total de vendas

    // Verifica se o funcionario atingiu a cota mensal
    if (vendedor->total_vendas >= cota) {
        vendedor->salario += bonus;
        printf("\n%s atingiu a cota mensal e recebeu o bonus de R$ %.2f.\n", vendedor->nome, bonus);
    }
    else {
        printf("\n%s nao atingiu a cota mensal.\n", vendedor->nome);
    }

    // Exibe o total atualizado de vendas do funcionario
    printf("Total de vendas de %s: R$ %.2f\n", vendedor->nome, vendedor->total_vendas);
}
