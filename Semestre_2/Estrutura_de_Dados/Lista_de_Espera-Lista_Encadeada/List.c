#include <stdio.h>
#include <stdlib.h>

struct Patient{
    int ID;
    char Name[100];
    struct Patient *next;
};

typedef struct Patient pat;

int Size_Nodo(pat *Raiz){
    int size_pat = 0;
    while(Raiz){
        size_pat += 1;
        Raiz = Raiz->next;
    }
    return size_pat;
}

void displayLL(pat *p){
    printf("\n");
    printf("\t Mostrando a lista:\n");
    printf("\n");
    printf("\t Pos |  ID   | Name\n");
    int position = 1;
    if(p)
    {
        p=p->next;
        while(p){
            printf("\t ----+-------+--------\n");
            printf(" \t %03d | %05d | %s \n", position, p->ID, p->Name);
            position++;
            p=p->next;
        }

    }
    else
        printf("Lista vazia.\n");
    printf("\n");
}

void add_Pat(pat *Raiz){
    int position;
    pat *list;
    list =  malloc(sizeof(pat));
    printf("Número da Posição onde deseja inserir: ");
    scanf("%d", &position);
    printf("Insira o nome do Paciente: ");
    scanf("%s", &list->Name);
    printf("Insira o ID do Paciente: ");
    scanf("%d", &list->ID);

    if (position > Size_Nodo(Raiz)){
      position = Size_Nodo(Raiz);
      int count = 1;
      while (Raiz) {
        if (count == position){
          list->next = Raiz->next;
          Raiz->next = list;
          break;
        }
        Raiz = Raiz->next;
        count++;
      }
    }

    else{
      int count = 1;
      while (Raiz) {
        if (count == position){
          list->next = Raiz->next;
          Raiz->next = list;
          break;
        }
        Raiz = Raiz->next;
        count++;
      }
    }

}

void remove_Pat(pat *Raiz){
  int position;
  printf("Número da Posição onde deseja excluir: ");
  scanf("%d", &position);

  if (position > Size_Nodo(Raiz)){
    printf("Insira uma posição válida\n");
  }

  else{
    int count = 1;
    while (Raiz) {
      if (count == position){
        Raiz->next = Raiz->next->next;
        break;
      }
      Raiz = Raiz->next;
      count++;
    }
  }

  }

int main(){
    pat *pRaiz = malloc(sizeof(pat));
    int command = 0;

    while(command =! NULL){
      printf("Utilize o menu para interagir com a lista de espera:\n 1 - Adicionar paciente na lista;\n 2 - Remover paciente da lista;\n 3 - Mostrar Lista;\n 4 - Sair do programa;\n\n ");
      scanf("%d", &command);

      if (command == 1){
        add_Pat(pRaiz);
        displayLL(pRaiz);
      }

      else if (command == 2){
        remove_Pat(pRaiz);
        displayLL(pRaiz);
      }

      else if (command == 3){
        displayLL(pRaiz);
      }

      else if (command == 4){
        break;
      }

      else{
        printf("Insira um valor válido!\n\n");
        command = 0;
      }
    }
}
