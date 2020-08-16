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

vector <vector <int>> adj (200009);
vector <int> distanc (200009, INT_MAX);
vector <int> prevv (200009, -1);
vector <int> result;
queue <int> que;

int BFS (int v, int u)
{
    distanc[v] = 0;
    que.push (v);
    while (!que.empty ())
    {
        int temp = que.front();
        que.pop();
        for (size_t i = 0; i < adj[temp].size(); i++)
        {
            if (distanc[adj[temp][i]] == INT_MAX)
            {
                que.push (adj[temp][i]);
                distanc[adj[temp][i]] = distanc[temp] + 1;
                prevv [adj[temp][i]] = temp;
            }
        }

    }
    while (u != v)
    {
        result.push_back (u);
        if (prevv[u] == -1)
            return -1;
        u = prevv[u];
    }
    return (int) result.size();
}

int main()
{
    int n, m, x, y, v, u;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        adj[x].push_back (y);
        adj[y].push_back (x);
    }
    cin >> v >> u;
    cout << BFS (v, u);
    return 0;
}
