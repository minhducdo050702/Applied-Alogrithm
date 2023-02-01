#include <bits/stdc++.h>
using namespace std;
const int MAX = 50;
int n, p;
int a[MAX][MAX];
int best = INT_MAX;
int curr = 0;
int x[MAX];
int visited[MAX];
int load = 0;
int cmin = INT_MAX;
void input()
{
    memset(visited, 0, sizeof(visited));
    cin >> n >> p;
    for (int i = 0; i <= (2 * n); i++)
        for (int j = 0; j <= (2 * n); j++)
        {
            cin >> a[i][j];
            if (a[i][j] != 0)
                cmin = min(cmin, a[i][j]);
        }
    x[0] = 0;
    visited[0] = 1;
}
bool UCV(int i, int k)
{
    if (visited[i] == 1)
        return false;
    if (i > n)
    {
        if (visited[i - n] == 0)
            return false;
        if (load == 0)
            return false;
    }
    else
    {
        if (load + 1 > p)
            return false;
    }
    if ((curr + a[x[k - 1]][i] + cmin * (2 * n + 1 - k)) >= best)
        return false;
    return true;
}

void TRY(int k)
{
    for (int i = 1; i <= 2 * n; i++)
    {
        if (UCV(i, k))
        {
            x[k] = i;
            visited[i] = 1;
            curr += a[x[k - 1]][i];
            int temp = load;
            if (i > n)
                load--;
            else
                load++;
            if (k == 2 * n)
            {
                best = min(best, curr + a[i][0]);
            }
            else
                TRY(k + 1);
            visited[i] = 0;
            curr -= a[x[k - 1]][i];
            if (i > n)
                load++;
            else
                load--;
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