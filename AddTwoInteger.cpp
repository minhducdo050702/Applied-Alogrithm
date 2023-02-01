#include <bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long a, b;
    cin >> a >> b;
    unsigned long long c, d, e, f;
    c = a / 10;
    d = b / 10;
    e = a % 10;
    f = b % 10;
    if (e + f < 10)
    {
        if (c + d != 0)
            cout << c + d << e + f;
        else
            cout << e + f;
    }
    else
    {
        if (c + d != 0)
            cout << c + d + 1 << e + f - 10;
        else
            cout << e + f;
    }
    return 0;
}
