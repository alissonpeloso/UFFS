#include <stdio.h>
#include "util.h"

void quickSort(int *A, int start, int end){
    if (start < end){
        int pivo = particiona(A, start, end);
        quickSort(A, start, pivo-1);
        quickSort(A, pivo+1, end);
    }
}

int particiona(int *A, int start, int end){
    int pivo = end;
    int k = start;
    for (int i = start; i < end; i++){
        if(A[i] < A[pivo]){
            swap(&A[k],&A[i]);
            k++;
        }
    }
    swap(&A[k], &A[pivo]);
    return k;
}

int main(int argc, char const *argv[]){
    int size, ord;
    int *A;

    printf("Insira o tamanho da lista e ordenação (cres = 1, decres = -1, aleatória = 0)\n");
    printf("(ex: 10 1)\n");
    scanf("%i %i", &size, &ord);

    allocVector(&A,size);
    setVector(A,size,ord);

    printf("-----------------------------------------------------------------\n");

    printf("Lista original:\n");
    printVector(A,size);

    printf("-----------------------------------------------------------------\n");

    clock_t start;
	start = clock();

    quickSort(A,0,size-1);

    double end = (clock() - start) * 1000 / (double)CLOCKS_PER_SEC;
    
    printf("Lista ordenada:\n");
    printVector(A,size);

    printf("-----------------------------------------------------------------\n");

    printf("Tempo: %.3lf ms\n",end);

    return 0;
}
