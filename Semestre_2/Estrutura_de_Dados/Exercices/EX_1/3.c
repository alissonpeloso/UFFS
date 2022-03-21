#include <stdio.h>

int Fatorial(int x){
    int fat=1;
    for(int i=x; i>1; i--){
        fat = fat*i;
    }
    return fat;
}

void Fat10mat(int *m,int *solve){
    for(int i=0; i<10; i++){
        solve[i] = Fatorial(m[i]);
    }
}

int main(){
    int matriz[10]={1,2,3,4,5,6,7,8,9,10};
    int solve[10];
    Fat10mat(&matriz[0],&solve[0]);
    for(int i=0; i<10; i++){
        printf("%i, ", solve[i]);
    }
    printf("\n");
}