#include <bits/stdc++.h>

using namespace std;
vector <bool> visited (10009, false);
vector <vector <int>> adj (10009);
vector <vector <int>> Radj (10009);
stack <int> post_time;

void DFS (int x, vector <vector<int>> &adj)
{
    visited[x] = 1;
    for (int i = 0; i < (int) adj[x].size(); i++)
    {
        if (!visited[adj[x][i]])
            DFS (adj[x][i], adj);
    }
    post_time.push (x);
}

int main()
{
    int n, m, x, y, cnt = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        adj[x].push_back (y);
        Radj[y].push_back (x);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            DFS (i, adj);
    }
    for (int i = 0; i < 10009; i++)
        visited[i] = 0;
    while (!post_time.empty())
    {
        if (visited[post_time.top()])
        {
            post_time.pop();
        }
        else
        {
            DFS (post_time.top(), Radj);
            post_time.pop();
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
