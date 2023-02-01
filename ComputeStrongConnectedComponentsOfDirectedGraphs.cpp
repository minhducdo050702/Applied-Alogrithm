#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000
int n, m;
vector<int> edge[MAX];
int low[MAX];
int num[MAX];
int connect[MAX];
int dfs_time;
int par[MAX];
int scc = 0;
stack<int> st;
void dfs(int u)
{
    low[u] = num[u] = ++dfs_time;
    connect[u] = 1;
    st.push(u);
    for (auto v : edge[u])
    {
        if (v == par[u])
            continue;
        if (num[v] == 0)
        {
            par[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if (connect[v] == 1)
        {
            low[u] = min(low[u], num[v]);
        }
    }
    if (low[u] == num[u])
    {
        scc++;
        int v;
        while (1)
        {
            v = st.top();
            st.pop();
            connect[v] = 0;
            if (u == v)
                break;
        }
    }
}

int main()
{
    memset(par, -1, sizeof(par));
    cin >> n >> m;
    int temp1, temp2;
    for (int i = 1; i <= m; i++)
    {
        cin >> temp1 >> temp2;
        edge[temp1].push_back(temp2);
    }
    for (int i = 1; i <= n; i++)
    {
        if (num[i] == 0)
            dfs(i);
    }
    cout << scc;
    return 0;
}
