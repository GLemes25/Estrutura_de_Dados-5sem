#include <iostream>
// #include <conio.h>

using namespace std;

#define MAX 6

typedef int TIPOCHAVE;
typedef struct
{
        TIPOCHAVE chave;
        // Outros elementos
} REGISTRO;

typedef struct
{
        REGISTRO A[MAX];
        int start; // Posição inicial da fila
        int qtd;   // Qtde de elementos na fila

} FILA;

/*Funções a serem implementadas
1 - Inicialização
2 - Retornar a quantidade de elementos na fila
3 - Imprimir a fila
4 - Inserir elementos (No final)
5 - Remover elemento (No início)
6 - Reiniciar a estrutura
*/

// 1 - Inicialização
void initFila(FILA *f)
{

        f->start = 0;
        f->qtd = 0;
}

// 2 - Qtd elementos
int qtdElementos(FILA *f)
{

        return f->qtd;
}

// 3 - Imprimir fila
void printFila(FILA *f)
{

        // O primeiro elemento está na posição start o arranjo
        // Após a última posição a próxima é 0
        int i = f->start; // Define o início da fila
        int j;            // Controla o loop para acessar todas as posições do arranjo
        for (j = 0; j < f->qtd; j++)
        {
                cout << f->A[i].chave;
                i = (i + 1) % MAX;
        }

        cout << endl;
}

bool insere(FILA *f, REGISTRO reg)
{

        // verifica se a fola nao ta cheia
        // INSERE UM ELEMENTO NO FINAL
        // atualiza a qtde de elementos

        if (f->qtd >= MAX)
        {
                return false;
        }

        int pos = ((f->start + f->qtd) % MAX);
        f->A[pos] = reg;
        f->qtd++;
        return true;
};

bool remover(FILA *f, REGISTRO *reg)
{
        if (f->qtd == 0) // Verifica se esta vazio
        {
                return false;
        }

        *reg = f->A[f->start];
        f->start = (f->start + 1) % MAX;
        f->qtd--;
        return true;
};

int main()
{

        REGISTRO aux;
        bool r;
        FILA fila;

        initFila(&fila);

        aux.chave = 9;
        r = insere(&fila, aux);

        cout << r << endl;

        r = remover(&fila, &aux);

        cout << r << endl;
        if (r)
        {
                cout << "REMOVIDO" << endl;
        }

        return 0;
}