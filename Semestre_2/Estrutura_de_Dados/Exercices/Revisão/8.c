#include <stdio.h>

void sort(int *v, int size){
    for(int j=0; j<size; j++){
        for(int i=size-1; i>0; i--){
            if(v[i]<v[i-1]){
                int x = v[i-1];
                v[i-1] = v[i];
                v[i] = x;
            }
        }
    }

}

void solve(int n, int *m){
    int m1[n*n];
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            m1[n*i+j] = m[n*i+j];
        }
    }
    sort(&m1[0], (n*n));
    for(int i=n*n-1; i>0; i--){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                if(m1[i] == m[n*j+k]){
                printf("%d  %d  %d\n", m[n*j+k],j,k);
            }
        }
    }

}
}

int main(){
    int a[3][3]={3,7,1,1,2,8,5,3,4};
    solve(3, &a[0][0]);
}