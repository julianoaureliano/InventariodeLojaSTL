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

int main()
{
    vector<Produto> produtos;

    // adicionando produtos
    produtos.push_back(Produto("Camisa", "Vestuario", 79.90, 30));
    produtos.push_back(Produto("Calça Jeans", "Vestuario", 120.50, 20));
    produtos.push_back(Produto("Notebook", "Eletronicos", 3500.00, 5));
    produtos.push_back(Produto("Mouse Gamer", "Eletronicos", 150.00, 15));

    cout << "\n--- TODOS OS Produtos (vector) ---" << endl;
    for (const auto &opa : produtos)
    {
        opa.exibir();
    }
    return 0;
}
