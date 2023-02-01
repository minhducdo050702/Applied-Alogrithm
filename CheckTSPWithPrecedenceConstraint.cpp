#include <bits/stdc++.h>
using namespace std;
const int MAX = 2000;
int n, m;
int x[MAX];
int a[MAX][MAX];
vector<int> b[MAX];
int mark[MAX];

void check()
{
    int res = 0;
    mark[x[1]] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (auto j : b[x[i]])
        {
            if (mark[j] == 1)
            {
                cout << -1;
                return;
            }
        }
        res += a[x[i - 1]][x[i]];
        mark[x[i]] = 1;
    }
    cout << res + a[x[n]][x[1]];
}
int main()
{

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    cin >> m;
    int temp1, temp2;
    for (int i = 1; i <= m; i++)
    {
        cin >> temp1 >> temp2;
        b[temp1].push_back(temp2);
    }
    check();
    return 0;
}