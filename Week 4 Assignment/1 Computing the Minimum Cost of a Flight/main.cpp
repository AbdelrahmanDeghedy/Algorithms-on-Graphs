#include <bits/stdc++.h>

using namespace std;

vector <int> dist (100009, INT_MAX);
vector <vector <pair <int, int>>> adj (100009);

int Dijkstra (int node, int destination)
{
    priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> pq;
    dist[node] = 0;
    pq.push (make_pair (0, node));
    while (!pq.empty())
    {
        int parent = pq.top().second;
        pq.pop();
        for (size_t i = 0; i < adj[parent].size(); i++)
        {
            int child = adj[parent][i].second;
            int weight = adj[parent][i].first;
            if (dist[child] > dist[parent] + weight)
            {
                dist[child] = dist[parent] + weight;
                pq.push (make_pair (dist[child], child));
            }
        }
    }
    if (dist[destination] == INT_MAX)
        return -1;
    else
        return dist[destination];
}
int main()
{
    int x, y, u, v, w, n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> w;
        adj[x].push_back (make_pair (w, y));
    }
    cin >> u >> v;
    cout << Dijkstra (u, v);
    return 0;
}
