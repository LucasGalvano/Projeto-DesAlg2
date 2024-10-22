#ifndef publico_h
#define publico_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para os funcionarios
#define cota 3000.00
#define bonus 500.00
#define MAX_FUNCIONARIOS 10

struct Funcionarios{
    char nome[50];
    char cpf[12];
    float salario;
    int qtd_vendas;
    int quantidade;
    float total_vendas;
    int id;
};

// Estrutura para armazenar os clientes
struct Cliente{
    char nome[50];
    char cpf[12];
};

void cadastrar_cliente(struct Cliente* cliente);
void cadastrar_funcionario(struct Funcionarios *funcionarios, int *qtd_funcionarios);
void consultar_funcionario(struct Funcionarios *funcionarios, int qtd_funcionarios);
#endif