#include <iostream>
#include <vector>
#include <string>

struct Contato {
    std::string nome;
    std::string dataNascimento; 
};

void merge(std::vector<Contato>& contatos, int esquerda, int meio, int direita) {
    int i, j, k;
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    std::vector<Contato> L(n1), R(n2);

    for (i = 0; i < n1; i++)
        L[i] = contatos[esquerda + i];
    for (j = 0; j < n2; j++)
        R[j] = contatos[meio + 1 + j];

    i = 0;
    j = 0;
    k = esquerda;
    while (i < n1 && j < n2) {
        if (L[i].nome < R[j].nome) {
            contatos[k] = L[i];
            i++;
        } else if (L[i].nome == R[j].nome && L[i].dataNascimento < R[j].dataNascimento) {
            contatos[k] = L[i];
            i++;
        } else {
            contatos[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        contatos[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        contatos[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<Contato>& contatos, int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        mergeSort(contatos, esquerda, meio);
        mergeSort(contatos, meio + 1, direita);

        merge(contatos, esquerda, meio, direita);
    }
}

int main() {
    std::vector<Contato> contatos = {
        {"Ana", "1990-01-01"},
        {"Carlos", "1985-05-12"},
        {"Bia", "1995-07-23"},
        {"Ana", "1980-02-03"},
        {"Carlos", "1990-01-01"}
    };

    std::cout << "Antes da ordenação:\n";
    for (const auto& contato : contatos) {
        std::cout << "Nome: " << contato.nome << ", Data de Nascimento: " << contato.dataNascimento << std::endl;
    }

    mergeSort(contatos, 0, contatos.size() - 1);

    std::cout << "\nDepois da ordenação:\n";
    for (const auto& contato : contatos) {
        std::cout << "Nome: " << contato.nome << ", Data de Nascimento: " << contato.dataNascimento << std::endl;
    }

    return 0;
}