#include <stdio.h>

int main(){
    float a = 654.2;
    float b = 879.1;
    if(&a >&b){
        printf("%x \n", &a);
    }
    else{
        printf("%x \n", &b);
    }

    printf("A = %x, B = %x", &a, &b);
}