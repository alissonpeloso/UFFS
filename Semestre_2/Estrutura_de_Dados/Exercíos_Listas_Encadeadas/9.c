#include <stdio.h>
#include <stdlib.h>
#include "simple.h"

int main(){
  no *Root = malloc(sizeof(no));
  int command;

  while(command != 4){
    printf("O que desejas fazer?\n\n1 - Adicionar um nodo;\n2 - Remover um nodo;\n3 - Imprimir os valores da lista;\n4 - Sair;\n");
    scanf("%d", &command);

    if (command == 1){
      int numb;
      printf("Insira o valor do nodo: ");
      scanf("%d", &numb);
      Stack(Root, numb);
    }

    if (command == 2){
      int key;
      no *Aux = malloc(sizeof(no));
      printf("Insira o valor do nodo a ser excluido: ");
      scanf("%d", &key);
      Unstack_key(Root, Aux, key);
    }

    if (command == 3){
      Print_Node(Root);
    }
  }
}
