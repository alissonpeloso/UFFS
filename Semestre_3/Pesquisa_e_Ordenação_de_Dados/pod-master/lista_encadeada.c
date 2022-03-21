/*
    author: gschreiner

    Este é um código simples de implementação de uma lista duplamente encadeada utilizando duas estruturas. 
    Este código foi construido na aula do dia 14/10/2020;
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct ItemLista {
    int valor;
    
   struct ItemLista *next;
   struct ItemLista *prev;
};
typedef struct ItemLista ItemLista;

typedef struct {
    ItemLista *head;
    ItemLista *tail;
} Lista;


#define MAX 1000

/*
* Método responsável pro criar a lista. Recebe como parâmetro a estrutura da lista e o número de elementos que será gerado.
*/
void criaLista (Lista *lista, int size){
    ItemLista *aux;

    srand((unsigned)time(NULL));
    for(int i = 0; i< size; i++){
        aux = (ItemLista *) malloc (sizeof(ItemLista));
        aux->valor = rand()%MAX;
        aux->next = NULL;
        aux->prev = NULL;

        if (lista->head == NULL){ //lista vazia
            lista->head = aux;
            lista->tail = aux;
        }else{ //faz encadeamento
            lista->tail->next = aux; //Proximo do último elemento recebe o elemento criado
            aux->prev = lista->tail;
            lista->tail = aux; //Elemento criado vira o último da lista;
        }
    }

}

/*
* Método que imprime a lista. Recebe como parâmetro a lista a ser impressa na tela, 
*   e um interio que define a ordem de apresentação (caso > 0 imprime em ordem de inserção, 
    caso contrário imprime em ordem inversa a inserção)
*/
void imprimeLista(Lista *lista, int order){
    ItemLista *aux;
    if (order > 0){
        for (aux=lista->head; aux != NULL; aux = aux->next){
            printf("%d, ", aux->valor);
        }
    } else {
        for (aux=lista->tail; aux != NULL; aux = aux->prev){
            printf("%d, ", aux->valor);
        }
    }

}


int main(){

    Lista *lista = NULL;
    
    lista = (Lista * ) malloc (sizeof(Lista)); //aloca espaço para a lista
    lista->head = NULL;
    lista->tail = NULL;
    
    
    criaLista(lista, 10);
    
    printf("Primeiro elemento %d;\n Ultimo Elemento: %d\n\n", lista->head->valor, lista->tail->valor);

    printf("Ordem de inserção: \n");
    imprimeLista(lista, 1);

    printf("\nOrdem contrária de inserção: \n");
    imprimeLista(lista, -1);

    return 0;
}