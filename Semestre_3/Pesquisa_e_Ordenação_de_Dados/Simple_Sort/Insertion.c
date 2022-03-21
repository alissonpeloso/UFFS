#include "util.h"

int main(int argc, char const *argv[]){
    int size, ord;
    int *A;
    double swaps=0, compars=0;

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

    for(int i = 1; i < size; i++){
        int p = A[i];
        int j;

        for(j = i; j >= 0 && p < A[j-1]; j--){
            compars++;
            A[j] = A[j-1];
        }
        A[j] = p;
        swaps++;
    }

    double end = (clock() - start) * 1000 / (double)CLOCKS_PER_SEC;
    
    printf("Lista ordenada:\n");
    printVector(A,size);

    printf("-----------------------------------------------------------------\n");

    printf("Tempo: %.3lf ms | ",end);
    printf("Comparações: %.0lf | ", compars);
    printf("Trocas: %.0lf |\n", swaps);

    return 0;
}
