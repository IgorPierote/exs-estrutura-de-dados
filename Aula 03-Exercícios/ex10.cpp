#include <iostream>
#include <vector>
#include <string>

struct Evento {
    std::string titulo;
    std::string data; // no formato AAAA-MM-DD
    std::string horario; // no formato HH:MM
};

void insertionSort(std::vector<Evento>& eventos) {
    int i, j;
    Evento chave;
    for (i = 1; i < eventos.size(); i++) {
        chave = eventos[i];
        j = i - 1;

        while (j >= 0 && (eventos[j].data > chave.data || (eventos[j].data == chave.data && eventos[j].horario > chave.horario))) {
            eventos[j + 1] = eventos[j];
            j = j - 1;
        }
        eventos[j + 1] = chave;
    }
}

int main() {
    std::vector<Evento> eventos = {
        {"The town", "2022-01-01", "09:00"},
        {"Lolapaloza", "2022-01-01", "10:00"},
        {"Rockin rio", "2022-01-02", "09:00"},
        {"tomorrow land", "2022-01-01", "08:00"},
        {"sla 5", "2022-01-02", "10:00"}
    };

    std::cout << "Antes da ordenação:\n";
    for (const auto& evento : eventos) {
        std::cout << "Titulo: " << evento.titulo << ", Data: " << evento.data << ", Horário: " << evento.horario << std::endl;
    }

    insertionSort(eventos);

    std::cout << "\nDepois da ordenação:\n";
    for (const auto& evento : eventos) {
        std::cout << "Titulo: " << evento.titulo << ", Data: " << evento.data << ", Horário: " << evento.horario << std::endl;
    }

    return 0;
}