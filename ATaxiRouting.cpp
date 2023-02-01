#include <bits/stdc++.h>
using namespace std;
int n;
int a[50][50];
int x[50];
int visited[50];
int best = INT_MAX;
int curr = 0;
int cmin = INT_MAX;
void input()
{
    cin >> n;
    for (int i = 0; i <= 2 * n; i++)
        for (int j = 0; j <= 2 * n; j++)
        {
            cin >> a[i][j];
            if (a[i][j])
                cmin = min(cmin, a[i][j]);
        }
    x[0] = 0;
    visited[0] = 1;
}
bool UCV(int i, int k)
{
    if (visited[i] == 1)
        return false;
    if ((curr + a[x[k - 1] + n][i] + a[i][i + n] + cmin * (2 * n + 1 - 2 * k)) >= best)
        return false;
    return true;
}
void TRY(int k)
{
    for (int i = 1; i <= n; i++)
    {
        if (UCV(i, k))
        {
            if (k == 1)
                curr = curr + a[x[0]][i] + a[i][i + n];
            else
            {
                curr = curr + a[x[k - 1] + n][i] + a[i][i + n];
            }
            x[k] = i;
            visited[i] = 1;
            if (k == n)
                best = min(best, curr + a[i + n][0]);
            else
                TRY(k + 1);
            visited[i] = 0;
            if (k == 1)
                curr = curr - a[x[0]][i] - a[i][i + n];
            else
                curr = curr - a[x[k - 1] + n][i] - a[i][i + n];
        }
    }
}
int main()
{
    input();
    TRY(1);
    cout << best;
    return 0;
}