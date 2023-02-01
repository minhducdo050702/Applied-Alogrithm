#include <bits/stdc++.h>
using namespace std;
const int Q = 1e9 + 7;
// lexico
int n;
int cnt = 0;
int a[50];
int curr = 0;

bool UCV(int i, int k)
{
    if (curr + i > n)
        return false;
    return true;
}

void TRY(int k)
{
    for (int i = max(1, a[k - 1]); i <= n; i++)
    {
        if (UCV(i, k))
        {
            a[k] = i;
            curr += i;
            if (curr == n)
                cnt++;
            else
                TRY(k + 1);
            curr -= i;
        }
    }
}

int main()
{
    cin >> n;
    TRY(1);
    cout << cnt % Q;
    return 0;
}
