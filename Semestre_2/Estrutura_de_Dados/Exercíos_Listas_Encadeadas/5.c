#include <stdio.h>
#include <stdlib.h>
#include "circle.h"

int main(){
  no *Root = malloc(sizeof(no));
  int size_l;

  printf("Bem-vindo! Insira o tamanho da lista desejada: ");
  scanf("%d", &size_l);

  for(int i =0; i < size_l; i++){
    Scan_node(Root);
  }

  Print_Node(Root);

  int command = 1;
  while(command != 0){
    printf("O que desejas fazer?\n\n1 - Buscar um nome dado o valor da chave;\n2 - Inserir um novo elemento na lista mantendo a ordem;\n3 - Remover um elemento da lista;\n4 - Imprimir os valores da lista;\n5 - Copiar lista;\n ");
    scanf("%d", &command);
    if(command == 1){
      int key;
      printf("Insira a Key: ");
      scanf("%d", &key);
      printf("Nome: %s\n", Search_Name(Root, key));
    }
    else if(command == 2){
      Scan_node(Root);
    }
    else if(command == 3){
      Scan_Del_Node(Root);
    }
    else if(command == 4){
      Print_Node(Root);
    }
    else if(command == 5){
      no *Copy = malloc(sizeof(no));
      Copy_List(Root, Copy);
      printf("\tLista original:\n");
      Print_Node(Root);
      printf("\tLista cópia:\n");
      Print_Node(Copy);
    }

  }
  Clear_List(Root);
}
