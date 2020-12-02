int buscaBinaria(int element, int *A, int size){
    int inicio = 0;
    int fim = size-1;

    while(inicio <= fim){
        int meio = (inicio + fim) / 2;
        if (element == A[meio]){
            return meio;
        } 
        else if(element < A[meio]){
            fim = meio - 1;
        }
        else{
            inicio = meio + 1;
        }
    }
    return -1;
}

int main()
{
    int V[] = {1,2,3,4,5};
    int pos = buscaBinaria(1, V, 5);

    if(pos == -1){
        printf("Elemento não encontrado!\n");
    }else{
        printf("Elemento se encontra na posição %d\n", pos);
    }

    return 0;
}