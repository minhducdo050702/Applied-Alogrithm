#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
int T;
int n, m;
int visited[MAX];
int a[MAX];
int ans;
int d[MAX][MAX];
bool UCV(int i, int k)
{
    if (visited[i] == 1)
        return false;
    if (d[a[k - 1]][i] == 0)
        return false;
    return true;
}
void TRY(int k)
{
    for (int i = 2; i <= n; i++)
    {
        if (UCV(i, k))
        {
            a[k] = i;
            visited[i] = 1;
            if (k == n)
            {
                if (d[i][a[1]] == 1)
                {
                    ans = 1;
                    return;
                }
            }
            else
                TRY(k + 1);
            visited[i] = 0;
        }
    }
}
int main()
{
    cin >> T;
    for (int j = 1; j <= T; j++)
    {
        ans = 0;
        memset(visited, 0, sizeof(visited));
        memset(a, 0, sizeof(a));
        memset(d, 0, sizeof(d));
        a[1] = 1;
        visited[1] = 1;
        cin >> n >> m;
        int temp1, temp2;
        for (int i = 1; i <= m; i++)
        {
            cin >> temp1 >> temp2;
            d[temp1][temp2] = 1;
            d[temp2][temp1] = 1;
        }
        ans = 0;
        TRY(2);
        cout << ans << endl;
    }
    return 0;
}