#include <iostream>
#include <conio.h>
using namespace std;

struct address{
        int chave;
        //char nome[30];
        //char rua [30];
        //char cidade[30];
        //char estado[3];
        //char cep[30];
        struct address *prox;
};
typedef struct address no;
typedef struct{
    no *inicio;
    int top; // posição do ultimo elemento da pilha

}Pilha;

//Procedimentos simples para manipulação da estrutura
//1- Inicializar a lista
void init (Pilha *l){
  l->inicio = NULL;
  l->tam=0;
}
//2-Inserir um nó no inicio da lista
void insereIni(Pilha *l, int valor){
    //Primeiro criar na memória o nó
    //Deve ser um ponteiro
    no *novo = (no*) malloc(sizeof(no));
    novo->chave=valor;
    //novo->prox =NULL;
    novo->prox = l->inicio;
    l->inicio = novo;
    l->tam++;
}
void insereFim(Pilha *l,int val){
    no *atual, *novo=(no*) malloc(sizeof(no));
    novo ->prox = NULL;
    novo ->chave = val;
    //Pode ser que a lista ainda não contenha nenhum valor
    if(l->inicio==NULL){
        l->inicio = novo;
    }
    else{
        //percorrer a lista para encontrar o  último elemento
        atual = l->inicio;
        while(atual->prox!=NULL){
            atual=atual->prox;
        }
        atual->prox = novo;
    }
    l->tam++;
}
void imprime(Pilha *l){
    no *atual;//ponteiro para o nó a ser manipulado
    atual = l->inicio;
    cout <<"Tamanho da lista: "<< l->tam<<endl;
    cout <<"Lista: ";
    while(atual!=NULL){
        cout<<atual ->chave<<" ";//imprime o atual
        atual = atual->prox;
    }
    cout<<endl<<endl;
}
void remover(Pilha *l, int val){
    no *atual, *Aremover=NULL;
    atual = l->inicio;
    if(atual==NULL){
        cout<<"Lista vazia!"<<endl;
    }
    else if (l->inicio->chave == val) { // se o elemento está no inicio
        cout <<"Achei no inicio "<< l->inicio->chave<<endl;
        Aremover = l->inicio;
        l->inicio = Aremover->prox;
    }
    else{
        cout <<"Nao está no inicio"<<endl;
        while(atual->prox!= NULL && atual->prox->chave!=val)
        {
            //vai para o proximo nó
            atual=atual->prox;
            //vai até quebrar por encontrar ouchegar no fim da lista
            //fora do laço é que eu descubroo pq quebou
        }
        if(atual ->prox !=NULL && atual->prox->chave == val){
            cout<<"achei o valor: "<<atual ->prox->chave<<endl;
            Aremover = atual->prox;
            atual->prox = Aremover ->prox;
        }
        else{
            cout << "Nao achei!\n";
            Aremover = NULL;
        }
    }
    if(Aremover){
        free(Aremover);
        l->tam--;
    }
}

int main()
{
    Pilha lista;
    init(&lista);
    int op=0;
    int val;
    while (op!=5){
        cout <<"1-Inserir no inicio\n2-Imprimir \n";
        cout <<"3-Inserie no Fim\n4-Remover\n5-Sair\n";
        cin>>op;
        switch(op)
        {
            case 1:
                cout <<"Informe uma chave: ";
                cin >> val;
                insereIni(&lista,val);
                break;
            case 2:
                imprime(&lista);
                break;
            case 3:
                cout<<"Informe a chave: ";
                cin >> val;
                insereFim(&lista,val);
                break;
            case 4:
                cout<<"Informe a chave: ";
                cin >> val;
                remover(&lista,val);
                break;
            case 5:
                cout<<"Fim!";
                break;
            default:
                cout <<"Op. Errada!";
        }
    }
    return 0;
}