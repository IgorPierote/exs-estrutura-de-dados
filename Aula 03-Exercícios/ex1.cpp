#include <string>
#include <vector>
#include <iostream>

struct Event {
    std::string datetime; 
};

// Função para comparar duas datas 
bool compareDatetime(const std::string& a, const std::string& b) {
    return a < b;
}

// Função de ordenação Insertion Sort
void sortEvents(std::vector<Event>& events) {
    for (int i = 1; i < events.size(); i++) {
        Event key = events[i];
        int j = i - 1;

        // Move os elementos do vetor, que são maiores que a chave, para uma posição à frente de sua posição atual
        while (j >= 0 && compareDatetime(events[j].datetime, key.datetime)) {
            events[j + 1] = events[j];
            j = j - 1;
        }
        events[j + 1] = key;
    }
}

int main() {
    std::vector<Event> events = {
        {"2022-02-01 10:00:00"},
        {"2022-01-02 12:00:00"},
        {"2022-03-01 09:00:00"}
    };

    sortEvents(events);

    for (const auto& event : events) {
        std::cout << event.datetime << std::endl;
    }

    return 0;
}