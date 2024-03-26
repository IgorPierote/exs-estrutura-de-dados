#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string descricao;
    int prioridade; 
};

void merge(std::vector<Task>& tarefas, int esquerda, int meio, int direita) {
    int i, j, k;
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    std::vector<Task> L(n1), R(n2);

    for (i = 0; i < n1; i++)
        L[i] = tarefas[esquerda + i];
    for (j = 0; j < n2; j++)
        R[j] = tarefas[meio + 1 + j];

    i = 0;
    j = 0;
    k = esquerda;
    while (i < n1 && j < n2) {
        if (L[i].prioridade <= R[j].prioridade) {
            tarefas[k] = L[i];
            i++;
        } else {
            tarefas[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        tarefas[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        tarefas[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<Task>& tarefas, int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        mergeSort(tarefas, esquerda, meio);
        mergeSort(tarefas, meio + 1, direita);

        merge(tarefas, esquerda, meio, direita);
    }
}

int main() {
    std::vector<Task> tarefas = {
        {"Correr", 3},
        {"Academia", 1},
        {"Trabaia", 2},
        {"Estuda", 4}
    };

    std::cout << "Antes da ordenação:\n";
    for (const auto& tarefa : tarefas) {
        std::cout << "Nome da Tarefa: " << tarefa.descricao << ", Prioridade: " << tarefa.prioridade << std::endl;
    }

    mergeSort(tarefas, 0, tarefas.size() - 1);

    std::cout << "\nDepois da ordenação:\n";
    for (const auto& tarefa : tarefas) {
        std::cout << "Nome da Tarefa: " << tarefa.descricao << ", Prioridade: " << tarefa.prioridade << std::endl;
    }

    return 0;
}