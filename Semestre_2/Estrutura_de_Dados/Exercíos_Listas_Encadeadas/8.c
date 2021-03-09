#include <stdio.h>
#include <stdlib.h>
#include "simple.h"

//arrumar o Simetric

int main(){
  no *Root = malloc(sizeof(no));
  Binary_list_queue(Root);
  Print_Node(Root);

  printf("Texto invertido: ");
  Print_data_Inverse(Root);
  printf("\n");

  int check = Simetric(Root);
  if (Simetric(Root) == 1){
    printf("É um palíndromo\n");
  }
  else{
    printf("Não é um palíndromo\n");
  }
  Clear_List(Root);
}
