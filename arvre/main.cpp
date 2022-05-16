#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

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
    cout << "---- Arvore de Busca Binaria Inicializada ----" << endl
         << endl;
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
        cout << "(Chave Invalida!) \n\n";
    }

    return node;
}

// remove um no
PointerType remove(PointerType node, int key)
{
    if (node == NULL)
    {
        cout << "Não encontrado! " << endl;
    }
    else
    {

        //  Procura pelo no
        if (node->info == key)
        {
            // encontrou o no
        }
        else
        {
            // ainda nao encontrei
            // vou caminhar pela arvre
        }
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
    return NULL; // Não encontrou
}

void show(PointerType node)
{

    if (node != NULL)
    {
        cout << node->info << " ";
        cout << "(";
        show(node->left);
        show(node->right);
        cout << ")";
    }
}

void showOrdered(PointerType node)
{

    if (node != NULL)
    {
        showOrdered(node->left);
        cout << node->info << " ";
        showOrdered(node->right);
    }
}
void menu()
{
    cout << "1-Inicializar ABB" << endl;
    cout << "2-Inserir um elemento" << endl;
    cout << "3-Imprimir ordenado" << endl;
    cout << "4-Imprimir arvore" << endl;
    cout << "5-Inserir dados do vetor" << endl;
    cout << "6-" << endl;
    cout << "7-" << endl;
    cout << "8-Sair" << endl
         << endl;
    cout << "Escolha uma opcao acima: " << endl;
}
void getch(void)
{
    cout << endl;
    system("read -p \"Pressione enter para continuar\" continuando");
    cout << endl;
}

int main()
{
    PointerType treeRoot; // raiz da arvore
    int option = 0;       // Tamanho vetor e
    int array[100];
    while (option != 8)
    {
        menu();
        cin >> option;
        switch (option)
        {
        case 1:
            treeRoot = init();
            break;
        case 2:
            cout << "Insercao de elemento dentro da ABB";

            int value;
            cout << "\nChave: ";
            cin >> value;
            treeRoot = insert(treeRoot, value);
            break;
        case 3:
            cout << "\n----Imprime ordenado----\n";
            showOrdered(treeRoot);
            cout << endl
                 << endl;
            break;
        case 4:
            cout << "\n--Imprime arvore---\n";
            show(treeRoot);
            cout << endl
                 << endl;
            break;
        case 5:
            int size;
            cout << "Insercao de Vertor na ABB" << endl;
            cout << "Digite o tamanho do vetor" << endl;
            cin >> size;
            array[size]; // vetor

            /* Inicializa Random */
            srand(time(NULL));

            cout << "Vetor: ";
            for (int i = 0; i < size; i++)
            {
                array[i] = rand() % 100 + 1;
                cout << array[i] << " ";
                treeRoot = insert(treeRoot, array[i]);
                cout << " -  ";
            }
            cout << endl
                 << endl;

            break;
        case 6:
            cout << "Remocao de elemento dentro da ABB";

            int value;
            cout << "\nChave: ";
            cin >> value;
            treeRoot = remove(treeRoot, value);
            break;

            break;
        case 7:

            break;
        case 8:
            cout << "Programa finalizado com sucesso!!" << endl;
            break;
        default:
            cout << "Opcao Invalida" << endl;
            break;
        }
        getch();
    }

    return 0;
}