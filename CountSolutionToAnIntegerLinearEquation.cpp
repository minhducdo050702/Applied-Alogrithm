#include <bits/stdc++.h>
using namespace std;
int n, M;
int cnt = 0;
int tong = 0;
int a[100];
bool UCV(int i, int k)
{
    if (k == n)
        return i * a[k] + tong == M;
    return true;
}
void TRY(int k)
{
    for (int i = 1; i <= M - tong - n + k; i++)
    {
        if (UCV(i, k))
        {
            tong += i * a[k];
            if (k == n)
                cnt++;
            else
                TRY(k + 1);
            tong -= i * a[k];
        }
    }
}

int main()
{
    cin >> n >> M;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    TRY(1);
    cout << cnt;
    return 0;
}