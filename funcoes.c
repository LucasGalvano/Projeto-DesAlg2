#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int gera_codigo() {
    int codigo;
    codigo = rand() % 1000;
    return codigo;
}

int checa_codigo(int **codigos, int *tamanho, int codigo) {
    // Verifica se o codigo ja existe no vetor
    int i;
    for (i = 0; i < *tamanho; i++) {
        if ((*codigos)[i] == codigo) {
            printf("Codigo %d ja existe.\n", codigo);
            return 1;
        }
    }

    // Adiciona o codigo no vetor caso ele não seja repetido
    *codigos = realloc(*codigos, (*tamanho + 1) * sizeof(int));
    if (*codigos == NULL) {
        printf("Erro ao alocar memoria.\n");
        return -1;
    }

    // Adiciona o novo numero ao vetor de codigos
    (*codigos)[*tamanho] = codigo;
    (*tamanho)++;
    return 0;
}

void salvarRelatorio(Relatorio novo_relatorio) {
    FILE *file = fopen("relatorios.txt", "a");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    fprintf(file, "Conteudo: %s\n", novo_relatorio.conteudo);
    fclose(file);
    printf("Relatorio salvo e exibido:\n");
    printf("Conteudo: %s\n\n", novo_relatorio.conteudo);
}

void gerarRelatorio() {
    Relatorio novo_relatorio;
    printf("Digite o conteudo do relatorio: ");
    fgets(novo_relatorio.conteudo, sizeof(novo_relatorio.conteudo), stdin);
    novo_relatorio.conteudo[strcspn(novo_relatorio.conteudo, "\n")] = 0;
    salvarRelatorio(novo_relatorio);
}

void cadastrar_loja(struct Loja *loja) {
    printf("Digite o nome da loja: ");
    fgets(loja->nome_loja, 50, stdin);
    loja->nome_loja[strcspn(loja->nome_loja, "\n")] = '\0';

    int senhaValida = 0;

    while (!senhaValida) {
        printf("Digite uma senha de 6 digitos: ");
        fgets(loja->senha, 7, stdin);
        loja->senha[strcspn(loja->senha, "\n")] = '\0';

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

    if (strcmp(loja->nome_loja, nome_login) == 0 && strcmp(loja->senha, senha_login) == 0) {
        printf("Login realizado com sucesso!\n");
        return 1;
    } else {
        printf("Nome e/ou senha incorretos. Tente novamente.\n");
        return 0;
    }
}
