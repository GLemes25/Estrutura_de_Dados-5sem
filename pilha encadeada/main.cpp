#include <iostream>
// #include <conio.h>
using namespace std;

struct address{
        int key;
        struct address *next;
};

typedef struct address nodeType;

typedef struct{
    nodeType *start;
    int top;
}stackType;

//Procedimentos simples para manipulação da estrutura
//1- Inicializar a lista
void init (stackType *p){
  p->start = NULL;
  p->top=0;
}


bool pop(stackType *stack){
    nodeType *current, *toRemove=NULL;
    current = stack->start;
    if(current==NULL){
        cout<<"Pilha vazia!!\n"<<endl;
    }else {
        toRemove = stack->start;
        stack->start = toRemove->next;
    if(toRemove){
        free(toRemove);
        stack->top--;
        }
    }
}

void imprimePilha(stackType *stack){
    nodeType *current;//ponteiro para o nó a ser manipulado
    current = stack->start;
    cout <<"Tamanho da pilha: "<< stack->top<<endl;
    cout <<"Pilha: ";
    while(current!=NULL){
        cout<<current ->key<<" ";//imprime o atual
        current = current->next;
    }
    cout<<endl<<endl;
}

//2-Inserir um nó no inicio da pilha
bool push(stackType *stack, int value){
    //Primeiro criar na memória o nó
    //Deve ser um ponteiro
    nodeType *newStack = (nodeType*) malloc(sizeof(nodeType));
    newStack->key=value;
    //novo->prox =NULL;
    newStack->next = stack->start;
    stack->start = newStack;
    stack->top++;
    imprimePilha(stack);
}

int main()
{
    stackType stack;
    init(&stack);
    int option=0;
    int value;
    while (option!=5){
        cout <<"-----------------Menu---------------------------\n";
        cout <<"1-Iniciar a pilha\n2-Inserir no inicio da pilha \n";
        cout <<"3-Remover do topo da pilha\n4-Imprimir pilha\n5-Sair\n";
        cin>>option;
        switch(option)
        {
            case 1:
                init(&stack);
                cout << "Operacao realizada com sucesso!!\n";
                break;
            case 2:
                cout<<"Informe a chave: ";
                cin >> value;
                push(&stack,value);
                break;
            case 3:
                pop(&stack);
                cout << "Valor removido com sucesso da pilha!!\n";
                break;
            case 4:
                imprimePilha(&stack);
                break;
            case 5:
                cout<<"Fim!";
                break;
            default:
                cout <<"Op. Errada!\n";
        }
    }
    return 0;
}