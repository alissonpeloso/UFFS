#include <stdio.h>
#include <stdlib.h>

//Estrutura base do nó.
struct Node
{
    int nData;
    struct Node *proximo;
};

typedef struct Node node;

int Size_Nodo(node *pRaiz){
    int size_nodos = -1;
    while(pRaiz){
        size_nodos += 1;
        pRaiz = pRaiz->proximo;
    }
    return size_nodos;
}

//Função pra inserir nó no Início.
void Insert_init(node *nome, node *pRaiz){
    nome = (node*) malloc(sizeof(node*));
    nome->proximo = pRaiz->proximo;
    pRaiz->proximo = nome;
    int a;
    printf("Insira o valor do primeiro nó: ");
    scanf("%d", &a);
    nome->nData = a;
}

//Função pra inserir nó no Final.
void Insert_end(node *nome, node *pRaiz){
    nome = (node*) malloc(sizeof(node*));
    while(pRaiz){
        if(pRaiz->proximo == NULL){
            pRaiz->proximo = nome;
            int a;
            printf("Insira o valor do último nó: ");
            scanf("%d", &a);
            nome->nData = a;
            break;
        }
        pRaiz = pRaiz->proximo;
    }

}

//Função pra inserir nó no Meio.
void Insert_between(node *nome, node *pAnt){
    nome = (node*) malloc(sizeof(node*));
    nome->proximo = pAnt->proximo;
    pAnt->proximo = nome;
    int a;
    printf("Insira o valor do nó a ser criado: ");
    scanf("%d", &a);
    nome->nData = a;
}

//Função pra excluir nó no Início.
void Del_init(node *pRaiz){
    pRaiz->proximo = pRaiz->proximo->proximo;
}

//Função pra excluir nó no Fim.
void Del_end(node *pRaiz){
    while(pRaiz){
        if (pRaiz->proximo->proximo == NULL){
            pRaiz->proximo = NULL;
            break;
        }
        pRaiz = pRaiz->proximo;
    }
}

//Função pra excluir nó no Meio.
void Del_mid(node *pRaiz, node *p){
    while(pRaiz){
        if(pRaiz->proximo == p){
            pRaiz->proximo = p->proximo;
            break;
        }
        else{pRaiz = pRaiz->proximo;}
    }
}


//Função pra printar o nó na tela.
void displayLL(node *p){
    printf("Mostrando a lista:\n");
    if(p)
    {
        do
        {
            printf(" %d", p->nData);
            p=p->proximo;
        }
        while(p);
    }
    else
        printf("Lista vazia.");
}

void Print_Nodo_Reverse(node* pRaiz,int Size){
    printf("Mostrando a lista reversa:\n");
    int vetor_data[Size];
    for (int position = Size; position>0; position--){
        vetor_data[position] = pRaiz->nData;
        pRaiz = pRaiz->proximo;
        }
    for (int position = 1; position<Size+1; position++){
        printf("%d ", vetor_data[position]);
        }
}

int main(void)
{
    node *pRaiz = NULL;
    node *pNode1 = NULL;
    node *pNode2 = NULL;
    node *pNode3 = NULL;

    //Criando os nos e associando os dados.
    pRaiz = (node*) malloc(sizeof(node*));

    pNode1 = (node*) malloc(sizeof(node*));
    pNode1->nData = 10;

    pNode2 = (node*) malloc(sizeof(node*));
    pNode2->nData = 20;

    pNode3 = (node*) malloc(sizeof(node*));
    pNode3->nData = 30;

    //Conectando os nós
    pRaiz->proximo = pNode1;
    pNode1->proximo = pNode2;
    pNode2->proximo = pNode3;
    pNode3->proximo = NULL;
    node *pNodePrime = NULL;
    node *pNodeUltimate = NULL;
    node *pNodeMid = NULL;

    printf("%d\n", Size_Nodo(pRaiz));

    //Teste 1:
    Insert_init(pNodePrime, pRaiz);

    if(pRaiz)
        displayLL(pRaiz->proximo);
        printf("\n");

    //Teste 2 :
    Insert_end(pNodeUltimate, pRaiz);

    if(pRaiz)
        displayLL(pRaiz->proximo);
        printf("\n");

    //Teste 3 :
    Insert_between(pNodeMid, pNode2);

    if(pRaiz)
        displayLL(pRaiz->proximo);
        printf("\n");

    //Teste 4:
    Del_init(pRaiz);
    Del_end(pRaiz);
    Del_mid(pRaiz, pNode2);

    if(pRaiz)
        displayLL(pRaiz->proximo);
        printf("\n");
        Print_Nodo_Reverse(pRaiz->proximo, Size_Nodo(pRaiz));
        printf("\n");


    //Mostrando a lista.
    //if(pRaiz)
        //displayLL(pRaiz->proximo);

  free(pNode1);
  free(pNode2);
  free(pNode3);
  free(pNodePrime);
  free(pNodeUltimate);
  free(pNodeMid);

  return 0;
}
