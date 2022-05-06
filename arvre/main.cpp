#include <iostream>
#include <stdio.h>

using namespace std;

typedef struct tree
{
    struct tree *left;
    struct tree *right;
    int info;
} NodeType;

typedef NodeType *PointerType;

PointerType init()
{
    PointerType treeRoot; // raiz da arvore
    treeRoot = init();
}

int main()
{
    int option;
    bool initiate = false;

    return 0;
}
