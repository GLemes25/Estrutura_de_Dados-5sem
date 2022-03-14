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
        int start; // Posição inicial da fila
        int quantity;   // quantitye de elementos na fila

} rowType;

/*Funções a serem implementadas
1 - Inicialização
2 - Retornar a quantidade de elementos na fila
3 - Imprimir a fila
4 - Inserir elementos (No final)
5 - Remover elemento (No início)
6 - Reiniciar a estrutura
*/

// 1 - Inicialização
void initRow(rowType *f)
{

        f->start = 0;
        f->quantity = 0;
}

// 2 - quantity elementos
int elementQuantity(rowType *f)
{

        return f->quantity;
}

// 3 - Imprimir fila
void printRow(rowType *f)
{

        // O primeiro elemento está na posição start o arranjo
        // Após a última posição a próxima é 0
        int i = f->start; // Define o início da fila
        int j;            // Controla o loop para acessar todas as posições do arranjo
        for (j = 0; j < f->quantity; j++)
        {
                cout << f->list[i].key;
                i = (i + 1) % maxQuantity;
        }

        cout << endl;
}

bool insert(rowType *f, objectType reg)
{

        // verifica se a fola nao ta cheia
        // INSERE UM ELEMENTO NO FINAL
        // atualiza a quantitye de elementos

        if (f->quantity >= maxQuantity)
        {
                return false;
        }

        int pos = ((f->start + f->quantity) % maxQuantity);
        f->list[pos] = reg;
        f->quantity++;
        return true;
};

bool remove(rowType *f, objectType *reg)
{
        if (f->quantity == 0) // Verifica se esta vazio
        {
                return false;
        }

        *reg = f->list[f->start];
        f->start = (f->start + 1) % maxQuantity;
        f->quantity--;
        return true;
};

int main()
{

        objectType aux;
        bool r;
        rowType fila;

        initRow(&fila);

        aux.key = 9;
        r = insert(&fila, aux);

        cout << r << endl;

        r = remove(&fila, &aux);

        cout << r << endl;
        if (r)
        {
                cout << "REMOVIDO" << endl;
        }

        return 0;
}