#include <iostream>
#include <vector>
#include <string>

struct Product {
    std::string produto;
    double preco; 
};

// Função de ordenação Selection Sort
void selectionSort(std::vector<Product>& products) {
    int n = products.size();
    for (int i = 0; i < n - 1; i++) {
        // Encontre o mínimo elemento no vetor desordenado
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (products[j].preco < products[min_idx].preco)
                min_idx = j;

        // Troque o mínimo elemento encontrado com o primeiro elemento
        std::swap(products[min_idx], products[i]);
    }
}

// Função para imprimir os produtos
void printProducts(const std::vector<Product>& products) {
    for (const auto& product : products) {
        std::cout << "Produto: " << product.produto << ", Preço: " << product.preco << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    std::vector<Product> products = {
        {"PC top", 300.0},
        {"PC mêdio", 250.0},
        {"PC marro menos", 200.0},
        {"PC da positivo", 2500.0}
    };

    std::cout << "Produtos Desordenados:\n";
    printProducts(products);

    selectionSort(products);

    std::cout << "Produtos Ordenados:\n";
    printProducts(products);

    return 0;
}