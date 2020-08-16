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
vector <vector <int>> adj (1009);
vector <int> finish (1009, -1);
vector <int> start (1009, -1);
int timer = 1;
bool cycle = 0;

void DFS_Cycle (int x)
{
    start [x] = timer ++;
    for (int i = 0; i < (int) adj[x].size(); i++)
    {
        int child = adj[x][i];
        if (start[child] == -1)
            DFS_Cycle (child);
        else
        {
            if (finish[child] == -1)
                cycle = 1;
        }
    }
    finish[x] = timer++;
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
        if (start[i] == -1)
            DFS_Cycle (i);
    }
    cout << cycle;

    return 0;
}
