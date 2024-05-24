#ifndef CONTATO_H
#define CONTATO_H

#include <string>

class Contato {
public:
    std::string nome;
    std::string telefone;
    std::string email;
    bool favorito;

    Contato(std::string n, std::string t, std::string e, bool f = false)
        : nome(n), telefone(t), email(e), favorito(f) {}
};

#endif // CONTATO_H