#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e4 + 4;
const int Q = 1e9 + 7;
int a[MAX];
int N;
void process()
{
    a[0] = 1;
    for (int i = 1; i <= N; i++)
        for (int j = i; j <= N; j++)
        {
            a[j] = (a[j] + a[j - i]) % Q;
        }
}
int main()
{
    cin >> N;
    process();
    cout << a[N];
    return 0;
}
