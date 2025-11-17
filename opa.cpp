#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
using namespace std;

// classe Produto
class Produto
{
public:
    string nome;
    string categoria;
    double preco;
    int estoque;

    Produto(string n, string c, double p, int e)
        : nome(n), categoria(c), preco(p), estoque(e) {}

    void exibir() const
    {
        cout << "Produto: " << nome << ", Categoria: " << categoria << ", Preco: " << preco << " , Estoque: " << estoque << endl;
    }
};

void exibirCategoriasUnicas(const vector<Produto> &produtos)
{
    set<string> categoriaUnica; // set categoria unica
                                // set: categorias unicas de produtos
    for (const Produto &produto : produtos)
    {
        categoriaUnica.insert(produto.categoria);
    }
    cout << "\n--- CATEGORIAS UNICAS (set) ---" << endl;
    for (const string &unico : categoriaUnica)
    {
        cout << "- " << unico << endl;
    }
}
void exibirProdutos(const vector<Produto> &produtos)
{
    cout << "\n--- TODOS OS Produtos (vector) ---" << endl;
    for (const auto &opa : produtos)
    {
        opa.exibir();
    }
}

map<string, int> quantidadeEmEstoquePorCategoria(const vector<Produto> &produtos)
{
    // map<string, int>: contagem de produtos por categoria
    map<string, int> quantidadeEmEstoque;
    for (auto &p : produtos)
    {
        quantidadeEmEstoque[p.categoria] += p.estoque;
    }
    return quantidadeEmEstoque;
}

map<string, double> valorTotalEmEstoquePorCategoria(const vector<Produto> &produtos)
{
    // map<string, double>: valor total em estoque por categoria
    map<string, double> valorTotalEmEstoque;
    for (auto &p : produtos)
    {
        valorTotalEmEstoque[p.categoria] += p.preco * p.estoque;
    }
    return valorTotalEmEstoque;
}
int main()
{
    vector<Produto> produtos;

    // adicionando produtos
    produtos.push_back(Produto("Camisa", "Vestuario", 79.90, 30));
    produtos.push_back(Produto("Calça Jeans", "Vestuario", 120.50, 20));
    produtos.push_back(Produto("Notebook", "Eletronicos", 3500.00, 5));
    produtos.push_back(Produto("Mouse Gamer", "Eletronicos", 150.00, 15));

    exibirProdutos(produtos);

    // quantidade Total do estoque por Categoria(map)
    auto quantidadeEmEstoque = quantidadeEmEstoquePorCategoria(produtos);
    cout << "\n-----Quantidade Total do estoque por Categoria(map):\n";
    for (const auto &par : quantidadeEmEstoque)
    {
        cout << "Categoria: " << par.first << " | Quantidade Total:  " << par.second << endl;
    }

    // map<string, double>: valor total em estoque por categoria
    auto valorTotalEmEstoque = valorTotalEmEstoquePorCategoria(produtos);
    cout << "\n-----Valor Total por Categoria(map):\n";
    for (const auto &par : valorTotalEmEstoque)
    {
        cout << "Categoria: " << par.first << " | Valor Total: R$ " << par.second << endl;
    }

    exibirCategoriasUnicas(produtos);
    return 0;
}
