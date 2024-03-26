#include <iostream>
#include <vector>
#include <string> 

struct Transaction {
    std::string nomeDoCliente;
    double value; 
};

// Função de ordenação Insertion Sort
void insertionSort(std::vector<Transaction>& transactions) {
    int n = transactions.size();
    for (int i = 1; i < n; i++) {
        Transaction key = transactions[i];
        int j = i - 1;

        // Mova os elementos do vetor que são maiores que a chave, para uma posição à frente de sua posição atual
        while (j >= 0 && transactions[j].value > key.value) {
            transactions[j + 1] = transactions[j];
            j = j - 1;
        }
        transactions[j + 1] = key;
    }
}

void printTransactions(const std::vector<Transaction>& transactions) {
    for (const auto& transaction : transactions) {
        std::cout << "Cliente: " << transaction.nomeDoCliente << ", Valor: " << transaction.value << std::endl;
    }
    std::cout << std::endl;
}

int main() { 
    std::vector<Transaction> transactions = {
        {"Cleber", 100.0},
        {"Clebinho", 50.0},
        {"Clebaldo", 200.0},
        {"Clerucio", 25.0}
    };

    std::cout << "Transações Desordenadas:\n";
    printTransactions(transactions);

    insertionSort(transactions);

    std::cout << "Transações Ordenadas:\n";
    printTransactions(transactions);

    return 0;
} 