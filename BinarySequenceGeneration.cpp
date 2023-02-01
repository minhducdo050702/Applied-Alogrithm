#include <bits/stdc++.h>
using namespace std;
#define MAX 21
int n;
int A[MAX];
void ghinhan()
{
    for (int i = 1; i <= n; i++)
        cout << A[i];
    cout << endl;
}
void TRY(int k)
{
    for (int i = 0; i <= 1; i++)
    {
        A[k] = i;
        if (k == n)
            ghinhan();
        else
            TRY(k + 1);
    }
}
int main()
{
    cin >> n;
    TRY(1);
    return 0;
}