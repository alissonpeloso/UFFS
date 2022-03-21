#include <stdio.h>

float Medmatrix(int *m,int tam){
    float soma = 0.0;
    for(int i=0;i<tam;i++){
        soma+= m[i];
    }
    float Med = soma / tam;
    return Med;
}

int main(){
    int matriz[8]={10,10,8,10,10,9,10,10};
    int size = sizeof(matriz)/sizeof(matriz[0]);

    float med = Medmatrix(&matriz[0], size);
    printf("A média é igual a %.2f", med);
}