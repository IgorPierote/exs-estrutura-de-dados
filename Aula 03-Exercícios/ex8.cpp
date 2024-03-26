#include <iostream>
#include <vector>
#include <string>

struct Jogador {
    std::string nome;
    int pontuacao;
};

void selectionSort(std::vector<Jogador>& jogadores) {
    int i, j, max_idx;
    Jogador temp;
    for (i = 0; i < jogadores.size() - 1; i++) {
        // Encontra o jogador com a maior pontuação
        max_idx = i;
        for (j = i + 1; j < jogadores.size(); j++)
            if (jogadores[j].pontuacao > jogadores[max_idx].pontuacao)
                max_idx = j;

        // Troca o jogador encontrado com o primeiro jogador
        temp = jogadores[max_idx];
        jogadores[max_idx] = jogadores[i];
        jogadores[i] = temp;
    }
}

int main() {
    std::vector<Jogador> jogadores = {
        {"Jogador1", 100},
        {"Jogador2", 200},
        {"Jogador3", 150},
        {"Jogador4", 180},
        {"Jogador5", 170}
    };

    std::cout << "Antes da ordenação:\n";
    for (const auto& jogador : jogadores) {
        std::cout << "Nome: " << jogador.nome << ", Pontuação: " << jogador.pontuacao << std::endl;
    }

    selectionSort(jogadores);

    std::cout << "\nDepois da ordenação:\n";
    for (const auto& jogador : jogadores) {
        std::cout << "Nome: " << jogador.nome << ", Pontuação: " << jogador.pontuacao << std::endl;
    }

    return 0;
}