// Autor: Alisson Luan de Lima Peloso

#include "BFS.h"
#include "DFS.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    int ** matAdj;
    int n;
    printf("Insira o número de vértices: ");
    scanf("%d", &n);

    //Criando a Matriz de adjacencia
    matAdj = (int **) malloc(sizeof(int *)*n);
    for(int i = 0; i < n; i++){
        matAdj[i] = malloc(sizeof(int)*n);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("Inira o valor %d, %d: ", i,j);
            scanf("%d", &matAdj[i][j]);
        }
    }

    printf("\n****************************** Matriz ******************************\n");

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d\t|", matAdj[i][j]);
        }
        printf("\n");
    }

    printf("\n*******************************************************************\n");

    int origin = -1;
        while(origin == -1){
        printf("Insira o vértice incial para busca: ");
        scanf("%d", &origin);

        if(origin >= n || origin < 0){
            printf("ERRO: Insira um vértice válido!\n");
            origin = -1;
        }
    }

    int destiny = -1;
        while(destiny == -1){
        printf("Insira o vértice que você deseja buscar: ");
        scanf("%d", &destiny);

        if(destiny >= n || destiny < 0){
            printf("ERRO: Insira um vértice válido!\n");
            destiny = -1;
        }
    }

    int choice = 0;
    printf("Selecione a opção desejada:\n1) Realizar busca em largura (BFS);\n2) Realizar busca em profundidade (DFS);\n3) Realizar com as duas operações de busca;\nOu digite 0 (zero) para sair; \nInsira a opção aqui: ");
    scanf("%d", &choice);

    //Criando a Matriz de controle do BFS
    int ** matBFS;

    //Criando a Matriz de controle do DFS
    int ** matDFS;

    switch (choice){
    case 1:
        bfs(matAdj, matBFS, n, origin, destiny);
    break;

    case 2:
        dfs(matAdj, matDFS, n, origin, destiny);
    break;

    case 3:
        bfs(matAdj, matBFS, n, origin, destiny);
        dfs(matAdj, matDFS, n, origin, destiny);
    break;

    default:
        exit(0);
    }    
}