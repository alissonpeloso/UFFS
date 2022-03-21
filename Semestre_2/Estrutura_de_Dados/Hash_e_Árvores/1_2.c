#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

int main(void)
{
    int tamanho_da_tabela_hash = 10;
    node *tabela_hash[tamanho_da_tabela_hash];
    for (int i = 0; i < tamanho_da_tabela_hash; i++)
    {
        tabela_hash[i] = NULL;
    }

    int command = 1;
    while(command)
    {
      printf("Bem-vindo! O que deseja fazer?\n");
      printf("1 - Adicionar nodo na tabela Hash;\n2 - Remover nodo da tabela Hash\n3 - Printar toda a lista;\n-- Pressione 0 para sair --\n");
      scanf("%d", &command);
      if (command == 1)
      {
        request(&tabela_hash[0]);
      }
      else if (command == 2) {
        request_del(&tabela_hash[0]);
      }
      else if (command == 3) {
        print_all(&tabela_hash[0]);
      }
      else if (command == 4){
        print_address(&tabela_hash[0]);
      }
      else if (command == 0) {
        break;
      }
      else
      {
        printf("Insira um valor válido!\n");
      }
    }

    return 0;
}
