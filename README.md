# Loja de Roupas - Sistema de Gestão

Este projeto consiste em um sistema de gestão para uma loja de roupas com um saldo inicial de 10 mil reais, com diversas funcionalidades que permitem controlar as vendas, estoque, cadastro de funcionários e clientes, além de gerar relatórios e gerenciar o caixa da loja. O código foi organizado em diferentes branches, cada uma responsável por um aspecto específico da operação da loja.

Para rodar o código no terminal, utilize o comando "gcc main.c caixa.c estoque.c funcoes.c publico.c"

## Funcionalidades Principais

1. Registrar venda
2. Adicionar Estoque
3. Consultar Estoque
4. Buscar no Estoque
5. Cadastrar Funcionário
6. Consultar Funcionários
7. Cadastrar Clientes
8. Consultar Clientes
9. Gerar Relatório
10. Caixa da Loja
11. Sair

## Estrutura do Código

O código do projeto foi dividido em diferentes branches para facilitar o desenvolvimento e organização:

- **caixa**: Responsável por controlar o fluxo de caixa da loja.
- **publico**: Contém funcionalidades voltadas para os funcionários e clientes.
- **estoque**: Manipula a quantidade de produtos, códigos das roupas e preços.
- **funcoes**: Contém funções complementares que não se encaixam diretamente nas outras branches.
