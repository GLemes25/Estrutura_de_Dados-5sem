#include <iostream>
// #include <conio.h>
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
    int top;
}PILHA;

//Procedimentos simples para manipulação da estrutura
//1- Inicializar a lista
void init (PILHA *p){
  p->inicio = NULL;
  p->top=0;
}

//2-Inserir um nó no inicio da pilha
bool push(PILHA *p, int valor){
    //Primeiro criar na memória o nó
    //Deve ser um ponteiro
    no *novo = (no*) malloc(sizeof(no));
    novo->chave=valor;
    //novo->prox =NULL;
    novo->prox = p->inicio;
    p->inicio = novo;
    p->top++;
}

bool pop(PILHA *p){
    no *atual, *Aremover=NULL;
    atual = p->inicio;
    if(atual==NULL){
        cout<<"Pilha vazia!!\n"<<endl;
    }else {
        Aremover = p->inicio;
        p->inicio = Aremover->prox;
    if(Aremover){
        free(Aremover);
        p->top--;
        }
    }
}

void imprimePilha(PILHA *p){
    no *atual;//ponteiro para o nó a ser manipulado
    atual = p->inicio;
    cout <<"Tamanho da pilha: "<< p->top<<endl;
    cout <<"Pilha: ";
    while(atual!=NULL){
        cout<<atual ->chave<<" ";//imprime o atual
        atual = atual->prox;
    }
    cout<<endl<<endl;
}


int main()
{
    PILHA pilha;
    init(&pilha);
    int op=0;
    int val;
    while (op!=5){
        cout <<"1-Iniciar a pilha\n2-Inserir no inicio da pilha \n";
        cout <<"3-Remover do topo da pilha\n4-Imprimir pilha\n5-Sair\n";
        cin>>op;
        switch(op)
        {
            case 1:
                init(&pilha);
                cout << "Operacao realizada com sucesso!!\n";
                break;
            case 2:
                cout<<"Informe a chave: ";
                cin >> val;
                push(&pilha,val);
                break;
            case 3:
                pop(&pilha);
                cout << "Valor removido com sucesso da pilha!!\n";
                break;
            case 4:
                imprimePilha(&pilha);
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