#include <bits/stdc++.h>
using namespace std;
int n;
int a[100];
void ghinhan()
{
    for (int i = 1; i <= n; i++)
        cout << a[i];
    cout << endl;
}
bool UCV(int i, int k)
{
    if (i == 0)
        return true;
    else
        return a[k - 1] == 0;
}
void TRY(int k)
{
    for (int i = 0; i <= 1; i++)
    {
        if (UCV(i, k))
        {
            a[k] = i;
            if (k == n)
                ghinhan();
            else
                TRY(k + 1);
        }
    }
}
int main()
{
    cin >> n;
    TRY(1);
    return 0;
}