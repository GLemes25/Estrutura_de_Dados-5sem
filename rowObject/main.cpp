#include <iostream>
// #include <conio.h>

using namespace std;

#define maxQuantity 6

typedef int keyType;
typedef struct
{
    keyType key;
    // Outros elementos
} objectType;

typedef struct
{
    objectType list[maxQuantity];
    int start;    // Posição inicial da row
    int quantity; // quantitye de elementos na row

} rowType;

/*Funções a serem implementadas
1 - Inicialização
2 - Retornar a quantidade de elementos na row
3 - Imprimir a row
4 - Inserir elementos (No final)
5 - Remover elemento (No início)
6 - Reiniciar a estrutura
*/

// 1 - Inicialização
void initRow(rowType *row)
{

    row->start = 0;
    row->quantity = 0;
}

// 2 - quantity elementos
int elementQuantity(rowType *row)
{

    return row->quantity;
}

// 3 - Imprimir row
void printRow(rowType *row)
{

    // O primeiro elemento está na posição start o arranjo
    // Após a última posição a próxima é 0
    int i = row->start; // Define o início da row
    int j;              // Controla o loop para acessar todas as posições do arranjo
    for (j = 0; j < row->quantity; j++)
    {
        cout << "  " << row->list[i].key;
        i = (i + 1) % maxQuantity;
    }

    cout << endl;
    cout << "Quantidade de Elementos: " << elementQuantity(row) << endl;
}

bool insert(rowType *row, objectType object)
{

    // verifica se a fola nao ta cheia
    // INSERE UM ELEMENTO NO FINAL
    // atualiza a quantitye de elementos

    if (row->quantity >= maxQuantity)
    {
        return false;
    }

    int pos = ((row->start + row->quantity) % maxQuantity);
    row->list[pos] = object;
    row->quantity++;
    return true;
};

bool remove(rowType *row, objectType *object)
{
    if (row->quantity == 0) // Verifica se esta vazio
    {
        return false;
    }

    *object = row->list[row->start];
    row->start = (row->start + 1) % maxQuantity;
    row->quantity--;
    return true;
};

void displayMenu()
{
    cout << "-------------------------------------" << endl;
    cout << "\tMenu" << endl;
    cout << "-------------------------------------" << endl;
    cout << "1 - Adicionar item na fila" << endl;
    cout << "2 - Remover item da fila" << endl;
    cout << "3 - Mostrar fila" << endl;
    cout << "4 - Reiniciar fila" << endl;
    cout << "5 - Sair " << endl;
    cout << "Escolha uma ação: " << endl
         << endl;
}

void getch(void)
{
    cout << endl;
    system("read -p \"Pressione enter para continuar\" continuando");
    cout << endl;
}
int main()
{

    objectType aux;
    rowType row,newRow;
    int option;
    bool result;
    string text;

    initRow(&row);
    initRow(&newRow);

    do
    {
        /* code */

        displayMenu();
        cin >> option;

        switch (option)
        {
        case 1:
        {
            cout << "\nInforme um valor para ser adicionado: ";
            cin >> aux.key;
            result = insert(&row, aux);
            text = result ? ("\nDado adicionado com sucesso!!") : ("\nA fila esta cheia!!!");
            cout << text << endl;
            break;
        }

        case 2:
        {
            result = remove(&row, &aux);
            text = (result) ? ("\nDado removido com sucesso!!") : ("\nA fila nao tem elementos para serem removidos!!");
            cout << text << endl;
            break;
        }
        case 3:
        {
            printRow(&row);
            break;
        }

        case 4:
        {
            row=newRow;
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