#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
const long Q = 1e9 + 7;
ull a, b;

ull expmod(ull x, ull y) // x^y%Q
{
    if (y == 0)
        return 1;
    else if (y % 2 == 1)
        return (expmod(x, y - 1) * x) % Q;
    else
    {
        ull tmp = expmod(x, y / 2) % Q;
        return (tmp * tmp) % Q;
    }
}

int main()
{
    cin >> a >> b;
    cout << expmod(a % Q, b);
    return 0;
}