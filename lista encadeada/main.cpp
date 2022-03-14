#include <iostream>
#include <stdio.h>

using namespace std;

struct address
{
    int key;
    char nome[30];
    char rua[30];
    char cidade[30];
    char estado[30];
    char cep[10];
    struct address *prox;
};

typedef struct address no;

typedef struct
{
    no *inicio;
    int tam;
} LISTA;

void init(LISTA *l)
{
    l->inicio = NULL;
    l->tam = 0;
}

void insereBegin(LISTA *l, int valor)
{
    no *novo = (no *)malloc(sizeof(no));
    novo->key=valor;
    novo->prox = NULL;
    l->inicio = novo;
    l->tam++;
}
/*função para manipular
 1-inicializar
 2-retornar qtd de elementos
 3- imprimir os elementos da pilha
 4- inserir elementos na pilha(push)
 5- retirar elementos da pilha (pop)
 6- reniciar a pilha
*/
// iostream
// 1- iniicializar a pilha

int main()
{
    LISTA lista;
    init(&lista);
    cout << "Opção invalida" << endl;

    return 0;
}
