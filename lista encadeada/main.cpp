#include <iostream>
// #include <conio.h>
using namespace std;

struct address{
        int key;
        //char nome[30];
        //char rua [30];
        //char cidade[30];
        //char estado[3];
        //char cep[30];
        struct address *next;
};
typedef struct address nodeType;
typedef struct{
    nodeType *start;
    int size;
}listType;

//Procedimentos simples para manipulação da estrutura
//1- Inicializar a lista
void init (listType *list){
  list->start = NULL;
  list->size=0;
}
//2-Inserir um nó no start da lista
void insertStart(listType *list, int value){
    //Primeiro criar na memória o nó
    //Deve ser um ponteiro
    nodeType *newList = (nodeType*) malloc(sizeof(nodeType));
    newList->key=value;
    //newList->next =NULL;
    newList->next = list->start;
    list->start = newList;
    list->size++;
}
void insertEnd(listType *list,int value){
    nodeType *current, *newList=(nodeType*) malloc(sizeof(nodeType));
    newList ->next = NULL;
    newList ->key = value;
    //Pode ser que a lista ainda não contenha nenhum valor
    if(list->start==NULL){
        list->start = newList;
    }
    else{
        //percorrer a lista para encontrar o  último elemento
        current = list->start;
        while(current->next!=NULL){
            current=current->next;
        }
        current->next = newList;
    }
    list->size++;
}
void showList(listType *list){
    nodeType *current;//ponteiro para o nó a ser manipulado
    current = list->start;
    cout <<"\nTamanho da lista: "<< list->size<<endl;
    cout <<"Lista: ";
    while(current!=NULL){
        cout<<current ->key<<" ";//imprime o current
        current = current->next;
    }
    cout<<endl<<endl;
}
void remove(listType *list, int value){
    nodeType *current, *toRemove=NULL;
    current = list->start;
    if(current==NULL){
        cout<<"\nLista vazia!"<<endl;
    }
    else if (list->start->key == value) { // se o elemento está no start
        cout <<"\nAchei no start "<< list->start->key<<endl;
        toRemove = list->start;
        list->start = toRemove->next;
    }
    else{
        cout <<"\nNao está no start"<<endl;
        while(current->next!= NULL && current->next->key!=value)
        {
            //vai para o proximo nó
            current=current->next;
            //vai até quebrar por encontrar ouchegar no fim da lista
            //fora do laço é que eu descubroo pq quebou
        }
        if(current ->next !=NULL && current->next->key == value){
            cout<<"\nAchei o valor: "<<current ->next->key<<endl;
            toRemove = current->next;
            current->next = toRemove ->next;
        }
        else{
            cout << "\nNao achei!\n";
            toRemove = NULL;
        }
    }
    if(toRemove){
        free(toRemove);
        list->size--;
    }
}

int main()
{
    listType list;
    init(&list);
    int option=0;
    int value;
    while (option!=5){
        cout <<"\n1-Inserir no Inicio\n2-Imprimir \n";
        cout <<"3-Inserie no Fim\n4-Remover\n5-Sair\n";
        cin>>option;
        switch(option)
        {
            case 1:
                cout <<"\nInforme uma chave: ";
                cin >> value;
                insertStart(&list,value);
                break;
            case 2:
                showList(&list);
                break;
            case 3:
                cout<<"\nInforme a chave: ";
                cin >> value;
                insertEnd(&list,value);
                break;
            case 4:
                cout<<"\nInforme a chave: ";
                cin >> value;
                remove(&list,value);
                break;
            case 5:
                cout<<"\nFim!";
                break;
            default:
                cout <<"\nOp. Errada!\n\n";
        }
    }
    return 0;
}