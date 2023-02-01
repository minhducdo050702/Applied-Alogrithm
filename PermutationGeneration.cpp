#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int n;
int a[MAX];
int mark[MAX];
void ghinhan()
{
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << endl;
}

bool UCV(int i, int k)
{
    return mark[i] == 0;
}
void TRY(int k)
{
    for (int i = 1; i <= n; i++)
    {
        if (UCV(i, k))
        {
            a[k] = i;
            mark[i] = 1;
            if (k == n)
                ghinhan();
            else
                TRY(k + 1);
            mark[i] = 0;
        }
    }
}

int main()
{
    cin >> n;
    TRY(1);
    return 0;
}