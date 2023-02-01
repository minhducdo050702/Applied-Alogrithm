#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6;
int N, M;
vector<int> edge[MAX];
int d[MAX];
queue<int> q;
int visited[MAX];
void input()
{
    cin >> N >> M;
    int temp1, temp2;
    for (int i = 0; i < M; i++)
    {
        cin >> temp1 >> temp2;
        edge[temp1].push_back(temp2);
        edge[temp2].push_back(temp1);
    }
}
int BFS(int x)
{
    memset(d, -1, sizeof(d));
    q.push(x);
    d[x] = 0;
    while (!q.empty())
    {
        int y = q.front();
        q.pop();
        for (auto i : edge[y])
        {
            if (d[i] == -1)
            {
                q.push(i);
                d[i] = d[y] + 1;
            }
            else
            {
                if (d[y] % 2 == d[i] % 2)
                    return 0;
            }
        }
    }
    return 1;
}

int main()
{
    input();
    cout << BFS(1);
    return 0;
}