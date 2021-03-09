#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *file;

    char f[20];
    char lido[100];
    
    printf("Insira o nome do Arquivo: ");
    scanf("%s", f);

    file = fopen(f,"r");
    if (file == NULL){
        printf("Erro ao abrir arquivo.\n");
        return 1;
    }

    int nWords = 0;   
    

    while(fscanf(file, "%s", lido) > 0) {
        nWords++;
    }   
    
    printf("Número de palavras do arquivo %s: %d\n", f,nWords);

    fclose(file);

    return 0;
}
