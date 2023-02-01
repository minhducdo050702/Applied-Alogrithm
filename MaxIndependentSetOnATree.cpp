#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int n;
int d[MAX];
int edge[MAX][MAX];
int best = 0;
int curr = 0;
int visited[MAX];
int a[MAX];
bool UCV(int i, int k)
{
    if (visited[i] == 1)
        return false;
    for (int j = 1; j <= k - 1; j++)
        if (edge[i][a[j]] == 1)
            return false;
    return true;
}
void TRY(int k)
{
    for (int i = 1; i <= n; i++)
    {
        if (UCV(i, k))
        {
            a[k] = i;
            visited[i] = 1;
            curr += d[i];
            best = max(curr, best);
            TRY(k + 1);
            visited[i] = 0;
            curr -= d[i];
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> d[i];
    int temp1, temp2;
    for (int i = 1; i < n; i++)
    {
        cin >> temp1 >> temp2;
        edge[temp1][temp2] = 1;
        edge[temp2][temp1] = 1;
    }
    TRY(1);
    cout << best;
    return 0;
}