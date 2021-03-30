#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void addToQueue(int *queue, int *tail, int valor){
    *tail += 1;
    queue[*tail] = valor;
    return;
}

void rmFromQueue(int *queue, int *head){
    *head = *head+1;
    return;
}

void printQueue(int *queue, int head, int tail){
    printf("Queue: ");
    for(int i = head; i <= tail; i++){
        printf("[%d] ", queue[i]);
    }
    printf("\n");
    return;
}

void printColorBFS(int **matBFS, int n){
    printf("White: ");
    for(int i = 0; i < n; i++){
        if(matBFS[i][3] == 0){
            printf("[%d] ", i);
        }
    }
    printf("\n");

    printf("Gray:  ");
    for(int i = 0; i < n; i++){
        if(matBFS[i][3] == 1){
            printf("[%d] ", i);
        }
    }
    printf("\n");

    printf("Black: ");
    for(int i = 0; i < n; i++){
        if(matBFS[i][3] == 2){
            printf("[%d] ", i);
        }
    }
    printf("\n");

    return;
}

void printBFS(int **matBFS, int n, int visiting){
    printf("\tVert.\t|\tJumps\t|\tPreview\t|\tColor\t|\n");
    printf(" ---------------|---------------|---------------|---------------|\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++){
            if(matBFS[i][j] == INT_MAX){
                printf("\tINF\t|");
            } 
            else{
                if(j == 3){
                    if(matBFS[i][j] == 0){
                        printf("\tWhite\t|");
                    }
                    else if(matBFS[i][j] == 1){
                        printf("\tGray\t|");
                    }
                    else if(matBFS[i][j] == 2){
                        printf("\tBlack\t|");
                    }
                }
                else if(j == 2 && matBFS[i][j] == -1){
                    printf("\tnone\t|");
                }
                else{
                    printf("\t%d\t|", matBFS[i][j]);    
                }    
            }
        }
        if(i == visiting && visiting > -1 && visiting < n){
            printf(" <- visiting");
        }
        printf("\n");
    }
}

void bfs(int **matAdj, int **matBFS, int n, int startValue, int destiny){
    matBFS = (int **) malloc(sizeof(int *)*n);
    for(int i = 0; i < n; i++){
        matBFS[i] = (int *) malloc(sizeof(int)*4);
        matBFS[i][0] = i;
        matBFS[i][1] = INT_MAX;
        matBFS[i][2] = -1;
        matBFS[i][3] = 0; // 0 = white, 1 = gray, 2 = black
    }

    // criando a fila
    int queue[1000];
    int head = 0;
    int tail = 0;


    printf("\n-----------------------------------------------------------------------------------------\n");
    printf("|                                BUSCA EM LARGURA (BFS)                                 |");
    printf("\n-----------------------------------------------------------------------------------------\n");
    printf("- Vamos sair do vértice %d e buscar o vértice %d\n", startValue, destiny);

    if(startValue == destiny){
        printf("O vértice de início é igual ao vértice de destino, você já encontrou o vértice!\n");
        return;
    }

    int i = startValue;
    matBFS[i][1] = 0;
    queue[head] = i;
    printQueue(queue, head, tail);

    while (i < n){
        printf("\n****************************** Visitando o vértice %d ******************************\n", i);
        matBFS[i][3] = 1;
        
        for(int j = 0; j < n; j++){
            if(matAdj[i][j] != 0 && matBFS[j][3] == 0){
                addToQueue(queue, &tail, j);
                matBFS[j][3] = 1;
                matBFS[j][1] = matBFS[i][1] + 1;
                matBFS[j][2] = i;
            }
            if(matAdj[i][j] != 0 && j == destiny){
                printBFS(matBFS, n, i);
                printQueue(queue, head, tail);
                printf("-----------------\n");
                printColorBFS(matBFS, n);
                printf("\n\t>>>>> Chegamos ao destino!\n");
                
                return;
            }
            if(head > tail){
                printf("\n*** Não foi possível encontrar o destino! ***\n");
                return;
            }
        }
        matBFS[i][3] = 2;

        printBFS(matBFS, n, i);
        rmFromQueue(queue, &head);
        printQueue(queue, head, tail);
        printf("-----------------\n");
        printColorBFS(matBFS, n);
        i = queue[head];
    }
}