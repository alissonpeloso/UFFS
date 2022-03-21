#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void uppercase(char *string, int size){
    for(int i = 0; i < size; i++){
        string[i] = toupper(string[i]);
    }
}

int main(){
    FILE *fileOrigem, *fileDestino;

    fileOrigem = fopen("test.txt","r");
    fileDestino = fopen("newText.txt","w");

    if (fileOrigem == NULL || fileDestino == NULL){
        printf("Erro ao abrir arquivo.\n");
        exit(1);
    }

    while (!feof(fileOrigem)){
        fprintf(fileDestino,"%c",toupper(fgetc(fileOrigem)));
    }

    fclose(fileOrigem);
    fclose(fileDestino);
   
    return 0;
}
