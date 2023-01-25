#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n, m, cnt = 0;
    cin >> n >> m;

    queue<pair<int, int>> q;

    char matrix[n][m];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(matrix[i][j] == '.')
            {
                cnt++;

                q.push({i, j});

                while(!q.empty())
                {
                    pair<int, int> p = q.front();
                    q.pop();

                    int x = p.first;
                    int y = p.second;

                    if(matrix[x][y] == '.')
                    {
                        matrix[x][y] = '#';

                        if(x + 1 < n)
                        {
                            q.push({x + 1, y});
                        }

                        if(x - 1 >= 0)
                        {
                            q.push({x - 1, y});
                        }

                        if(y + 1 < m)
                        {
                            q.push({x, y + 1});
                        }

                        if(y - 1 >= 0)
                        {
                            q.push({x, y - 1});
                        }
                    }
                }
                
            }
        }
    }

    cout << cnt << endl;
}