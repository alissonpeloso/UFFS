#include <stdio.h>

void strcpy(char *destino, char *origem){
    int i = 0;
    while(origem[i]!= '\0'){
        destino[i] = origem[i];
        i++;
    }
    destino[i] = '\0';
}

int main(){
    int i = 0;
    char b[] = "Um teste de char bem elaborado necessita de bastante texto para a função realizar a cópia";   
    char a[sizeof(b)];
    strcpy(&a[0],&b[0]);
    printf("\n");

    printf("a = %s / b = %s",a,b);
}