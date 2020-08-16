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

struct node
{
    int x;
    int y;
    int parent;
    int rankk;

    node (int a, int b, int c, int d = 0)
    {
        x = a;
        y = b;
        parent = c;
        rankk = d;
    }
};

struct edge
{
    int u;
    int v;
    double weight;
    edge (int a, int b, double c)
    {
        u = a;
        v = b;
        weight = c;
    }
};

bool cmp (const edge &e1, const edge &e2)
{
    return e1.weight < e2.weight;
}

int findd (int i, vector <node> &nodes)
{
    if (i != nodes[i].parent)
        nodes[i].parent = findd (nodes[i].parent, nodes);
    return nodes[i].parent;
}

void Union (int s1, int s2, vector <node> &nodes)
{
    int r1 = findd (s1, nodes);
    int r2 = findd (s2, nodes);
    if (r1 != r2)
    {
        if (nodes[r1].rankk > nodes[r2].rankk)
            nodes[r2].parent = r1;
        else
        {
            nodes[r1].parent = r2;
            if (nodes[r1].rankk == nodes[r2].rankk)
                nodes[r2].rankk++;
        }
    }
}

double weight (int x1, int x2, int y1, int y2)
{
    return sqrt ((x1 - y1) * (x1 - y1) + (x2 - y2) * (x2 - y2));
}

double min_distance (vector <int> x, vector <int> y, int n)
{
    vector <node> nodes;
    vector <edge> edges;
    double result = 0.;
    for (int i = 0; i < n; i++)
        nodes.push_back (node (x[i], y[i], i));
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            edges.push_back (edge (i, j, weight (x[i], y[i], x[j], y[j])));
        }
    }
    sort (edges.begin(), edges.end(), cmp);
    for (size_t i = 0; i < edges.size(); i++)
    {
        int s1 = edges[i].u;
        int s2 = edges[i].v;
        if (findd (s1, nodes) != findd (s2, nodes))
        {
            result += edges[i].weight;
            Union (s1, s2, nodes);
        }
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    vector <int> x (n), y (n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];

    }
    cout << setprecision (10) << fixed << min_distance (x, y, n);
    return 0;
}
