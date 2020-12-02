struct node{
    int numb;
    struct node *next;
};

typedef struct node no;

int Size_List(no *Root){
    int size_no = 0;
    Root = Root->next;
    while(Root){
        size_no += 1;
        Root = Root->next;
    }
    return size_no;
}

void Copy_List(no *Root, no *Newlist){
  Root = Root->next;
  while(Root){
    no *New = malloc(sizeof(no));
    Newlist->next=New;
    New->numb = Root->numb;

    Root = Root->next;
    Newlist = Newlist->next;
  }
}

no *Add_Node(no *Root, int position, int numb){
  no *List = malloc(sizeof(no));
  no *sub = Root;
  List->numb = numb;
  if(position > Size_List(sub)){
    position = Size_List(sub)+1;
  }

  int count = 1;
  while(sub){
    if (count == position){
      List->next = sub->next;
      sub->next = List;
      break;
    }
    sub = sub->next;
    count++;
  }
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

void Print_Node(no *Root){
  printf("\tMostrando a Lista:\n");
  printf("N   | P              | Next           | Data \n");
  printf("---------------------------------------------\n");
  int count = 0;
  if(Root){
    printf("%3d | %14p | %14p | %6d\n", count++, Root, Root->next, Root->numb);
    printf("---------------------------------------------\n");
    Root = Root->next;
    while(Root){
      printf("%3d | %14p | %14p | %6d\n", count++, Root, Root->next, Root->numb);
      Root = Root->next;
    }
    printf("\n");
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

void Delete_Node(no *Root, int position){
  if(position>Size_List(Root)){
    printf("Insira uma posição válida!\n");
    return;
  }
  no *previous = Gets_Node(Root,position-1);
  no *Deletednode = previous->next;
  previous->next = previous->next->next;
  free(Deletednode);
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

void Swap_Node(no *Root, int pos1,int pos2){
  no *aux1 = Gets_Node(Root, pos1);
  no *aux2 = Gets_Node(Root, pos2);
  no *previous1 = Gets_Node(Root, pos1 - 1);
  no *previous2 = Gets_Node(Root, pos2 - 1);
  no *next1 = Gets_Node(Root, pos1 + 1);
  no *next2 = Gets_Node(Root, pos2 + 1);

  if (Size_List(Root) >= 2){
    if (pos2-pos1 == 1){
      aux2->next = aux1;
      aux1->next = next2;
      previous1->next = aux2;
    }

    else if (pos1-pos2 == 1){
      aux1->next = aux2;
      aux2->next  = next1;
      previous2->next = aux1;
    }

    else{
      previous1->next = aux2;
      aux2->next = next1;

      previous2->next = aux1;
      aux1->next = next2;
    }
  }
  else{
    printf("Não é possível realizar essa operação!\n");
  }
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

//--------------Pilha e Fila------------------------------------------------

void  Queue(no *Root, int numb){
  int position = Size_List(Root)+1;
  Add_Node(Root, position, numb);
}

int Unqueue(no *Root){
  int Deleted = Gets_Node(Root, 1)->numb;
  Delete_Node(Root, 1);
  return Deleted;
}

void Stack(no *Root, int numb){
  int position = 1;
  Add_Node(Root, position, numb);
}

int Unstack(no *Root){
  int Deleted = Gets_Node(Root, 1)->numb;
  Delete_Node(Root, 1);
  return Deleted;
}

void Binary_list(no *Root){
  int c;
  printf("Digite uma sequência binária:\n");
  printf("- valores diferentes de 0 e 1 serão ignorados \n");
  printf("- o número 2 encerra a sequência:\n");
  while ((c = getchar()) != EOF)
  {
    c = c - 48;
    if (c == 2)
    {
      break;
    }
    if ((c == 1) || (c == 0))
    {
      Stack(Root, c);
    }
  }
}

void Print_data(no *Root){
  if(Root){
    Root = Root->next;
    while(Root){
      printf("%d", Root->numb);
      Root = Root->next;
    }
    printf("\n");
  }
  else
    printf("Lista Vazia\n");
}

int Simetric(no *Root){
  int pos_left = 1;
  int pos_right = Size_List(Root);
  while ((pos_left != pos_right) && pos_left-1 != pos_right){
    no *left_node = Gets_Node(Root, pos_left);
    no *right_node = Gets_Node(Root, pos_right);
    if (left_node->numb != right_node->numb){
      return 0;
    }
    pos_left++;
    pos_right--;
  }
  return 1;
}

void Binary_list_queue(no *Root){
  int c;
  printf("Digite uma sequência binária:\n");
  printf("- valores diferentes de 0 e 1 serão ignorados \n");
  printf("- o número 2 encerra a sequência:\n");
  while ((c = getchar()) != EOF)
  {
    c = c - 48;
    if (c == 2)
    {
      break;
    }
    if ((c == 1) || (c == 0))
    {
      Queue(Root, c);
    }
  }
}

void Print_data_Inverse(no *Root){
  if(Root){
    for (int size = Size_List(Root); size > 0; size-- ){
      no *sub = Gets_Node(Root, size);
      printf("%d", sub->numb);
    }
    printf("\n");
  }
  else
    printf("Lista Vazia\n");
}

void Unstack_key(no *Root, no *Aux, int key){
  int size_root = Size_List(Root);
  no *sub = Root;
  for(int pos = 0; pos<size_root; pos++){
    int Deleted = Gets_Node(sub, 1)->numb;
    Delete_Node(sub, 1);
    if (Deleted == key){
      break;
    }
    Stack(Aux, Deleted);
  }
  int size_aux = Size_List(Aux);
  for( int pos_aux = 0; pos_aux < size_aux; pos_aux++){
    int numb_aux = Gets_Node(Aux, 1)->numb;
    Stack(Root, numb_aux);
    Aux = Aux->next;
  }
}
