#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <list>
#include <string>
#include <sstream>
#include <map>

// a. Validação de expressões com parênteses
bool validaExpressao(const std::string& expressao) {
    std::stack<char> pilha;
    std::map<char, char> pares = {{')', '('}, {']', '['}, {'}', '{'}};

    for (char c : expressao) {
        if (c == '(' || c == '[' || c == '{') {
            pilha.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (pilha.empty() || pilha.top() != pares[c]) {
                return false;
            }
            pilha.pop();
        }
    }
    return pilha.empty();
}

// b. Notação Polonesa Reversa (NPR)
float avaliaNPR(const std::string& expressao) {
    std::stack<float> pilha;
    std::stringstream ss(expressao);
    std::string token;
    while (ss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            float segundo = pilha.top(); pilha.pop();
            float primeiro = pilha.top(); pilha.pop();
            if (token == "+") pilha.push(primeiro + segundo);
            else if (token == "-") pilha.push(primeiro - segundo);
            else if (token == "*") pilha.push(primeiro * segundo);
            else if (token == "/") pilha.push(primeiro / segundo);
        } else {
            pilha.push(std::stof(token));
        }
    }
    return pilha.top();
}

// c. Simulação de fila de impressão
struct Trabalho {
    int id;
    int prioridade;
};

bool operator<(const Trabalho& a, const Trabalho& b) {
    return a.prioridade < b.prioridade; // Maior prioridade vem primeiro
}

void simulaFilaImpressao() {
    std::priority_queue<Trabalho> fila;
    std::list<Trabalho> concluidos;
    
    // Adicionando trabalhos na fila de impressão
    fila.push(Trabalho{1, 5});
    fila.push(Trabalho{2, 2});
    fila.push(Trabalho{3, 3});

    // Processando a fila de impressão
    while (!fila.empty()) {
        Trabalho atual = fila.top();
        fila.pop();
        std::cout << "Imprimindo trabalho ID: " << atual.id << " com prioridade: " << atual.prioridade << std::endl;
        concluidos.push_back(atual);
    }
}

// Testes
int main() {
    // Teste para validação de expressões
    std::cout << "Validação de Expressões:" << std::endl;
    std::cout << "{[()]}: " << (validaExpressao("{[()]}") ? "Válido" : "Inválido") << std::endl;
    std::cout << "{[(])}: " << (validaExpressao("{[(])}") ? "Válido" : "Inválido") << std::endl;
    std::cout << "--------------------------------" << std::endl;

    // Teste para NPR
    std::cout << "Notação Polonesa Reversa:" << std::endl;
    std::cout << "3 4 + 2 * 7 /: " << avaliaNPR("3 4 + 2 * 7 /") << std::endl;
    std::cout << "5 1 2 + 4 * + 3 -: " << avaliaNPR("5 1 2 + 4 * + 3 -") << std::endl;
    std::cout << "--------------------------------" << std::endl;

    // Teste para simulação de fila de impressão
    std::cout << "Simulação de Fila de Impressão:" << std::endl;
    simulaFilaImpressao();
    std::cout << "--------------------------------" << std::endl;

    return 0;
}