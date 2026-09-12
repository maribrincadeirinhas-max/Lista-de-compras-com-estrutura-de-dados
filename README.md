# Lista de Compras com Estrutura de Dados em C

Este é um sistema simples e interativo de **Lista de Compras** desenvolvido em linguagem C. O projeto foi estruturado utilizando conceitos de **Estruturas de Dados Dinâmicas**, especificamente uma lista simplesmente encadeada com ponteiros de controle para o primeiro e o último produto.

## Funcionalidades

O programa conta com um menu interativo que permite realizar as seguintes operações:
1. **Adicionar Produto:** Insere um novo item sempre no final da lista.
2. **Remover Produto:** Busca um produto pelo nome e o remove da memória.
3. **Exibir Produtos:** Mostra todos os itens da lista indicando se já foram comprados.
4. **Marcar Produto:** Altera o status de um produto específico para "Comprado".
5. **Total:** Exibe a quantidade total de produtos cadastrados na lista.

## 🛠️ Tecnologias e Conceitos Utilizados

- **Linguagem:** C
- **Alocação Dinâmica de Memória:** `malloc` e `free`
- **Estruturas de Dados:** Listas Encadeadas (`struct`)

##Como executar o programa:
   - No Windows (Prompt/PowerShell):
     ```cmd
     gcc ListaCompras.c -o ListaCompras.exe
     ```
     ```cmd
     .\ListaCompras.exe
     ```
