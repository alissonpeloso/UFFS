#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector <vector<int>> graphs;
vector <int> colors;

void dfs(int s, int color) {
    if (colors[s] != 0 && colors[s] != color) {
        cout << "IMPOSSIBLE" << endl;
        exit(0);
    }

    if (colors[s] != 0) return;
    colors[s] = color;

    int nextColor = 1;
    if (color == 1) nextColor = 2;

    for (auto u: graphs[s]) {
        dfs(u, nextColor);
    }
}

int main()
{
    int n, m;

    cin >> n >> m;

    graphs = vector <vector<int>> (n+1);
    colors = vector <int> (n+1, 0);

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graphs[a].push_back(b);
        graphs[b].push_back(a);
    }

    dfs (1, 1);

    int i = find(colors.begin(), colors.end(), 0) - colors.begin();
    while(i < colors.size()) {
        dfs(i, 1);
        i = find(colors.begin(), colors.end(), 0) - colors.begin();
    }

    for (int i = 1; i <= n; i++) {
        cout << colors[i] << " ";
    }
    cout << endl;
}