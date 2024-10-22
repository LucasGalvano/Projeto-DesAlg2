#ifndef publico_h
#define publico_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para os funcionarios
struct Funcionarios{
    char nome[50];
    char cpf[12];
    float salario;
    int qtd_vendas;
};

// Estrutura para armazenar os clientes
struct Cliente{
    char nome[50];
    char cpf[12];
};
#endif