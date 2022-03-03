typedef int keyType;
#define maxObject 50

typedef struct
{
    keyType key;
} objecType;

typedef struct
{
    objecType objectList[maxObject];
    int elementNumber;
} objectListType;

#include <iostream>
#include <bits/stdc++.h>
// #include <conio.h>
// Funções para manipular a lista sequencial
void displayMenu();
objectListType orderList(objectListType *list);
bool confirm();
void initList(objectListType *list);                   // Inicialização da lista com Zero elementos
void elementsQuantity(objectListType *list);           // Retorna a qtde de elementos na lista
void printList(objectListType *list);                  // Imprime o conteúdo da lista
void insertList(objectListType *list, objecType rg);   // insere um elemento na posição desejada. // Se não for permitido retorna false.
int findIndexByKey(objectListType *list, keyType key); // busca o elemento na lista
                                                       // Se encontar retorna a posição Senão retorna -1

using namespace std;

int main()
{
    objectListType list;
    int option;
    bool doAgain = true;

    // lista.objectList[0].key = 10;
    // lista.objectList[1].key = 20;
    // lista.objectList[2].key = 30;

    do
    {
        /* code */

        displayMenu();
        cin >> option;

        switch (option)
        {
        case 1:
        {
            int firstKey;
            initList(&list);
            cout << "digite o primeiro item da lista " << endl;
            cin >> firstKey;
            list.objectList[0].key = firstKey;
            break;
        }

        case 2:
        {
            elementsQuantity(&list);
            break;
        }
        case 3:
        {
            printList(&list);
            break;
        }
        case 4:
        {
            int index;
            objecType aux;
            cout << "Digite a achave :" << endl;
            cin >> aux.key;
            insertList(&list, aux);
            list = orderList(&list);
            break;
        }
        case 5:
        {
            keyType key;
            cout << "Digite a chave :" << endl;
            cin >> key;
            findIndexByKey(&list, key);
            // orderList(&list);
            break;
        }
        default:
            cout << "Opção invalida" << endl;
        }
        doAgain = confirm();

    } while (doAgain == true);

    return 0;
}

// Fun��es//
void initList(objectListType *list)
{
    list->elementNumber = 1;
}

void elementsQuantity(objectListType *list)
{
    cout << "qtd elementos na lista: " << list->elementNumber << endl;
}

void printList(objectListType *list)
{
    int i; // manipular o indice do vetor da estrutura onde está armazenado a informação (key)
    cout << "Lista: [ ";
    for (i = 0; i < list->elementNumber; i++)
    {
        cout << list->objectList[i].key;

        i == list->elementNumber - 1 ? cout << " ] " : cout << " - ";
    }
    cout << endl;
}
void insertList(objectListType *list, objecType key)
{
    int position = list->elementNumber;
    // validação da posição informada e se a lista está cheia
    if (list->elementNumber != maxObject || position > 0)
    {
        int j; // var. para auxiliar na manipul1ação dos índice
        // Deslocando os elementos para direita
        for (j = list->elementNumber; j > position; j--)
            list->objectList[j] = list->objectList[j - 1];

        // Armazenando a key na posição desejada
        list->objectList[position] = key;
        list->elementNumber++;
    }
}
int findIndexByKey(objectListType *list, keyType key)
{
    int i = 0; // var. para auxiliar na manipulação dos índice
    while (i < list->elementNumber)
    {
        if (key == list->objectList[i].key)
            return i; // retorna a posição do elemento
        else
            i++;
    }
    return -1; // nenhum elemento encontrado
}
void displayMenu()
{
    cout << "-------------------------------------" << endl;
    cout << "\tMenu" << endl;
    cout << "-------------------------------------" << endl;
    cout << "1 - Iniciar Lista" << endl;
    cout << "2 - Mostrar Quantidade de Elementos" << endl;
    cout << "3 - Mostrar Lista" << endl;
    cout << "4 - Inserir Item na Lista" << endl;
    cout << "5 - Achar Elementos " << endl;
    cout << "Digite 1,2,3,4 ou 5: " << endl
         << endl;
}
bool confirm()
{
    char confirm;
    do
    {
        cout << "Deseja Continar? [y/n]" << endl;
        cin >> confirm;
    } while (!cin.fail() && confirm != 'y' && confirm != 'n');
    return (confirm == 'y' ? true : false);
}
objectListType orderList(objectListType *list)
{
    int aux;
    objectListType orderedList;
    orderedList.elementNumber = list->elementNumber;

    for (int i = 0; i < list->elementNumber; i++)
    {
        for (int j = i + 1; j < list->elementNumber; j++)
        {
            if (list->objectList[i].key > list->objectList[j].key)
            {
                aux = list->objectList[i].key;
                list->objectList[i].key = list->objectList[j].key;
                list->objectList[j].key = aux;
                orderedList.objectList[j].key = aux;
                orderedList.objectList[i].key = list->objectList[i].key;
            }
        }
    }

    printList(&orderedList);

    return orderedList;
}