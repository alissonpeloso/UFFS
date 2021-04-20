// Autor: Alisson Luan de Lima Peloso
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printPrim(int **matControl, int n, int visiting){
    printf("\tvert\t|\tknown\t|\tcost\t|\tpath\t|\n");
    printf("----------------+---------------+---------------+---------------|\n");

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++){
            if(matControl[i][j] == INT_MAX){
                printf("\tINF\t|");
            }
            else{
                printf("\t%d\t|", matControl[i][j]);
            }
        }
        if(i == visiting && visiting > -1 && visiting < n){
            printf(" ← visiting");
        }
        printf("\n");
    }
}

int smallest(int **matControl, int n){
    int small = INT_MAX;
    int position;
    for(int i = 0; i<n; i++){
        if (matControl[i][1] != 1 && matControl[i][2] < small){
            small = matControl[i][2];
            position = i;
        }
    }
    if(small == INT_MAX){
        return -1;
    }
    return position;
}

void prim(int **matAdj, int **matControl, int n, int startValue){
    int i = startValue;
    matControl[i][2] = 0;
    while(i < n){
        printf("\n\n****************************** Visitando o vértice %d ******************************\n\n", i);
        matControl[i][1] = 1;

        for(int j = 0; j < n; j++){
            if(matAdj[i][j] != 0 && matControl[j][1] != 1 && matAdj[i][j] < matControl[j][2]){
                matControl[j][2] = matAdj[i][j];
                matControl[j][3] = i;
            }
        }

        printPrim(matControl, n, i);

        int small = smallest(matControl, n);
        if(small == -1 || small > n){
            return;
        }
        i = small;
        getc(stdin);
    }
}

int main(){
    int ** matAdj;
    int ** matControl;
    int n;
    printf("Insira o número de vértices: ");
    scanf("%d", &n);

    matAdj = (int **) malloc(sizeof(int *)*n);
    for(int i = 0; i < n; i++){
        matAdj[i] = malloc(sizeof(int)*n);
    }

    matControl = (int **) malloc(sizeof(int *)*n);
    for(int i = 0; i < n; i++){
        matControl[i] = malloc(sizeof(int)*4);
        matControl[i][0] = i;
        matControl[i][1] = 0;
        matControl[i][2] = INT_MAX;
        matControl[i][3] = -1;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("Inira o valor %d, %d: ", i,j);
            scanf("%d", &matAdj[i][j]);
        }
    }

    printf("\n\n****************************** Matriz ******************************\n\n");

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d\t|", matAdj[i][j]);
        }
        printf("\n");
    }

    int startValue;
    printf("\nInsira o valor inicial desejado: ");
    scanf("%d", &startValue);

    prim(matAdj, matControl, n, startValue);

    printf("\n\n****************************** Prim ******************************\n\n");

    printPrim(matControl, n, -1);

    int cost = 0;
    printf("\nArestas da árvore geradora mínima:\n\t");
    for(int i = 0; i < n; i++){
        cost+=matControl[i][2];
        if(matControl[i][3] == -1){

        }
        else{
            printf("(%d,%d) ", matControl[i][0], matControl[i][3]);
        }
    }
    printf("\n\n\tCusto Total: %d\n", cost);
}