/*Author : Abdelrahman Ehab Deghedy */
/***********************************************/
/*
*    ------
*   |  ---  \
*   | |    \ \
*   | |     \ |
*   | |     | |
*   | |     / /
*   |  --- / /
*    -------     eghedy
*/
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
    int n, m, x, y, component = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        adj[x].push_back (y);
        adj[y].push_back (x);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            DFS (i);
            component++;
        }
    }
    cout << component;
    return 0;
}
