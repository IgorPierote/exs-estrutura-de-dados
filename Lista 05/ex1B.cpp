#include <stack>
#include <iostream>

template<typename T>
class Fila {
private:
    std::stack<T> pilha1, pilha2;

    void transferir(std::stack<T>& origem, std::stack<T>& destino) {
        while (!origem.empty()) {
            destino.push(origem.top());
            origem.pop();
        }
    }

public:
    void enfileirar(T valor) {
        pilha1.push(valor);
    }

    T desenfileirar() {
        if (pilha2.empty()) {
            transferir(pilha1, pilha2);
        }
        T valor = pilha2.top();
        pilha2.pop();
        return valor;
    }

    T frente() {
        if (pilha2.empty()) {
            transferir(pilha1, pilha2);
        }
        return pilha2.top();
    }
};

int main() {
    Fila<int> fila;
    fila.enfileirar(1);
    fila.enfileirar(2);
    fila.enfileirar(3);

    std::cout << fila.desenfileirar() << std::endl; // Deve exibir: 1
    std::cout << fila.frente() << std::endl; // Deve exibir: 2
    fila.enfileirar(4);
    std::cout << fila.desenfileirar() << std::endl; // Deve exibir: 2
    std::cout << fila.desenfileirar() << std::endl; // Deve exibir: 3

    return 0;
}