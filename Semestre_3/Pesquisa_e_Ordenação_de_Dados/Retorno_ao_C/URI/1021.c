#include <stdio.h>

int main() {
    double in;
    scanf("%lf", &in);

    int n100=0, n50=0, n20=0, n10=0, n5=0, n2=0, c1=0, c050=0, c025=0, c010=0, c005=0, c001=0;
    int inteiros, decimais;
    inteiros = (int)in;
    float res = (in - inteiros)*100;
    decimais = (int) res;

    if (inteiros>=100){
        n100 = inteiros/100;
        inteiros = inteiros%100;
    }
    
     if (inteiros>=50){
        n50 = inteiros/50;
        inteiros = inteiros%50;
    }

    if (inteiros>=20){
        n20 = inteiros/20;
        inteiros = inteiros%20;
    }

    if (inteiros>=10){
        n10= inteiros/10;
        inteiros = inteiros%10;
    }

    if (inteiros>=5){
        n5= inteiros/5;
        inteiros = inteiros%5;
    }

    if (inteiros>=2){
        n2= inteiros/2;
        inteiros = inteiros%2;
    }

    if (inteiros>=1){
        c1= inteiros/1;
        inteiros = inteiros%1;
    }

    if (decimais>=50){
        c050= decimais/50;
        decimais = decimais%50;
    }

    if (decimais>=25){
        c025= decimais/25;
        decimais = decimais%25;
    }
    
    if (decimais>=10){
        c010= decimais/10;
        decimais = decimais%10;
    }

    if (decimais>=5){
        c005= decimais/5;
        decimais = decimais%5;
    }

    if (decimais>=1){
        c001= decimais/1;
        decimais = decimais%1;
    }

    printf("NOTAS:\n");
    printf("%i nota(s) de R$ 100.00\n", n100);
    printf("%i nota(s) de R$ 50.00\n", n50);
    printf("%i nota(s) de R$ 20.00\n", n20);
    printf("%i nota(s) de R$ 10.00\n", n10);
    printf("%i nota(s) de R$ 5.00\n", n5);
    printf("%i nota(s) de R$ 2.00\n", n2);
    printf("MOEDAS:\n");
    printf("%i moeda(s) de R$ 1.00\n", c1);
    printf("%i moeda(s) de R$ 0.50\n", c050);
    printf("%i moeda(s) de R$ 0.25\n", c025);
    printf("%i moeda(s) de R$ 0.10\n", c010);
    printf("%i moeda(s) de R$ 0.05\n", c005);
    printf("%i moeda(s) de R$ 0.01\n", c001);

    return 0;
}