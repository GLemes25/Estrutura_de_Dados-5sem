#include <iostream>
// #include <conio.h>
#include <locale.h>
using namespace std;

struct address
{
    int chave;
    // char nome[30];
    // char rua [30];
    // char cidade[30];
    // char estado[3];
    // char cep[30];
    struct address *prox;
    struct address *ant;
};
typedef struct address no;
typedef struct
{
    no *inicio;
    no *fim;
    int tam;
} LISTA;

void getch(void)
{
    cout << endl;
    system("read -p \"Pressione enter para continuar\" continuando");
    cout << endl;
}

// Procedimentos simples para manipulação da estrutura
// 1- Inicializar a lista
void init(LISTA *l)
{
    l->inicio = NULL;
    l->fim = NULL;
    l->tam = 0;
}
void insereFim(LISTA *l, int val)
{
    // 1° criar uma cópia do nó
    no *novo = (no *)malloc(sizeof(no));

    // Verificar se a lista está vazia
    if (l->inicio == NULL)
    {
        cout << "Lista VAZIA!" << endl;
        l->inicio = novo;
        l->fim = novo;
        novo->prox = NULL;
        novo->ant = NULL;
        l->tam = l->tam + 1;
        novo->chave = val;
    }
    else
    {
        cout << "Lista NAO VAZIA!" << endl;
        novo->prox = NULL;
        novo->ant = l->fim;
        // l->fim->prox=novo;
        novo->ant->prox = novo;
        l->fim = novo;
        l->tam = l->tam + 1;
        novo->chave = val;
    }
}
void imprime(LISTA *l)
{
    no *atual; // ponteiro para o nó a ser manipulado
    atual = l->inicio;
    cout << "Tamanho da lista: " << l->tam << endl;
    cout << "Lista: ";
    while (atual != NULL)
    {
        cout << atual->chave << " "; // imprime o atual
        atual = atual->prox;
    }
    cout << endl
         << endl;
    getch();
    system("cls||clear");
}
void insereInicio(LISTA *l, int val)
{
    // 1° criar uma cópia do nó
    no *novo = (no *)malloc(sizeof(no));
    novo->chave = val;
    // Verificar se a lista está vazia
    if (l->inicio == NULL)
    {
        cout << "A lista esta vazia! Inserindo no inicio\n";
        novo->prox = NULL;
        novo->ant = NULL;
        l->inicio = novo;
        l->fim = novo;
        l->tam = 1;
    }
    // A lista não está vazia
    else
    {
        cout << "A lista NAO esta vazia!Inserindo no inicio\n";
        novo->prox = l->inicio;
        novo->ant = l->inicio->ant; // novo->ant=NULL;
        l->inicio->ant = novo;
        l->tam = l->tam + 1;
        l->inicio = novo;
    }
}

