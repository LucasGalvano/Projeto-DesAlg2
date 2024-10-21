#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funcoes.h"
#include "estoque.h"

int main() {

    // Def para a loja
    struct Loja loja;
    int logado = 0;
    cadastrar_loja(&loja);

    while (!logado) {
        logado = login(&loja);
    }

    // def para codigo 
    srand(time(NULL));
    int *codigos = NULL;
    int tamanho = 0;
    int qtd_produtos = 0;
    int opcao, continuar = 1;

    while (continuar) {
        printf("\n=-=-= Menu da Loja =-=-=\n");
        printf("1. Registrar venda\n");
        printf("2. Adicionar Estoque\n");
        printf("3. Consultar estoque\n");
        printf("4. Buscar no estoque\n");
        printf("5. Funcionarios\n");
        printf("6. Cadastrar clientes\n");
        printf("7. Gerar relatorio\n");
        printf("8. Caixa da loja\n");
        printf("9. Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);
        clearBuffer();
        
        switch (opcao) {
            case 1:
                printf("Registrar venda\n");
                break;
            case 2:
                adicionar_estoque();
                break;
            case 3:
                exibir_estoque();
                break;
            case 4:
                buscar_produto();
                break;
            case 5:
                printf("Funcionarios\n");
                break;
            case 6:
                printf("Cadastrar clientes\n");
                break;
            case 7:
                gerarRelatorio();
                break;
            case 8:
                printf("Caixa da loja\n");
                break;
            case 9:
                printf("Saindo...\n");
                continuar = 0;
                break;
            default:
                printf("Opção invalida.\n");
        }
    }

    free(codigos);
    return 0;
}