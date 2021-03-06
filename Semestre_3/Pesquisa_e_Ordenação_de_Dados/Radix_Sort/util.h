#include <stdio.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int compare (const void * a, const void * b){
  return ( *(int*)a - *(int*)b );
}

int compareInverse (const void * a, const void * b){
  return ( *(int*)b - *(int*)a );
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void printVector(int *A, int size){
    for(int i=0;i<size;i++){
        printf("%i ", A[i]);
    }
    printf("\n");
}

void allocVector(int **A, int size){  
    *A = (int*) malloc(size*sizeof(int));
}

void setVector(int *A, int size, int order){
    srand(time(NULL));
    for(int i=0; i<size; i++){
        A[i] = rand()%100000;
    }

    if (order == 1){
        qsort(A, size, sizeof(int), compare);
    }

    else if (order == -1){
        qsort(A, size, sizeof(int), compareInverse);
    }
}

int buscaMax(int *A, int size){
    int max = A[0];
    for(int i = 0; i < size; i++){
        if(A[i] > max){
            max = A[i];
        }
    }
    return max;
}
