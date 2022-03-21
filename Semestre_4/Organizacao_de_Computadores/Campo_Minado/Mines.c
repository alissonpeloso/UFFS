#include <stdio.h>
#include <stdlib.h>

void calcula_bombas(int **field, int size){
    for (int i = 0; i < size; i++){
       for (int j = 0; j < size; j++){
            int count_bombs = 0;
            if(field[i][j] == 0){
                int starti, endi, startj, endj;

                //Verificação de linhas
                if(i == 0){
                    starti = 0;
                    endi = i+1;
                }
                else if (i == size-1){
                    endi = size-1;
                    starti = i-1;
                }
                else{
                    starti = i-1;
                    endi = i+1;
                }

                //Verificação de colunas
                if(j == 0){
                    startj = 0;
                    endj = j+1;
                }
                else if (j == size-1){
                    endj = size-1;
                    startj = j-1;
                }
                else{
                    startj = j-1;
                    endj = j+1;
                }

                printf("starti= %d, endi = %d - startj= %d, endj = %d\n", starti, endi, startj, endj);
                
                for(int k = starti; k <= endi; k++){
                    for(int l = startj; l <= endj; l++){
                        if(field[k][l] == 9){
                            count_bombs++;
                        }
                    }
                }
                field[i][j] = count_bombs;
            }
       } 
    }
}

int mostra_campo(int **interface, int **field, int size){
    int situation = 0;
    int count = 0;
    printf("    0 1 2 3 4 5 6 7\n");
    printf("    _______________\n");
    for(int i = 0; i < size; i++){
        printf("%d  |", i);
        for(int j = 0; j < size; j++){
            if(interface[i][j] == 0){
                printf("- ");
            }
            else if(interface[i][j] == 1){
                count++;
                if (field[i][j] == 9){
                    printf("B ");
                    situation = 1;
                }
                else{
                    printf("%d ", field[i][j]);
                }
            }
            else{
                printf("F ");
            }
        }
        printf("\n");
    }

    if(count == size*size-10){
        situation = 2;
    }
    return situation;
}

int main(){
    int **field, **interface;
    int size = 8;
    field = calloc(size, sizeof(int *));
    interface = calloc(size, sizeof(int *));
    for(int i = 0; i < size; i++){
        field[i] = calloc(size, sizeof(int));
        interface[i] = calloc(size, sizeof(int));
    }

    // "Sorteio":
    field[0][2] = 9;
    field[2][0] = 9;
    field[2][3] = 9;
    field[3][2] = 9;
    field[3][3] = 9;
    field[5][0] = 9;
    field[6][0] = 9;
    field[7][0] = 9;
    field[7][1] = 9;
    field[7][6] = 9;

    calcula_bombas(field, size);

    int op = 1;
    int countFlags = 0;
    while (op != 0){
        printf("\n***** Campo Minado *****\n\n");
        int situation = mostra_campo(interface, field, size);

        if (situation == 1){
            printf("\nVocê pisou em uma Mina Terrestre! Não se preocupe, vou consolar sua esposa :D\n");
            exit(0);
        }
        else if(situation == 2){
            printf("\nParabéns!!! Você sobreviveu.\n");
            exit(0);
        }
        
        printf("\nSelecione a opção desejada:\n1) Revelar posição no campo minado;\n2) Adicionar/Remover uma bandeira;\n");
        scanf("%d", &op);

        int i;
        int j;
        switch (op) {
        case 1:
            printf("Qual a posição desejada (ex: 0 0)? ");
            scanf("%d %d", &i, &j);
            if(i > 7 || j > 7){
                printf("ERRO: Selecione uma posição válida!\n");
            }
            else if(interface[i][j] == 10){
                printf("OPS, não é possível pisar aqui! Tem uma bandeirinha sua\n");
                
            }
            else{
                interface[i][j] = 1;
            }
        break;
        case 2:
            printf("Qual a posição desejada (ex: 0 0)? ");
            scanf("%d %d", &i, &j);
            if(i > 7 || j > 7){
                printf("ERRO: Selecione uma posição válida!\n");
            }
            else if(countFlags>=10){
                printf("Você ultrapassou o limite de Bandeiras!\n");
            }
            else if(interface[i][j] >= 10){
                interface[i][j] = 0;
                countFlags--;
            }
            else if(interface[i][j] == 1){
                printf("ERRO: Selecione uma posição válida!\n");
            }
            else{
                interface[i][j] = 10;
                countFlags++;
            }
            printf("Bandeiras: %d/10\n", countFlags);
        break;
        default:
            exit(0);
        }
    }
}
