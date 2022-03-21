#include <stdio.h>

int SumM2(int *m, int tam){
    int sum = 0;
    for(int i=0;i<tam;i++){
        sum+=m[i];
    }
    return sum;
}

int main(){
    int matriz[2][2]={10,20,30,5};
    int size = sizeof(matriz)/sizeof(matriz[0][0]);
    int soma = SumM2(&matriz[0][0],size);
    printf("A soma dos elementos da matriz é: %d", soma);
}