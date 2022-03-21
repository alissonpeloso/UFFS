#include <stdio.h>

int main(){
    double a[1001];
    a[0] = -161;
    a[1] = -399;
    a[2] = -944;

    for(int i = 3; i <= 1000; i++){
        double ant = a[i-1];
        double ant2 = a[i-2];
        double ant3 = a[i-3];

        a[i] = (6*ant) - (12*ant2) + (8*ant3) + (i*pow(3,i));
    }

    printf("a3 = %lf\n", a[2]);
    printf("a4 = %lf\n", a[3]);
    printf("a1000 = %lf\n",a[50]);

    return 0;
}
