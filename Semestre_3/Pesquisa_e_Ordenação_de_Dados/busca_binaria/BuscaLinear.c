int buscaLinear(int element,int *A, int size){
    for (int i = 0; i < size; i++){
        if(A[i] == element){
            return i;
        }
    }
    return -1;
}

int main()
{
    int V[] = {1,2,3,4,5};
    int pos = buscaLinear(8, V, 5);

    if(pos == -1){
        printf("Elemento não encontrado!\n");
    }else{
        printf("Elemento se encontra na posição %d\n", pos);
    }

    return 0;
}
