#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void verify_degree(int ** matAdj, int n, int * degree){
    for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = 0; j < n; j++){
            if(matAdj[i][j] != 0){
                count++;
            }
        }
        degree[i] = count;
    }
    return;
}

void list_order_by_degree(int *degree, int n, int *list){
    for(int i = 0; i < n; i++){
        int bigger = 0;
        int posbigger;
        for(int j = 0; j < n; j++){
            if(degree[j] > bigger){
                bigger = degree[j];
                posbigger = j;
            }
        }
        list[i] = posbigger;
        degree[posbigger] = -1;
    }
    return;
}

bool is_colorful(int * color, int n){
    for(int i = 0; i < n; i++){
        if(color[i] == 0){
            return false;
        }
    }
    return true;
}

bool can_paint(int ** matAdj, int n, int pos,int * color, int colorNum){
    if(color[pos] != 0){
        return false;
    }

    for(int i = 0; i < n; i++){
        if(matAdj[pos][i] != 0){
            if(color[i] == colorNum){
                return false;
            }
        }
    }
    return true;
}

void print_color(int *color, int n, int visiting){
    printf("\n");
    printf("|\tVert.\t|\tCor\t|\n");
    printf("|---------------+---------------|\n");
    for(int i = 0; i < n; i++){
        if(color[i] == 0){
            printf("|\t%d\t|(%d) none\t| ", i, color[i]);
        }
        else if(color[i] == 1){
            printf("|\t%d\t|(%d) blue\t| ", i, color[i]);
        }
        else if(color[i] == 2){
            printf("|\t%d\t|(%d) red\t| ", i, color[i]);
        }
        else if(color[i] == 3){
            printf("|\t%d\t|(%d) green\t| ", i, color[i]);
        }
        else if(color[i] == 4){
            printf("|\t%d\t|(%d) yellow\t| ", i, color[i]);
        }
        else if(color[i] == 5){
            printf("|\t%d\t|(%d) white\t| ", i, color[i]);
        }
        else{
            printf("|\t%d\t|\t%d\t| ", i, color[i]); // Só fiz até 5 cores, o resto fica em número hehe
        }
        if(i == visiting){
            printf("←");
        }
        printf("\n");
    }
    printf("-------------------------------------------------------\n");

}

int welsh_powell(int ** matAdj, int n, int * list, int * color){
    int colorNum = 1;
    int i = 0;

    while(!is_colorful(color, n)){
        printf("\n-> Imprimindo as cores dos vértices: (parcial) <-\n");
        print_color(color, n, list[i]);
        
        if(color[list[i]] == 0){
            for(int j = 0; j < n; j++){
                if(matAdj[list[j]][list[i]] == 0 && can_paint(matAdj, n, list[j], color, colorNum)){
                    color[list[j]] = colorNum;
                }
            }
            colorNum++;
            i++;
        }
        else{
            i++;
        }
    }
    return colorNum;
}

int main(){
    int ** matAdj;
    int n;

    printf("Insira o número de vértices: ");
    scanf("%d", &n);

    int * degree = malloc(sizeof(int) * n);
    int * list = malloc(sizeof(int) * n);
    int * color = calloc(n, sizeof(int));

    //Criando a Matriz de adjacencia
    matAdj = (int **) malloc(sizeof(int *)*n);
    for(int i = 0; i < n; i++){
        matAdj[i] = malloc(sizeof(int)*n);
    }

    //Preenchendo Matriz de adjacencia
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("Inira o valor %d, %d: ", i,j);
            scanf("%d", &matAdj[i][j]);
        }
    }

    // Printando Matriz de adjacencia
    printf("\n****************************** Matriz ******************************\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d\t|", matAdj[i][j]);
        }
        printf("\n");
    }

    verify_degree(matAdj, n, degree);
    printf("\n\n-> Grau de Cada Nodo <-\n");
    printf("\n|\tVert.\t|\tGrau\t|\n");
    printf("|---------------+---------------|\n");
    for (int i = 0; i < n; i++){
        printf("|\t%d\t|\t%d\t|\n", i, degree[i]);
    }
    printf("\n");

    list_order_by_degree(degree, n, list);

    printf("\n\n-> Lista de Vértices Ordenados pelo Grau (decrescente) <-\n");
    printf("\n|\tOrd.\t|\tVert.\t|\n");
    printf("|---------------+---------------|\n");
    for (int i = 0; i < n; i++){
        printf("|\t%dº\t|\t%d\t|\n", i+1, list[i]);
    }
    printf("\n");
    printf("\n******************************************************************\n");


    int ncolor = welsh_powell(matAdj, n, list, color);

    printf("\n-> Imprimindo as cores dos vértices: (Final) <-\n");
    print_color(color, n, -1);
    printf("Foram utilizadas %d cores para colorir esse grafo!\n", ncolor-1);
}