#include <bits/stdc++.h>
using namespace std;
int k, n;
int a[50];
int curr = 0;
void ghinhan()
{
    for (int i = 1; i <= k; i++)
        cout << a[i] << " ";
    cout << endl;
}
bool UCV(int i, int m)
{
    if (m == k)
        return curr + i == n;
    else
        return true;
}
void TRY(int m)
{
    for (int i = a[m - 1]; i <= (n - curr - (k - m)); i++)
    {
        if (UCV(i, m))
        {
            a[m] = i;
            curr += i;
            if (m == k)
                ghinhan();
            else
                TRY(m + 1);
            curr -= i;
        }
    }
}
int main()
{
    cin >> k >> n;
    a[0] = 1;
    TRY(1);
    return 0;
}