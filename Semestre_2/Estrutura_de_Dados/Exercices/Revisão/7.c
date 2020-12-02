#include <stdio.h>

void solve(int n, int *m){
    int k, Lin, Col;
    k = -999999;
    for (int i = 0; i<n ; i++){
        for (int j=0; j<n; j++){
            if(m[n*i+j] > k){
            k = m[n*i+j];
            Lin = i;
            Col = j;
        }
        }
        
    }
    printf(" k = %d, Lin = %d, Col = %d\n", k, Lin, Col);
}

int main(){
    int a = 5;
    int m[]= {0,1,2,3,4,5,6,7,8,9,10001,11,12,13,14,15,16,17,18,19,20,21,22,23,24};
    solve(a, &m[0]);
}