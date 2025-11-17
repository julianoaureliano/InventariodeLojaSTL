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
void adicionarProduto(vector<Produto> &produtos)
{
    string nome, categoria;
    double preco;
    int estoque;
    cout << "\n---ADICIONAR PRODUTO: \n";
    cin.ignore();
    cout << "Nome do Produto: ";
    getline(cin, nome);
    cout << "Categoria do Produto: ";
    getline(cin, categoria);
    cout << "Preco do produto: ";
    cin >> preco;
    cout << "Estoque do produto: ";
    cin >> estoque;
    produtos.emplace_back(nome, categoria, preco, estoque);
    cout << "Produto adicionado com sucesso!\n";
}

Produto *buscarProduto(vector<Produto> &produtos, const string &nome)
{
    for (auto &p : produtos)
    {
        if (p.nome == nome)
        {
            return &p;
        }
    }
    return nullptr;
}

void buscarProdutoPorNome(vector<Produto> &produtos)
{
    cout << "\n--- BUSCAR PRODUTO ---\n";
    cin.ignore();
    string nome;
    cout << "Digite o nome: ";
    getline(cin, nome);

    Produto *p = buscarProduto(produtos, nome);
    if (p != nullptr)
        p->exibir();
    else
        cout << "\nProduto nao encontrado! Atente as letras maiusculas e menusculas\n";
}

int main()
{
    vector<Produto> produtos;

    // adicionando produtos
    produtos.push_back(Produto("Camisa", "Vestuario", 79.90, 30));
    produtos.push_back(Produto("Calça Jeans", "Vestuario", 120.50, 20));
    produtos.push_back(Produto("Notebook", "Eletronicos", 3500.00, 5));
    produtos.push_back(Produto("Mouse Gamer", "Eletronicos", 150.00, 15));

    int opcao;
    do
    {
        cout << "\n========== MENU ==========\n";
        cout << "1 - Adicionar Produto\n";
        cout << "2 - Listar Produtos\n";
        cout << "3 - Quantidade Total do estoque por Categoria\n";
        cout << "4 - Valor total em estoque por categoria\n";
        cout << "5 - Mostrar Categorias Unicas\n";
        cout << "6 - Buscar Produto por nome\n";
        cout << "7 - Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            adicionarProduto(produtos);
            break;

        case 2:
            exibirProdutos(produtos);
            break;

        case 3:
        {
            // quantidade Total do estoque por Categoria(map)
            auto quantidadeEmEstoque = quantidadeEmEstoquePorCategoria(produtos);
            cout << "\n-----Quantidade Total do estoque por Categoria(map):\n";
            for (const auto &par : quantidadeEmEstoque)
            {
                cout << "Categoria: " << par.first << " | Quantidade Total:  " << par.second << endl;
            }
            break;
        }

        case 4:
        {
            // map<string, double>: valor total em estoque por categoria
            auto valorTotalEmEstoque = valorTotalEmEstoquePorCategoria(produtos);
            cout << "\n-----Valor Total por Categoria(map):\n";
            double totalvalorEstoque = 0;
            for (const auto &par : valorTotalEmEstoque)
            {
                cout << "Categoria: " << par.first << " | Valor Total: R$ " << par.second << endl;
                totalvalorEstoque += par.second;
            }
            cout << "---Valor total do Inventário: R$" << totalvalorEstoque << endl;

            break;
        }

        case 5:
            exibirCategoriasUnicas(produtos);
            break;

        case 6:
            buscarProdutoPorNome(produtos);
            break;
        case 7:
            cout << "Encerrando o sistema...\n";
            break;

        default:
            cout << "\n----Opcao invalida!----\n";
        }

    } while (opcao != 7);

    return 0;
}
