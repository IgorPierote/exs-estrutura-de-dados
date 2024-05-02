#include <iostream>

class Node {
public:
    char data;
    Node* prev;
    Node* next;

    Node(char data) : data(data), prev(nullptr), next(nullptr) {}
};

class TextEditor {
private:
    Node* head;
    Node* tail;
    Node* cursor; // O cursor agora aponta para o nó onde a próxima inserção/deleção ocorrerá à direita

public:
    TextEditor() : head(nullptr), tail(nullptr), cursor(nullptr) {}

    ~TextEditor() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insertCharacter(char data) {
        Node* newNode = new Node(data);
        if (head == nullptr) { // Lista vazia
            head = tail = newNode;
        } else if (cursor == nullptr) { // Inserção no início
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        } else { // Inserção após o cursor
            newNode->next = cursor->next;
            newNode->prev = cursor;
            if (cursor->next != nullptr) {
                cursor->next->prev = newNode;
            } else {
                tail = newNode;
            }
            cursor->next = newNode;
        }
        cursor = newNode; // O cursor sempre move para o novo nó inserido
    }

    void deleteCharacter() {
        if (cursor == nullptr) return; // Nada para deletar se o cursor estiver no início
        Node* toDelete = cursor->next;
        if (toDelete == nullptr) return; // Nada para deletar se não houver nada após o cursor

        if (toDelete->next != nullptr) {
            toDelete->next->prev = cursor;
        } else {
            tail = cursor; // Se estiver deletando o último nó
        }
        cursor->next = toDelete->next;

        delete toDelete;
    }

    void moveCursorLeft() {
        if (cursor != nullptr) {
            cursor = cursor->prev;
        }
    }

    void moveCursorRight() {
        if (cursor != nullptr && cursor->next != nullptr) {
            cursor = cursor->next;
        }
    }

    void moveCursorToStart() {
        cursor = nullptr; // Move o cursor para o início do texto
    }

    void displayText() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data;
            temp = temp->next;
        }
        std::cout << "\n";
    }
};

int main() {
    // Primeiro Teste: Inserindo "Hello World" e removendo " World"
    {
        TextEditor editor;
        std::string input = "Hello World";
        for (char c : input) {
            editor.insertCharacter(c);
        }
        editor.displayText(); // Deve mostrar "Hello World"

        // Posicionando o cursor corretamente para começar a deletar " World"
        for (int i = 0; i < 6; ++i) {
            editor.moveCursorLeft();
        }

        // Deletando " World"
        for (int i = 0; i < 6; ++i) {
            editor.deleteCharacter();
        }
        editor.displayText(); // Deve mostrar "Hello"
    }

    {
        TextEditor editor; // Cria uma nova instância do editor para o segundo teste
        std::string input = "Data";
        for (char c : input) {
            editor.insertCharacter(c);
        }
        editor.moveCursorToStart(); // Move o cursor para o início
        input = "Test ";
        for (char c : input) {
            editor.insertCharacter(c);
        }
        editor.displayText(); // Deve mostrar "Test Data"
    }

    return 0;
}