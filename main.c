#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funcoes.h"
#include "estoque.h"
#include "publico.h"
#include "caixa.h"


int main() {

    // Def para a loja
    struct Caixa caixa = {0.0};
    struct Loja loja;
    int logado = 0;
    cadastrar_loja(&loja);

    while (!logado) {
        logado = login(&loja);
    }

    // Def para o estoque
    int qtd_produtos = 0;
    struct Produto estoque[MAX_PRODUTOS];

    // Def para funcionarios e cliente
    int qtd_funcionarios = 0;
    int qtd_cliente = 0;
    struct Funcionarios funcionarios[MAX_FUNCIONARIOS];

    // def para codigo 
    srand(time(NULL));
    int *codigos = NULL;
    int tamanho = 0;
    int opcao, continuar = 1;

    // def para o publico
    struct Funcionarios funcionario;
    struct Cliente cliente;

    // loop do menu
    while (continuar) {
        printf("\n=-=-= Menu da Loja =-=-=\n");
        printf("1. Registrar venda\n");
        printf("2. Adicionar Estoque\n");
        printf("3. Consultar estoque\n");
        printf("4. Buscar no estoque\n");
        printf("5. Cadastrar funcionario\n");
        printf("6. Consultar funcionarios\n");
        printf("7. Cadastrar clientes\n");
        printf("8. Consultar clientes\n");
        printf("9. Gerar relatorio\n");
        printf("10. Caixa da loja\n");
        printf("11. Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);
        clearBuffer();

        switch (opcao) {
            case 1:
                registrar_venda(estoque, &qtd_produtos, funcionarios, qtd_funcionarios, &caixa);
                break;
            case 2:
                adicionar_estoque(estoque, &qtd_produtos); 
                break;
            case 3:
                exibir_estoque(estoque, &qtd_produtos);
                break;
            case 4:
                buscar_produto(estoque, &qtd_produtos);
                break;
            case 5:
                cadastrar_funcionario(funcionarios, &qtd_funcionarios);
                break;
            case 6:
                consultar_funcionario(funcionarios, qtd_funcionarios);
                break;
            case 7:
                cadastrar_cliente(&cliente, &qtd_cliente);
                break;
            case 8:
                consultar_cliente(&cliente, qtd_cliente);
                break;
            case 9:
                gerarRelatorio();
                break;
            case 10:
                printf("Caixa da loja: R$: %.2f\n", caixa.saldo);
                break;
            case 11:
                printf("Saindo...\n");
                continuar = 0;
                break;
            default:
                printf("Opcao invalida.\n");
        }
    }

    free(codigos);
    return 0;
}
