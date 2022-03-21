#include <string.h>

struct circlenode{
  int numb;
  char name[100];
  struct circlenode *next;
  struct circlenode *previous;
};

typedef struct circlenode no;

int Size_List(no *Root){
  no *sub = Root;
  int size_no = 0;
  if(Root->next == NULL){
    return size_no;
  }
  do{
      size_no += 1;
      Root = Root->next;
  } while(Root != sub->previous);
  return size_no;
}

no *Gets_Node(no *Root, int position){
  int count = 0;
  no *p = Root;
  if(position > Size_List(p)){
      return NULL;
      }

  else if(position <= 0){
    return Root;
  }

  else{
    while(p){
      if(position==count){
        return p;
      }
      p = p->next;
      count++;
    }
  }
}

void Print_Node(no *Root){
  int size = Size_List(Root);
  printf("\tMostrando a Lista:\n");
  printf("N   | P              | Previous       | Next           | Data | Name         \n");
  printf("-----------------------------------------------------------------------------\n");
  int count = 0;
  if(Root->next != NULL){
    printf("%3d | %14p | %14p | %14p | %5d | %14s\n", count++, Root, Root->previous, Root->next, Root->numb, Root->name);
    printf("-----------------------------------------------------------------------------\n");
    Root = Root->next;
    do{
      printf("%3d | %14p | %14p | %14p | %5d | %14s\n", count++, Root, Root->previous, Root->next, Root->numb, Root->name);
      Root = Root->next;
    }while(count <= size);
    printf("\n\n");
  }
  else
    printf("Lista Vazia\n");
}

no *Add_Node(no *Root, int position, int numb, char *name){
  no *new_node = malloc(sizeof(no));
  no *previous_node;
  no *pushed_node;
  int size = Size_List(Root);

  if (position <= 0){
    position = 1;
  }

  if(size == 0){
    Root->next = new_node;
    Root->previous = new_node;
    previous_node = new_node;
    pushed_node = new_node;
  }

  else if(Gets_Node(Root, position) == NULL){
    pushed_node = Root->next;
    previous_node = Root->previous;
    previous_node->next = new_node;
    pushed_node->previous = new_node;
    Root->previous = new_node;
  }

  else if(position == 1){
    pushed_node = Root->next;
    previous_node = Root->previous;
    previous_node->next = new_node;
    pushed_node->previous = new_node;
    Root->next = new_node;
  }

  else{
    pushed_node = Gets_Node(Root, position);
    previous_node = pushed_node->previous;
    previous_node->next = new_node;
    pushed_node->previous = new_node;
  }

  new_node->next = pushed_node;
  new_node->previous = previous_node;
  new_node->numb = numb;
  strcpy(new_node->name ,name);

  return new_node;
}

void Scan_node(no *Root){
  int position;
  int numb;
  char name[100];
  printf("Insira a posição do nodo: ");
  scanf("%d", &position);
  printf("Insira o valor do nodo: ");
  scanf("%d", &numb);
  printf("Insira o nome do nodo: ");
  scanf("%s", name);
  Add_Node(Root, position, numb, name);
}

void Delete_Node(no *Root, int position){
  if(position > Size_List(Root)){
    printf("Insira uma posição válida!\n");
    return;
  }
  no *deleted_node = Gets_Node(Root, position);
  if ((deleted_node == NULL) || (deleted_node == Root)){
    return;
  }

  no *previous_node = deleted_node->previous;
  no *next_node = deleted_node->next;
  if (deleted_node == Root->next){
    Root->next = next_node;
  }
  if(position == Size_List(Root)){
    Root->previous = previous_node;
  }
  previous_node->next = next_node;
  next_node->previous = previous_node;
  free(deleted_node);
}

void Scan_Del_Node(no *Root){
  int position;
  printf("Insira a posição do nodo que deseja excluir: ");
  scanf("%d", &position);
  Delete_Node(Root, position);
}

void Clear_List(no *Root){
  while(Root->next != NULL){
    Delete_Node(Root,1);
  }
  free(Root);
}

char *Search_Name(no *Root, int number){
  int size = Size_List(Root);
  no *sub = Root;
  for(int count = 0; count <= size; count++){
    if(sub->numb == number){
      return sub->name;
    }
    sub = sub->next;
  }
  printf("Valor não encontrado!\n");
}

void Copy_List(no *Root, no *Newlist){
  no *sub = Root;
  int size = Size_List(Root);
  sub = sub->next;
  for (int i = 0; i < size; i++){
    int numb = sub->numb;
    //char *name;
    //strcpy(sub->name, name);
    printf("a\n");
    Add_Node(Newlist, size, numb, sub->name);

    sub = sub->next;
  }
}
