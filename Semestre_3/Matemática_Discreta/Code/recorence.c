#include <stdio.h>

int main(){
    double a[1001];
    a[0] = 22;
    a[1] = 0;
    a[2] = 0;

    for(int i = 3; i <= 1000; i++){
        double ant = a[i-1];
        double ant2 = a[i-2];
        double ant3 = a[i-3];
        a[i] = (6*ant) + (-12*ant2) + (8*ant3) + (i*pow(2,i));
    }

    for(int j = 0; j < 10; j++){
        printf("a%d = %.lf\n", j, a[j]);
    }

    return 0;
}