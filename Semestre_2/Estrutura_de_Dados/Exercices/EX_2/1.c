#include <stdio.h>

void swap(float *a, float *b){
    float j = *a;
    *a = *b;
    *b = j;
}

void maxMin(int *v, int *max, int *min, int size){
    *max = v[0];
    *min = v[0];
    for(int i=0; i<size; i++){
        if(*max<v[i]){
            *max = v[i];
        }
        if(*min>v[i]){
            *min = v[i];
        }
    }
}

int main(){
    int max,min;
    int vetor[5]={9999,5,0,-54,6};
    int size = sizeof(vetor)/sizeof(vetor[0]);
    maxMin(&vetor[0],&max, &min, size);
    printf("Max = %d, Min = %d", max,min);
}