/*
    author: gschreiner

    Este é um código simples de implementação de uma lista duplamente encadeada utilizando duas estruturas. 
    Também foi desenvolvida uma solução para ordenação dos elementos, utilizando o método de ordenção de insetion sort;
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct ItemLista {
    int valor;
    
   struct ItemLista *next; //proximo elemento
   struct ItemLista *prev; // elemento anterior
};
typedef struct ItemLista ItemLista;

typedef struct {
    ItemLista *head; //primeiro elemento da lista.
    ItemLista *tail; //o último elemento da lista.
} Lista;


#define MAX 100

/*
 Adiciona um elemento na lista em qualquer posição.
 Recebe como parametros a lista onde o elemento é inserido, o elemento anterior ao inserido e o elemento a ser inserido
*/
void adicionaElemento(Lista *lista, ItemLista *itemAnterior, ItemLista *elemento){
    
    if (itemAnterior == NULL){ //trocar a cabeça da lista, adicionar antes do primeiro elemento
        lista->head->prev = elemento; //anterior da cabeça aponta para o novo
        elemento->next = lista->head; //proximo do novo, é a cabeça da lista
        elemento->prev = NULL; //anterior do novo é nada.

        lista->head = elemento; //atualiza a cabeça da lista.
        return;
    }

    ItemLista *itemProximo = itemAnterior->next; //se itemAnterior == null , segmentation fault
    if (itemProximo == NULL){ // ele é o tail, final da lista
        itemAnterior->next = elemento;
        elemento->prev = itemAnterior;
        elemento->next = NULL;
        lista->tail = elemento; //atualiza o ultimo elemento da lista
    } else{ //qualquer elemento menos o último
        itemAnterior->next = elemento;
        elemento->prev = itemAnterior;
        elemento->next = itemProximo;
        itemProximo->prev = elemento;
        
        //  Fazer encadeamento sem variavel auxiliar.
        //elemento->next = itemAnterior->next;
        //elemento->next->prev = elemento;
        //itemAnterior->next = elemento;
        //elemento->prev = itemAnterior;
    }

    //itemProximo->prev = elemento;

}



/*
* Método responsável por criar a lista. Recebe como parâmetro a estrutura da lista e o número de elementos que será gerado.
*/
void criaLista (Lista *lista, int size){
    ItemLista *aux;

    srand((unsigned)time(NULL));
    for(int i = 0; i< size; i++){
        aux = (ItemLista *) malloc (sizeof(ItemLista));
        aux->valor = rand()%MAX; //sorteando um valor aleatório
        aux->next = NULL;
        aux->prev = NULL;

        if (lista->head == NULL){ //lista vazia
            lista->head = aux;
            lista->tail = aux;
        }else{ //faz encadeamento
            adicionaElemento(lista, lista->tail, aux);
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

void swap(Lista *lista, ItemLista *destino, ItemLista *elemento){
    ItemLista *aux;
    aux = elemento->prev;
    
    if (destino == NULL){ //cabeça da lista
        aux->next = elemento->next;
        if (aux->next != NULL)
            aux->next->prev = aux;
        else {
            lista->tail = aux;
        }
        elemento->next = lista->head;
        lista->head->prev = elemento;
        elemento->prev = NULL;
        lista->head = elemento;

    } else {
        elemento->prev = destino; // anterior do elemento é o j;
        aux->next = elemento->next; //meu ex anterior, aponta para o meu proximo.
        if (aux->next != NULL)
            aux->next->prev = aux; //meu proximo, agora aponta pro meu ex anterior
        else{ //ultimo da lista
            lista->tail = aux;
        }
        destino->next->prev = elemento;
        elemento->next = destino->next;
        destino->next = elemento;
    }
}


void insertionSort(Lista *lista){
    ItemLista *i, *j, *elemento, *aux, *aux2;

    for (i=lista->head->next; i != NULL; i = i->next){
        for(j = i->prev; j != NULL; j = j->prev ){
            if (j->valor < i->valor){
                if (j == i->prev){
                    break;
                }
                aux = i->prev; //anterior do atual
                swap (lista, j, i); //troca os dois elementos
                i = aux;
                break;
            }        
        }
        if (j == NULL){ //foi até a cabeça da lista

            aux = i->prev;
            swap(lista, NULL, i);
            i = aux;
        } 

    }

}

void adicionaElementoInsertionSort(Lista *lista, ItemLista *elemento){
    //for percorrendo a lista, de trás pra frente (tail para head), até encontrar a posição do elemento.
        //apos encontrar a posição adiciona o elemento.

}

int main(){

    Lista *lista = NULL;
    
    lista = (Lista * ) malloc (sizeof(Lista)); //aloca espaço para a lista
    lista->head = NULL;
    lista->tail = NULL;
    
    
    criaLista(lista, 15);


    
    
    printf("Primeiro elemento %d;\n Ultimo Elemento: %d\n\n", lista->head->valor, lista->tail->valor);

    printf("Ordem de inserção: \n");
    imprimeLista(lista, 1);

    printf("\n\n COmeço da ordenação\n");
    insertionSort(lista);
    printf("\n\n Fim da ordenação\n");

    printf("\nApós adicionar o -23: \n");
    imprimeLista(lista, 1);
    printf("\n");

    return 0;
}