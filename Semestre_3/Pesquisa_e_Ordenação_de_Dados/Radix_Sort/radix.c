#include <stdio.h>
#include "util.h"

void radixSort(int *A, int n){
    int max = buscaMax(A,n);
    for(int i = 1; max/i > 0; i*=10){
        countingSort(A,i,n);
    }
}

void countingSort(int *A,int d, int n){
    int aux[n];
    int contagem[10] = {0,0,0,0,0,0,0,0,0,0};
    int posicao[10] = {0,0,0,0,0,0,0,0,0,0};
    int digito;
    for(int i = 0; i <n; i++){
        digito = (A[i]/d) % 10;
        contagem[digito]++;
    }

    for (int i = 1; i < 10; i++){
        posicao[i] = contagem[i-1]+posicao[i-1];
    }

    for (int i = 0; i < n; i++){
        digito = (A[i]/d) % 10;
        aux[(posicao[digito])] = A[i];
        posicao[digito]++;
    }

    for(int i = 0; i < n; i++){
        A[i] = aux[i];
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

    radixSort(A,size);

    double end = (clock() - start) * 1000 / (double)CLOCKS_PER_SEC;
    
    printf("Lista ordenada:\n");
    printVector(A,size);

    printf("-----------------------------------------------------------------\n");

    printf("Tempo: %.3lf ms\n",end);

    return 0;
}
