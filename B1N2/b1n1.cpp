#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <numeric>

class Pessoa {
public:
    std::string nome;
    std::string dataNascimento;
    double peso;
    double altura;

    Pessoa() {}

    Pessoa(std::string nome, std::string dataNascimento, double peso, double altura) {
        this->nome = nome;
        this->dataNascimento = dataNascimento;
        this->peso = peso;
        this->altura = altura;
    }
};

// Bubble Sort
void bubbleSort(std::vector<Pessoa>& pessoas) {
    int i, j;
    int n = pessoas.size();
    for (i = 0; i < n-1; i++)      
        for (j = 0; j < n-i-1; j++) 
            if (pessoas[j].nome > pessoas[j+1].nome)
                std::swap(pessoas[j], pessoas[j+1]);
}

// Insertion Sort
void insertionSort(std::vector<Pessoa>& pessoas) {
    int i, j;
    Pessoa key;
    int n = pessoas.size();
    for (i = 1; i < n; i++) {
        key = pessoas[i];
        j = i - 1;
        while (j >= 0 && pessoas[j].nome > key.nome) {
            pessoas[j + 1] = pessoas[j];
            j = j - 1;
        }
        pessoas[j + 1] = key;
    }
}

// Selection Sort
void selectionSort(std::vector<Pessoa>& pessoas) {
    int i, j, min_idx;
    int n = pessoas.size();
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (pessoas[j].nome < pessoas[min_idx].nome)
                min_idx = j;
        std::swap(pessoas[min_idx], pessoas[i]);
    }
}

// Merge Sort
void merge(std::vector<Pessoa>& pessoas, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    std::vector<Pessoa> L(n1), R(n2);
    for (i = 0; i < n1; i++)
        L[i] = pessoas[l + i];
    for (j = 0; j < n2; j++)
        R[j] = pessoas[m + 1+ j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i].nome <= R[j].nome) {
            pessoas[k] = L[i];
            i++;
        }
        else {
            pessoas[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        pessoas[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        pessoas[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<Pessoa>& pessoas, int l, int r) {
    if (l < r) {
        int m = l+(r-l)/2;
        mergeSort(pessoas, l, m);
        mergeSort(pessoas, m+1, r);
        merge(pessoas, l, m, r);
    }
}

// Quick Sort
int partition (std::vector<Pessoa>& pessoas, int low, int high) {
    Pessoa pivot = pessoas[high];
    int i = (low - 1);
    for (int j = low; j <= high- 1; j++) {
        if (pessoas[j].nome <= pivot.nome) {
            i++;
            std::swap(pessoas[i], pessoas[j]);
        }
    }
    std::swap(pessoas[i + 1], pessoas[high]);
    return (i + 1);
}

void quickSort(std::vector<Pessoa>& pessoas, int low, int high) {
    if (low < high) {
        int pi = partition(pessoas, low, high);
        quickSort(pessoas, low, pi - 1);
        quickSort(pessoas, pi + 1, high);
    }
}

int main() {
    std::vector<Pessoa> pessoas;
    std::ifstream file("dados_pessoais.csv");
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string nome, dataNascimento, pesoStr, alturaStr;
        std::getline(ss, nome, ';');
        std::getline(ss, dataNascimento, ';');
        std::getline(ss, pesoStr, ';');
        std::getline(ss, alturaStr, ';');
        double peso = std::stod(pesoStr);
        double altura = std::stod(alturaStr);
        pessoas.push_back(Pessoa(nome, dataNascimento, peso, altura));
    }

    // Print each element in the vector
    for (const auto& pessoa : pessoas) {
        std::cout << "Nome: " << pessoa.nome << ", Data de Nascimento: " << pessoa.dataNascimento << ", Peso: " << pessoa.peso << ", Altura: " << pessoa.altura << std::endl;
    }


    std::vector<double> tempos;
    clock_t start, end;

    double tempo;
    
    start = clock();
    bubbleSort(pessoas);
    end = clock();
    tempo = ((double) end - start) / CLOCKS_PER_SEC; 
    tempos.push_back(tempo); 
    std::cout << "Bubble Sort: " << tempo << " Segundos" << std::endl;

    start = clock();
    insertionSort(pessoas);
    end = clock();
    tempo = ((double) end - start) / CLOCKS_PER_SEC;
    tempos.push_back(tempo); 
    std::cout << "Insertion Sort: " << tempo << " Segundos" << std::endl;

    start = clock();
    selectionSort(pessoas);
    end = clock();
    tempo = ((double) end - start) / CLOCKS_PER_SEC;
    tempos.push_back(tempo);
    std::cout << "Selection Sort: " << tempo << " Segundos" << std::endl;

    start = clock();
    mergeSort(pessoas, 0, pessoas.size() - 1);
    end = clock();
    tempo = ((double) end - start) / CLOCKS_PER_SEC;
    tempos.push_back(tempo);
    std::cout << "Merge Sort: " << tempo << " Segundos" << std::endl;

    start = clock();
    quickSort(pessoas, 0, pessoas.size() - 1);
    end = clock();
    tempo = ((double) end - start) / CLOCKS_PER_SEC;
    tempos.push_back(tempo);
    std::cout << "Quick Sort: " << tempo << " Segundos" << std::endl;


    // Cálculo da média
    double media = std::accumulate(tempos.begin(), tempos.end(), 0.0) / tempos.size();

    // Cálculo da mediana
    std::vector<double> tempos_copia = tempos; // Crie uma cópia dos tempos para não modificar o vetor original
    size_t n = tempos_copia.size() / 2;
    std::nth_element(tempos_copia.begin(), tempos_copia.begin()+n, tempos_copia.end());
    double mediana = tempos_copia[n];

    // Cálculo do desvio padrão
    double sq_sum = std::inner_product(tempos.begin(), tempos.end(), tempos.begin(), 0.0);
    double stdev = std::sqrt(sq_sum / tempos.size() - media * media);

    std::cout << "Média: " << media << "\n";
    std::cout << "Mediana: " << mediana << "\n";
    std::cout << "Desvio padrão: " << stdev << "\n";

    return 0;

}