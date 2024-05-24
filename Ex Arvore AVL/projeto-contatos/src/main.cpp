#include <iostream>
#include "../include/AVLTree.h"

void menu() {
    AVLTree tree;
    int opcao;

    do {
        std::cout << "***********************************************\n";
        std::cout << "1. Adicionar Contato\n";
        std::cout << "2. Remover Contato\n";
        std::cout << "3. Buscar Contato\n";
        std::cout << "4. Listar Contatos\n";
        std::cout << "5. Listar Favoritos\n";
        std::cout << "6. Exportar Contatos para CSV\n";
        std::cout << "7. Importar Contatos de CSV\n";
        std::cout << "8. Sair\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;

        std::string nome, telefone, email, filename;
        bool favorito;

        switch (opcao) {
            case 1:
                std::cout << "Nome: ";
                std::cin >> nome;
                std::cout << "Telefone: ";
                std::cin >> telefone;
                std::cout << "Email: ";
                std::cin >> email;
                std::cout << "Favorito (1 para sim, 0 para não): ";
                std::cin >> favorito;
                tree.adicionarContato(nome, telefone, email, favorito);
                break;
            case 2:
                std::cout << "Nome do contato a ser removido: ";
                std::cin >> nome;
                tree.removerContato(nome);
                break;
            case 3:
                std::cout << "Nome do contato a ser buscado: ";
                std::cin >> nome;
                tree.buscarContato(nome);
                break;
            case 4:
                tree.listarContatos();
                break;
            case 5:
                tree.listarFavoritos();
                break;
            case 6:
                std::cout << "Nome do arquivo para exportação (sem extensão .csv): ";
                std::cin >> filename;
                tree.exportarContatosCSV(filename);
                break;
            case 7:
                std::cout << "Nome do arquivo para importação (sem extensão .csv): ";
                std::cin >> filename;
                tree.importarContatosCSV(filename);
                break;
            case 8:
                std::cout << "Saindo...\n";
                break;
            default:
                std::cout << "Opção inválida!\n";
                break;
        }
    } while (opcao != 8);
}

int main() {
    menu();
    return 0;
}