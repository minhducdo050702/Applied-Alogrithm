#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 5;
int N, M;
vector<int> edge[MAX];
int visited[MAX];
int cnt = 0;
void input()
{
    cin >> N >> M;
    int temp1, temp2;
    for (int i = 1; i <= M; i++)
    {
        cin >> temp1 >> temp2;
        edge[temp1].push_back(temp2);
        edge[temp2].push_back(temp1);
    }
}
void DFS(int x)
{
    stack<int> s;
    s.push(x);
    visited[x] = 1;
    while (!s.empty())
    {
        int u = s.top();
        s.pop();
        for (auto v : edge[u])
        {
            if (visited[v] == 0)
            {
                visited[v] = 1;
                s.push(v);
            }
        }
    }
    cnt++;
}
int main()
{
    input();
    for (int i = 1; i <= N; i++)
        if (visited[i] == 0)
            DFS(i);
    cout << cnt;
    return 0;
}