#include <stdio.h>
#include <stdlib.h>
#include "simple.h"

int main(){
  no *stack = malloc(sizeof(no));
  no *queue = malloc(sizeof(no));
  int command;

  while(command != 5){
    printf("O que desejas fazer?\n\n1 - Ler um valor;\n2 - Remover um elemento da pilha e colocar na fila;\n3 - Remover um elemento da fila e colocar na pilha;\n4 - Imprimir os valores da lista;\n5 - Sair;\n");
    scanf("%d", &command);

    if(command == 1){
      int numb;
      printf("Insira o número: ");
      scanf("%d", &numb);
      if(numb>0){
        Stack(stack, numb);
      }
      else if(numb < 0){
        Queue(queue, numb);
      }
      else{
        printf("Insira um valor válido!\n");
        return 0;
      }
    }

    if(command == 2){
      if(Size_List(stack) > 0){
        int deleted = Unstack(stack);
        Queue(queue, deleted);
      }
      else{
        printf("Primeiro insira um valor na pilha!\n");
      }
    }
    if(command == 3){
      if (Size_List(queue) > 0){
        int deleted = Unqueue(queue);
        Stack(stack, deleted);
      }
      else{
        printf("Primeiro insira um valor na fila!\n");
      }

    }
    if(command == 4){
      printf("Fila:\n");
      Print_Node(queue);
      printf("Pilha:\n");
      Print_Node(stack);
    }

  }
  Clear_List(queue);
  Clear_List(stack);
}
