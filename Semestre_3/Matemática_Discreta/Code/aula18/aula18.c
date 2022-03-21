#include <stdio.h>

int main(){
    double a[1001];
    a[0] = 1;
    a[1] = 0;
    a[2] = 1;

    for(int i = 3; i <= 1000; i++){
        double ant = a[i-1];
        double ant2 = a[i-2];
        double ant3 = a[i-3];
        a[i] = (2*ant) + (9*ant2) + (-18*ant3) + pow(7,i);
    }

    printf("a3 = %.lf\n", a[9]);

    return 0;
}