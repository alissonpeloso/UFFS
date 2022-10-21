#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;

const int n = 7;
int grid[n][n];
int cont = 0;
ll calls = 0;

bool isFreePos(int i, int j) {
    if (i >= 0 && j >= 0 && i < n && j < n && grid[i][j] == 0){
        return true;
    }
    return false;
}

void search(int s, int i, int j) // s -> step; i and j -> positions
{
    calls++;
    if(s == n * n - 1) { // number total of steps
        if(i == n-1 && j == n-1) { // final position, solution finded.
            cont++; // add 1 to solutions count.
        }
        return;
    }

    // Optmization 1
    if (i == 0 && j == 0){
        grid[i][j] = 1;
        search(s+1, i+1, j);
    }

    // Optimization 2
    if (i == n-1 && j == n-1){
        return;
    }
    
    // Optimization 3
    if (((i == 0 || i == n-1) && isFreePos(i, j-1)) || (j == n-1 || j == 0) && isFreePos(i-1, j)){
        return;
    }

    // Optimization 4
    if(isFreePos(i+1, j) && isFreePos(i-1, j) && !isFreePos(i, j+1) && !isFreePos(i, j-1)){
        return;
    }
    if(!isFreePos(i+1, j) && !isFreePos(i-1, j) && isFreePos(i, j+1) && isFreePos(i, j-1)){
        return;
    }

    if (isFreePos(i+1, j)) { // going down
        grid[i][j] = 1;
        search(s+1, i+1, j);
        grid[i+1][j] = 0;
    }
    if (isFreePos(i-1, j)) { // going up
        grid[i][j] = 2;
        search(s+1, i-1, j);
        grid[i-1][j] = 0;
    }
    if (isFreePos(i, j+1)) { // going right
        grid[i][j] = 3;
        search(s+1, i, j+1);
        grid[i][j+1] = 0;
    }
    if (isFreePos(i, j-1)) { // going left
        grid[i][j] = 4;
        search(s+1, i, j-1);
        grid[i][j-1] = 0;
    }
    
}

int main()
{
    search(0,0,0);

    cout << cont*2 << "\n" << calls << "\n";

    return 0;
}