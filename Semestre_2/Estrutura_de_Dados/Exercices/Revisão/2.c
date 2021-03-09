#include <stdio.h>

void sort(float *v, int size){
    for(int j=0; j<size; j++){
        for(int i=size-1; i>0; i--){
            if(v[i]<v[i-1]){
                float x = v[i-1];
                v[i-1] = v[i];
                v[i] = x;
            }
        }
    }

}

int main(){
    float valores[5] = {5,4,3,8,1};
    int size = sizeof(valores)/sizeof(valores[0]);
    sort(&valores[0], size);
    for(int i=0; i<size; i++){
        printf("%.1f ",valores[i]);
    }
    printf("\n");
}