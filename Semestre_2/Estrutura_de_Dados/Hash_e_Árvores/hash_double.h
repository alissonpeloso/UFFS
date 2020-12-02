//Estrutura base do nó->
struct Node
{
  int valor;
  struct Node *proximo;
  struct Node *anterior;
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
void displayLL(int chave, node *p){
  int i;
  printf("\nposicao %d:", chave);
  if (p){
    if (p->proximo == p){
      printf(" %d ", p->valor);
    }
    else do{
      printf(" %d ", p->valor);
      p = p->proximo;
    } while (p);
  }
  else
    printf("nodo vazio.");
}

void insert(node *tabela_hash[], int code)
{
    int key = hash(code);
    if (tabela_hash[key] == NULL){
      tabela_hash[key] = (node *)malloc(sizeof(node));
      tabela_hash[key]->valor = code;
      tabela_hash[key]->proximo = tabela_hash[key];
      tabela_hash[key]->anterior = tabela_hash[key];
    }
    else if (tabela_hash[key]->proximo == tabela_hash[key]){
      node *new = malloc(sizeof(node));
      tabela_hash[key]->proximo = new;
      tabela_hash[key]->anterior = new;
      new->proximo = NULL;
      new->anterior = NULL;
      new->valor = code;
    }
    else{
      node *ant = tabela_hash[key]->anterior;
      node *new = malloc(sizeof(node));
      new->anterior = ant;
      ant->proximo = new;
      new->proximo = NULL;
      new->valor = code;
      tabela_hash[key]->anterior = new;
    }
}

void request(node *tabela_hash[])
{
  int number;
  printf("Digite o número que deseja inserir:\n");
  scanf("%d", &number);
  insert(&tabela_hash[0], number);
}

void delete(node *tabela_hash[], int code)
{
  int key = hash(code);
  if (tabela_hash[key] == NULL){
    printf("Insira um valor válido\n\n");
    return;
  }
  if (tabela_hash[key]->proximo == tabela_hash[key]){
    if(tabela_hash[key]->valor == code){
      tabela_hash[key] = NULL;
    }
    else{
      printf("Insira um valor válido\n\n");
    }
    return;
  }
  else{
    if(tabela_hash[key]->valor == code){
        tabela_hash[key]->proximo->anterior = tabela_hash[key]->anterior;
        tabela_hash[key] = tabela_hash[key]->proximo;
        tabela_hash[key]->proximo->anterior = NULL;
        return;
      }
    else{
      node *sub = tabela_hash[key];
      while(sub){
        if(sub->proximo->valor == code){
          sub->proximo = sub->proximo->proximo;
          if(sub->proximo == NULL){
            tabela_hash[key]->anterior = sub;
            if(sub->anterior == sub){
              tabela_hash[key]->proximo = sub;
            }
            return;
          }

          sub->proximo->anterior = sub;
          tabela_hash[key]->anterior = sub->proximo;

          return;
        }
        if(sub->proximo == NULL){
          printf("Insira um valor válido!\n\n");
          return;
        }
        sub=sub->proximo;
      }
    }
  }
}

void request_del(node *tabela_hash[])
{
  int number;
  printf("Digite o número que deseja excluir:\n");
  scanf("%d", &number);
  delete(&tabela_hash[0], number);
}

void print_all(node *tabela_hash[])
{
  printf("Estrutura completa:\n");
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
  }printf("\n\n");
}

void print_address(node *tabela_hash[]){
  int key;
  printf("Qual posição quer imprimir? ");
  scanf("%d", &key);

  node *p = tabela_hash[key];
  printf("\nposicao %d:\n", key);
  printf("N   | P              | Previous       | Next           | Data \n");
  printf("--------------------------------------------------------------\n");
  if (p){
    int count = 0;
    if (p->proximo == p){
      printf("%3d | %14p | %14p | %14p | %d |\n", count++, p, p->anterior, p->proximo, p->valor);
    }
    else do{
      printf("%3d | %14p | %14p | %14p | %d |\n", count++, p, p->anterior, p->proximo, p->valor);
      p = p->proximo;
    } while (p);
  }
  else
    printf("nodo vazio.");
}
