#include <iostream>
#include <vector>
#include <queue>

// Definição da classe Tarefa
class Tarefa {
public:
    int id;
    int cargaDeTrabalho; // Representa a carga de trabalho, por exemplo, tempo necessário para completar a tarefa

    Tarefa(int id, int cargaDeTrabalho) : id(id), cargaDeTrabalho(cargaDeTrabalho) {}
};

// Definição da classe Servidor
class Servidor {
public:
    int id;
    std::queue<Tarefa> tarefas;

    Servidor(int id) : id(id) {}

    void adicionarTarefa(const Tarefa& tarefa) {
        tarefas.push(tarefa);
    }

    bool estaLivre() {
        return tarefas.empty();
    }
};

// Definição da classe BalanceadorDeCarga
class BalanceadorDeCarga {
private:
    std::vector<Servidor> servidores;

public:
    BalanceadorDeCarga(int numeroDeServidores) {
        for (int i = 0; i < numeroDeServidores; ++i) {
            servidores.push_back(Servidor(i));
        }
    }

    void distribuirTarefa(const Tarefa& tarefa) {
        // Encontra o servidor com menos tarefas
        int indiceMenosTarefas = 0;
        for (int i = 1; i < servidores.size(); ++i) {
            if (servidores[i].tarefas.size() < servidores[indiceMenosTarefas].tarefas.size()) {
                indiceMenosTarefas = i;
            }
        }

        // Adiciona a tarefa ao servidor selecionado
        servidores[indiceMenosTarefas].adicionarTarefa(tarefa);
        std::cout << "Tarefa " << tarefa.id << " com carga de trabalho " << tarefa.cargaDeTrabalho
                  << " atribuída ao Servidor " << servidores[indiceMenosTarefas].id << std::endl;
    }

    // Função para simular o processamento das tarefas
    void processarTarefas() {
        for (auto& servidor : servidores) {
            while (!servidor.tarefas.empty()) {
                Tarefa tarefa = servidor.tarefas.front();
                servidor.tarefas.pop();
                std::cout << "Servidor " << servidor.id << " processando tarefa " << tarefa.id << std::endl;
                // Aqui poderia ser implementada uma simulação de tempo de processamento baseada em cargaDeTrabalho
            }
        }
    }
};

// Função principal para demonstrar o uso do BalanceadorDeCarga
int main() {
    BalanceadorDeCarga balanceador(3); // Cria um balanceador de carga com 3 servidores

    // Adiciona tarefas
    balanceador.distribuirTarefa(Tarefa(1, 5));
    balanceador.distribuirTarefa(Tarefa(2, 3));
    balanceador.distribuirTarefa(Tarefa(3, 4));
    balanceador.distribuirTarefa(Tarefa(4, 2));
    balanceador.distribuirTarefa(Tarefa(5, 1));

    // Simula o processamento das tarefas
    balanceador.processarTarefas();

    return 0;
}