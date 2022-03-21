#include <stdio.h>

int main(){
    int matriz[100][100];
    int *pm = &matriz[0][0];

    for (int i = 0; i<100; i++){
        for (int j = 0; j<100; j++){
            pm[100*i+j]= 1;
            printf("%d ", pm[100*i+j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int k = 0; k<100; k++){
        for (int l = 0; l<100; l++){
            pm[100*k+l]= (100*k+l)+1;
            printf("%d ", pm[100*k+l]);
        }
        printf("\n");
    }
    printf("\n");
}