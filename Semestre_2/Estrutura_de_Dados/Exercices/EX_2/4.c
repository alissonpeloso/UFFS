#include <stdio.h>

int SumCube(int *a, int *b){
    *a = (*a)*(*a)*(*a);
    *b = (*b)*(*b)*(*b);
    int sum = *b + *a;

    return sum;
}

int main(void){
    int a = 8;
    int b = 9;
    int x = SumCube(&a,&b);
    printf("Soma = %d, A = %d, B = %d\n", x,a,b);
}