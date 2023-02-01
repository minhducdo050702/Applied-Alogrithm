#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000000;
int n, m;
vector<int> edge[MAX];
int low[MAX];
int num[MAX];
int par[MAX];
int child_cnt[MAX];
int isAP[MAX];
int dfs_time = 0;
int bridge_cnt = 0;
int point_cnt = 0;
void DFS(int u)
{
    low[u] = num[u] = ++dfs_time;

    for (auto v : edge[u])
    {
        if (par[u] == v)
            continue;
        if (num[v] == 0)
        {
            par[v] = u;
            child_cnt[u]++;
            DFS(v);
            low[u] = min(low[u], low[v]);
            if (par[u] == -1)
            {
                if (child_cnt[u] > 1)
                    isAP[u] = 1;
            }
            else if (low[v] >= num[u])
                isAP[u] = 1;
        }
        else
            low[u] = min(low[u], num[v]);
    }
}
void processP()
{
    for (int i = 1; i <= n; i++)
        if (isAP[i] == 1)
            point_cnt++;
}
void processB()
{
    for (int i = 1; i <= n; i++)
        for (auto j : edge[i])
        {
            if (low[j] > num[i])
                bridge_cnt++;
        }
}
int main()
{
    memset(par, -1, sizeof(par));
    cin >> n >> m;
    int temp1, temp2;
    for (int i = 0; i < m; i++)
    {
        cin >> temp1 >> temp2;
        edge[temp1].push_back(temp2);
        edge[temp2].push_back(temp1);
    }
    for (int i = 1; i <= n; i++)
    {
        if (num[i] == 0)
            DFS(i);
    }
    processB();
    processP();
    cout << point_cnt << " " << bridge_cnt;
    return 0;
}