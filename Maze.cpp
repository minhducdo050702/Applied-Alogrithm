#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000;
int n, m, r, c;
int A[MAX][MAX];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int process()
{
    if (A[r][c] == 1)
        return -1;
    queue<pair<int, int>> q;
    int visited[MAX][MAX];
    int step[MAX][MAX];
    q.push(pair<int, int>(r, c));
    visited[r][c] = 1;
    step[r][c] = 1;
    pair<int, int> v;
    int xx, yy;
    while (!q.empty())
    {
        v = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            xx = v.first + dx[i];
            yy = v.second + dy[i];
            if (A[xx][yy] == 0 && visited[xx][yy] == 0)
            {
                visited[xx][yy] = 1;
                step[xx][yy] = step[v.first][v.second] + 1;
                if (xx == 1 || xx == n || yy == 1 || yy == m)
                    return step[xx][yy];
                q.push(pair<int, int>(xx, yy));
            }
        }
    }
    return -1;
}

int main()
{
    cin >> n >> m >> r >> c;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> A[i][j];

    cout << process();
    return 0;
}