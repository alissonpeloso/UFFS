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

void insert(node *tabela_hash[], int code)
{
    int key = hash(code);

    if (!tabela_hash[key]){
        tabela_hash[key] = (node *)malloc(sizeof(node));
        tabela_hash[key]->valor = code;
        tabela_hash[key]->proximo = NULL;
      } else {
        node *sub = tabela_hash[key];
        while(sub->proximo)
        {
            sub = sub->proximo;
        }
        node *new = (node *)malloc(sizeof(node));
        new->proximo = NULL;
        new->valor = code;
        sub->proximo = new;
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
  node *sub = tabela_hash[key];
  if(tabela_hash[key] == NULL){
    printf("Insira um valor válido!\n");
    return;
  }
  if(tabela_hash[key]->valor == code){
    if(tabela_hash[key]->proximo == NULL){
      tabela_hash[key] = NULL;
      return;
    }
    else{
      tabela_hash[key]= tabela_hash[key]->proximo;
      return;
    }
  }
  else{
    while(sub){
      if(sub->proximo == NULL){
        printf("Insira um valor válido!\n\n");
        return;
      }
      if(sub->proximo->valor == code){
        sub->proximo = sub->proximo->proximo;
        return;
      }
      sub=sub->proximo;
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
  printf("N   | P              | Next           | Data \n");
  printf("---------------------------------------------\n");
  if (p){
    int count = 0;
    do{
      printf("%3d | %14p | %14p | %d\n", count++, p, p->proximo, p->valor);
      p = p->proximo;
    } while (p);
  }
  else
    printf("nodo vazio.");
}
