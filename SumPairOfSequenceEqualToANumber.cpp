#include <bits/stdc++.h>
using namespace std;
int Q = 0;
int n, M;
int a[1000000];
void input()
{
    cin >> n >> M;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
}
int find(int a[], int start, int end, int key)
{
    if (start <= end)
    {
        int mid = (start + end) / 2;
        if (a[mid] == key)
            return 1;
        else if (a[mid] < key)
            return find(a, mid + 1, end, key);
        else
            return find(a, start, mid - 1, key);
    }
    return 0;
}
void process()
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] * 2 == M)
            continue;
        res += find(a, 0, n - 1, M - a[i]);
    }
    Q = res / 2;
}
int main()
{
    input();
    process();
    cout << Q;
    return 0;
}