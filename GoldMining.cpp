#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000000;
int n, L1, L2;
int a[MAX];
int f[MAX];
int f_max = 0;
//do phuc tap O(n^2)
void process()
{
    for (int i = 1; i < L1; i++)
        f[i] = a[i];
    for (int i = L1; i <= n; i++)
    {
        for (int j = max(i - L2, 1); j <= max(i - L1, 1); j++)
        {
            f[i] = max(f[i], f[j] + a[i]);
        }
        f_max = max(f_max, f[i]);
    }
}
int main()
{
    cin >> n >> L1 >> L2;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    process();
    cout << f_max;
    return 0;
}