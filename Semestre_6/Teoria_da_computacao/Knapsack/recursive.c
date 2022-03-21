#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int cache[1001][100001];

int price[] = {4,8,5,3};
int pages[] = {5,12,8,1};

int solve(int i, int w, int n) {
    printf("%d %d %d\n", i, w, n);

    if (i == n) {
        return 0;
    }
	if (cache[i][w] > 0) {
		return cache[i][w];
	}
        
    int a;
    if (price[i] > w) {
        a = -INT_MAX;
    } else {
        a = pages[i] + solve(i+1, w-price[i], n);
    }

    int b = solve(i + 1, w, n);

    cache[i][w] = (a > b ? a : b);
    return cache[i][w];
}

int main() {
    int result = solve(0, 10, 4);
    printf("%d\n", result);
}