#include <stdio.h>

void ReadMatrx(int *m1, int *m2, int size){
    for (int i = 0; i < size; i++){
        printf("Insira o valor da Matriz 1 na posição %d: ",i+1);
        scanf("%d",&m1[i]);
    }
    for (int i = 0; i < size; i++){
        printf("Insira o valor da Matriz 2 na posição %d: ",i+1);
        scanf("%d",&m2[i]);
    }
}

void MultMatrx(int *m1, int *m2, int *m3, int a1, int a2, int a3, int l1, int l2, int l3){
    int sum = 0;
    for (int i = 0; i < a3; i++){
        for (int j = 0; j < l3; j++){
            sum = 0;
            for (int k = 0; k < l1; k++){
                sum += m1[i*l1+k]*m2[j+k*l2];
            }
            m3[i*l3+j] = sum;
        }
    }
}

void PrintMatrx(int *m,int a, int l){
    for (int i=0; i<a; i++){
        for(int j=0; j<l; j++){
            printf("%d ", m[i*l+j]);
        }
        printf("\n");
    }

}

int main(){
    printf("******** Multiplicação de Matrizes ********\n");
    printf("Primeiro precisamos saber o tamanho das matrizes :D\n");
    printf("\n");
    int a1, l1, a2, l2;
    printf("Digite a altura da Matriz 1: ");
    scanf("%d",&a1);
    printf("Digite a largura da Matriz 1: ");
    scanf("%d",&l1);
    printf("Digite a altura da Matriz 2: ");
    scanf("%d",&a2);
    printf("Digite a largura da Matriz 2: ");
    scanf("%d",&l2);
    printf("\n");
    if (l1 != a2) {
        printf("As matrizes não podem ser multiplicadas :(, tente novamente! '~' \n");
        return 0;
        }
    int a3 = a1;
    int l3 = l2;
    int m1[a1][l1];
    int m2[a2][l2]; 
    int m3[a3][l3];
    printf("Agora, precisamos do valor de cada posição da Matriz!\n");
    ReadMatrx(&m1[0][0],&m2[0][0],a1*l1);
    MultMatrx(&m1[0][0], &m2[0][0], &m3[0][0],a1,a2,a3,l1,l2,l3);
    printf("\n");
    printf("Prontinho, aqui está o resultado! :3\n");
    PrintMatrx(&m3[0][0],a3, l3);

}
