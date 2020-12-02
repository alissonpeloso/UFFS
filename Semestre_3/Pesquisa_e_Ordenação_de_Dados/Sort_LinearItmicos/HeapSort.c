#include <stdio.h>
#include "util.h"

void heapSort(int *A, int n){
    for(int k = (n/2-1); k >= 0; k--){
        criaHeap(A,k,n);
    }

    for (int k = n-1; k > 0; k--){
        swap(&A[0], &A[k]);
        criaHeap(A,0,k);
    }
}

void criaHeap(int *A, int i, int n){
    int maior = i;
    int left = (2*i)+1;
    int right = (2*i)+2;
    if(left < n && A[left] > A[i]){
        maior = left;
    }
    if(right < n && A[right] > A[maior]){
        maior = right;
    }

    if(maior != i){
        swap(&A[i], &A[maior]);
        criaHeap(A, maior, n);
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

    heapSort(A,size);

    double end = (clock() - start) * 1000 / (double)CLOCKS_PER_SEC;
    
    printf("Lista ordenada:\n");
    printVector(A,size);

    printf("-----------------------------------------------------------------\n");

    printf("Tempo: %.3lf ms\n",end);

    return 0;
}