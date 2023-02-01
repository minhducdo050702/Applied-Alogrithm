#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const ull Q = 1e9 + 7;
const ull MAX = 1e6;
ull n;
ull a[MAX];
ull merge(ull a[], ull start, ull mid, ull end)
{
    ull cnt = 0;
    ull temp[MAX];
    ull start1 = start;
    ull end1 = mid;
    ull start2 = mid + 1;
    ull end2 = end;
    ull index = start1;
    for (; start1 <= end1 && start2 <= end2; index++)
    {
        if (a[start1] > a[start2])
        {
            cnt = (cnt + (mid - start1 + 1));
            temp[index] = a[start2];
            start2++;
        }
        else
        {
            temp[index] = a[start1];
            start1++;
        }
    }
    for (; start1 <= end1; index++, start1++)
        temp[index] = a[start1];
    for (; start2 <= end2; index++, start2++)
        temp[index] = a[start2];
    for (ull index = start; index <= end; index++)
        a[index] = temp[index];
    return cnt % Q;
}
ull invert(ull a[], ull start, ull end)
{
    if (start == end)
        return 0;
    ull mid = (start + end) / 2;
    ull invertL = invert(a, start, mid);
    ull invertR = invert(a, mid + 1, end);
    ull invertM = merge(a, start, mid, end);
    return (invertL + invertM + invertR) % Q;
}
int main()
{
    cin >> n;
    ull temp;
    for (ull i = 0; i < n; i++)
        cin >> a[i];
    cout << invert(a, 0, n - 1);
    return 0;
}
