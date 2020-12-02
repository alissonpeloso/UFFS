#include <stdio.h>

#define SIZE 11
#define NULL_ELMT -2147483648

int hash(int element){
    while(element >= SIZE){
        element = element % SIZE;
    }
    return element;
}

void addHash(int *A, int element){
    for(int j = 0; j < SIZE; j++){
        int key = hash(hash(element)+j);

        if(A[key] == NULL_ELMT){
            A[key] = element;
            return;
        }
    }
}

void printV(int *A, int size){
    printf("Lista:\n");
    for (int i = 0; i < size; i++){
        printf("%d, ", A[i]);
    }
    printf("\n");
}

int main(){
    int hashTable[SIZE];
    for(int i = 0; i < SIZE; i++){
        hashTable[i] = NULL_ELMT;
    }
    addHash(hashTable,7);
    addHash(hashTable,7);
    addHash(hashTable,8);
    addHash(hashTable,7);
    addHash(hashTable,1);

    printV(hashTable,SIZE);

    
    return 0;
}
