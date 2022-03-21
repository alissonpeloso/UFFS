#include <stdio.h>

int main(){
    char s[1] = {"S"};
    char word[1];
    float matriz[12][12], sum = 0;
    int i,j;

    scanf("%s", word);

    for(i=0;i < 12; i++){
        for(j=0;j<12; j++){
            scanf("%f", &matriz[i][j]);

            if(i<j){
                sum+= matriz[i][j];
            }
        }
    }

    if (word[0] == s[0]){
        printf("%.1f\n", sum);
    }

    else{
        printf("%.1f\n", sum/66);
    }

    return 0;
}
