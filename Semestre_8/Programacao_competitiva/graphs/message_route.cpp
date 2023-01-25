#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector <vector<int>> graphs;

queue<int> q;
vector<bool> visited;
vector<int> path;

void bfs(int x) {
    visited[x] = true;
    path[x] = 0;
    q.push(x);

    while (!q.empty()) {
        int s = q.front(); q.pop();

        for (auto u : graphs[s]) {
            if (visited[u]) continue;

            visited[u] = true;
            path[u] = s;
            q.push(u);
        }
    }
}

int main()
{
    int n, m;

    cin >> n >> m;

    graphs = vector <vector<int>> (n+1);
    visited = vector <bool> (n+1, false);
    path = vector <int> (n+1, -1);

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graphs[a].push_back(b);
        graphs[b].push_back(a);
    }

    bfs(1);

    if (path[n] == -1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<int> ans;
    ans.push_back(n);

    int x = n;
    while (x != 1) {
        x = path[x];
        ans.push_back(x);
    }

    cout << ans.size() << endl;

    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }
}