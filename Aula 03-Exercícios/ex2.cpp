#include <iostream>
#include <string>

struct Product {
    std::string name; 
    int stockLevel; 
};

// Função de ordenação Selection Sort
void selectionSort(Product products[], int n) {
    // Loop para percorrer todos os elementos do vetor
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // assumindo o primeiro elemento como o menor
        
        // Loop para encontrar o elemento mínimo em produtos não ordenados
        for (int j = i + 1; j < n; j++) {
            // Se o produto atual tem um nível de estoque menor que o produto mínimo atual, atualize o índice mínimo
            if (products[j].stockLevel < products[minIndex].stockLevel) {
                minIndex = j;
            }
        }
        
        // Troca o elemento mínimo encontrado pelo primeiro elemento
        if (minIndex != i) {
            std::swap(products[i], products[minIndex]);
        }
    }
}

int main() {
    Product products[] = {
        {"Produto Coca", 5},
        {"Produto Dolly", 2},
        {"Produto Fanta", 8},
        {"Produto Sprite", 3},
        {"Produto Tubaina", 1}
    };
    int n = sizeof(products) / sizeof(products[0]);
    
    // Imprimindo antes da ordenação
    std::cout << "Antes do selection sort:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << products[i].name << " - Stock: " << products[i].stockLevel << std::endl;
    }
    
    // Ordenando
    selectionSort(products, n);
    
    // Imprimindo após a ordenação
    std::cout << "Depois do selection sort:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << products[i].name << " - Stock: " << products[i].stockLevel << std::endl;
    }
    
    return 0;
}