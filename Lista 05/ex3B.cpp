#include <iostream>

class Node {
public:
    int value;
    Node* next;

    Node(int val) : value(val), next(nullptr) {}
};

bool hasCycle(Node* head) {
    Node *slow = head, *fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true; // Ciclo detectado
        }
    }

    return false; // Sem ciclo
}

// Função principal para demonstração
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = head; // Cria um ciclo para teste

    if (hasCycle(head)) {
        std::cout << "Ciclo detectado." << std::endl;
    } else {
        std::cout << "Sem ciclo." << std::endl;
    }


    return 0;
}