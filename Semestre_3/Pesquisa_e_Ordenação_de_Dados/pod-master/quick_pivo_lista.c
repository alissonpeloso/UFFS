/* Esqueleto de implementação do quick sort utilizando lista encadeada.

*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int val;
} Valor;

struct ItemLista {
    Valor *valor;
    int posicao;

    struct ItemLista *prev;
    struct ItemLista *prox;
};
typedef struct ItemLista ItemLista;

typedef struct {
    ItemLista *head;
    ItemLista *tail;
} Lista;



Lista *criaLista(int size){
    Lista *lista = (Lista *) malloc( sizeof (Lista));
    
    ItemLista *first =  (ItemLista *) malloc( sizeof (ItemLista));
    first->prev = NULL;
    first->prox = NULL;
    first->valor = (Valor *) malloc( sizeof (Valor));

    lista->head = first;

    srand((unsigned)time(NULL));

    //seta o valor do primeiro elemento
    first->valor->val = rand() % size;
    //first->val = size;
    first->posicao = 0;
    ItemLista *elemento = first;
    ItemLista *aux;
    int i = size-1;
    while(i > 0){
        aux = ( ItemLista *) malloc( sizeof (ItemLista));
        aux->valor = (Valor *) malloc( sizeof (Valor));
        aux->valor->val = rand() % size; //seta o valor de aux
        aux->posicao = elemento->posicao + 1;
        aux->prev = elemento; //seta o anterior de aux como sendo o elemento
        aux->prox = NULL;
        elemento->prox = aux; //seta o proximo do anterior (elemento) como sendo aux
        elemento = aux;
        i--;
    }
    lista->tail = aux;
    
    return lista;
}

void printLista (Lista *lista){
    ItemLista *aux;
    printf("\n---- Lista ----\n\t");
    for (aux = lista->head; aux != NULL; aux = aux->prox){
        printf("%d, ",aux->valor->val);
    }
    printf("\n------------\n");
}

void swap( ItemLista *a, ItemLista *b ){
    ItemLista *proximaA, *anteriorA;
    int posicaoA;

    if (a == b){
        return;
    }

    Valor *aux = a->valor;
    a->valor = b->valor;
    b->valor = aux;

}

//Essa função retorna o pivo.
ItemLista *particiona( ItemLista *inicio, ItemLista *fim){
    ItemLista *pivo = fim;
    ItemLista *k = inicio;
    ItemLista *i = inicio;

    for(i ; i != fim ; i = i->prox){
        if(i->valor->val <= pivo->valor->val){  
            swap(k,i);
            k = k->prox;
        }
    } 

    if(k->valor->val > pivo->valor->val){
        swap(k, pivo); 
    } 
    return k;
}

void quickSort( ItemLista *inicio, ItemLista *fim){
    if (inicio->posicao < fim->posicao){
        ItemLista *pivo = particiona(inicio, fim);
        if(pivo->prev != NULL){
            quickSort(inicio, pivo->prev);
        }
        if(pivo->prox != NULL){
            quickSort(pivo->prox, fim);
        }
    }
}



int main(){
  

    Lista *lista;

    
    int size = 10;
    

    printf("Quick: %d \n\n", size);

    lista = criaLista(size);

    printLista(lista);

    quickSort(lista->head, lista->tail);

    printLista(lista);
    
    return 0;
}
