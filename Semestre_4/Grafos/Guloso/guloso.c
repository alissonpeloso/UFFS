// Implementar um aglritmo guloso que tenta achar um caminho entre dois nodos.
// O algoritmo pode não achar um caminho, mesmo que esse exista (se chegar em um ponto onde não consegue mais avançar deve retornar "Impossível com Guloso", ou se fizer mais que N passos. Verificar se a melhor opção não para o mesmo nodo, se for, pega a segunda melhor).
// O algoritmos deve ser im'plementado sobre uma matriz de adjacência.
// A cada passo o algoritmo deve mostrar as oções que possui e a opção escolhida.

// Autor: Alisson Luan de Lima Peloso

#include <stdio.h>
#include <stdlib.h>

int smallest(int **matriz, int i, int n){
    int small = 2147483647;
    for(int j=0; j < n; j++){
        if(matriz[i][j] < small && matriz[i][j] != 0 && j != i){
            small = matriz[i][j];
        }
    }
    return small;
}

int options(int **matriz, int i, int n, int valDestino){
    int count = 0;
    printf("\n********** Opções Disponíveis **********\n");
    for(int j = 0; j < n; j++){
        if(matriz[i][j] > 0){
            printf("Vértice: %d | Custo: %d\n", j+1, matriz[i][j]);
            count++;
        }
    }
    if(matriz[i][valDestino] > 0){
        return 1;
    }
    if (count == 0){
        printf("Chegamos no Sumidouro. Impossível com o Guloso :(\n");
        return 0;
    }
    return -1;
}

void guloso(int **matriz, int n, int valInício, int valDestino){
    int i = valInício, custoTotal = 0, count = 0;
    while(i < n){
        if(count > n){
            printf("Cansei! Impossível com o guloso :(\n");
            return;
        }
        int opt = options(matriz, i, n, valDestino);
        if (opt == 1){
            printf("\n********** Opção Escolhida **********\n");
            custoTotal+= matriz[i][valDestino];
            printf("Vamos para o vértice %d | Custo Total: %d\n", valDestino+1, custoTotal);
            printf("Chegamos ao destino :D\n");
            return;
        }
        if(opt == 0){
            return;
        }
        for(int j = 0; j < n; j++){
            if(matriz[i][j] == smallest(matriz, i, n)){
                printf("\n********** Opção Escolhida **********\n");
                custoTotal+= matriz[i][j];
                printf("Vamos para o vértice %d | Custo Total: %d\n", j+1, custoTotal);
                i = j;
                break;
            }
        }
        count++;
    }
}

int main(){
    int ** matAdj;
    int n;
    printf("Insira o número de vértices: ");
    scanf("%d", &n);

    matAdj = (int *) malloc(sizeof(int *)*n);
    for(int i = 0; i < n; i++){
        matAdj[i] = malloc(sizeof(int)*n);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("Inira o valor %d, %d: ", i,j);
            scanf("%d", &matAdj[i][j]);
        }
    }

    printf("\n********** Matriz **********\n");

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d\t|", matAdj[i][j]);
        }
        printf("\n");
    }

    guloso(matAdj, n, 0, n-1);
}