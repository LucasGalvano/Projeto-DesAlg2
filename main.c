#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "funcoes.h"

int main(void)
{

    Relatorio novo_relatorio;

    //funçao q gera senha(mudar conforme o códifo evolui)
    gera_senha();

    int opcao, continuar = 1;

    while(continuar){
        printf("\n=-=-= Menu da Loja =-=-=\n");
        printf("1. Registrar venda\n");
        printf("2. Adicionar Estoque\n");
        printf("3. Consultar estoque\n");
        printf("4. Funcionarios\n");
        printf("5. Cadastrar clientes\n");
        printf("6. Gerar relatorio\n");
        printf("7. Caixa da loja\n");
        printf("8. Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Registrar venda\n");
            break;
        case 2:
            printf("Adicionar Estoque\n");
            break;
        case 3:
            printf("Consultar estoque\n");
            break;
        case 4:
            printf("Funcionarios\n");
            break;
        case 5:
            printf("Cadastrar clientes\n");
            break;
        case 6:
            gerarRelatorio();
            break;
        case 7:
            printf("Caixa da loja\n");
            break;
        case 8:
            printf("Saindo...\n");
            continuar = 0;
            break;
        default:
            printf("Opcao invalida.\n");
        }
    }

    return 0;
}