#include "util.h"

#define SIZE 5

int main(int argc, char const *argv[])
{
    int *V;
    allocVector(&V, SIZE);
    setVector(V, SIZE, -1);

    for (int i=0; i < SIZE; i++){
        printf("%i ", V[i]);
    }
    printf("\n");

    return 0;
}
