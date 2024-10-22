#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "publico.h"

struct Funcionarios funcioario;
void cadastrar_funcionario(struct Funcionarios *funcionario){
    printf("Digite o nome do funcionario: ");
    fgets(funcionario->nome, 50, stdin);
    funcionario->nome[strcspn(funcionario->nome, "\n")] = '\0';

    int cpf_valido = 0;

    while (!cpf_valido) {
        printf("Digite o CPF do funcionario: ");
        fgets(funcionario->cpf, 12, stdin);
        funcionario->cpf[strcspn(funcionario->cpf, "\n")] = '\0';

        if (strlen(funcionario->cpf) == 11) {
            cpf_valido = 1;
        } 
        else {
            printf("Erro! O CPF deve ter 11 digitos.\n");
        }
        clearBuffer();
    }
    printf("Funcionario cadastrado com sucesso!\n\n");
}

void cadastrar_cliente(struct Funcionarios *cliente){
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