#include <iostream>
#include <conio.h>

using namespace std;
#define MAX 50
typedef int TIPOCHAVE;
typedef struct{
    TIPOCHAVE chave;
    //outros campos

}REGISTRO;
typedef struct{

REGISTRO A[MAX];
int top;//posição do ultimo elemento da pilha
}PILHA;

/*função para manipular
 1-inicializar
 2-retornar qtd de elementos
 3- imprimir os elementos da pilha
 4- inserir elementos na pilha(push)
 5- retirar elementos da pilha (pop)
 6- reniciar a pilha
*/
 //1- iniicializar a pilha

 void initPilha(PILHA *p){
  p ->top = - 1;


 }
//2-retorna a qtd de elementos na pilha
int tamPilha(PILHA *p){
return p ->top+1;

}
//3- exibir os elementos amarzenados na pilha
void exibePilha(PILHA *p ){
    //exibe os elementos do topo para baixo
    int i;//manipular o indice do vetor
    cout<< "PILHA: ";

    for(i= p->top;i>=0;i-- ){

        cout<<p->A[i].chave<< " ";
    }
       cout<<endl;
}
//4- inserir elementos na pilha (push)
//inserir sempre no topo da pilha se a pilha não estiver cheia
bool push (PILHA *p , REGISTRO reg){

   if(p->top >= MAX -1)
    return false;
   //caso da pilha n esteja cheia adiciono mais um elemento no topo
   p->top = p->top+1;//atualiza a posição da pilha do topo
   p->A[p->top]=reg;
   return true;


}
//5- retirar um elemento da pilha

bool pop( PILHA *p){
   if(p->top == -1)
    return false;

   p ->top = p->top-1;
   return true;
}







int main()
{
    bool result;
    PILHA pilha;
    REGISTRO aux;
    // inicializar a pilha
    initPilha(&pilha);

    // adicionando um elemento na pilha
    aux.chave = 18;
    result = push(&pilha,aux);
    cout<< result<<endl;
    //adicionando outro elemento
    aux.chave = 13;
    result = push(&pilha,aux);
    cout<< result<<endl;
   //adicionando outro elemento
    aux.chave = 1;
    result = push(&pilha,aux);
    cout<< result<<endl;
    //adicionando outro elemento
    aux.chave = 2;
    result = push(&pilha,aux);
    cout<< result<<endl;

    exibePilha(&pilha);
    //remover um elemento da pilha
    result=pop(&pilha);
    cout<<result<<endl;
    exibePilha(&pilha);
    getch();


    return 0;
}