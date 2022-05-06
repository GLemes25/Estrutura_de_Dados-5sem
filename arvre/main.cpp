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

// inicialização da abb
PointerType init()
{
    return NULL;
}

// Inserir um no
PointerType insert(PointerType node, int key)
{
    // SE: A raiz é NULL instala o nó na raiz da arvore
    // SENAO:
    //    SE: A chave a ser inserida for menor que a raiz
    //        Insere na subarvore da esquerda
    //    SENAO:
    //        Insere na subarvore da direita

    if (node == NULL)
    {
        node = (PointerType)malloc(sizeof(PointerType));
        node->info = key;
        node->left = NULL;
        node->right = NULL;
    }
    else if (key < node->info)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->info)
    {
        node->right = insert(node->right, key);
    }
    else
    {
        cout << "Chave Invalida! \n\n";
    }

    return node;
}

PointerType find(PointerType node, int key)
{
    while (node != NULL)
    {
        if (node->info == key)
        {
            return node;
        }
        else if (node->info > key)
        {
            node = node->left;
        }
        else
        {
            node->right;
        }
    }
    return NULL;    //Não encontrou 
}

void show(PointerType node)
{

    cout << "\t" << node->info << "\n";
    cout << node->left->info;
    node->right ? cout << "\t\t" << (node->right->info) << "\n" : cout << "\t\t"
                                                                       << "NULL"
                                                                       << "\n";
}

int main()
{
    PointerType treeRoot; // raiz da arvore
    treeRoot = init();
    treeRoot = insert(treeRoot, 10);
    treeRoot = insert(treeRoot, 1);
    treeRoot = insert(treeRoot, 17);
    show(treeRoot);



    return 0;
}
