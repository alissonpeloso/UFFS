#include <stdio.h>
#include <stdlib.h>
#include "double.h"

int main(){
  no *Root = malloc(sizeof(no));
  int size_list;
  printf("Bem-vindo! Qual o tamanho da lista desejada?\n");
  scanf("%d", &size_list);

  for(int i=0; i<size_list; i++){
    Scan_node(Root);
  }
  Print_Node(Root);

  int command = 1;
  while(command != 0){
    printf("O que desejas fazer?\n\n1 - Adicionar nodo;\n2 - Excluir nodo;\n3 - Buscar posição do nodo;\n0 - Sair\n");
    scanf("%d", &command);
    if(command == 1){
      Scan_node(Root);
      Print_Node(Root);
    }
    if(command == 2){
      Print_Node(Root);
      Scan_Del_Node(Root);
      Print_Node(Root);

    }
    if(command == 3){
      int number;
      printf("Insira o conteúdo no nodo: ");
      scanf("%d", &number );
      int solve = Search_Node(Root, number);
      printf("Posição do nodo buscado: %d\n", solve);
      printf("\n");
    }
    if(command == 0){
      break;
    }
  }
  Clear_List(Root);
}
