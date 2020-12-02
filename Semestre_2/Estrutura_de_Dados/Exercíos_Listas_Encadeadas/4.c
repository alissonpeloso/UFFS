#include <stdio.h>
#include <stdlib.h>
#include "double.h"

void Solve_1(no *ListA){
  no *sub = ListA;
  int size = Size_List(sub);
  no *onefake = Gets_Node(sub, 1);
  no *twofake = Gets_Node(sub, 2);
  onefake->previous = Gets_Node(sub, size);
  Gets_Node(sub, size)->next = Gets_Node(sub, 1);
  onefake->next = NULL;
  sub->next = twofake;
  sub->previous = onefake;
  twofake->previous = NULL;
}

void Solve_2(no *ListB){
  //Usei o Copy inverse pra aproveitar o ponteiro do previous!
}

void Solve_3(no *ListC){
  no *sub = ListC;
  int size = Size_List(sub);
  if(size%2 == 0){
    int first = 1, last = Size_List(sub);
    for(int i=0; i<size/2 ; i++){
      Gets_Node(sub, first)->numb += Gets_Node(sub, last)->numb;
      Delete_Node(sub, last);
      first++;
      last--;
    }

  }
  else{
    printf("Insira uma lista de tamanho par!\n");
  }
}

int main(){
  no *Root = malloc(sizeof(no));
  no *ListA = malloc(sizeof(no));
  no *ListB = malloc(sizeof(no));
  no *ListC = malloc(sizeof(no));

  int size_l;
  printf("Bem-vindo! Insira o tamanho da lista desejada: ");
  scanf("%d", &size_l);

  for(int i =0; i < size_l; i++){
    Scan_node(Root);
  }

  Print_Node(Root);

  Copy_List(Root, ListA);
  Copy_Inverse(ListA,ListB);
  Copy_List(ListA,ListC);

  Solve_1(ListA);
  Print_Node(ListA);

  Solve_2(ListB);
  Print_Node(ListB);

  Solve_3(ListC);
  Print_Node(ListC);

  Clear_List(Root);
  Clear_List(ListA);
  Clear_List(ListB);
  Clear_List(ListC);

}
