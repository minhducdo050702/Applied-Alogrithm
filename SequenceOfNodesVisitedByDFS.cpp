#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000000;
int n, m;
vector<int> edge[MAX];
int visited[MAX];
void input()
{
    cin >> n >> m;
    int temp1, temp2;
    for (int i = 1; i <= m; i++)
    {
        cin >> temp1 >> temp2;
        edge[temp1].push_back(temp2);
        edge[temp2].push_back(temp1);
    }
    for (int i = 1; i <= n; i++)
        sort(edge[i].begin(), edge[i].end());
}
void DFS(int u)
{
    cout << u << " ";
    visited[u] = 1;
    for (auto v : edge[u])
        if (visited[v] == 0)
            DFS(v);
}

int main()
{
    input();
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
            DFS(i);
    }
    return 0;
}
