#include <iostream>

template<typename T>
class No {
public:
    T valor;
    No* proximo;
    No* anterior;
    No(T valor) : valor(valor), proximo(nullptr), anterior(nullptr) {}
};

template<typename T>
class ListaDuplamenteLigada {
private:
    No<T>* cabeca;
    No<T>* cauda;
public:
    ListaDuplamenteLigada() : cabeca(nullptr), cauda(nullptr) {}

    void inserir(T valor) {
        No<T>* novoNo = new No<T>(valor);
        if (cabeca == nullptr) {
            cabeca = cauda = novoNo;
        } else {
            cauda->proximo = novoNo;
            novoNo->anterior = cauda;
            cauda = novoNo;
        }
    }

    bool remover(T valor) {
        No<T>* temp = cabeca;
        while (temp != nullptr) {
            if (temp->valor == valor) {
                if (temp->anterior) temp->anterior->proximo = temp->proximo;
                if (temp->proximo) temp->proximo->anterior = temp->anterior;
                if (temp == cabeca) cabeca = temp->proximo;
                if (temp == cauda) cauda = temp->anterior;
                delete temp;
                return true;
            }
            temp = temp->proximo;
        }
        return false;
    }

    No<T>* buscar(T valor) {
        No<T>* temp = cabeca;
        while (temp != nullptr) {
            if (temp->valor == valor) return temp;
            temp = temp->proximo;
        }
        return nullptr;
    }

    void reverter() {
        No<T>* temp = nullptr;
        No<T>* atual = cabeca;
        cauda = cabeca;
        while (atual != nullptr) {
            temp = atual->anterior;
            atual->anterior = atual->proximo;
            atual->proximo = temp;
            atual = atual->anterior;
        }
        if (temp != nullptr) cabeca = temp->anterior;
    }

    void exibir() {
        No<T>* temp = cabeca;
        while (temp != nullptr) {
            std::cout << temp->valor << " ";
            temp = temp->proximo;
        }
        std::cout << std::endl;
    }
};

int main() {
    ListaDuplamenteLigada<int> lista;
    lista.inserir(1);
    lista.inserir(2);
    lista.inserir(3);
    lista.exibir(); // Deve exibir: 1 2 3

    lista.remover(2);
    lista.exibir(); // Deve exibir: 1 3

    lista.reverter();
    lista.exibir(); // Deve exibir: 3 1

    if (lista.buscar(3)) {
        std::cout << "3 encontrado\n";
    } else {
        std::cout << "3 não encontrado\n";
    }

    return 0;
}