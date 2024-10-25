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
        if(fgets(novo_funcionario.nome, sizeof(novo_funcionario.nome), stdin) == NULL){
            printf("Erro ao ler nome, tente novamente.\n");
            return;
        }
        novo_funcionario.nome[strcspn(novo_funcionario.nome, "\n")] = '\0';
    } while (strlen(novo_funcionario.nome) == 0);

    // Checador de CPF
    int cpf_valido = 0;

    while (!cpf_valido) {
        printf("Digite o CPF do funcionario: ");
        if(fgets(novo_funcionario.cpf, sizeof(novo_funcionario.cpf), stdin) == NULL) {
            printf("Erro ao ler CPF, tente novamente.\n");
            continue;
        }
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


void consultar_funcionario(struct Funcionarios *funcionarios, int qtd_funcionarios){
    if (qtd_funcionarios == 0) {
        printf("Nenhum funcionario cadastrado, cadastre um e volte mais tarde!.\n");
        return;
    }

    printf("\n--- Funcionarios Atuais ---\n");
    int i;
    for (i = 0; i < qtd_funcionarios; i++) {
        printf("ID: %d\n", funcionarios[i].id);
        printf("Nome: %s\n", funcionarios[i].nome);
        printf("CPF: %s\n", funcionarios[i].cpf);
        printf("Salario: R$ %.2f\n", funcionarios[i].salario);
        printf("Total de Vendas: R$ %.2f\n", funcionarios[i].total_vendas);
        printf("-------------\n");
    }
}

void cadastrar_cliente(struct Cliente *cliente, int *qtd_cliente){
    struct Cliente novo_cliente;

    printf("Digite o nome do cliente: ");
    if(fgets(novo_cliente.nome, sizeof(novo_cliente.nome), stdin) == NULL){
        printf("Falha ao ler nome. Tente novamente.\n");
        return;
    }
    novo_cliente.nome[strcspn(novo_cliente.nome, "\n")] = '\0';

    int cpf_valido = 0;

    while (!cpf_valido) {
        printf("Digite o CPF do cliente: ");
        if(fgets(novo_cliente.cpf, sizeof(novo_cliente.cpf), stdin) == NULL){
            printf("Falha ao ler CPF. Tente novamente.\n");
            continue;
        }
        novo_cliente.cpf[strcspn(novo_cliente.cpf, "\n")] = '\0';

        if (strlen(novo_cliente.cpf) == 11) {
            cpf_valido = 1;
        } 
        else {
            printf("Erro! O CPF deve ter 11 digitos.\n");
        }
        clearBuffer();
    }

    cliente[*qtd_cliente] = novo_cliente;
    (*qtd_cliente)++;
    printf("Cliente cadastrado com sucesso!\n\n");
}

void consultar_cliente(struct Cliente *cliente, int qtd_cliente){
    if (qtd_cliente == 0) {
        printf("Nenhum cliente cadastrado, cadastre um e volte mais tarde!.\n");
        return;
    }
    printf("\n--- Clientes Atuais ---\n");
    int i;
    for (i = 0; i < qtd_cliente; i++) {
        printf("Nome: %s\n", cliente[i].nome);
        printf("CPF: %s\n", cliente[i].cpf);
        printf("-------------\n");
    }
}