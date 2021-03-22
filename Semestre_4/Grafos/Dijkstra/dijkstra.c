// Autor: Alisson Luan de Lima Peloso
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printDijkstra(int **matDij, int n, int visiting){
    printf("\tvert.\t|\tknown\t|\tcost\t|\tpath\t|\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++){
            if(matDij[i][j] == INT_MAX){
                printf("\tINF\t|");
            }
            else{
                printf("\t%d\t|", matDij[i][j]);
            }
        }
        if(i == visiting && visiting > -1 && visiting < n){
            printf(" <- visiting");
        }
        printf("\n");
    }
}

int smallest(int **matDij, int n){
    int small = INT_MAX;
    int position;
    for(int i = 0; i<n; i++){
        if (matDij[i][1] != 1 && matDij[i][2] < small){
            small = matDij[i][2];
            position = i;
        }
    }
    if(small == INT_MAX){
        return -1;
    }
    return position;
}

void dijkstra(int **matAdj, int **matDij, int n, int startValue){
    int i = startValue;
    matDij[i][2] = 0;
    while(i < n){
        printf("\n\n****************************** Visitando o vértice %d ******************************\n\n", i);
        matDij[i][1] = 1;

        for(int j = 0; j < n; j++){
            if(matAdj[i][j] != 0 && matDij[j][1] != 1 && (matAdj[i][j] + matDij[i][2]) < matDij[j][2]){
                matDij[j][2] = matAdj[i][j] + matDij[i][2];
                matDij[j][3] = i;
            }
        }

        printDijkstra(matDij, n, i);

        int small = smallest(matDij, n);
        if(small == -1 || small > n){
            return;
        }
        i = small;
    }
}

int main(){
    int ** matAdj;
    int ** matDij;
    int n;
    printf("Insira o número de vértices: ");
    scanf("%d", &n);

    matAdj = (int **) malloc(sizeof(int *)*n);
    for(int i = 0; i < n; i++){
        matAdj[i] = malloc(sizeof(int)*n);
    }

    matDij = (int **) malloc(sizeof(int *)*n);
    for(int i = 0; i < n; i++){
        matDij[i] = malloc(sizeof(int)*4);
        matDij[i][0] = i;
        matDij[i][1] = 0;
        matDij[i][2] = INT_MAX;
        matDij[i][3] = -1;
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
    printf("Insira o valor inicial desejado: ");
    scanf("%d", &startValue);

    dijkstra(matAdj, matDij, n, startValue);

    printf("\n\n****************************** Dijkstra ******************************\n\n");

    printDijkstra(matDij, n, -1);
}