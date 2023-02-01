#include <bits/stdc++.h>
using namespace std;
int maxload = INT_MAX;
int m, n;
int k;
vector<int> a[40];
int b[40][40]; // b[i][j] giao vien i co the day mon j
int c[40][40]; // c[i][j] mon i trung lich mon j
int l[40];     // l[i]=j nghia la giao vien i da day j mon
void input()
{
    cin >> m >> n;
    int temp1, temp2, temp3;
    for (int i = 1; i <= m; i++)
    {
        cin >> temp1;
        for (int j = 1; j <= temp1; j++)
        {
            cin >> temp2;
            b[i][temp2] = 1;
        }
    }
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> temp1 >> temp2;
        c[temp1][temp2] = 1;
        c[temp2][temp1] = 1;
    }
}
bool UCV(int i, int k)
{
    if (b[i][k] == 0)
        return false;
    if (l[i] + 1 >= maxload)
        return false;
    for (auto j : a[i])
        if (c[j][k] == 1)
            return false;
    return true;
}
void TRY(int k)
{
    for (int i = 1; i <= m; i++)
    {
        if (UCV(i, k))
        {
            a[i].push_back(k);
            l[i]++;
            if (k == n)
            {
                int maxtemp = 0;
                for (int j = 1; j <= m; j++)
                    maxtemp = max(maxtemp, l[j]);
                maxload = min(maxload, maxtemp);
            }
            else
                TRY(k + 1);
            a[i].pop_back();
            l[i]--;
        }
    }
}
int main()
{
    input();
    TRY(1);
    cout << maxload;
    return 0;
}
