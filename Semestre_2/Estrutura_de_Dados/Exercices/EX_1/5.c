#include <stdio.h>

void BubSort(float *m, int tam){
    
    for(int j=0; j<tam;j++ ){
        for(int i=tam-1; i>0; i--){
            if(m[i]<m[i-1]){
                float x = m[i-1];
                m[i-1] = m[i];
                m[i] = x;
            }
        }
    }    
}

int main(){
    float matriz[10]={-10,9,8,7,6,5,4,3,2,1};
    int size = sizeof(matriz)/sizeof(matriz[0]);
    BubSort(&matriz[0], size);
    for(int i=0; i<size; i++){
        printf("%.2f ",matriz[i]);
    }
   
}