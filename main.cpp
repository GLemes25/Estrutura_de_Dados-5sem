typedef int TIPOCHAVE;
#define MAX 50

typedef struct {
    TIPOCHAVE chave;
    //outros campos
}REGISTRO;

typedef struct {
    REGISTRO A[MAX];
    int nroElem;
}LISTA;

#include <iostream>
#include <conio.h>
//Funções para manipular a lista sequencial
void initLista(LISTA *l);//Inicialização da lista com Zero elementos
int qtdElem (LISTA *l);//Retorna a qtde de elementos na lista
void imprimeLista(LISTA *l); // Imprime o conteúdo da lista
bool insertLista (LISTA *l,REGISTRO rg, int i); //insere um elemento na posição desejada.
                                                //Se não for permitido retorna false.
int buscaElem (LISTA *l, TIPOCHAVE ch);//busca o elemento na lista
                    //Se encontar retorna a posição Senão retorna -1

using namespace std;

int main()
{
    LISTA lista;
    initLista(&lista);
    //cout <<"qtd elementos(main): "<<lista.nroElem;
    cout << "qtd elementos na lista: " << qtdElem(&lista) <<endl;
    //Adicionar manualmente os elementos na lista
    lista.A[0].chave = 10;
    lista.A[1].chave = 20;
    lista.A[2].chave = 30;
    imprimeLista(&lista);
    cout <<endl;
    REGISTRO aux;
    bool result;
    aux.chave = 50;
    result = insertLista(&lista,aux,1);
    cout <<result<<endl;
    imprimeLista(&lista);

    int x = buscaElem(&lista,200);
    cout << endl << "Valor encontador na pos.: " << x <<endl;
    return 0;
}

//Funções//
void initLista(LISTA *l){
    l-> nroElem = 3;
    //cout << "qtd elementos(func): " <<l->nroElem <<endl;
}

int qtdElem (LISTA *l){
    return l->nroElem;
}

void imprimeLista(LISTA *l){
    int i; // manipular o indice do vetor da estrutura onde está armazenado a informação (chave)
    cout <<"Lista: ";
    for(i=0;i< l->nroElem;i++)
    {
        cout <<l ->A[i].chave<<" ";
    }
}
bool insertLista (LISTA *l,REGISTRO rg, int i)
{
    //validação da posição informada e se a lista está cheia
    if(l->nroElem == MAX || i<0 || i > l->nroElem)
        return false;

    int j; // var. para auxiliar na manipulação dos índice
    //Deslocando os elementos para direita
    for(j = l->nroElem; j> i;j--)
        l ->A[j]=l->A[j-1];

    //Armazenando a chave na posição desejada
    l ->A[i] = rg;
    l ->nroElem++;
    return true;
}
int buscaElem (LISTA *l, TIPOCHAVE ch)
{
    int i=0; // var. para auxiliar na manipulação dos índice
    while (i < l->nroElem)
    {
        if (ch == l->A[i].chave)
            return i; // retorna a posição do elemento
        else
            i++;
    }
    return -1; //nenhum elemento encontrado
}
