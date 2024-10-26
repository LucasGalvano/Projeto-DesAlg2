# Loja de Roupas - Registro de Vendas

Este módulo implementa a função `registrar_venda`, responsável pelo processo de registrar vendas na loja. Ele exibe o estoque, valida o funcionário, processa a venda, atualiza o saldo do caixa e as vendas dos funcionários.

## Função Principal

- **registrar_venda**: Registra uma venda com os seguintes passos:
  - Exibe o estoque de produtos.
  - Valida o ID do funcionário que realizou a venda.
  - Valida o código do produto vendido e o remove do estoque.
  - Atualiza o total de vendas do funcionário e adiciona um bônus se a meta for atingida.
  - Adiciona o valor da venda ao saldo do caixa.

