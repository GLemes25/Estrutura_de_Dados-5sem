#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Declarações iniciais
typedef struct elem{
	int info;
	struct elem *prox;
	
}tipoElem;

typedef struct{
	tipoElem *inicio;
	tipoElem *fim;
}Fila;

Fila *q;
int count=0;

//Função para criar fila vazia
void cria_fila(){
	q->inicio = NULL;
	q->fim = NULL;
	printf("FILA CRIADA!");
}

//Função para verificar se a fila está vazia
int fila_vazia(){
	if(q->inicio == NULL)
	    return 1;
	else
	   return 0;
} 

//Função insere na fila
int insere(int valor){
	tipoElem *p;
	p = (tipoElem*) malloc(sizeof(tipoElem));
	if(p == NULL)
	    return 0;
	count++;
	p->info = valor;
	p->prox = NULL;
	if(fila_vazia())
	    q->inicio = p;
	else{
		q->fim->prox = p;
		q->fim = p;
	}
	return 1;
}

//Função para remover elemento na fila
int remove(){
	tipoElem *p;
	if(fila_vazia()){
		printf("FILA VAZIA!\n");
		return 0;
	}
	else{
		count--;
		p = q->inicio;
		q->inicio = p->prox;
		if(q->inicio == NULL)
		    q->fim == NULL;
		free(p);
	}
	return 1;
}

//Função para consultar primeiro elemento
int consulta(){
	int valor;
	if(fila_vazia()){
		printf("FILA VAZIA!\n");
		return 0;
	}
	else{
		valor = q->inicio->info;
	    printf("PRIMEIRO ELEMENTO: %d\n", valor);
	    return 1;
	}
}
//Função que retorna o tamanho da fila
int tamanho(){
	return count;
}

//Função que imprime a fila
void imprimir() {
     tipoElem *ponteiro = q->inicio;
     if( fila_vazia() ){
    	printf("FILA VAZIA!\n");
     }
     while (ponteiro != NULL) {
           printf("%d\n", ponteiro->info);
           ponteiro = ponteiro->prox;
     }
}

//Função que destroi a fila
int destruir(){
	tipoElem *temp;
	if(fila_vazia()){
		printf("FILA VAZIA!\n");
		return 0;
	}
	else{
		while(q->inicio != NULL){
			temp = q->inicio;
			q->inicio = q->inicio->prox;
			free(temp);
		}
		printf("FILA DESTRUÍDA!\n");
		count=0;
		return 1;
	}		
}

int main(){
		int valor=0, op=0;
	setlocale(LC_ALL,""); //comando para usar caracteres especiais
	
	do{
        printf("=========MENU==========");
        printf("\n(1) CRIAR FILA\n(2) INSERIR ELEMENTO\n(3) REMOVER ELEMENTO\n(4) CONSULTAR TAMANHO");
        printf("\n(5) CONSULTAR INÍCIO\n(6) IMPRIMIR FILA\n(7) DESTRUIR FILA\n");
        printf("=======================\n");
        
        do{
	      printf("DIGITE SUA OPÇÃO: ");
          scanf("%d", &op);
        }while(op < 1 || op > 6);
      
        system("cls || clear");
      
        switch(op){
        	case 1: cria_fila();
            case 2: printf("DIGITE O VALOR A SER INSERIDO: ");
                    scanf("%d", &valor);
                    insere(valor);
                    break;
            case 3: remove();
                    break;
            case 4: printf("QUANTIDADE DE ELEMENTOS DA FILA: %d \n", tamanho() );
                    break;
            case 5: consulta();
                    break;
			case 6: printf("ELEMENTOS DA FILA:\n");
			        imprimir();
			        break;    
			case 7: destruir();
			        break;        
        }
        
        printf("\nDIGITE 0 PARA CONTINUAR: ");
		scanf("%d", &op);
		printf("\n\n");
		
	}while(op==0);
	
	return 0;
}
