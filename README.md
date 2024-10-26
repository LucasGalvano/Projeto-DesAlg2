# Loja de Roupas - Branch `funcoes`

Esta branch contém funções de suporte essenciais para o sistema de gestão da loja. As principais funcionalidades incluem geração de código, login, limpeza de buffer e criação de relatórios.

## Funcionalidades Principais

- **Geração de Código**: 
  - `gera_codigo`: Cria um código único para identificar produtos.
  - `checa_codigo`: Verifica se o código gerado é único e o adiciona ao sistema.

- **Relatórios**: 
  - `gerarRelatorio`: Cria relatórios baseados em dados inseridos.
  - `salvarRelatorio`: Salva o relatório em um arquivo para consulta futura.

- **Cadastro e Login**:
  - `cadastrar_loja`: Cadastro de uma nova loja com nome e senha.
  - `login`: Autentica o acesso da loja com nome e senha.

- **Limpeza de Buffer**:
  - `clearBuffer`: Limpa a entrada de dados para evitar erros.

Essas funções auxiliam o programa principal e estão organizadas para fácil manutenção e integração com outras partes do sistema.

