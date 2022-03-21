#include <stdio.h>
#include <stdlib.h>
#include "simple.h"

void Solve_1(no *ListA){
  no *sub = ListA;
  int size = Size_List(sub);
  no *onefake = Gets_Node(sub, 1);
  Gets_Node(sub, size)->next = Gets_Node(sub, 1);
  sub->next = sub->next->next;
  onefake->next = NULL;
}

void Solve_2(no *ListB){
  no *sub = ListB;
  if(Size_List(sub)%2 == 0){
    int first = 1, last = Size_List(sub);
    for(int i=0; i<(Size_List(ListB)/2) ; i++){
      Swap_Node(sub, first, last);
      first++;
      last--;
    }
  }
  else{
    int first = 1, last = Size_List(sub);
    for(int i=0; i<((Size_List(ListB)-1)/2);i++){
      Swap_Node(sub, first, last);
      first++;
      last--;
    }
  }
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
    return;
  }
  Print_Node(ListC);
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
  Copy_List(ListA,ListB);
  Copy_List(ListA,ListC);

  Solve_1(ListA);
  printf("Solução 1: \n" );
  Print_Node(ListA);

  Solve_2(ListB);
  printf("Solução 2: \n" );
  Print_Node(ListB);

  printf("Solução 3: \n");
  Solve_3(ListC);

  Clear_List(Root);
  Clear_List(ListA);
  Clear_List(ListB);
  Clear_List(ListC);

}
