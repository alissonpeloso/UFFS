#include <stdio.h>
int main(){
    int x, *p, *q;
    p = &x;
    q = p;
    x = 10;
    printf("\n%d\n", *q);
    return(0);
}