void removeInicio(LISTA *l)
{
    no *Aremover;
    Aremover = NULL;
    Aremover = l->inicio;
    if (Aremover == NULL)
        cout << "Lista Vazia!" << endl;
    else
    {
        if (Aremover->prox != NULL)
        {
            l->inicio = Aremover->prox;
            Aremover->prox->ant = NULL;
            l->tam = l->tam - 1;
        }
        else
        {
            cout << "Apenas 1 elemento na lista, lista reiniciada" << endl;
            init(l);
        }
    }
    if (Aremover)
    {
        free(Aremover);
    }
} // Fim remove inicio
void removeFim(LISTA *l)
{
    no *Aremover;
    Aremover = NULL;
    Aremover = l->fim;
    if (Aremover == NULL)
        cout << "Lista Vazia!" << endl;
    else
    {
        if (Aremover->ant != NULL)
        {
            Aremover->ant->prox = NULL;
            l->fim = Aremover->ant;
            l->tam = l->tam - 1;
        }
        else
        {
            cout << "Apenas 1 elemento na lista, lista reiniciada" << endl;
            init(l);
        }
    }
    if (Aremover)
    {
        free(Aremover);
    }
}
void removeItem(LISTA *l, int ch)
{
    // Verificar se a lista está vazia
    if (l->inicio == NULL)
    {
        cout << "Lista Vazia!!" << endl;
        getch();
        system("cls||clear");
    }
    else
    {
        // Encontrar o elemento na lista
        no *atual, *Aremover;
        atual = l->inicio;
        Aremover = NULL;
        while (atual != NULL)
        {
            if (atual->chave == ch)
            {
                cout << "Achei: " << atual->chave << endl; // Encontrou elemento
                getch();
                system("cls||clear");
                Aremover = atual;
                break;
            } // fim verifica se encontrou elemento
            atual = atual->prox;
        } // fim while para percorrer a lista
        if (Aremover == NULL)
        {
            cout << "Não achei!" << endl;
            getch();
            system("cls||clear");
        }
        else
        {
            // O elemento foi encontrado na lista
            //É o primeiro?
            if (Aremover->ant == NULL)
            {
                cout << "É o primeiro da lista" << endl;
                getch();
                system("cls||clear");
                if (Aremover->prox != NULL)
                {
                    l->inicio = Aremover->prox;
                    Aremover->prox->ant = NULL;
                    l->tam = l->tam - 1;
                }
                else
                {
                    cout << "Apenas 1 elemento na lista, lista reiniciada" << endl;
                    getch();
                    system("cls||clear");
                    init(l);
                }
            }
            //É o último?
            else if (Aremover->prox == NULL)
            {
                cout << "É o último da lista" << endl;
                getch();
                system("cls||clear");
                if (Aremover->ant != NULL)
                {
                    Aremover->ant->prox = NULL;
                    l->fim = Aremover->ant;
                    l->tam = l->tam - 1;
                }
                else
                {
                    cout << "Apenas 1 elemento na lista, lista reiniciada" << endl;
                    getch();
                    system("cls||clear");
                    init(l);
                }
            }
            // Está entre dois elementos?
            else
            {
                cout << "Está entre 2 elementos" << endl;
                getch();
                system("cls||clear");
                Aremover->ant->prox = Aremover->prox;
                Aremover->prox->ant = Aremover->ant;
                l->tam = l->tam - 1;
            }
            if (Aremover != NULL)
                free(Aremover);
        }
    } // Fim verificação de elemento na lista
} // Fim procedimento remover item

int main()
{
    setlocale(LC_ALL, "Portuguese");
    LISTA lista;
    init(&lista);
    int op, val;
    op = 0;
    while (op != 8)
    {
        cout << "1-Inserir no inicio" << endl;
        cout << "2-Inserir no fim" << endl;
        cout << "3-Imprimir: inicio para o fim" << endl;
        cout << "4-Imprimir: fim para o inicio" << endl;
        cout << "5-Remover no inicio" << endl;
        cout << "6-Remover no final" << endl;
        cout << "7-Remover item" << endl;
        cout << "8-Sair" << endl;
        cin >> op;
        switch (op)
        {
        case 1:
            cout << "Chave: ";
            cin >> val;
            insereInicio(&lista, val);
            break;
        case 2:
            cout << "Chave: ";
            cin >> val;
            insereFim(&lista, val);
            break;
        case 3:
            imprime(&lista);
            break;
        case 4:

            break;
        case 5:
            cout << "Removendo no inicio" << endl;
            removeInicio(&lista);
            break;
        case 6:
            cout << "Removendo do fim" << endl;
            removeFim(&lista);
            break;
        case 7:
            cout << "Removendo um item da lista" << endl;
            cout << "Chave: ";
            cin >> val;
            removeItem(&lista, val);
            break;
        case 8:
            cout << "Fim do programa! Volte sempre!" << endl;
            break;
        default:
            cout << "Opção Inválida" << endl;
            break;

        } // fim case
    }     // fim while

    return 0;
}