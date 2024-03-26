#include <iostream>
#include <vector>
#include <string>

struct Musica {
    std::string titulo;
    std::string categoria;
};

// Função para ordenar a playlist usando Insertion Sort
void insertionSort(std::vector<Musica>& playlist) {
    int i, j;
    Musica chave;
    // Percorre todos os elementos do vetor
    for (i = 1; i < playlist.size(); i++) {
        // Seleciona o elemento atual
        chave = playlist[i];
        j = i - 1;

        // Move os elementos do vetor[0..i-1], que são maiores que a chave, para uma posição à frente
        // da sua posição atual
        while (j >= 0 && playlist[j].categoria > chave.categoria) {
            playlist[j + 1] = playlist[j];
            j = j - 1;
        }
        // Insere a chave na posição correta no vetor ordenado
        playlist[j + 1] = chave;
    }
}

int main() {
    std::vector<Musica> playlist = {
        {"Musica1", "Rock"},
        {"Musica2", "Pop"},
        {"Musica3", "Jazz"},
        {"Musica4", "Classica"},
        {"Musica5", "Rock"}
    };

    std::cout << "Antes da ordenação:\n";
    for (const auto& musica : playlist) {
        std::cout << "Titulo: " << musica.titulo << ", Categoria: " << musica.categoria << std::endl;
    }

    insertionSort(playlist);

    std::cout << "\nDepois da ordenação:\n";
    for (const auto& musica : playlist) {
        std::cout << "Titulo: " << musica.titulo << ", Categoria: " << musica.categoria << std::endl;
    }

    return 0;
}