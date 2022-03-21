#include <stdio.h>

int main(){
    int a, b, *p;
    b = 0; 
    p = &b;
    a = *p; 
    a = 10; 
    (*p)++; 
    --a; 
    (*p) += a;
    printf("A = %d, B = %d, P = %d", a,b,*p);
}