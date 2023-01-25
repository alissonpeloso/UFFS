#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector <vector<int>> graphs;
vector <bool> visited;

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

    graphs = vector <vector<int>> (n+1);
    visited = vector <bool> (n+1, false);

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graphs[a].push_back(b);
        graphs[b].push_back(a);
    }

    dfs (1);

    int cnt = 0;
    vector <vector<int>> newRoads;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cnt++;
            newRoads.push_back({1, i});

            graphs[1].push_back(i);
            graphs[i].push_back(1);

            dfs(i);
        }
    }

    cout << cnt << endl;

    for (auto road: newRoads) {
        cout << road[0] << " " << road[1] << endl;
    }
}