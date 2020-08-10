#include <bits/stdc++.h>

using namespace std;

vector <int> adj [1000009];
vector <bool> visited (1000009, false);

void DFS (int x)
{
    visited[x] = true;
    for (int i = 0; i < (int) adj[x].size(); i++)
    {
        if (!visited[adj[x][i]])
            DFS (adj[x][i]);
    }
}

int main()
{
    int v1, v2, n, m, x, y;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        adj[x].push_back (y);
        adj[y].push_back (x);
    }
    cin >> v1 >> v2;
    DFS (v1);
    if (visited[v2] == 1 || v1 == v2)
        cout << 1;
    else
        cout << 0;
    return 0;
}
