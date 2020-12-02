#include <stdio.h>

float sumTriM(int *m, int x, int y){
    int soma=0;
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            if(i<j){
                soma+=m[i*y+j];
            }
        }
    }
    return soma;
}

int main(){
    int matriz[3][3]={1,2,3,4,5,6,7,8,9};
    int i = sizeof(matriz)/sizeof(matriz[0]);
    int j = sizeof(matriz[0])/sizeof(matriz[0][0]);
    float solve = sumTriM(&matriz[0][0], i, j);
    printf("A soma é: %.2f", solve);
}