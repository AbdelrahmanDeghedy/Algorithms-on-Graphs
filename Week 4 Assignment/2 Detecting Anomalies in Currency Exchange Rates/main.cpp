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

vector <long long> dist (100009, INT_MAX);
vector <vector <pair <int, int>>> adj (100009);
bool neg_cycle;

void BellmanFord (int V)
{
    dist[V] = 0;
    for (int i = 0, flag = 0; i < V - 1; i++, flag = 0)
    {
        for (int k = 1; k <= V; k++)
        {
            for (size_t j = 0; j < adj[k].size(); j++)
            {
                int child = adj[k][j].second;
                int weight = adj[k][j].first;
                if (dist[child] > dist[k] + weight)
                {
                    dist[child] = dist[k] + weight;
                    flag = 1;
                }
            }
        }
        if (!flag)  //For efficiency (detect if no relaxation happened
            break;
    }
    for (int k = 1; k <= V; k++)    //loop for negative cycle detection
    {
        for (size_t j = 0; j < adj[k].size(); j++)
        {
            int child = adj[k][j].second;
            int weight = adj[k][j].first;
            if (dist[child] > dist[k] + weight)
                neg_cycle = 1;
        }
    }
}
int main()
{
    int x, y, w, n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> w;
        adj[x].push_back (make_pair (w, y));
    }
    BellmanFord (n);
    cout << neg_cycle;
    return 0;
}
