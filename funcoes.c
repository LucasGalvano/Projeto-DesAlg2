#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clearBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void salvarRelatorio(Relatorio novo_relatorio)
{
    FILE *file = fopen("relatorios.txt", "a");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    // Escreve a data e o conteúdo no arquivo
    fprintf(file, "Conteudo: %s\n\n", novo_relatorio.conteudo);
    fclose(file); // Fecha o arquivo

    // Mostra no terminal
    printf("Relatorio salvo e exibido:\n");
    printf("Conteudo: %s\n\n", novo_relatorio.conteudo);
}

void gerarRelatorio()
{
    Relatorio novo_relatorio; // Criando um novo relatório

    // Coletando o conteúdo do relatório
    printf("Digite o conteudo do relatorio: ");
    clearBuffer();
    fgets(novo_relatorio.conteudo, sizeof(novo_relatorio.conteudo), stdin);
    novo_relatorio.conteudo[strcspn(novo_relatorio.conteudo, "\n")] = 0;

    // Salvando o relatório
    salvarRelatorio(novo_relatorio);
}

//função que gera senha
int gera_senha(){
    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // Gera e imprime uma senha de 6 dígitos
    printf("Senha gerada: ");
    for (int i = 0; i < 6; i++) {
        printf("%d", rand() % 10);  // Gera um número aleatório entre 0 e 9
    }
    
    printf("\n");
}