// 3 - (3, 5)Escreva uma função que copie um vetor para uma lista simplesmente encadeada.
// Pense em uma solução genérica para um tamanho qualquer de vetor,
//  esta implementação será bonificada com mais um ponto na nota da prova.
// Caso não consiga crie uma solução para um vetor de 10 posições,
//  esta solução valerá no máximo a pontuação da questão.

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct address
{
    int key;
    struct address *next;
};
typedef struct address nodeType;
typedef struct
{
    nodeType *start;
    int size;
} listType;

void initList(listType *list)
{
    list->start = NULL;
    list->size = 0;
}

void insertList(listType *list, int value)
{
    nodeType *current, *newList = (nodeType *)malloc(sizeof(nodeType));
    newList->next = NULL;
    newList->key = value;
    if (list->start == NULL)
    {
        list->start = newList;
    }
    else
    {
        current = list->start;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newList;
    }
    list->size++;
}
void showList(listType *list)
{
    nodeType *current;
    current = list->start;
    cout << "Lista: ";
    while (current != NULL)
    {
        cout << current->key << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    int size;

    cout << "informe o tamanho do vetor" << endl;
    cin >> size;
    int array[size];

    /* Inicializa Random */
    srand(time(NULL));

    cout << "Vetor: ";
    for (int i = 0; i < size; i++)
    {
        /* cria numero de 1 a 100: */
        array[i] = rand() % 100 + 1;
        cout << array[i] << " ";
    }
    cout << endl;

    listType list;
    initList(&list);
    for (int i = 0; i < size; i++)
    {
        insertList(&list, array[i]);
    }
    showList(&list);
    cout << endl;

    return 0;
}