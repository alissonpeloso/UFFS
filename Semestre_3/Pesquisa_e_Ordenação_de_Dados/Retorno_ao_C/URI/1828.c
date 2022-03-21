#include <stdio.h>
#define SIZE 7

int comp (char *a, char *b){
    int i;
    char space[0] = {" "};
    for (i=0;i<SIZE;i++){
        if (a[i] != b[i]){
            return 1;
        }
        if (a[i] == space[0]){
            return 0;
        }
    }
    return 0;
}

int solve(char *a, char *b){
    char tesoura[SIZE] = {"tesoura"}, pedra[SIZE] = {"pedra"}, papel[SIZE] = {"papel"}, lagarto[SIZE] = {"lagarto"}, spock[SIZE] = {"Spock"};
    
    if (comp(a,b) == 0){
        return 0;
    }

    if (comp(a,pedra) == 0){
        if (comp(b,tesoura) == 0 || comp(b,lagarto) == 0){
            return 1;
        }
        else{
            return -1;
        }
    }

    if (comp(a,papel) == 0){
        if (comp(b,pedra) == 0 || comp(b,spock) == 0){
            return 1;
        }
        else{
            return -1;
        }
    }

    if (comp(a,tesoura) == 0){
        if (comp(b,papel) == 0 || comp(b,lagarto) == 0){
            return 1;
        }
        else{
            return -1;
        }
    }

    if (comp(a,lagarto) == 0){
        if (comp(b,spock) == 0 || comp(b,papel) == 0){
            return 1;
        }
        else{
            return -1;
        }
    }

    if (comp(a,spock) == 0){
        if (comp(b,tesoura) == 0 || comp(b,pedra) == 0){
            return 1;
        }
        else{
            return -1;
        }
    }
}

int main(){
    int n,i,r;
    char p1[SIZE], p2[SIZE];
    scanf("%i", &n);
    for (i=1; i <= n; i++){
        scanf("%s %s", p1, p2);
        r = solve(p1,p2);
        printf("Caso #%i: ", i);
        
        if (r == 0){
            printf("De novo!\n");
        }
        else if(r == 1){
            printf("Bazinga!\n");
        }
        else if(r == -1)
        {
            printf("Raj trapaceou!\n");
        }
    }
     
    return 0;
}