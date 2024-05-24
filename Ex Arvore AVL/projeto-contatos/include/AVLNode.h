#ifndef AVLNODE_H
#define AVLNODE_H

#include "Contato.h"

class AVLNode {
public:
    Contato* contato;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(Contato* c)
        : contato(c), left(nullptr), right(nullptr), height(1) {}
};

#endif // AVLNODE_H