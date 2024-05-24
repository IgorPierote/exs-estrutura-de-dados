#ifndef AVLTREE_H
#define AVLTREE_H

#include "AVLNode.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>

class AVLTree {
private:
    AVLNode* root;

    int height(AVLNode* node) {
        return node ? node->height : 0;
    }

    int getBalance(AVLNode* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    AVLNode* rightRotate(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = std::max(height(y->left), height(y->right)) + 1;
        x->height = std::max(height(x->left), height(x->right)) + 1;

        return x;
    }

    AVLNode* leftRotate(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = std::max(height(x->left), height(x->right)) + 1;
        y->height = std::max(height(y->left), height(y->right)) + 1;

        return y;
    }

    AVLNode* insert(AVLNode* node, Contato* contato) {
        if (!node)
            return new AVLNode(contato);

        if (contato->nome < node->contato->nome)
            node->left = insert(node->left, contato);
        else if (contato->nome > node->contato->nome)
            node->right = insert(node->right, contato);
        else
            return node;

        node->height = 1 + std::max(height(node->left), height(node->right));

        int balance = getBalance(node);

        if (balance > 1 && contato->nome < node->left->contato->nome)
            return rightRotate(node);

        if (balance < -1 && contato->nome > node->right->contato->nome)
            return leftRotate(node);

        if (balance > 1 && contato->nome > node->left->contato->nome) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && contato->nome < node->right->contato->nome) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    AVLNode* minValueNode(AVLNode* node) {
        AVLNode* current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    AVLNode* deleteNode(AVLNode* root, std::string nome) {
        if (!root)
            return root;

        if (nome < root->contato->nome)
            root->left = deleteNode(root->left, nome);
        else if (nome > root->contato->nome)
            root->right = deleteNode(root->right, nome);
        else {
            if (!root->left || !root->right) {
                AVLNode* temp = root->left ? root->left : root->right;

                if (!temp) {
                    temp = root;
                    root = nullptr;
                } else
                    *root = *temp;

                delete temp;
            } else {
                AVLNode* temp = minValueNode(root->right);
                root->contato = temp->contato;
                root->right = deleteNode(root->right, temp->contato->nome);
            }
        }

        if (!root)
            return root;

        root->height = 1 + std::max(height(root->left), height(root->right));

        int balance = getBalance(root);

        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);

        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);

        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    AVLNode* search(AVLNode* root, std::string nome) {
        if (!root || root->contato->nome == nome)
            return root;

        if (root->contato->nome < nome)
            return search(root->right, nome);

        return search(root->left, nome);
    }

    void listarContatos(AVLNode* root) {
        if (root) {
            listarContatos(root->left);
            std::cout << root->contato->nome << ", " << root->contato->telefone << ", "
                      << root->contato->email << std::endl;
            listarContatos(root->right);
        }
    }

    void listarFavoritos(AVLNode* root) {
        if (root) {
            listarFavoritos(root->left);
            if (root->contato->favorito) {
                std::cout << root->contato->nome << ", " << root->contato->telefone << ", "
                          << root->contato->email << std::endl;
            }
            listarFavoritos(root->right);
        }
    }

    void exportarContatosCSV(AVLNode* root, std::ofstream& file) {
        if (root) {
            exportarContatosCSV(root->left, file);
            file << root->contato->nome << "," << root->contato->telefone << "," << root->contato->email << "," << root->contato->favorito << "\n";
            exportarContatosCSV(root->right, file);
        }
    }

    void importarContatosCSV(std::ifstream& file) {
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string nome, telefone, email, favoritoStr;
            bool favorito;

            std::getline(ss, nome, ',');
            std::getline(ss, telefone, ',');
            std::getline(ss, email, ',');
            std::getline(ss, favoritoStr, ',');
            favorito = favoritoStr == "1";

            Contato* novoContato = new Contato(nome, telefone, email, favorito);
            root = insert(root, novoContato);
        }
    }

public:
    AVLTree() : root(nullptr) {}

    void adicionarContato(std::string nome, std::string telefone, std::string email, bool favorito = false) {
        Contato* novoContato = new Contato(nome, telefone, email, favorito);
        root = insert(root, novoContato);
    }

    void removerContato(std::string nome) {
        root = deleteNode(root, nome);
    }

    void buscarContato(std::string nome) {
        AVLNode* resultado = search(root, nome);
        if (resultado) {
            std::cout << "Contato encontrado: " << resultado->contato->nome << ", "
                      << resultado->contato->telefone << ", " << resultado->contato->email << std::endl;
        } else {
            std::cout << "Contato não encontrado." << std::endl;
        }
    }

    void listarContatos() {
        listarContatos(root);
    }

    void listarFavoritos() {
        listarFavoritos(root);
    }

    void exportarContatosCSV(const std::string& filename) {
        std::string fullFilename = filename;
        if (fullFilename.find(".csv") == std::string::npos) {
            fullFilename += ".csv";
        }
        std::ofstream file(fullFilename);
        if (file.is_open()) {
            exportarContatosCSV(root, file);
            file.close();
            std::cout << "***********************************************\n";
            std::cout << "Contatos exportados para " << fullFilename << " com sucesso." << std::endl;
        } else {
            std::cerr << "Erro ao abrir o arquivo " << fullFilename << " para exportação." << std::endl;
        }
    }

    void importarContatosCSV(const std::string& filename) {
        std::string fullFilename = filename;
        if (fullFilename.find(".csv") == std::string::npos) {
            fullFilename += ".csv";
        }
        std::ifstream file(fullFilename);
        if (file.is_open()) {
            importarContatosCSV(file);
            file.close();
            std::cout << "***********************************************\n";
            std::cout << "Contatos importados de " << fullFilename << " com sucesso." << std::endl;
        } else {
            std::cerr << "Erro ao abrir o arquivo " << fullFilename << " para importação." << std::endl;
        }
    }
};

#endif // AVLTREE_H