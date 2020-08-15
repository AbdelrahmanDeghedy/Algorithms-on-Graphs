for (int i = 0; i < E; i++)
{
    for (int j = 0; j < 3; j++)
        cin >> graph[i][j];
}
for (int j = 0; j < E; j++)
{
    if (dis[graph[j][0]] + graph[j][2] < dis[graph[j][1]])
        dis[graph[j][1]] = dis[graph[j][0]] + graph[j][2];
}
