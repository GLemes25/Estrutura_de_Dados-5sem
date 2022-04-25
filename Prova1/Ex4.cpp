// 4- (3,5) Construa uma função que recebe como parâmetros uma Lista L1 e um valor inteiro x e que insira o valor x da lista L1.
// A inserção deve ser realizada de maneira que a lista permaneça ordenada em ordem crescente. Use as funções de inserção,
// remoção e impressão já implementadas.

#include <iostream>
#include <locale.h>
using namespace std;

struct address
{
    int key;
    struct address *next;
    struct address *previous;
};
typedef struct address nodeType;
typedef struct
{
    nodeType *start;
    nodeType *end;
    int size;
} listType;

void getch(void)
{
    cout << endl;
    system("read -p \"Pressione enter para continuar\" continuando");
    cout << endl;
}

void initList(listType *list)
{
    list->start = NULL;
    list->end = NULL;
    list->size = 0;
}
void insert(listType *list, int value)
{
    nodeType *newList = (nodeType *)malloc(sizeof(nodeType));

    if (list->start == NULL)
    {
        cout << "Iniciando Lista" << endl;
        list->start = newList;
        list->end = newList;
        newList->next = NULL;
        newList->previous = NULL;
        list->size++;
        newList->key = value;
    }
    else
    {
     
        
        newList->next = NULL;
        newList->previous = list->end;
        newList->previous->next = newList;
        list->end = newList;
        list->size = list->size + 1;
        newList->key = value;
    }
}
void showList(listType *list)
{
    nodeType *current;
    current = list->start;
    cout << "Tamanho da lista: " << list->size << endl;
    cout << "Lista: ";
    while (current != NULL)
    {
        cout << current->key << " ";
        current = current->next;
    }
    cout << endl;
    getch();
}

void removeItem(listType *list, int value)
{
    if (list->start == NULL)
    {
        cout << "Lista está Vazia" << endl;
        getch();
    }
    else
    {
        nodeType *current, *toRemove;
        current = list->start;
        toRemove = NULL;
        while (current != NULL)
        {
            if (current->key == value)
            {
                cout << "Removendo " << current->key << " ..." << endl;
                getch();
                toRemove = current;
                break;
            }
            current = current->next;
        }
        if (toRemove == NULL)
        {
            cout << "Valor nao encontrado!" << endl;
            getch();
        }
        else
        {
            if (list->size == 1)
            {
                initList(list);
            }
            else
            {
                if (toRemove->previous == NULL && toRemove->next != NULL)
                {
                    list->start = toRemove->next;
                    toRemove->next->previous = NULL;
                }
                else if (toRemove->next == NULL && toRemove->previous != NULL)
                {
                    toRemove->previous->next = NULL;
                    list->end = toRemove->previous;
                }
                else
                {
                    toRemove->previous->next = toRemove->next;
                    toRemove->next->previous = toRemove->previous;
                }
                    free(toRemove);
                    list->size --;
            }
        }
    }
}

int main()
{
    listType list;
    initList(&list);

    int option = 0;
    while (option != 4)
    {
        int value;
        cout << "1-Inserir valor" << endl;
        cout << "2-Remover item" << endl;
        cout << "3-Mostrar Lista" << endl;
        cout << "4-Sair" << endl;
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Chave: ";
            cin >> value;
            insert(&list, value);
            break;
        case 2:
            cout << "Chave: ";
            cin >> value;
            removeItem(&list, value);
            break;
        case 3:
            showList(&list);
            break;
        case 4:
            cout << "Saindo...!" << endl;
            break;
        default:
            cout << "Opção Inválida" << endl;
            break;
        }
    }

    return 0;
}