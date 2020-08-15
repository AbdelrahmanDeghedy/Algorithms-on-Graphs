#include <bits/stdc++.h>
#include <limits>
using namespace std;

vector <long long> dist (100009, numeric_limits<long long>::max());
vector <vector <pair <int, int>>> adj (100009);
vector <long long> prevv (100009, -1);
vector <int> negative_cycle_elements;
vector <int> ForBFS;
queue <int> q;
bool neg_cycle;


void BFS (int node)
{
    vector <long long> dist2 (100009, INT_MAX);
    dist2[node] = 0;
    q.push (node);
    while (!q.empty())
    {
        int father = q.front();
        q.pop();
        for (int i = 0; i < (int) adj[father].size(); i++)
        {
            int child = adj[father][i].second;
            if (dist2[child] == INT_MAX)
            {
                q.push (child);
                negative_cycle_elements.push_back (child);
                dist2[child] = dist2[father] + 1;
            }
        }
    }
}

bool connectedComp (int node, int endd)
{
    vector <long long> dist2 (100009, INT_MAX);
    dist2[node] = 0;
    prevv[node] = 0;
    q.push (node);
    while (!q.empty())
    {
        int father = q.front();
        q.pop();
        for (int i = 0; i < (int) adj[father].size(); i++)
        {
            int child = adj[father][i].second;
            if (dist2[child] == INT_MAX)
            {
                q.push (child);
                dist2[child] = dist2[father] + 1;
                prevv[child] = father;
            }
        }
    }
    if (prevv[endd] == -1)
        return 0;
    else
        return 1;
}


void BellmanFord (int V, int s)
{
    dist[s] = 0;
    for (int i = 0, flag = 0; i < V - 1; i++, flag = 0)
    {
        for (int k = 1; k <= V; k++)
        {
            for (size_t j = 0; j < adj[k].size(); j++)
            {
                int child = adj[k][j].second;
                int weight = adj[k][j].first;
                if (dist[child] > dist[k] + weight && dist[k] != numeric_limits<long long>::max())
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
            if (dist[child] > dist[k] + weight && dist[k] != numeric_limits<long long>::max())
            {
                neg_cycle = 1;
                ForBFS.push_back (child);
                negative_cycle_elements.push_back (child);
            }
        }
    }

    for (size_t i = 0; i < ForBFS.size(); i++)
        BFS (ForBFS[i]);
}
int main()
{
    int x, y, w, n, m, s, op = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> w;
        adj[x].push_back (make_pair (w, y));
    }
    cin >> s;
    BellmanFord (n, s);
    sort (negative_cycle_elements.begin(), negative_cycle_elements.end());
    negative_cycle_elements.erase (unique (negative_cycle_elements.begin(), negative_cycle_elements.end()), negative_cycle_elements.end());

    for (int i = 1; i <= n; i++)
    {
      op = 0;
      for (int j = 0; j < (int)negative_cycle_elements.size(); j++)
      {
          if (negative_cycle_elements[j] == i && connectedComp (s, negative_cycle_elements[j]))
          {
              cout << "-" << "\n";
              op = 1;
              break;
          }
      }
        if (op) continue;
        if (!connectedComp (s, i))
            cout << "*" << "\n";
        else
            cout << dist[i] << "\n";
    }
    return 0;
}
