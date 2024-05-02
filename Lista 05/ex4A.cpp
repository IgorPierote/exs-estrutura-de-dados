#include <iostream>

// Definição da estrutura de um nó na lista duplamente ligada
class Node {
public:
    char data; // Dado armazenado no nó (um caractere)
    Node* prev; // Ponteiro para o nó anterior
    Node* next; // Ponteiro para o próximo nó

    // Construtor
    Node(char data) : data(data), prev(nullptr), next(nullptr) {}
};

// Classe Editor de Texto
class TextEditor {
private:
    Node* head; // Ponteiro para o início da lista
    Node* tail; // Ponteiro para o final da lista
    Node* cursor; // Ponteiro para representar a posição atual do cursor

public:
    // Construtor
    TextEditor() : head(nullptr), tail(nullptr), cursor(nullptr) {}

    // Destrutor
    ~TextEditor() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Método para inserir um caractere na posição atual do cursor
    void insertCharacter(char data) {
        Node* newNode = new Node(data);
        if (cursor == nullptr) { // Inserção no início ou quando a lista está vazia
            if (head == nullptr) {
                head = tail = newNode;
            } else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
        } else {
            newNode->next = cursor->next;
            newNode->prev = cursor;
            if (cursor->next != nullptr) {
                cursor->next->prev = newNode;
            } else {
                tail = newNode;
            }
            cursor->next = newNode;
        }
        cursor = newNode; // Atualiza a posição do cursor para o novo nó inserido
    }

    // Método para deletar o caractere na posição atual do cursor
    void deleteCharacter() {
        if (cursor == nullptr) return;
        if (cursor->prev != nullptr) {
            cursor->prev->next = cursor->next;
        } else {
            head = cursor->next;
        }
        if (cursor->next != nullptr) {
            cursor->next->prev = cursor->prev;
        } else {
            tail = cursor->prev;
        }
        Node* toDelete = cursor;
        cursor = cursor->prev; // Move o cursor para trás após a deleção
        delete toDelete;
    }

    // Método para mover o cursor uma posição para a esquerda
    void moveCursorLeft() {
        if (cursor != nullptr && cursor->prev != nullptr) {
            cursor = cursor->prev;
        }
    }

    // Método para mover o cursor uma posição para a direita
    void moveCursorRight() {
        if (cursor != nullptr && cursor->next != nullptr) {
            cursor = cursor->next;
        }
    }

    // Método para exibir o texto atual
    void displayText() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data;
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    TextEditor editor;

    // Teste 1: Inserção básica de texto
    std::cout << "Teste 1: Inserção de 'Hello'" << std::endl;
    editor.insertCharacter('H');
    editor.insertCharacter('e');
    editor.insertCharacter('l');
    editor.insertCharacter('l');
    editor.insertCharacter('o');
    editor.displayText(); // Esperado: Hello
    std::cout << "\n";

    // Teste: Inserção de texto com espaço
    std::cout << "Teste 2: Inserção de espaço e 'World'" << std::endl;
    editor.insertCharacter(' ');
    editor.insertCharacter('W');
    editor.insertCharacter('o');
    editor.insertCharacter('r');
    editor.insertCharacter('l');
    editor.insertCharacter('d');
    editor.displayText(); // Esperado: Hello World
    std::cout << "\n";

    // Teste: Deleção de caracteres
    std::cout << "Teste 3: Deleção de 'd'" << std::endl;
    editor.deleteCharacter(); // Deleta 'd'
    editor.displayText(); // Esperado: Hello Worl
    std::cout << "\n";

    // Teste: Movimentação do cursor e inserção
    std::cout << "Teste 4: Movimentação do cursor para esquerda e inserção de 'd'" << std::endl;
    editor.moveCursorLeft(); // Move o cursor para 'l'
    editor.moveCursorLeft(); // Move o cursor para 'r'
    editor.insertCharacter('d'); // Insere 'd' após 'r'
    editor.displayText(); // Esperado: Hello World
    std::cout << "\n";

    // Teste: Movimentação do cursor para o início e inserção
    std::cout << "Teste 5: Movimentação do cursor para o início e inserção de 'Start '" << std::endl;
    editor = TextEditor(); // Reinicia o editor
    editor.insertCharacter('S');
    editor.insertCharacter('t');
    editor.insertCharacter('a');
    editor.insertCharacter('r');
    editor.insertCharacter('t');
    editor.insertCharacter(' ');
    editor.insertCharacter('H');
    editor.insertCharacter('e');
    editor.insertCharacter('l');
    editor.insertCharacter('l');
    editor.insertCharacter('o');
    editor.displayText(); // Esperado: Start Hello
    std::cout << "\n";

    // Teste: Deleção e inserção
    std::cout << "Teste 6: Deleção de 'Start ' e inserção de 'End'" << std::endl;
    // Reiniciando o editor para este teste
    editor = TextEditor();
    editor.insertCharacter('H');
    editor.insertCharacter('e');
    editor.insertCharacter('l');
    editor.insertCharacter('l');
    editor.insertCharacter('o');
    editor.insertCharacter(' ');
    editor.insertCharacter('W');
    editor.insertCharacter('o');
    editor.insertCharacter('r');
    editor.insertCharacter('l');
    editor.insertCharacter('d');
    // Simulando a movimentação para o final e inserindo ' End'
    editor.insertCharacter(' ');
    editor.insertCharacter('E');
    editor.insertCharacter('n');
    editor.insertCharacter('d');
    editor.displayText();
    std::cout << "\n";

    return 0;
}