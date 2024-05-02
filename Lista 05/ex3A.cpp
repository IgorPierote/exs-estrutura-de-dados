#include <iostream>
#include <stack>
#include <sstream>
#include <map>
#include <cctype>
#include <vector>

// Função para verificar se um caractere é um operador
bool isOperator(char c) {
    return std::string("+-*/^").find(c) != std::string::npos;
}

// Função para verificar a precedência dos operadores
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Função para converter infixo para pós-fixo
std::string infixToPostfix(const std::string& infix) {
    std::stack<char> stack;
    std::string output;

    for (char c : infix) {
        if (std::isdigit(c) || c == '.') {
            output += c;
        } else if (c == '(') {
            stack.push(c);
        } else if (c == ')') {
            while (!stack.empty() && stack.top() != '(') {
                output += ' ';
                output += stack.top();
                stack.pop();
            }
            stack.pop(); // Remove '('
        } else if (isOperator(c)) {
            output += ' ';
            while (!stack.empty() && precedence(c) <= precedence(stack.top())) {
                output += stack.top();
                output += ' ';
                stack.pop();
            }
            stack.push(c);
        }
    }

    while (!stack.empty()) {
        output += ' ';
        output += stack.top();
        stack.pop();
    }

    return output;
}

// Função principal para demonstração
int main() {
    std::string infix = "3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3";
    std::string postfix = infixToPostfix(infix);
    std::cout << "Infix: " << infix << std::endl;
    std::cout << "Postfix: " << postfix << std::endl;

    return 0;
}