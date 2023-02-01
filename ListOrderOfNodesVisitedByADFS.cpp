#include <bits/stdc++.h>
using namespace std;
const int MAX = 3e5;
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
}
void DFS(int x)
{
    cout << x << " ";
    visited[x] = 1;
    for (auto i : edge[x])
        if (visited[i] == 0)
            DFS(i);
}

int main()
{
    input();
    DFS(1);
    return 0;
}