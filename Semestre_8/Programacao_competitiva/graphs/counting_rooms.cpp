#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector <vector<int>> graphs;
vector <bool> visited;
int cnt = 0;

void dfs(int s) {
    if (visited[s]) return;
    visited[s] = true;

    for (auto u: graphs[s]) {
        dfs(u);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    char matrix[n][m];
    int roomSpace[n][m];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] == '.') {
                graphs.push_back(vector<int>());
                visited.push_back(false);

                roomSpace[i][j] = cnt++;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if (matrix[i][j] == '#') continue;
            if (i > 0 && matrix[i-1][j] == '.') {
                graphs[roomSpace[i][j]].push_back(roomSpace[i-1][j]);
            }
            if (i < n-1 && matrix[i+1][j] == '.') {
                graphs[roomSpace[i][j]].push_back(roomSpace[i+1][j]);
            }
            if (j > 0 && matrix[i][j-1] == '.') {
                graphs[roomSpace[i][j]].push_back(roomSpace[i][j-1]);
            }
            if (j < m-1 && matrix[i][j+1] == '.') {
                graphs[roomSpace[i][j]].push_back(roomSpace[i][j+1]);
            }
        }
    }

    if(visited.size() == 0) {
        cout << 0 << endl;
        return 0;
    }

    int components = 0;
    while(true) {
        int i = find(visited.begin(), visited.end(), false) - visited.begin();
        if (i == visited.size()) break;
        dfs(i);
        components++;
    }

    cout << components << endl;

    return 0;
}