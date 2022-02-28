typedef int keyType;
#define maxObject 50

typedef struct
{
    keyType key;
    // outros campos
} objecType;

typedef struct
{
    objecType objectList[maxObject];
    int elementNumber;
} listType;

#include <iostream>
// #include <conio.h>
// Fun��es para manipular a lista sequencial
void displayMenu();
void initList(listType *l);                        // Inicializa��o da lista com Zero elementos
int elementsQuantity(listType *l);                 // Retorna a qtde de elementos na lista
void printList(listType *l);                       // Imprime o conte�do da lista
bool insertList(listType *l, objecType rg, int i); // insere um elemento na posi��o desejada.
                                                   // Se n�o for permitido retorna false.
int findElement(listType *l, keyType ch);          // busca o elemento na lista
                                                   // Se encontar retorna a posi��o Sen�o retorna -1

using namespace std;

int main()
{
    displayMenu();
    listType lista;
    initList(&lista);
    // cout <<"qtd elementos(main): "<<lista.elementNumber;
    cout << "qtd elementos na lista: " << elementsQuantity(&lista) << endl;
    // Adicionar manualmente os elementos na lista
    lista.objectList[0].key = 10;
    lista.objectList[1].key = 20;
    lista.objectList[2].key = 30;
    printList(&lista);
    cout << endl;
    objecType aux;
    bool result;
    aux.key = 50;
    result = insertList(&lista, aux, 1);
    cout << result << endl;
    printList(&lista);

    int x = findElement(&lista, 200);
    cout << endl
         << "Valor encontador na pos.: " << x << endl;
    return 0;
}

// Fun��es//
void initList(listType *l)
{
    l->elementNumber = 3;
    // cout << "qtd elementos(func): " <<l->elementNumber <<endl;
}

int elementsQuantity(listType *l)
{
    return l->elementNumber;
}

void printList(listType *l)
{
    int i; // manipular o indice do vetor da estrutura onde est� armazenado a informa��o (key)
    cout << "Lista: ";
    for (i = 0; i < l->elementNumber; i++)
    {
        cout << l->objectList[i].key << " ";
    }
}
bool insertList(listType *l, objecType rg, int i)
{
    // valida��o da posi��o informada e se a lista est� cheia
    if (l->elementNumber == maxObject || i < 0 || i > l->elementNumber)
        return false;

    int j; // var. para auxiliar na manipula��o dos �ndice
    // Deslocando os elementos para direita
    for (j = l->elementNumber; j > i; j--)
        l->objectList[j] = l->objectList[j - 1];

    // Armazenando a key na posi��o desejada
    l->objectList[i] = rg;
    l->elementNumber++;
    return true;
}
int findElement(listType *l, keyType ch)
{
    int i = 0; // var. para auxiliar na manipula��o dos �ndice
    while (i < l->elementNumber)
    {
        if (ch == l->objectList[i].key)
            return i; // retorna a posi��o do elemento
        else
            i++;
    }
    return -1; // nenhum elemento encontrado
}
void displayMenu()
{
    cout << "------------------------\n";
    cout << "\tMenu\n";
    cout << "------------------------\n";
    cout << "1 - Difficulty\n";
    cout << "2 - Sound";
    cout << "3 - Back\n";
    cout << "3 - Back\n";
    cout << "Digite 1,2,3 ou 4: \n\n";
}