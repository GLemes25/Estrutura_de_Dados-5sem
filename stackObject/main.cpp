#include <iostream>
#include <stdio.h>

using namespace std;
#define MAX 50
typedef int KeyType;
typedef struct
{
    KeyType key;
    // outros campos
} ObjectType;
typedef struct
{

    ObjectType list[MAX];
    int top; // posição do ultimo elemento da pilha
} StackType;

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

bool initStack(StackType *stack)
{
    stack->top = -1;
    return true;
}
// 2-retorna a qtd de elementos na pilha
int sizeStack(StackType *stack)
{
    return stack->top + 1;
}

// 3- exibir os elementos amarzenados na pilha
void showStack(StackType *stack)
{
    // exibe os elementos do topo para baixo
    int i; // manipular o indice do vetor

    cout << "pilha: ";

    for (i = stack->top; i >= 0; i--)
    {

        cout << stack->list[i].key << " ";
    }
    cout << endl;

    cout << sizeStack(stack) << " Itens " << endl;
}
// 4- inserir elementos na pilha (push)
// inserir sempre no topo da pilha se a pilha não estiver cheia
bool push(StackType *stack, ObjectType object)
{

    if (stack->top >= MAX - 1)
        return false;
    // caso da pilha n esteja cheia adiciono mais um elemento no topo
    stack->top = stack->top + 1; // atualiza a posição da pilha do topo
    stack->list[stack->top] = object;
    return true;
}
// 5- retirar um elemento da pilha
bool remove(StackType *stack)
{
    if (stack->top == -1)
        return false;

    stack->top = stack->top - 1;
    return true;
}
void displayMenu()
{
    cout << "-------------------------------------" << endl;
    cout << "\tMenu" << endl;
    cout << "-------------------------------------" << endl;
    cout << "1 - Adicionar item na plha" << endl;
    cout << "2 - Remover item da pilha" << endl;
    cout << "3 - Mostrar pilha" << endl;
    cout << "4 - Reiniciar pilha  " << endl;
    cout << "5 - Sair " << endl;
    cout << "Escolha uma ação: " << endl
         << endl;
}
void getch(void)
{
    cout<<endl;
    system("read -p \"Pressione enter para continuar\" continuando");
    cout<<endl;

}

int main()
{
    StackType stack;
    StackType newStack;
    int option;
    bool initiate = false;

    // inicializar a pilha
    do
    {
        /* code */

        displayMenu();
        cin >> option;

        initiate ?: initiate = initStack(&stack),initStack(&newStack);

        switch (option)
        {
        case 1:
        {
            ObjectType aux;
            bool result;

            cout << "Digite Chave " << endl;
            cin >> aux.key;

            result = push(&stack, aux);
            cout << (result ? "Adicionado com sucesso " : "Pilha esta cheia") << endl;

            break;
        }

        case 2:
        {
            remove(&stack);
            break;
        }
        case 3:
        {
            showStack(&stack);
            break;
        }
        case 4:
        {
            stack=newStack;
            break;
        }
        case 5:
        {

            cout << "Saindo..." << endl;

            break;
        }

        default:
            cout << "Opção invalida" << endl;
        }
        getch();

    } while (option != 5);
    return 0;
}
