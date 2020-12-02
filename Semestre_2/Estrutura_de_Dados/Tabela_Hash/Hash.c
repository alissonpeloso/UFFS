#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estrutura base do nó->
struct Node
{
  int valor;
  struct Node *proximo;
};

typedef struct Node node;

// funcao que retorna o ultimo digito do numero como chave de hash
int hash(int codigo)
{
  int chave = codigo;
  while (chave >= 10)
  {
    chave = chave % 10;
  }
  return chave;
}

// imprime a lista na posicao da chave hash
void displayLL(int chave, node *p)
{
  int i;
  printf("\nposicao %d:", chave);
  if (p)
  {
    do
    {
      printf(" %d ", p->valor);
      p = p->proximo;
    } while (p);
  }
  else
    printf("nodo vazio.");
}

void Add_hash(node *pos_list, int code)
{
  if (pos_list == NULL){
    pos_list = malloc(sizeof(node));
    pos_list->valor = code;
    printf("%d\n", pos_list->valor);
    pos_list->proximo = NULL;
  }
  else{
    node *new = malloc(sizeof(node));
    new->valor = code;
    while(pos_list){
      if(pos_list->proximo == NULL){
        pos_list->proximo = new;
        break;
      }
      pos_list = pos_list->proximo;
    }
  }
}

int main(void)
{
  int tamanho_da_tabela_hash = 10;
  node *tabela_hash[tamanho_da_tabela_hash];
  for (int i = 0; i < tamanho_da_tabela_hash; i++)
  {
    tabela_hash[i] = NULL;
  }

  // criando o primeiro nodo na tabela hash
  int codigo1 = 100112345;
  int chave1 = hash(codigo1);

  // criando o primeiro nodo na tabela hash
  tabela_hash[chave1] = (node *)malloc(sizeof(node));
  tabela_hash[chave1]->valor = codigo1;
  tabela_hash[chave1]->proximo = NULL;

  // informacoes para inserir o segundo nodo
  int codigo2 = 100154321;
  int chave2 = hash(codigo2);

  // criando o segundo nodo na tabela hash
  tabela_hash[chave2] = (node *)malloc(sizeof(node));
  tabela_hash[chave2]->valor = codigo2;
  tabela_hash[chave2]->proximo = NULL;

  // teste 1
  int codigo3 = 11121541;
  int chave3 = hash(codigo3);
  if (tabela_hash[chave3] == NULL){
    tabela_hash[chave3] = (node *) malloc(sizeof(node));
    tabela_hash[chave3]->valor = codigo3;
    printf("%d\n", tabela_hash[chave3]->valor);
    tabela_hash[chave3]->proximo = NULL;
  }
  else{
    node *new = malloc(sizeof(node));
    new->valor = codigo3;
    while(tabela_hash[chave3]){
      if(tabela_hash[chave3]->proximo == NULL){
        tabela_hash[chave3]->proximo = new;
        break;
      }
      tabela_hash[chave3] = tabela_hash[chave3]->proximo;
    }
  }

  // imprimindo toda a estrutura
  for (int i = 0; i < 10; i++)
  {
    if (tabela_hash[i])
    {
      displayLL(i, tabela_hash[i]);
    }
    else
    {
      printf("\nposicao %d, nodo vazio", i);
    }
  }

  return 0;
}
