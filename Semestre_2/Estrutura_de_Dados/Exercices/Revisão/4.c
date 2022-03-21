#include <stdio.h>   

int main () {
    float matrx [50][50];
    float *mt = &matrx[0][0];
    int i,j;
    for (i=0;i<50;i++)
        for (j=0;j<50;j++)
            mt[50*i+j]=0.0; 
    return(0);
}