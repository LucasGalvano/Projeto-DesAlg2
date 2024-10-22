#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "publico.h"
#include "funcoes.h"
#include "estoque.h"
#include "caixa.h"

void cadastrar_funcionario(struct Funcionarios *funcionarios, int *qtd_funcionarios) {
    struct Funcionarios novo_funcionario;
    
    // Nome do funcionário
    do {
        printf("Digite o nome do funcionario: ");
        fgets(novo_funcionario.nome, 50, stdin);
        novo_funcionario.nome[strcspn(novo_funcionario.nome, "\n")] = '\0';
    } while (strlen(novo_funcionario.nome) == 0);

    // Checador de CPF
    int cpf_valido = 0;

    while (!cpf_valido) {
        printf("Digite o CPF do funcionario: ");
        fgets(novo_funcionario.cpf, 12, stdin);
        novo_funcionario.cpf[strcspn(novo_funcionario.cpf, "\n")] = '\0';

        if (strlen(novo_funcionario.cpf) == 11) {
            cpf_valido = 1;
        }
        else {
            printf("Erro! O CPF deve ter 11 digitos.\n");
        }
        clearBuffer();
    }

    // Defs para o novo funcionario
    novo_funcionario.salario = 2000.0;  
    novo_funcionario.total_vendas = 0;  
    novo_funcionario.id = *qtd_funcionarios + 1;  

    // Incrementa o número de funcionários
    funcionarios[*qtd_funcionarios] = novo_funcionario;
    (*qtd_funcionarios)++;

    printf("Funcionario cadastrado com sucesso! ID: %d\n", novo_funcionario.id);
}


void consultar_funcionario(struct Funcionarios *funcionarios, int qtd_funcionarios) {
    if (qtd_funcionarios == 0) {
        printf("Nenhum funcionario cadastrado, cadastre um e volte aqui.\n");
        return;
    }

    printf("\n--- Funcionarios Atuais ---\n");
    int i;
    for (i = 0; i < qtd_funcionarios; i++) {
        printf("ID: %d\n", funcionarios[i].id);
        printf("Nome: %s\n", funcionarios[i].nome);
        printf("CPF: %s\n", funcionarios[i].cpf);
        printf("Salario: %.2f\n", funcionarios[i].salario);
        printf("Total de Vendas: %.2f\n", funcionarios[i].total_vendas);
        printf("-------------\n");
    }
}

void cadastrar_cliente(struct Cliente *cliente){
    printf("Digite o nome do cliente: ");
    fgets(cliente->nome, 50, stdin);
    cliente->nome[strcspn(cliente->nome, "\n")] = '\0';

    int cpf_valido = 0;

    while (!cpf_valido) {
        printf("Digite o CPF do cliente: ");
        fgets(cliente->cpf, 12, stdin);
        cliente->cpf[strcspn(cliente->cpf, "\n")] = '\0';

        if (strlen(cliente->cpf) == 11) {
            cpf_valido = 1;
        } 
        else {
            printf("Erro! O CPF deve ter 11 digitos.\n");
        }
        clearBuffer();
    }
    printf("Cliente cadastrado com sucesso!\n\n");
}