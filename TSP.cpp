#include <bits/stdc++.h>
using namespace std;
int n;
int a[30][30];
int best = INT_MAX;
int curr = 0;
int visited[30];
int x[30];
int cmin = INT_MAX;
void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] != 0)
                cmin = min(cmin, a[i][j]);
        }
    x[1] = 1;
    visited[1] = 1;
}
bool UCV(int i, int k)
{
    if (visited[i] == 1)
        return false;
    if ((curr + (n - k) * cmin) > best)
        return false;
    return true;
}
void TRY(int k)
{
    for (int i = 1; i <= n; i++)
    {
        if (UCV(i, k))
        {
            x[k] = i;
            visited[i] = 1;
            curr += a[x[k - 1]][i];
            if (k == n)
            {
                curr += a[i][1];
                best = min(best, curr);
                curr -= a[i][1];
            }
            else
                TRY(k + 1);
            visited[i] = 0;
            curr -= a[x[k - 1]][i];
        }
    }
}
int main()
{
    input();
    TRY(2);
    cout << best;
    return 0;
}