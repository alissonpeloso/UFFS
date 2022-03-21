#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include<stdbool.h>

void addToStack(int *stack, int *top, int value){
    *top += 1;
    stack[*top] = value;
}

void rmFromStack(int *stack, int *top){
    stack[*top] = 0;
    *top -= 1;
}

void printStack(int *stack, int top){
    printf("\nStack:");
    for(int i = top; i >= 0; i--){
        printf("\t[%d]\n", stack[i]);
    }
    return;
}

void printColorDFS(int **matDFS, int n){
    printf("White: ");
    for(int i = 0; i < n; i++){
        if(matDFS[i][1] == 0){
            printf("[%d] ", i);
        }
    }
    printf("\n");

    printf("Gray:  ");
    for(int i = 0; i < n; i++){
        if(matDFS[i][1] == 1){
            printf("[%d] ", i);
        }
    }
    printf("\n");

    printf("Black: ");
    for(int i = 0; i < n; i++){
        if(matDFS[i][1] == 2){
            printf("[%d] ", i);
        }
    }
    printf("\n");

    return;
}

void printDFS(int **matDFS, int n, int visiting){
    printf("\tVert.\t|\tColor\t|\tPreview\t|\tD\t|\tF\t\n");
    printf(" ---------------|---------------|---------------|---------------|---------------|\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 5; j++){
            if(j == 1){
                if(matDFS[i][j] == 0){
                    printf("\tWhite\t|");
                }
                else if(matDFS[i][j] == 1){
                    printf("\tGray\t|");
                }
                else if(matDFS[i][j] == 2){
                    printf("\tBlack\t|");
                }
            }
            else if((j == 2 || j == 3 ||j == 4) && matDFS[i][j] == -1){
                printf("\tnone\t|");
            }
            else{
                printf("\t%d\t|", matDFS[i][j]);    
            }
        }
        if(i == visiting && visiting > -1 && visiting < n){
            printf(" <- visiting");
        }
        printf("\n");
    }
}

void dfs(int **matAdj, int **matDFS, int n, int startValue, int destiny){
    matDFS = (int **) malloc(sizeof(int *)*n);
    for(int i = 0; i < n; i++){
        matDFS[i] = (int *) malloc(sizeof(int)*5);
        matDFS[i][0] = i;
        matDFS[i][1] = 0; // 0 = white, 1 = gray, 2 = black
        matDFS[i][2] = -1;
        matDFS[i][3] = -1; //d -> instante em que foi visitado (gray)
        matDFS[i][4] = -1; //f -> quando já verificou todos os adjacentes (black)
    }

    // criando a pilha
    int stack[1000];
    int top = 0;

    int instant = 0;

    printf("\n-----------------------------------------------------------------------------------------\n");
    printf("|                              BUSCA EM PROFUNDIDADE (DFS)                              |");
    printf("\n-----------------------------------------------------------------------------------------\n");
    printf("- Vamos sair do vértice %d e buscar o vértice %d\n", startValue, destiny);

    if(startValue == destiny){
        printf("O vértice de início é igual ao vértice de destino, você já encontrou o vértice!\n");
        return;
    }

    int i = startValue;
    stack[0] = startValue;
    printStack(stack, top);
    int preview = -1;
    
    while (i < n){
        printf("\n****************************** Visitando o vértice %d ******************************\n", i);
        if(matDFS[i][1] == 0){
            matDFS[i][1] = 1;
            instant++;
            matDFS[i][3] = instant;
            matDFS[i][2] = preview;
        }

        bool haveANext = false;
        for(int j = 0; j < n; j++){
            if(matAdj[i][j] > 0 && matDFS[j][1] == 0){
                addToStack(stack, &top, j);
                haveANext = true;
                break;
            }
            if(stack[top] == destiny){
                printDFS(matDFS, n, i);
                printStack(stack, top);
                printf("-----------------\n");
                printColorDFS(matDFS, n);
                printf("\n\t>>>>> Chegamos ao destino!\n");
                
                return;
            }
        }

        printDFS(matDFS, n, i);
        printStack(stack, top);
        printf("-----------------\n");
        printColorDFS(matDFS, n);

        if(!haveANext){
            matDFS[i][1] = 2;
            instant++;
            matDFS[i][4] = instant;
            rmFromStack(stack, &top);
        }
        if(top < 0){
            printf("\n*** Não foi possível encontrar o destino! ***\n");
            return;
        }
        i = stack[top];
    }
}