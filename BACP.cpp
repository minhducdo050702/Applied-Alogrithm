#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int n, m;
int A[MAX][MAX];
int c[MAX];
vector<int> before[MAX]; // after[i] gom cac mon phai hoc
vector<int> after[MAX];

int maxload = INT_MAX;
int period[MAX];
int load[MAX]; // so tin chi cua ki i
bool UCV(int i, int k)
{
    if (load[i] + c[k] >= maxload) // nhanh can
        return false;
    for (auto j : before[k])
    {
        if (period[j] > i)
            return false;
    }
    for (auto j : after[k])
    {
        if (period[j] < i)
            return false;
    }
    return true;
}

void TRY(int k)
{
    for (int i = 1; i <= m; i++)
    {
        if (UCV(i, k)) // mon k o ky i
        {
            period[k] = i;
            load[i] = load[i] + c[k];
            if (k == n)
            {
                int maxtemp = 0;
                for (int i = 1; i <= m; i++)
                    maxtemp = max(maxtemp, load[i]);
                maxload = min(maxload, maxtemp);
            }
            else
                TRY(k + 1);
            load[i] = load[i] - c[k];
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> A[i][j];
            if (A[i][j] == 1)
            {
                before[j].push_back(i);
                after[i].push_back(j);
            }
        }
    memset(period, -1, sizeof(period));
    TRY(1);
    cout << maxload;
    return 0;
}