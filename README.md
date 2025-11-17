# 🏪 Inventário de loja usando STL em C++

Um sistema simples em **C++** para gerenciamento de produtos, controle de estoque e registro de vendas, utilizando diferentes estruturas da STL como **vector**, **set** e **map**.

---

## 🚀 Funcionalidades

✔ Adicionar novos produtos  
✔ Listar todos os produtos cadastrados  
✔ Exibir categorias únicas (usando `set`)  
✔ Calcular quantidade total em estoque por categoria (usando `map<string, int>`)  
✔ Calcular valor total do estoque por categoria (usando `map<string, double>`)  
✔ Buscar produto por nome  
✔ Registrar vendas com desconto em estoque  
✔ Exibir histórico de vendas

---

## Menu do Sistema

- 1 - Adicionar Produto
- 2 - Listar Produtos
- 3 - Quantidade Total do estoque por Categoria
- 4 - Valor total em estoque por categoria
- 5 - Mostrar Categorias Unicas
- 6 - Buscar Produto por nome
- 7 - Registrar venda
- 8 - Mostrar historico de vendas
- 9 - Sair do programa

---

## Estrutura do Projeto

### Classe `Produto`

Armazena informações essenciais como nome, categoria, preço e estoque.

### Struct `Venda`

Utilizada no histórico de vendas.

---

## ▶️ Como Executar

### Pré-requisitos

- Compilador C++ (G++, Clang ou MSVC)
- Terminal ou IDE (Dev-C++, CodeBlocks, Replit, Visual Studio, VSCode etc.)

# Como compilar e Executar

1. Salve o código em um arquivo chamado `main.cpp` ou baixe o arquivo.
2. Compile o programa:
   ```bash
   g++ main.cpp -o nomeescolhido
   ```
3. Execute o programa
   ```bash
   .\nomeescolhido
   ```

## 👩‍🚀 Autor

Desenvolvido por Juliano Aureliano. 😊

> **Nota:** Este projeto foi feito para uma atividade prática da unidade
