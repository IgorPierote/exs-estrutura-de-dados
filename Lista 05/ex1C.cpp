#include <stack>
#include <iostream>
#include <cassert>

template<typename T>
class MinStack {
private:
    std::stack<T> stack;
    std::stack<T> minStack;

public:
    void push(T value) {
        stack.push(value);
        if (minStack.empty() || value <= minStack.top()) {
            minStack.push(value);
        }
    }

    void pop() {
        assert(!stack.empty());
        if (stack.top() == minStack.top()) {
            minStack.pop();
        }
        stack.pop();
    }

    T top() {
        assert(!stack.empty());
        return stack.top();
    }

    T min() {
        assert(!minStack.empty());
        return minStack.top();
    }
};

int main() {
    MinStack<int> stack;
    stack.push(3);
    std::cout << "Top: " << stack.top() << std::endl; // Deve exibir: 3
    stack.push(2);
    std::cout << "Top: " << stack.top() << std::endl; // Deve exibir: 2
    stack.push(1);
    std::cout << "Top: " << stack.top() << std::endl; // Deve exibir: 1
    std::cout << "Min: " << stack.min() << std::endl; // Deve exibir: 1

    stack.pop();
    std::cout << "Top: " << stack.top() << std::endl; // Deve exibir: 2
    std::cout << "Min: " << stack.min() << std::endl; // Deve exibir: 2

    stack.push(0);
    std::cout << "Top: " << stack.top() << std::endl; // Deve exibir: 0
    std::cout << "Min: " << stack.min() << std::endl; // Deve exibir: 0

    return 0;
}