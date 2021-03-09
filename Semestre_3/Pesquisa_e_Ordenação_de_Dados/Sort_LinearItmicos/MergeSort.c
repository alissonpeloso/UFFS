#include <stdio.h>
#include "util.h"

void mergeSort(int *A,int start, int end){
    if (start < end){
        int mid = (start + end)/2;
        mergeSort(A, start, mid);
        mergeSort(A, mid+1, end);
        intercala(A, start, mid, end);
    }
}

void intercala(int *A, int start, int mid, int end){
    int aux[end-start+1];
    int i = start;
    int j = mid+1;
    int k = 0;

    while (i<=mid && j<=end){
        if (A[i] <= A[j]){
            aux[k] = A[i];
            i++;
        }
        else{
            aux[k] = A[j];
            j++;
        }
        k++;
    }

    while (i<=mid)    {
        aux[k] = A[i];
        k++;
        i++;
    }

    while (j <= end){
        aux[k] = A[j];
        k++;
        j++;
    }

    for (k=start;k<=end;k++){
        A[k] = aux[k - start];
    }
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

    mergeSort(A,0,size-1);

    double end = (clock() - start) * 1000 / (double)CLOCKS_PER_SEC;
    
    printf("Lista ordenada:\n");
    printVector(A,size);

    printf("-----------------------------------------------------------------\n");

    printf("Tempo: %.3lf ms\n",end);

    return 0;
}
