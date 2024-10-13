#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clearBuffer()
{
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
// Função para cadastro
void cadastrar_loja(struct Loja *loja) {
    // Nome da loja 
    printf("Digite o nome da loja: ");
    fgets(loja->nome_loja, 50, stdin);
    loja->nome_loja[strcspn(loja->nome_loja, "\n")] = '\0';

    // Senha
    int senhaValida = 0;
    while (!senhaValida) {
        printf("Digite uma senha de 6 digitos: ");
        fgets(loja->senha, 7, stdin);
        loja->senha[strcspn(loja->senha, "\n")] = '\0';

        // Verifica se a senha tem exatamente 6 caracteres
        if (strlen(loja->senha) == 6) {
            senhaValida = 1; 
        }
        else {
            printf("A senha deve ter exatamente 6 digitos.\n");
        }
        clearBuffer();
    }
    printf("Cadastro realizado com sucesso!\n\n");
}

// Função para login
int login(struct Loja *loja) {
    char nome_login[50];
    char senha_login[7];
    printf("--- Login ---\n");
    printf("Digite o nome da loja: ");
    fgets(nome_login, 50, stdin);
    nome_login[strcspn(nome_login, "\n")] = '\0';

    printf("Digite a senha: ");
    fgets(senha_login, 7, stdin);
    senha_login[strcspn(senha_login, "\n")] = '\0';

    clearBuffer();
    // Valida oq foi digitado no login
    if (strcmp(loja->nome_loja, nome_login) == 0 && strcmp(loja->senha, senha_login) == 0) {
        printf("Login realizado com sucesso!\n");
        return 1;
    }
    else {
        printf("Nome e/ou senha incorretos. Tente novamente.\n");
        return 0;
    }
}
