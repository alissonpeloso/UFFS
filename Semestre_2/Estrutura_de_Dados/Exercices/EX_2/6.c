#include <stdio.h>

void PrintArraway(float *v, float last){
    int i=0;
    while(v[i] != last){
        printf("%.2f ", v[i] );
        i++;
    }
}

int main(){
    float vetor[10]={1.5,2.9,3.0,4.4,5.8,6.7,7.1,8.2,9.9,10.12};
    PrintArraway(&vetor[0], vetor[10]);

}