#include <stdio.h>
#include <stdlib.h>
#include "simple.h"

void Solve(no *Root){
  no *sub = Root;
  int position = Size_List(sub);
  for(int i = position; i>0; i--){
    if(i%2 == 0){
      Delete_Node(sub, i);
    }
  }
}

int main(){
  no *Root = malloc(sizeof(no));
  int size_list;
  printf("Bem-vindo! Qual o tamanho da lista desejada?\n");
  scanf("%d", &size_list);

  for(int i=0; i<size_list; i++){
    Scan_node(Root);
  }
  Print_Node(Root);
  Solve(Root);
  Print_Node(Root);

  Clear_List(Root);
}
