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

vector <int> adj [100009];
vector <int> topological;
vector <bool> visited (100009, 0);



void DFS (int x)
{
    visited[x] = 1;
    for (int i = 0; i < (int) adj[x].size(); i++)
    {
        if (visited[adj[x][i]] == 0)
            DFS (adj[x][i]);
    }
    topological.push_back (x);
}

int main()
{
    int n, m, x, y;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        adj[x].push_back (y);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            DFS(i);
    }
    reverse (topological.begin(), topological.end());
    for (int i = 0; i < (int) topological.size(); i++)
        cout << topological[i] << " ";
    return 0;
}
