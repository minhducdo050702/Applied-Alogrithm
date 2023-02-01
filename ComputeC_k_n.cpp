#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int Q = 1e9 + 7;
ull C_tab[1000][1000];
ull C(int k, int n)
{
    if (k == 0 || n == k)
    {
        C_tab[k][n] = 1;
        return C_tab[k][n];
    }
    if (C_tab[k][n] > 0)
        return C_tab[k][n];
    else
    {
        C_tab[k][n] = (C(k - 1, n - 1) + C(k, n - 1)) % Q;
        return C_tab[k][n] % Q;
    }
}
int main()
{
    int k, n;
    cin >> k >> n;
    cout << C(k, n);
    return 0;
}