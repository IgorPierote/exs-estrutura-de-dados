#include <iostream> // Adicione esta linha
#include <vector>
#include <string>

// Função para combinar duas metades ordenadas em um único vetor ordenado
void merge(std::vector<std::string>& names, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Crie vetores temporários
    std::vector<std::string> L(n1), R(n2);

    // Copie os dados para os vetores temporários L[] e R[]
    for (i = 0; i < n1; i++)
        L[i] = names[left + i];
    for (j = 0; j < n2; j++)
        R[j] = names[mid + 1 + j];

    // Combine os vetores temporários de volta ao vetor names
    i = 0; // Índice inicial do primeiro subvetor
    j = 0; // Índice inicial do segundo subvetor
    k = left; // Índice inicial do subvetor mesclado
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            names[k] = L[i];
            i++;
        } else {
            names[k] = R[j];
            j++;
        }
        k++;
    }

    // Copie os elementos restantes da esquerda
    while (i < n1) {
        names[k] = L[i];
        i++;
        k++;
    }

    // Copie os elementos restantes da direita
    while (j < n2) {
        names[k] = R[j];
        j++;
        k++;
    }
}

// Função principal MergeSort
void mergeSort(std::vector<std::string>& names, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Ordena a primeira e a segunda metade
        mergeSort(names, left, mid);
        mergeSort(names, mid + 1, right);

        merge(names, left, mid, right);
    }
}

int main() {
    std::vector<std::string> names = {
        "photo3.jpg", "photo1.jpg", "photo2.jpg", "photo4.jpg", "photo5.jpg", "photo6.jpg"
    };

    mergeSort(names, 0, names.size() - 1);

    for (const auto& name : names) {
        std::cout << name << std::endl;
    }

    return 0;
}