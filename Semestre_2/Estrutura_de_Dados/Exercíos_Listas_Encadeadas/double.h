struct doublenode{
  int numb;
  struct doublenode *next;
  struct doublenode *previous;
};

typedef struct doublenode no;

int Size_List(no *Root){
    int size_no = 0;
    Root = Root->next;
    while(Root){
        size_no += 1;
        Root = Root->next;
    }
    return size_no;
}

void Print_Node(no *Root){
  printf("\tMostrando a Lista:\n");
  printf("N   | P              | Previous       | Next           | Data \n");
  printf("--------------------------------------------------------------\n");
  int count = 0;
  if(Root){
    printf("%3d | %14p | %14p | %14p | %5d |\n", count++, Root, Root->previous, Root->next, Root->numb);
    printf("--------------------------------------------------------------\n");
    Root = Root->next;
    while(Root){
      printf("%3d | %14p | %14p | %14p | %5d |\n", count++, Root, Root->previous, Root->next, Root->numb);
      Root = Root->next;
    }
    printf("\n\n");
  }
  else
    printf("Lista Vazia\n");
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

no *Add_Node(no *Root, int position, int numb){
  no *new_node = malloc(sizeof(no));
  no *previous_node;
  no *pushed_node;
  if (position <= 0){
    position = 1;
  }
  pushed_node = Gets_Node(Root, position);
  if (pushed_node == NULL){
    previous_node = Root->previous;
    Root->previous = new_node;
  }
  else{
    previous_node = pushed_node->previous;
    pushed_node->previous = new_node;
  }
  if (Root->next == pushed_node){
    Root->next = new_node;
  }
  if (previous_node != NULL){
    previous_node->next = new_node;
  }
  new_node->next = pushed_node;
  new_node->previous = previous_node;
  new_node->numb = numb;
  return new_node;
}

void Scan_node(no *Root){
  int position;
  int numb;
  printf("Insira a posição do nodo: ");
  scanf("%d", &position);
  printf("Insira o valor do nodo: ");
  scanf("%d", &numb);
  Add_Node(Root, position, numb);
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
  else{
    previous_node->next = next_node;
  }
  if (deleted_node == Root->previous){
    Root->previous = previous_node;
  }
  else{
    next_node->previous = previous_node;
  }
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

int Search_Node(no *Root, int number){
  no *sub = Root;
  int count = 0;
  while(sub){
    if(sub->numb == number){
      return count;
    }
    sub = sub->next;
    count++;
  }
  printf("Valor não encontrado!\n");
}

void Copy_List(no *Root, no *Newlist){
  Root = Root->next;
  while(Root){
    Add_Node(Newlist, Size_List(Newlist)+1, Root->numb);

    Root = Root->next;
  }
}

void Copy_Inverse(no *Root, no *Newlist){
  no *sub = Gets_Node(Root, Size_List(Root));
  int count = 0;
  int size = Size_List(Root);
  Root = Root->next;
  while(count < size){
    Add_Node(Newlist, Size_List(Newlist)+1, sub->numb);

    count++;
    sub = sub->previous;
  }
}
